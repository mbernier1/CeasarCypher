#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

#include <stdio.h>
#include <iomanip>

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::rename;


void Encryption();
void Decryption();


int main()
{
    int  menu = 2;
    cout << "Caesar Cipher" << endl;
    cout << "Would you like to encrypt or decrypt a file?" << endl;
    cout << "Please enter 1 for encrypt. (This will CLEAR any previously encrypted text.)\nPlease enter 2 for decrypt." << endl;
    cin >> menu;

    switch (menu)
	{
        case 1:
            Encryption();
            break;

        case 2:
            Decryption();
            break;

        default:
            cout << "Invalid Choice" << endl;
            
    }
    
    return 0;
}
void encryption() {
     

}



void Encryption()
{
    int key;
    char ch;
    char filename[100] = "";
    char newfilename[20] = "encrypted_text.txt";
    char result;

    ofstream outfile;
    outfile.open(newfilename, ofstream::out | ofstream::trunc);
    outfile.close();

    //1. Read in Key.
    cout << "Please enter the key you would like to use for encryption. (0-25)" << endl;
    cin >> key;

	// this if statement is in case the user decides to use a number bigger than 25
	if (key >= 26)
	{
		// modus by 26 cause that the max letters in alphabet
		// this will keep the key in the 0-25 range
        key %= 26;

	}
    
    //2. Read in "USERS" name for text file.                                      //take out this stuff in ( ) when strcat works
    cout << "Please enter the name of the text file you would like to be encrypted. (example: file.txt)" << endl;
    cin >> filename;


    //3. Encrypt text from file.
    ifstream fin;
    fin.open(filename);
    if (fin.is_open()) 
    {
        ifstream fin(filename);
        ofstream outfile;
        outfile.open(newfilename, std::ios_base::app);
        while (fin >> ch) 
        { 
            if (ch >= 97 && ch <= 122) {
                result = int((ch + key - 97) % 26 + 97);
                if (outfile.is_open())
                {
                    result = toupper(result);
                    outfile << result;
                }
                else
                {
                    cout << "Output file Error." << endl;
                }
            }
            if (ch >= 65 && ch <= 90) {
                result = int((ch + key - 65) % 26 + 65);
                if (outfile.is_open())
                {
                    outfile << result;
                }
                else
                {
                    cout << "Output file Error." << endl;
                }
            }

        }
        outfile.close();
        fin.close();
    }
    else
    {
        cout << "Error file didn't open." << endl;
    }
    //4. Save to new file.
    
}


void Decryption()
{
    int key;
    char ch;
    char filename[100] = "";
    char newfilename[20] = "decrypted_text.txt";
    char result;

    ofstream outfile;
    outfile.open(newfilename, ofstream::out | ofstream::trunc);
    outfile.close();

    //1. Read in Key.
    cout << "Please enter the key you would like to use for decryption. (0-25)" << endl;
    cin >> key;

    // this if statement is in case the user decides to use a number bigger than 25
    if (key >= 26)
    {
        // modus by 26 cause that the max letters in alphabet
        // this will keep the key in the 0-25 range
        key %= 26;

    }

    //2. Read in "USERS" name for text file.                                      
    cout << "Please enter the name of the text file you would like to decrypt. (example: file.txt)" << endl;
    cin >> filename;

    //3. Encrypt text from file.
    ifstream fin;
    fin.open(filename);
    if (fin.is_open())
    {
        ifstream fin(filename);
        ofstream outfile;
        outfile.open(newfilename, std::ios_base::app);
        while (fin >> ch)
        {
            if (ch >= 65 && ch <= 90) {

                result = int((ch - key + 65) % 26 + 65);

                if (outfile.is_open())
                {
                    result = tolower(result);
                    outfile << result;
                }
                else
                {
                    cout << "Output file Error." << endl;
                }
            }

        }
        outfile.close();
        fin.close();
    }
    else
    {
        cout << "Error file didn't open." << endl;
    }
}
