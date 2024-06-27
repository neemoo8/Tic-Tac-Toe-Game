//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "LoginFrm.h"
#include "UNIT1.h"
#include "Forgot_password.h"
#include "Signup.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TUNIT* UNIT;
//---------------------------------------------------------------------------
__fastcall TUNIT::TUNIT(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------

void __fastcall TUNIT::Button1Click(TObject* Sender)
{
	TLoginForm* LoginForm = new TLoginForm(this);
    LoginForm->Show();
    this->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TUNIT::Button2Click(TObject* Sender)
{
    TSIGN_UP* SIGN_UP = new TSIGN_UP(this);
    SIGN_UP->Show();
    this->Hide();
}

//---------------------------------------------------------------------------

void __fastcall TUNIT::Button3Click(TObject* Sender)
{
    TForgotpass* Forgotpass = new TForgotpass(this);
    Forgotpass->Show();
    this->Hide();
}
//---------------------------------------------------------------------------

