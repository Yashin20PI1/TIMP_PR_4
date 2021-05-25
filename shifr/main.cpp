#include "rc5.h"
#include "des.h"
int main ()
{    bool isTrue = true;
    string rejim;
    string in, out,IV,parol;
    cout << "Здравствуйте, пора что-нибудь зашифровать/расшифровать!" << endl;
    cout << "enDES - шифрование алгоритмом DES "<< endl;
    cout << "decDES - расшифрование алгоритмом DES "<< endl;
    cout << "enrc5 - шифрование алгоритмом RC5" << endl;
    cout << "decrc5 - расшифрование алгоритмом RC5"<< endl;
    cout << "exit - завершение программы"<< endl;
    do {cout << "Выбирете режим работы: ";cin >> rejim;
        if (rejim == "enDES") {
            cout << "Расположение файла: ";cin >> in;
            cout << "Расположение файла с результатом: ";cin >> out;
            cout << "Ваш пароль: ";cin >> parol;
            try {
                DES_CLASS enc(in,out,parol);
                enc.enDES(enc);
            }  catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl;
            }
        }
         if (rejim == "decDES") {
            cout << "Расположение файла: ";cin >> in;
            cout << "Расположение файла с результатом: ";cin >> out;
            cout << "Расположение файла с вектором инициализации: ";cin >> IV;
            cout << "Ваш пароль: ";cin >> parol;
            try {
                DES_CLASS dec(in,out,parol,IV);
                dec.decDES(dec);
            }  catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl;
            }
        }
        if (rejim == "enrc5") {
            cout << "Расположение файла: ";cin >> in;
            cout << "Расположение файла с результатом: ";cin >> out;
            cout << "Ваш пароль: ";cin >> parol;
            try {
                RC5_CLASS enc(in,out,parol);
                enc.enrc5(enc);
            }  catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl;
            }
        }
       
        if (rejim == "decrc5") {
            cout << "Расположение файла: ";cin >> in;
            cout << "Расположение файла с результатом: ";cin >> out;
            cout << "Расположение файла с вектором инициализации: ";cin >> IV;
            cout << "Ваш пароль: ";cin >> parol;
            try {
                RC5_CLASS dec(in,out, parol, IV );
                dec.decrc5(dec);
            } catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl;
            }
        }
        if (rejim == "exit") {
            cout << "Завершение работы программы." << endl;
            isTrue = false;
            break;
        }
    } while (isTrue != false);

    return 0;
}
