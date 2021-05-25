#pragma once
#include <cryptopp/cryptlib.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>
#include <cryptopp/des.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/filters.h>
#include <cryptopp/osrng.h>
#include "cryptopp/modes.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using namespace CryptoPP;

class DES_CLASS
{
private:
  string in;
  string out;
  string IV;
  string psw;
  string salt = "saltandsugarforourdearprepodfgfgfgfgfgfggf";
public:
  DES_CLASS() = delete;
  DES_CLASS(const string& in, const string& out, const string& pass);
  DES_CLASS(const string& in, const string& out, const string& pass, const string & iv);
  void enDES (DES_CLASS enc);
  void decDES (DES_CLASS dec);
};