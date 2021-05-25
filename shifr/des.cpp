#include "des.h"
DES_CLASS::DES_CLASS(const string& in, const string& out, const string& pass)
{   this->in = in;
    this->out = out;
    this->psw = pass;}
DES_CLASS::DES_CLASS(const string& in, const string& out, const string& pass, const string & iv)
{   this->in = in;
    this->out = out;
    this->psw = pass;
    this->IV = iv;}
void DES_CLASS::enDES (DES_CLASS enc)
{   SecByteBlock key(DES::DEFAULT_KEYLENGTH);
    PKCS12_PBKDF<SHA512> pbkdf;
    pbkdf.DeriveKey(key.data(), key.size(), 0, (byte*)enc.psw.data(), enc.psw.size(), (byte*)salt.data(), salt.size(), 1024, 0.0f);
    AutoSeededRandomPool prng;
    byte iv[DES::BLOCKSIZE];
    prng.GenerateBlock(iv, sizeof(iv));
    ofstream v_IV(string(enc.out + ".iv").c_str(), ios::out | ios::binary);
    v_IV.write((char*)iv, DES::BLOCKSIZE);
    v_IV.close();
    cout << "Был создан файл c вектором инициализации.\nРасположение следущее: " << enc.out << ".iv" << endl;
    CBC_Mode<DES>::Encryption encr;
    encr.SetKeyWithIV(key, key.size(), iv);
    FileSource fs(enc.in.c_str(), true, new StreamTransformationFilter(encr, new FileSink(enc.out.c_str())));
    cout << "Было проведено шифрование.\nРезультат в файле, его расположение следущее:\n" << enc.out << endl;}
void DES_CLASS::decDES (DES_CLASS dec)
{   SecByteBlock key(DES::DEFAULT_KEYLENGTH);
    PKCS12_PBKDF<SHA512> pbkdf;
    pbkdf.DeriveKey(key.data(), key.size(), 0, (byte*)dec.psw.data(), psw.size(), (byte*)salt.data(), salt.size(), 1024, 0.0f);
    byte iv[DES::BLOCKSIZE];
    ifstream v_IV(dec.IV.c_str(), ios::in | ios::binary);
    CBC_Mode<DES>::Decryption decr;
    decr.SetKeyWithIV(key, key.size(), iv);
    FileSource fs(dec.in.c_str(), true, new StreamTransformationFilter(decr, new FileSink(dec.out.c_str())));
    cout << "Было проведено расшифрование.\nРезультат в файле, его расположение следущее:\n" << dec.out << endl;}
