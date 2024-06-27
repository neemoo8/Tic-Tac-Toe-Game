//---------------------------------------------------------------------------

#ifndef LoginfrmH
#define LoginfrmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <sqlite3.h>
#include "Global.h"
		extern std::string globalUsername;
using namespace std;
sqlite3 *db;

//---------------------------------------------------------------------------
class TLoginForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *USERNAME;
	TLabel *PASSWORD;
	TEdit *user_edit;
	TEdit *pass_edit;
	TButton *login;
	void __fastcall loginClick(TObject *Sender);

private: // User declarations
	string encrypt(const string &str, const string &salt);
	void executeSQL(sqlite3 *db, const string &sql);

public: // User declarations
	__fastcall TLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLoginForm *LoginForm;
//---------------------------------------------------------------------------
#endif

