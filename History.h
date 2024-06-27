#ifndef HistoryH
#define HistoryH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include "Global.h"
#include <vector>
#include <sstream>
#include <climits>
#include <string>
#include <sqlite3.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include <iostream>

extern std::string globalUsername;
extern int GAME_ID;
extern const int USER_ID;

class TYour_history : public TForm
{
__published:
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TLabel *Label2;
	TEdit *Edit1;

	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);


private:
	void replayGame(sqlite3* db, int gameID);
	void displayScores(sqlite3* db);
	std::vector<std::vector<char>> board;

public:
	__fastcall TYour_history(TComponent* Owner);
};

extern PACKAGE TYour_history *Your_history;

#endif

