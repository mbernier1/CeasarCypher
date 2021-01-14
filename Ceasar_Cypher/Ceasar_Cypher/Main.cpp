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

void Encryption()
{
    int key;
    char ch;
    char filename[100] = "";
    char newfilename[20] = "_encrypted.txt";
    string result = "";
    char ext[5] = ".txt";

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

		// still working this out, not sure if its needed
		/*
		if (key == 0)
		{
            key = 25;
		}
        else
        {
            key -= 1;
        }
        */
	}
    
    //2. Read in "USERS" name for text file.                                      //take out this stuff in ( ) when strcat works
    cout << "Please enter the name of the text file you would like to be encrypted. (example: file.txt)" << endl;
    cin >> filename;
    //strcat(filename, ext);
    
	//Make this to where the user can name the file and then we add _encrypted.txt to their file name so it will save correctly
	//May have to move this down further so correct file can be opened
    //strcat(filename, newfilename);

    //3. Encrypt text from file.
    ifstream fin;
    fin.open(filename);
    if (fin.is_open()) 
    {
        ifstream fin(filename);
        
        while (fin >> ch) 
        { 
            //cout << ch;
            //atoi(ch);
            result = int((ch + key)-32);

        	// this is not working because "result" is not an int here
        	/*
        	 *if (result >= 123)
        	{
                cout << "Result needs to be wrapped around to start of alphabet" << endl;
        	}
        	if (result <= 96 && result >= 91)
        	{
                cout << "Result is between lowercase and uppercase alphabet" << endl;
        	}
        	*/
            cout << result;
            ofstream outfile;
        	
            //strcat(filename, newfilename);
            //strcpy(newfilename, filename);

            outfile.open(newfilename, std::ios_base::app);
        	
            if (outfile.is_open()) 
            {
                outfile << result;
            }
            else 
            {
                cout << "Output file Error." << endl;
            }
            outfile.close();
        }
        fin.close();
    }
    else
    {
        cout << "Error file didn't open." << endl;
    }
    //4. Save to new file using previously given name of file with _encrypted added.

}


void Decryption()
{
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