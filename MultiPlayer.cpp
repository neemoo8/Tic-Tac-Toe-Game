#include <vcl.h>
#pragma hdrstop

#include "MultiPlayer.h"
#include "History.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
sqlite3* db;
TMulti_player* Multi_player;

__fastcall TMulti_player::TMulti_player(TComponent* Owner) : TForm(Owner) {}

bool playerTurn = true; // true for player 1 (X), false for player 2 (O)
char board[3][3]; // to keep track of the board state
void TMulti_player::saveMoveToDatabase(sqlite3* db, int gameID, int userID,
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

void TMulti_player::saveGameScoreToDatabase(sqlite3* db, int gameID,
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

void __fastcall TMulti_player::ButtonClick(TObject* Sender)
{
    int moveNumber = 0;

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
    if (button->Caption == "") {
        button->Caption = playerTurn ? "X" : "O";
        int row = button->Tag / 3;
        int col = button->Tag % 3;
        board[row][col] = playerTurn ? 'X' : 'O';
        saveMoveToDatabase(db, GAME_ID, playerTurn ? USER1_ID : USER2_ID,
            ++moveNumber, row, col, playerTurn ? 'X' : 'O');

        playerTurn = !playerTurn;
        CheckWin();
    }
}

void __fastcall TMulti_player::CheckWin()
{
    std::string winner;
    // Check rows, columns and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
                board[i][0] != 0) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
                board[0][i] != 0))
        {
            ShowMessage((playerTurn ? "Player 2 (O)" : "Player 1 (X)") +
                        String(" wins!"));
            saveGameScoreToDatabase(db, GAME_ID, 1, 2, 1, "Player 1 wins!");
            GAME_ID++;
            ResetBoard();
            return;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
            board[0][0] != 0) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
            board[0][2] != 0))
    {
        ShowMessage(
            (playerTurn ? "Player 2 (O)" : "Player 1 (X)") + String(" wins!"));
        saveGameScoreToDatabase(db, GAME_ID, USER1_ID, USER2_ID,
            playerTurn ? USER2_ID : USER1_ID, winner + " wins!");
        GAME_ID++;
        ResetBoard();
        return;
    }

    // Check for a draw
    bool draw = true;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == 0)
                draw = false;

    if (draw) {
        ShowMessage("It's a draw!");
        saveGameScoreToDatabase(
            db, GAME_ID, 1, 2, 0, "Draw"); // Assuming 0 indicates a draw
        GAME_ID++;
        ResetBoard();
    }
}

void __fastcall TMulti_player::ResetBoard()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;

    for (int i = 1; i <= 9; i++) {
        TButton* button =
            dynamic_cast<TButton*>(FindComponent("Button" + IntToStr(i)));
        if (button)
            button->Caption = "";
    }
}

void __fastcall TMulti_player::Button10Click(TObject* Sender)
{
    Close();
}

void __fastcall TMulti_player::Button12Click(TObject* Sender)
{
    TYour_history* Your_history = new TYour_history(this);
    Your_history->Show();
    this->Hide();
}
//---------------------------------------------------------------------------

