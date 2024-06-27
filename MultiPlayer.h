//---------------------------------------------------------------------------

#ifndef MultiPlayerH
#define MultiPlayerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include "Global.h"
				#include <iostream>
#include <vector>
#include <sstream>
#include <climits>
#include <string>
#include <sqlite3.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include <string>
#include <functional>



extern const int AI_ID ;
const int USER1_ID = 2; // Example: ID for first human player
const int USER2_ID = 3; // Example: ID for second human player

using namespace std;
		extern std::string globalUsername;
		extern  int GAME_ID ;
		 extern const int USER_ID  ;
//---------------------------------------------------------------------------
class TMulti_player : public TForm
{
__published:	// IDE-managed Components
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
	TLabel *Label1;
	TButton *Button12;
	void __fastcall Button10Click(TObject *Sender);
void __fastcall ButtonClick(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);


private:	// User declarations
	void __fastcall CheckWin();// Function to check win
void saveMoveToDatabase(sqlite3* db, int gameID, int userID, int moveNumber, int row, int col, char player) ;
   void	saveGameScoreToDatabase(sqlite3* db, int gameID, int player1ID, int player2ID, int winnerID, const string& gameScore) ;
	void __fastcall ResetBoard();  // Function to reset board


public:		// User declarations
	__fastcall TMulti_player(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMulti_player *Multi_player;
//---------------------------------------------------------------------------
#endif

