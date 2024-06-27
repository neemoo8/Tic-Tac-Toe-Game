/---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("SinglePlayer.cpp", single_player);
USEFORM("UNIT1.CPP", UNIT);
USEFORM("Unit2.cpp", Form2);
USEFORM("WhoPF.cpp", WPF);
USEFORM("History.cpp", Your_history);
USEFORM("Loginfrm.cpp", LoginForm);
USEFORM("Menufrm.cpp", Menuform);
USEFORM("MultiPlayer.cpp", Multi_player);
//---------------------------------------------------------------------------
, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__clasApplication->CreateForm(__classid(TUNIT), &UNIT);
		Application->CreateForm(__classid(TMenuform), &Menuform);
		Application->CreateForm(__classid(Tsingle_player), &single_player);
		Application->CreateForm(__classid(TYour_history), &Your_history);
		Application->CreateForm(__classid(TMulti_player), &Multi_player);
		Application->CreateForm(__classid(TWPF), &WPF);
		Application->CreateForm(__classid(TLoginForm), &LoginForm);
		Application->CreateForm(__classid(TForm2), &Form2);
		ion(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
