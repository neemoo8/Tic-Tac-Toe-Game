//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "WhoPF.h"
#include "Singleplayer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWPF *WPF;
//---------------------------------------------------------------------------
__fastcall TWPF::TWPF(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWPF::Button1Click(TObject *Sender)
{
Tsingle_player *single_player = new Tsingle_player(this);
	 single_player->Show();
		this->Hide(); // أخفي نموذج تسجيل الدخول
}
//---------------------------------------------------------------------------
void __fastcall TWPF::Button2Click(TObject *Sender)
{
Tsingle_player *single_player = new Tsingle_player(this);
	 single_player->Show();
		this->Hide(); // أخفي نموذج تسجيل الدخول
}
//---------------------------------------------------------------------------
void __fastcall TWPF::Button3Click(TObject *Sender)
{
Tsingle_player *single_player = new Tsingle_player(this);
	 single_player->Show();
		this->Hide(); // أخفي نموذج تسجيل الدخول

}
//---------------------------------------------------------------------------
void __fastcall TWPF::Button4Click(TObject *Sender)
{
Tsingle_player *single_player = new Tsingle_player(this);
	 single_player->Show();
		this->Hide(); // أخفي نموذج تسجيل الدخول

}
//---------------------------------------------------------------------------
