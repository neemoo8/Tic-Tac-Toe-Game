#ifndef SinglePlayerH
#define SinglePlayerH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <vector>
#include <iostream>
#include <climits>
#include "Global.h"
#include <sstream>
#include <string>
#include <sqlite3.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include <string>
#include <functional>


		 extern const int AI_ID ;  // Example: ID for AI player
using namespace std;
		extern std::string globalUsername;
		extern  int GAME_ID ;
		 extern const int USER_ID  ;
		  extern const int BOARD_SIZE ;
using namespace std;


struct TreeNode {
	std::vector<std::vector<char>> board;
	std::vector<TreeNode*> children;
	int value;
	bool isMaximizingPlayer;

	TreeNode(std::vector<std::vector<char>> b, bool player) : board(b), value(0), isMaximizingPlayer(player) {}
};

class Tsingle_player : public TForm {
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
	TLabel *LabelStatus;
	TButton *historyButton;

	void __fastcall ButtonClick(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall historyButtonClick(TObject *Sender);


private:
	struct Move {
		int row;
		int col;
	};

	std::vector<std::vector<char>> board;

	int evaluateBoard(const std::vector<std::vector<char>>& board);
	bool isGameOver(const std::vector<std::vector<char>>& board);
	TreeNode* buildTree(TreeNode* node, int depth);
	int minimax(TreeNode* node, int alpha, int beta);
	Move findBestMove(std::vector<std::vector<char>>& board);
	void printBoard(const std::vector<std::vector<char>>& board);
	bool isMoveValid(const std::vector<std::vector<char>>& board, int row, int col);
	void ResetBoard();
	void CheckWin();

			 void	saveGameScoreToDatabase(sqlite3* db, int gameID, int player1ID, int player2ID, int winnerID, const string& gameScore)  ;
void saveMoveToDatabase(sqlite3* db, int gameID, int userID, int moveNumber, int row, int col, char player) ;

public:
	__fastcall Tsingle_player(TComponent* Owner);
};

extern PACKAGE Tsingle_player *single_player;

#endif // SinglePlayerH

