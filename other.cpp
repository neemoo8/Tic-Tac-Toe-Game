//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "other.h"
#include <sqlite3.h>

#include <iostream>
#include <string>
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;


using namespace std;

string generateSalt();
string encrypt(const string &str, const string &salt);
string decrypt(const string &str, const string &salt);

string generateSalt() {
	const int SALT_LENGTH = 8;
	string salt;
    srand(time(0));
    for (int i = 0; i < SALT_LENGTH; ++i) {
        char c = 'A' + rand() % 26;
        salt += c;
    }
	return salt;
}

string encrypt(const string &str, const string &salt) {
	string encrypted = salt;
    for (size_t i = 0; i < str.length(); ++i) {
        encrypted += str[i] + salt[i % salt.length()];
	}
	return encrypted;
}

//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


