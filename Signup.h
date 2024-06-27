#ifndef SignupH
#define SignupH
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
extern std::string globalUsername;
extern const int AI_ID;  // Declaration of AI_ID
//---------------------------------------------------------------------------
class TSIGN_UP : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TEdit *user_edit;
    TEdit *pass_edit;
    TButton *login;
    void __fastcall loginClick(TObject *Sender);
private:	// User declarations
    string generateSalt();
    string encrypt(const string &str, const string &salt);
    void executeSQL(sqlite3 *db, const string &sql);
public:		// User declarations
    __fastcall TSIGN_UP(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSIGN_UP *SIGN_UP;
//---------------------------------------------------------------------------
#endif

