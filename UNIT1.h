//---------------------------------------------------------------------------

#ifndef UNIT1H
#define UNIT1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Imaging.jpeg.hpp>

//---------------------------------------------------------------------------
class TUNIT : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;

	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
string generateSalt();
string encrypt(const string &str, const string &salt);
string decrypt(const string &str, const string &salt);
void executeSQL(sqlite3 *db, const string &sql);
public:		// User declarations
	__fastcall TUNIT(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TUNIT *UNIT;
//---------------------------------------------------------------------------
#endif
