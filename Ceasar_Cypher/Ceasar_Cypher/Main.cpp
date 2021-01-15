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
void DecryptNoKey();


int main()
{
    int  menu = 3;
    cout << "Caesar Cipher" << endl;
    cout << "Would you like to encrypt or decrypt a file?" << endl;
    cout << "Please enter 1 for encrypt. (This will CLEAR any previously encrypted text.)\n"
		 <<	"Please enter 2 for decrypt. (This will CLEAR any previously decrypted text.)\n"
		 << "Please enter 3 for decrypt without a key. (This will CLEAR any previously decrypted text.)" << endl;
	
    cin >> menu;

    switch (menu)
	{
        case 1:
            Encryption();
            break;

        case 2:
            Decryption();
            break;
    	
        case 3:
            DecryptNoKey();
            break;

        default:
            cout << "Invalid Choice" << endl;
    }
    
    return 0;
}

void Encryption()
{
    int key = 0;
    char ch;
    char filename[100] = "";
    char newFilename[20] = "encrypted_text.txt";
    char result;

    ofstream outfile;
    outfile.open(newFilename, ofstream::out | ofstream::trunc);
    outfile.close();

    //1. Read in Key.
    cout << "Please enter the key you would like to use for encryption. (0-25)" << endl;

	// this if statement is in case the user decides to use a number bigger than 25
	if (key >= 26)
	{
        cout << "That was an incorrect value. Please try again.";
        cout << "Please enter the key you would like to use for encryption. (0-25)" << endl;
	}
	
    cin >> key;

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
        outfile.open(newFilename, std::ios_base::app);
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
    int key = 0;
    char ch;
    char filename[100] = "";
    char newFilename[20] = "decrypted_text.txt";
    char result;

    ofstream outfile;
    outfile.open(newFilename, ofstream::out | ofstream::trunc);
    outfile.close();

    //1. Read in Key.
    cout << "Please enter the key you would like to use for decryption. (0-25)" << endl;

    // this if statement is in case the user decides to use a number bigger than 25
    if (key >= 26)
    {
        cout << "That was an incorrect value. Please try again.";
        cout << "Please enter the key you would like to use for decryption. (0-25)" << endl;
    }
	
    cin >> key;

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
        outfile.open(newFilename, std::ios_base::app);
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

void DecryptNoKey()
{
    int key, i = 0;
    char ch;
    char filename[100] = "";
    char newFilename[50] = "decrypted_no_key_text.txt";
    //char result;
    int keys[26] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
    //string encryptedText = "";
    char encryptedText[] = "\0";
    char * ch_ptr = nullptr;

    ofstream outfile;
    outfile.open(newFilename, ofstream::out | ofstream::trunc);
    outfile.close();

    //1. Read in "USERS" name for text file.                                      
    cout << "Please enter the name of the text file you would like to decrypt. (example: file.txt)" << endl;
    cin >> filename;

    int j = 0;
	
    //2. Encrypt text from file.
    while (i <= 25)
    {
        ifstream fin;
        fin.open(filename);
        if (fin.is_open())
        {
            ifstream fin(filename);
            ofstream outfile;
            outfile.open(newFilename, std::ios_base::app);
            // 1) select a key
            // 2) decrypt using chosen key
            // 3) check decrypted test in string for words: the is it and of
            // 4) if no words are found rinse and repeat
                //  else append to file

            while (fin >> ch)
            {
                encryptedText[j] += int((ch - keys[i] + 65) % 26 + 65);
                //cout << encryptedText << '\n';
                j++;
            }

            ch_ptr = strstr(encryptedText, ("the", "it", "is", "and", "of"));
        	
            if (ch_ptr != nullptr)
            {
                cout << "Those words are not in here." << endl;
            }
            else
            {
                cout << "Here are the words we found." << endl;
                cout << encryptedText[j];
            }
        	
            if (outfile.is_open())
            {
                //encryptedText = tolower(encryptedText);

                outfile << encryptedText;
            }
            else
            {
                cout << "Output file Error." << endl;
            }
        	
            outfile.close();
            fin.close();
        }
        else
        {
            cout << "Error file didn't open." << endl;
        }
    	//for (int ii = 0; ii < )
        //delete[] encryptedText;
        //cryptedText[j] = '\0';
        i++;
    }
}

