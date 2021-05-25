#pragma once
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>
#include <cryptopp/rc5.h>
#include <cryptopp/base64.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/filters.h>
#include <cryptopp/osrng.h>
#include "cryptopp/modes.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using namespace CryptoPP;

class RC5_CLASS
{
private:
  string in;
  string out;
  string psw;
  string IV;
  string salt = "saltandsugarforourdearprepodfgfgfgfgfgfggf";
public:
  RC5_CLASS() = delete;
  RC5_CLASS(const string& in, const string& out, const string& Pass);
  RC5_CLASS(const string& in, const string& out, const string& Pass, const string & iv);
  void enrc5(RC5_CLASS enc);
  void decrc5 (RC5_CLASS dec);
};