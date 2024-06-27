#include <vcl.h>
#pragma hdrstop

#include "History.h"
#include "Menufrm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TYour_history* Your_history;
sqlite3* db;

__fastcall TYour_history::TYour_history(TComponent* Owner) :
    TForm(Owner), board(3, std::vector<char>(3, '_'))
{
    if (sqlite3_open("C:\\New folder\\login.db", &db)) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    }

    const char* createTablesSQL = "CREATE TABLE IF NOT EXISTS game4 ("
                                  "game_id INTEGER, "
                                  "user_id INTEGER, "
                                  "move_number INTEGER, "
                                  "row INTEGER, "
                                  "col INTEGER, "
                                  "player TEXT);"
                                  "CREATE TABLE IF NOT EXISTS game_data ("
                                  "game_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                  "player1_id INTEGER, "
                                  "player2_id INTEGER, "
                                  "winner_id INTEGER, "
                                  "game_score TEXT);";
    char* errMsg = 0;
    if (sqlite3_exec(db, createTablesSQL, 0, 0, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void TYour_history::replayGame(sqlite3* db, int gameID)
{
    std::string sql =
        "SELECT move_number, row, col, player FROM game4 WHERE game_id = ? ORDER BY move_number;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, gameID);

        board = std::vector<std::vector<char> >(3, std::vector<char>(3, '_'));
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int moveNumber = sqlite3_column_int(stmt, 0);
            int row = sqlite3_column_int(stmt, 1);
            int col = sqlite3_column_int(stmt, 2);
            char player =
                reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3))[0];

            board[row][col] = player;

            TButton* button = dynamic_cast<TButton*>(
                FindComponent("Button" + IntToStr(row * 3 + col + 1)));
            if (button) {
                button->Caption = player;
            }

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        sqlite3_finalize(stmt);
    } else {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db)
                  << std::endl;
    }
}

void TYour_history::displayScores(sqlite3* db)
{
    std::string sql =
        "SELECT game_id, player1_id, player2_id, winner_id, game_score FROM game_data;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        std::cout
            << "Game ID | Player 1 ID | Player 2 ID | Winner ID | Game Score"
            << std::endl;
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int gameID = sqlite3_column_int(stmt, 0);
            int player1ID = sqlite3_column_int(stmt, 1);
            int player2ID = sqlite3_column_int(stmt, 2);
            int winnerID = sqlite3_column_int(stmt, 3);
            const char* gameScore =
                reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

            std::cout << gameID << " | " << player1ID << " | " << player2ID
                      << " | " << winnerID << " | " << gameScore << std::endl;
        }
        sqlite3_finalize(stmt);
    } else {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db)
                  << std::endl;
    }
}

void __fastcall TYour_history::Button12Click(TObject* Sender)
{
    Application->Terminate();
    ;
}
void __fastcall TYour_history::Button11Click(TObject* Sender)
{
    int gameID = StrToInt(Edit1->Text);
    replayGame(db, gameID);
}
void __fastcall TYour_history::Button10Click(TObject* Sender)
{
    TMenuform* Menuform = new TMenuform(this);
    Menuform->Show();
    this->Hide();
}
//---------------------------------------------------------------------------

