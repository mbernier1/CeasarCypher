#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
using std::rename;




void encryption();
void decryption();


int main()
{
    int  menu = 2;
    cout << "Caesar Cipher" << endl;
    cout << "Would you like to encrypt or decrypt a file?" << endl;
    cout << "Please enter 1 for encrypt. (This will CLEAR any previously encrypted text.)\nPlease enter 2 for decrypt." << endl;
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

void encryption() {
    int key;
    char ch;
    string filename;
    string newfilename = "encrypted_text.txt";
    string result = "";

    ofstream outfile;
    outfile.open(newfilename, ofstream::out | ofstream::trunc);
    outfile.close();



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
            ofstream outfile;
            outfile.open(newfilename, std::ios_base::app);
            if (outfile.is_open()) {
                outfile << result;
            }
            else {
                cout << "Output file Error." << endl;
            }
            outfile.close();
        }
        fin.close();
        
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