//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Global.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2* Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
int GAME_ID = 1;
std::string globalUsername = "";
const int USER_ID = std::hash<std::string> {}(globalUsername);
const int BOARD_SIZE = 3;

