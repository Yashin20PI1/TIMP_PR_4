#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main ()
{
    CryptoPP::SHA1 hash; 
    cout <<"Name: " << hash.AlgorithmName() << endl; 
    cout << "Diget size:" << hash.DigestSize() << endl; 
    cout << "Block size:" << hash.BlockSize() << endl; 
    fstream file;
    string path = "/home/student/text.txt";
    string str_message, file_contents;
    file.open(path);
    while(true) {
        getline(file,str_message);
        if (file.fail()) 
            break;
        file_contents += str_message;
    }
    cout << "content: " << file_contents << endl;
    vector<byte> digest (hash.DigestSize());
    hash.Update((const byte*)(file_contents.data()),file_contents.size()); 
    hash.Final(digest.data());
    cout << "Digest: ";
    CryptoPP::StringSource(digest.data(),digest.size(),true, new  CryptoPP::HexEncoder(new  CryptoPP::FileSink(cout))); // выводим хэш в формате "hex"
    cout << endl;
    return 0;
}
