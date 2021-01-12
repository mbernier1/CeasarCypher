#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

void encryption();
void decryption();


int main()
{
    int  menu = 2;
    cout << "Caesar Cipher" << endl;
    cout << "Would you like to encrypt or decrypt a file?" << endl;
    cout << "Please enter 1 for encrypt.\nPlease enter 2 for decrypt." << endl;
    cin >> menu;

        switch (menu) {
        case 1:
            encryption();
            break;

        case 2:
            decryption();
            break;

        default:
            cout << "Invalid Choice" << endl;
            
    }
    

    return 0;

}

//void encryption() {
//    int key = 7;
//    string filename = "default.txt";
//    char ch;
//    
//    cout << "What is the key you would like to use?" << endl;
//    //cout << "If key is not chosen, 7 will default." << endl;
//    cin >> key;
//    
//    cout << "Please enter what the name of your .TXT file you would like to encrypt." << endl;
//    //cout << "If file is not entered, default file will be used." << endl;
//    cin >> filename;
//
//    //Add line for opening file you want
//    ifstream fin;
//    fin.open(filename);
//    if (fin.is_open()) {
//        ifstream fin("filename", ifstream::in);
//        while (fin >> ch) {
//            cout << ch;
//            //convert to ascii
//            //cypher math (Plaintext + key) MOD 26
//            //convert ascii back to plaintext
//            //convert to UPPER
//            //new char value to save to new file default_encrypted.txt
//
//        }
//        fin.close();
//    }
//    else
//        cout << "Error file didn't open" << endl;
//    
//
//
//}

void encryption() {
    int key;
    char ch;
    string filename;
    string result = "";

    //1. Read in Key.
    cout << "Please enter the key you would like to used for encryption. (0-25)" << endl;
    cin >> key;
    
    //2. Read in "USERS" name for text file.
    cout << "Please enter the name of the text file you would like to be encrypted. (example: file.txt)" << endl;
    cin >> filename;

    //3. Encrypt text from file.
    ifstream fin;
    fin.open(filename);
    if (fin.is_open()) {
        ifstream fin(filename);
        while (fin >> ch) {
            //cout << ch;
            result = int((ch + key)-32);
            //cout << result;


        }
        fin.close();
        cout << result;
    }
    else
        cout << "Error file didn't open." << endl;

    //4. Save to new file using previously given name of file with _encrypted added.

}


void decryption() {
    string key;

}



//for i = 0 to msg[i] != '\0'
//ch = msg[i]
//encrypt for lowercase letter
//if(ch >= 'a' and ch <= 'z')
//ch = ch + key
//if (ch > 'z')
//ch = ch - 'z' + 'a' - 1
//done
//msg[i] = ch
//encrypt for uppercase letter
//else if (ch >= 'a' and ch <= 'z')
//ch = ch + key
//if (ch > 'z')
//ch = ch - 'z' + 'a' - 1
//done
//msg[i] = ch
//done
//done
//print encrypted message

//for i = 0 to msg[i] != '\0'
//ch = msg[i]
////decrypt for lowercase letter
//if (ch >= 'a' and ch <= 'z')
//ch = ch - key
//if (ch < 'a')
//    ch = ch + 'z' - 'a' + 1
//    done
//    msg[i] = ch
//    //decrypt for uppercase letter
//else if (ch >= 'a' and ch <= 'z')
//ch = ch + key
//if (ch < 'a')
//    ch = ch + 'z' - 'a' + 1
//    done
//    msg[i] = ch
//    done
//    done
//    print decrypted message