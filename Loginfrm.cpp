#include <vcl.h>
#pragma hdrstop
#include "Menufrm.h"
#include "Loginfrm.h"
#include "Global.h"
#include <sqlite3.h>
#include <string>

#pragma package(smart_init)
#pragma resource "*.dfm"
TLoginForm* LoginForm;

__fastcall TLoginForm::TLoginForm(TComponent* Owner) : TForm(Owner) {}

std::string TLoginForm::encrypt(const std::string &str, const std::string &salt)
{
    std::string encrypted = salt;
    for (size_t i = 0; i < str.length(); ++i) {
        encrypted += str[i] + salt[i % salt.length()];
    }
    return encrypted;
}

void executeSQL(sqlite3* db, const std::string &sql)
{
    char* errMsg = 0;
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void __fastcall TLoginForm::loginClick(TObject* Sender)
{
    String username = user_edit->Text;
    std::string username_str = AnsiString(username).c_str();
    globalUsername = AnsiString(username).c_str(); // تحديث قيمة globalUsername
    String password = pass_edit->Text;

    sqlite3* db;
    int rc = sqlite3_open("C:\\New folder\\login.db", &db);

    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        ShowMessage("Database opening error: " + String(sqlite3_errmsg(db)));
        return;
    }

    std::string sql = "SELECT salt, password FROM login WHERE username = '" +
                      username_str + "';";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        cerr << "Failed to fetch data: " << sqlite3_errmsg(db) << std::endl;
        ShowMessage(
            "Failed to prepare SQL statement: " + String(sqlite3_errmsg(db)));
        sqlite3_close(db);
        return;
    }

    std::string dbSalt, dbPassword;
    int count = 0;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        dbSalt = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        dbPassword =
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));

        if (dbPassword == encrypt(AnsiString(password).c_str(), dbSalt)) {
            count = 1;
        }
    } else {
        ShowMessage("No matching user found");
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    if (count == 1) {
        TMenuform* Menuform = new TMenuform(this);
        Menuform->Show();
        this->Hide();
    } else {
        ShowMessage("WRONG PASSWORD OR USERNAME PLEASE TRY AGAIN");
    }
}

