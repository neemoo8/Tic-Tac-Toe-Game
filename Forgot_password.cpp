#include <vcl.h>
#pragma hdrstop

#include "Forgot_password.h"
#include "Loginfrm.h"
#include "UNIT1.h"
#include <sqlite3.h>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForgotpass* Forgotpass;
//---------------------------------------------------------------------------
__fastcall TForgotpass::TForgotpass(TComponent* Owner) : TForm(Owner)
{
    sqlite3* db;
    int rc = sqlite3_open("C:\\New folder\\login.db", &db);

    if (rc) {
        ShowMessage("Can't open database: " + String(sqlite3_errmsg(db)));
    } /*else {
		ShowMessage("Opened database successfully");
	}*/

    std::string createTableSQL = "CREATE TABLE IF NOT EXISTS login ("
                                 "username TEXT PRIMARY KEY NOT NULL, "
                                 "salt TEXT NOT NULL, "
                                 "password TEXT NOT NULL);";
    executeSQL(db, createTableSQL);
    sqlite3_close(db);
}

std::string TForgotpass::decrypt(
    const std::string &str, const std::string &salt)
{
    std::string decrypted;
    for (size_t i = salt.length(); i < str.length(); ++i) {
        decrypted += str[i] - salt[(i - salt.length()) % salt.length()];
    }
    return decrypted;
}

void TForgotpass::executeSQL(sqlite3* db, const std::string &sql)
{
    char* errMsg = 0;
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        ShowMessage("SQL error: " + String(errMsg));
        sqlite3_free(errMsg);
    }
}

//---------------------------------------------------------------------------
void __fastcall TForgotpass::Button1Click(TObject* Sender)
{
    String username = user_edit->Text;
    sqlite3* db;
    int rc = sqlite3_open("C:\\New folder\\login.db", &db);
    if (rc) {
        ShowMessage("Can't open database: " + String(sqlite3_errmsg(db)));
        return;
    }

    std::string username_str = AnsiString(username).c_str();
    std::string dbSalt, dbPassword;

    std::string sql = "SELECT salt, password FROM login WHERE username = '" +
                      username_str + "';";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        ShowMessage("Failed to fetch data: " + String(sqlite3_errmsg(db)));
        sqlite3_close(db);
        return;
    }

    int count = 0;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        dbSalt = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        dbPassword =
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        count = 1;
    }
    sqlite3_finalize(stmt);

    if (count == 1) {
        std::string decryptedPass = decrypt(dbPassword, dbSalt);
        ShowMessage("Hurray, account found\nYour password is " +
                    String(decryptedPass.c_str()));
        TLoginForm* LoginForm = new TLoginForm(this);
        LoginForm->Show();
        this->Hide();
        sqlite3_close(db);
    } else {
        ShowMessage("Your username was not found");
	}
}

void __fastcall TForgotpass::Button2Click(TObject* Sender)
{
    TUNIT* UNIT = new TUNIT(this);
    UNIT->Show();
    this->Hide();
}
//---------------------------------------------------------------------------

