#include <vcl.h>
#pragma hdrstop

#include "SinglePlayer.h"
#include "History.h"
#include <algorithm>

#pragma package(smart_init)
#pragma resource "*.dfm"
sqlite3* db;
int moveNumber = 0;

Tsingle_player* single_player;

__fastcall Tsingle_player::Tsingle_player(TComponent* Owner) : TForm(Owner)
{
    // Initialize the board with '_'
    board = vector<vector<char> >(BOARD_SIZE, vector<char>(BOARD_SIZE, '_'));
    // Attach ButtonClick to all buttons
    Button1->OnClick = ButtonClick;
    Button2->OnClick = ButtonClick;
    Button3->OnClick = ButtonClick;
    Button4->OnClick = ButtonClick;
    Button5->OnClick = ButtonClick;
    Button6->OnClick = ButtonClick;
    Button7->OnClick = ButtonClick;
    Button8->OnClick = ButtonClick;
    Button9->OnClick = ButtonClick;
}

int Tsingle_player::evaluateBoard(const vector<vector<char> > &board)
{
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X')
                return 10;
            else if (board[i][0] == 'O')
                return -10;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'X')
                return 10;
            else if (board[0][i] == 'O')
                return -10;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X')
            return 10;
        else if (board[0][0] == 'O')
            return -10;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X')
            return 10;
        else if (board[0][2] == 'O')
            return -10;
    }

    return 0; // No winner yet
}

void Tsingle_player::saveMoveToDatabase(sqlite3* db, int gameID, int userID,
    int moveNumber, int row, int col, char player)
{
    std::string sql =
        "INSERT INTO game4 (game_id, user_id, move_number, row, col, player) VALUES (?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, gameID);
        sqlite3_bind_int(stmt, 2, userID);
        sqlite3_bind_int(stmt, 3, moveNumber);
        sqlite3_bind_int(stmt, 4, row);
        sqlite3_bind_int(stmt, 5, col);
        sqlite3_bind_text(stmt, 6, &player, 1, SQLITE_STATIC);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    } else {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
    }
}
void Tsingle_player::saveGameScoreToDatabase(sqlite3* db, int gameID,
    int player1ID, int player2ID, int winnerID, const string &gameScore)
{
    std::string sql =
        "INSERT INTO game_data (game_id, player1_id, player2_id, winner_id, game_score) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, gameID);
        sqlite3_bind_int(stmt, 2, player1ID);
        sqlite3_bind_int(stmt, 3, player2ID);
        sqlite3_bind_int(stmt, 4, winnerID);
        sqlite3_bind_text(stmt, 5, gameScore.c_str(), -1,
            SQLITE_STATIC); // Bind the new column value as a string
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    } else {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
    }
}

bool Tsingle_player::isGameOver(const vector<vector<char> > &board)
{
    // Check if the board is full
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == '_')
                return false; // There is an empty cell, game is not over
        }
    }
    return true; // No empty cells, game is over (tie)
}

TreeNode* Tsingle_player::buildTree(TreeNode* node, int depth)
{
    // Build the game tree using minimax algorithm
    if (depth >= BOARD_SIZE * BOARD_SIZE || evaluateBoard(node->board) != 0 ||
        isGameOver(node->board))
    {
        node->value = evaluateBoard(node->board);
        return node;
    }

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (node->board[i][j] == '_') {
                vector<vector<char> > newBoard = node->board;
                newBoard[i][j] =
                    node->isMaximizingPlayer ? 'X' : 'O'; // Alternate turns
                TreeNode* child =
                    new TreeNode(newBoard, !node->isMaximizingPlayer);
                node->children.push_back(buildTree(child, depth + 1));
            }
        }
    }

    return node;
}

int Tsingle_player::minimax(TreeNode* node, int alpha, int beta)
{
    // Minimax algorithm implementation
    if (node->children.empty()) {
        return node->value;
    }

    if (node->isMaximizingPlayer) {
        int maxEval = INT_MIN;
        for (auto child : node->children) {
            int eval = minimax(child, alpha, beta);
            maxEval = std::max(maxEval, eval); // Use std::max
            alpha = std::max(alpha, eval); // Use std::max
            if (beta <= alpha)
                break;
        }
        node->value = maxEval;
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (auto child : node->children) {
            int eval = minimax(child, alpha, beta);
            minEval = std::min(minEval, eval); // Use std::min
            beta = std::min(beta, eval); // Use std::min
            if (beta <= alpha)
                break;
        }
        node->value = minEval;
        return minEval;
    }
}

