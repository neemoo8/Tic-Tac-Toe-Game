//---------------------------------------------------------------------------

#ifndef Forgot_passwordH
#define Forgot_passwordH
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
using namespace std;

//---------------------------------------------------------------------------
class TForgotpass : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *user_edit;
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
	   string decrypt(const string &str, const string &salt);
	   void executeSQL(sqlite3 *db, const string &sql);
public:		// User declarations
	__fastcall TForgotpass(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForgotpass *Forgotpass;
//---------------------------------------------------------------------------
#endif
