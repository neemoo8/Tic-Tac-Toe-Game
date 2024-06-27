//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Menufrm.h"
#include "SinglePlayer.h"
#include "Multiplayer.h"
#include "History.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMenuform* Menuform;
//---------------------------------------------------------------------------
__fastcall TMenuform::TMenuform(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TMenuform::Button1Click(TObject* Sender)
{
    Tsingle_player* single_player = new Tsingle_player(this);
    single_player->Show();
    this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TMenuform::Button2Click(TObject* Sender)
{
    TMulti_player* Multi_player = new TMulti_player(this);
    Multi_player->Show();
    this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TMenuform::Button4Click(TObject* Sender)
{
    TYour_history* Your_history = new TYour_history(this);
    Your_history->Show();
    this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TMenuform::Button3Click(TObject* Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

