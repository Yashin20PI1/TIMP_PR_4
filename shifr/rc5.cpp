#include "rc5.h"
RC5_CLASS::RC5_CLASS(const string& in, const string& out, const string& parol)
{    this->in = in;
    this->out = out;
    this->psw = parol;}
RC5_CLASS::RC5_CLASS(const string& in, const string& out, const string& parol, const string & iv)
{   this->in = in;
    this->out = out;
    this->psw = parol;
    this->IV = iv;}
void RC5_CLASS::enrc5 (RC5_CLASS enc)
{    SecByteBlock key(RC5::DEFAULT_KEYLENGTH);
    PKCS12_PBKDF<SHA1> pbkdf;
    pbkdf.DeriveKey(key.data(), key.size(), 0, (byte*)enc.psw.data(), enc.psw.size(), (byte*)salt.data(), salt.size(), 1024, 0.0f);
    byte iv[RC5::BLOCKSIZE];
    ofstream v_IV(string(enc.out + ".iv").c_str(), ios::out | ios::binary);
    v_IV.write((char*)iv, RC5::BLOCKSIZE);
    v_IV.close();
    cout << "Был создан файл c вектором инициализации.\nРасположение следущее: " << enc.out << ".iv" << endl;
    CBC_Mode<RC5>::Encryption encr;
    encr.SetKeyWithIV(key, key.size(), iv);
    FileSource fs(enc.in.c_str(), true, new StreamTransformationFilter(encr, new FileSink(enc.out.c_str())));
    cout << "Было проведено шифрование.\nРезультат в файле, его расположение следущее:\n" << enc.out << endl;}
void RC5_CLASS::decrc5 (RC5_CLASS dec)
{    SecByteBlock key(RC5::DEFAULT_KEYLENGTH);
    PKCS12_PBKDF<SHA1> pbkdf;
    pbkdf.DeriveKey(key.data(), key.size(), 0, (byte*)dec.psw.data(), psw.size(), (byte*)salt.data(), salt.size(), 1024, 0.0f);
    byte iv[RC5::BLOCKSIZE];
   ifstream v_IV(dec.IV.c_str(), ios::in | ios::binary);
   v_IV.read((char*)(&iv), RC5::BLOCKSIZE);
    CBC_Mode<RC5>::Decryption decr;
    decr.SetKeyWithIV(key, key.size(), iv);
    FileSource fs(dec.in.c_str(), true, new StreamTransformationFilter(decr, new FileSink(dec.out.c_str())));
    cout << "Было проведено расшифрование.\nРезультат в файле, его расположение следущее:\n" << dec.out << endl;}
