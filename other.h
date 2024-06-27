//---------------------------------------------------------------------------

#ifndef otherH
#define otherH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <string>


bool login(const std::string &username, const std::string &password);
bool signup(const std::string &username, const std::string &password);
std::string retrievePassword(const std::string &username)
//---------------------------------------------------------------------------

