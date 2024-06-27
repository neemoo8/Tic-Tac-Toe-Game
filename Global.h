//---------------------------------------------------------------------------

#ifndef GlobalH
#define GlobalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <string>

extern std::string globalUsername;
extern int GAME_ID ;
   extern const int USER_ID  ;
  extern const int BOARD_SIZE ;
  extern const int AI_ID ;
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
