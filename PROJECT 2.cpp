// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
// ---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("MultiPlayer.cpp", Multi_player);
USEFORM("Menufrm.cpp", Menuform);
USEFORM("UNIT1.CPP", UNIT);
USEFORM("SinglePlayer.cpp", single_player);
USEFORM("Signup.cpp", SIGN_UP);
USEFORM("Forgot_password.cpp", Forgotpass);
USEFORM("Loginfrm.cpp", LoginForm);
USEFORM("History.cpp", Your_history);
USEFORM("Global.cpp", Form2);

// ---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int) {
	try {
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "TIC TAC TOE";
		Application->CreateForm(__classid(TUNIT), &UNIT);
		Application->CreateForm(__classid(TLoginForm), &LoginForm);
		Application->CreateForm(__classid(TMenuform), &Menuform);
		Application->CreateForm(__classid(Tsingle_player), &single_player);
		Application->CreateForm(__classid(TMulti_player), &Multi_player);
		Application->CreateForm(__classid(TYour_history), &Your_history);
		Application->CreateForm(__classid(TSIGN_UP), &SIGN_UP);
		Application->CreateForm(__classid(TForgotpass), &Forgotpass);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->Run();
	}
	catch (Exception &exception) {
		Application->ShowException(&exception);
	}
	catch (...) {
		try {
			throw Exception("");
		}
		catch (Exception &exception) {
			Application->ShowException(&exception);
		}
	}
	return 0;
}
// ---------------------------------------------------------------------------