Tsingle_player::Move Tsingle_player::findBestMove(vector<vector<char> > &board)
{
    // Find the best move using minimax algorithm
    TreeNode* root = new TreeNode(board, true);
    buildTree(root, 0);

    int bestScore = INT_MIN;
    Move bestMove;

    // Loop through all possible moves and find the best one
    for (auto child : root->children) {
        int moveScore = minimax(child, INT_MIN, INT_MAX);
        if (moveScore > bestScore) {
            bestScore = moveScore;
            for (int i = 0; i < BOARD_SIZE; ++i) {
                for (int j = 0; j < BOARD_SIZE; ++j) {
                    if (board[i][j] != child->board[i][j]) {
                        bestMove.row = i;
                        bestMove.col = j;
                    }
                }
            }
        }
    }

    delete root;
    return bestMove;
}

void Tsingle_player::printBoard(const vector<vector<char> > &board)
{
    // Function to print the Tic-Tac-Toe board (for debugging)
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool Tsingle_player::isMoveValid(
    const vector<vector<char> > &board, int row, int col)
{
    // Check if the move is valid (within bounds and cell is empty)
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE &&
           board[row][col] == '_';
}

void __fastcall Tsingle_player::ButtonClick(TObject* Sender)
{
    // Handle button click
    if (sqlite3_open("C:\\New folder\\login.db", &db)) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
    }
    const char* createTablesSQL =
        "CREATE TABLE IF NOT EXISTS game4 ("
        "game_id INTEGER, "
        "user_id INTEGER, "
        "move_number INTEGER, "
        "row INTEGER, "
        "col INTEGER, "
        "player TEXT);"
        "CREATE TABLE IF NOT EXISTS game_data ("
        "game_id INTEGER PRIMARY KEY AUTOINCREMENT, " // Ensure each game has a unique ID
        "player1_id INTEGER, "
        "player2_id INTEGER, "
        "winner_id INTEGER, "
        "game_score TEXT);";
    char* errMsg = 0;
    if (sqlite3_exec(db, createTablesSQL, 0, 0, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }

    TButton* button = dynamic_cast<TButton*>(Sender);
    int row = button->Tag / BOARD_SIZE;
    int col = button->Tag % BOARD_SIZE;

    if (button->Caption != "") {
        ShowMessage("Invalid move. Try again.");
        return;
    }
    if (isMoveValid(board, row, col)) {
        board[row][col] = 'O'; // Player's move
        button->Caption = "O";
        saveMoveToDatabase(db, GAME_ID, USER_ID, ++moveNumber, row, col, 'O');
        // Update GUI or any other necessary actions
        // Example: printBoard(board);

        // Check game state
        if (evaluateBoard(board) == -10) {
            ShowMessage("Player wins!");
            saveGameScoreToDatabase(db, GAME_ID, 1, 2, 1, "Player 1 wins!");
            ResetBoard();
            return;
        } else if (isGameOver(board)) {
            ShowMessage("It's a tie!");
            saveGameScoreToDatabase(db, GAME_ID, 1, 2, 0, "tie!");
            ResetBoard();
            return;
        }

        // AI's turn
        Move bestMove = findBestMove(board);
        board[bestMove.row][bestMove.col] = 'X'; // AI's move

        TButton* aiButton = dynamic_cast<TButton*>(FindComponent(
            "Button" + IntToStr(bestMove.row * BOARD_SIZE + bestMove.col + 1)));
        aiButton->Caption = "X";
        saveMoveToDatabase(
            db, GAME_ID, AI_ID, ++moveNumber, bestMove.row, bestMove.col, 'X');

        // Update GUI or any other necessary actions
        // Example: printBoard(board);

        // Check game state after AI move
        if (evaluateBoard(board) == 10) {
            ShowMessage("AI wins!");
            saveGameScoreToDatabase(db, GAME_ID, 1, 2, 1, "AI wins!");
            ResetBoard();
            return;
        } else if (isGameOver(board)) {
            ShowMessage("It's a tie!");
            saveGameScoreToDatabase(db, GAME_ID, 1, 2, 0, "tie!");
            ResetBoard();
            return;
        }
    }
}

void Tsingle_player::ResetBoard()
{
    // Reset the board to initial state
    board = vector<vector<char> >(BOARD_SIZE, vector<char>(BOARD_SIZE, '_'));
    for (int i = 1; i <= BOARD_SIZE * BOARD_SIZE; ++i) {
        TButton* button =
            dynamic_cast<TButton*>(FindComponent("Button" + IntToStr(i)));
        if (button) {
            button->Caption = "";
        }
    }
}

void __fastcall Tsingle_player::historyButtonClick(TObject* Sender)
{
    TYour_history* Your_history = new TYour_history(this);
    Your_history->Show();
    this->Hide(); // ????
}

void __fastcall Tsingle_player::Button10Click(TObject* Sender)
{
    Close();
}

