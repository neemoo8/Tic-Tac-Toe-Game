#include <vcl.h>
#pragma hdrstop
#include "Signup.h"
#include "Menufrm.h"
#include <sqlite3.h>
#include <string>

#pragma package(smart_init)
#pragma resource "*.dfm"
TSIGN_UP* SIGN_UP;

const int AI_ID = 1; // Definition of AI_ID

__fastcall TSIGN_UP::TSIGN_UP(TComponent* Owner) : TForm(Owner)
{
    sqlite3* db;
    int rc = sqlite3_open("C:\\New folder\\login.db", &db);

    if (rc) {
        ShowMessage("Can't open database: " + String(sqlite3_errmsg(db)));
    }

    std::string createTableSQL = "CREATE TABLE IF NOT EXISTS login ("
                                 "username TEXT PRIMARY KEY NOT NULL, "
                                 "salt TEXT NOT NULL, "
                                 "password TEXT NOT NULL);";
    executeSQL(db, createTableSQL);
    sqlite3_close(db);
}

std::string TSIGN_UP::generateSalt()
{
    const int SALT_LENGTH = 8;
    std::string salt;
    srand(time(0));
    for (int i = 0; i < SALT_LENGTH; ++i) {
        char c = 'A' + rand() % 26;
        salt += c;
    }
    return salt;
}

std::string TSIGN_UP::encrypt(const std::string &str, const std::string &salt)
{
    std::string encrypted = salt;
    for (size_t i = 0; i < str.length(); ++i) {
        encrypted += str[i] + salt[i % salt.length()];
    }
    return encrypted;
}

void TSIGN_UP::executeSQL(sqlite3* db, const std::string &sql)
{
    char* errMsg = 0;
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        ShowMessage("SQL error: " + String(errMsg));
        sqlite3_free(errMsg);
    }
}

void __fastcall TSIGN_UP::loginClick(TObject* Sender)
{
    String username = user_edit->Text;
    String password = pass_edit->Text;
    std::string username_str = AnsiString(username).c_str();
    globalUsername = AnsiString(username).c_str();
    sqlite3* db;
    int rc = sqlite3_open("C:\\New folder\\login.db", &db);

    if (rc) {
        ShowMessage("Can't open database: " + String(sqlite3_errmsg(db)));
        return;
    }

    std::string sql =
        "SELECT username FROM login WHERE username = '" + username_str + "';";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        ShowMessage("Failed to fetch data: " + String(sqlite3_errmsg(db)));
        sqlite3_close(db);
        return;
    }

    bool usernameTaken = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        usernameTaken = true;
    }
    sqlite3_finalize(stmt);

    if (usernameTaken) {
        ShowMessage("ERROR: Username is already taken");
        sqlite3_close(db);
        return;
    }

    std::string salt = generateSalt();
    std::string encryptedPass = encrypt(AnsiString(password).c_str(), salt);

    sql = "INSERT INTO login (username, salt, password) VALUES ('" +
          username_str + "', '" + salt + "', '" + encryptedPass + "');";
    executeSQL(db, sql);

    sqlite3_close(db);
    const int AI_ID = 1;
    TMenuform* Menuform = new TMenuform(this);
    Menuform->Show();
    this->Hide();
}

