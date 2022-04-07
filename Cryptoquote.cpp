/************************************************************************
*																		*
*	Program:	Cryptoquote.cpp											*
*																		*
*	Author:		Micheal James Davis										*
*																		*
*	Date:		Oct 18, 2019										    *
*																		*
*	Purpose: To create a puzzle by pulling a quote from an outside		*
*	source to randomize the letters and allowing to user to solve the	*
*	random letter quote.												*
*																		*									*
*																		*
*************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <cstdlib>		
#include <ctime>
#include <algorithm>

using namespace std;

string getQuote();
string toupper(string s);	
string permute();
string encrypted(string quote, string key);
string fillUnderscores(string quote);
void frequencies(string s);
void replaceLetter(string encrypted, string& answer, char encrypted_char, char replace_char);

// Sets the values of the functions outside the main for they can be used inside 

/****************************************************************************
*																			*
*	Function:	getQuote													*
*																			*
*	Purpose:	To read a randomly selected quote from a file of quotes		*
*																			*
****************************************************************************/

string getQuote()
{
	//	Open the input file

	ifstream fin("//hams-cs/Students/davism22/COMS261/Project 3/Quotes.txt");

	//	Verify that the file was opened

	if (!fin)
	{
		cout << "Failed to open file" << endl;
		system("pause");
		exit(-1);
	}

	int num_of_quotes;
	fin >> num_of_quotes;

	//	Pick a quote at random

	int pos = rand() % num_of_quotes;

	//	Read the specified number of quotes and stop reading

	string quote;

	for (int i = 0; i < pos; i++)
		getline(fin, quote);

	//	Return the last quote read, in uppercase

	return toupper(quote);
}

/****************************************************************************
*																			*
*	Function:	permute														*
*																			*
*	Purpose:	To permute the 26 uppercase letters of the alphabet			*
*																			*
*	Note:		This algorithm guarantees that no letter will be in its		*
*				original position											*
*																			*
****************************************************************************/

string permute()
{
	//	Begin with the alphabet in standard order

	string key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	//	For each position, swap letter with a later position

	for (int i = 0; i < 25; i++)
	{
		int pos = i + 1 + rand() % (25 - i);
		char temp = key[i];
		key[i] = key[pos];
		key[pos] = temp;
	}

	//	Return the permutation

	return key;

	
}

/****************************************************************************
*																			*
*	Function:	toupper														*
*																			*
*	Purpose:	To convert the letters in a string to all uppercase			*
*																			*
****************************************************************************/

string toupper(string s)
{
	for (int i = 0; i < s.size(); i++)
		s[i] = toupper(s[i]);
	return s;
}


/****************************************************************************
*																			*
*	Function:	frequencies													*
*																			*
*	Purpose:	To report the frequencies of the letters in a string		*
*																			*
****************************************************************************/

void frequencies(string encrypt)
{
	//	Start with the alphabet in standard order

	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	//	Initialize the frequencies

	int freq[26] = { 0 };

	//	Find the frequency of each letter in the string

	for (int i = 0; i < encrypt.size(); i++)
		if (isalpha(encrypt[i]))
			freq[toupper(encrypt[i]) - 'A']++;

	//	Arrange the letters in order of descending frequency

	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 25 - i; j++)
			if (freq[j] < freq[j + 1])
			{
				int temp_i = freq[j];
				freq[j] = freq[j + 1];
				freq[j + 1] = temp_i;
				char temp_c = alphabet[j];
				alphabet[j] = alphabet[j + 1];
				alphabet[j + 1] = temp_c;
			}

	//	Report the frequencies

	cout << endl << "Frequencies of the letters" << endl << endl;

	int i = 0;
	while (i < 26 && freq[i] > 0)
	{
		cout << '\t' << alphabet[i] << ' ' << freq[i] << "   ";
		i++;
		if (i % 10 == 0)
			cout << endl;
	}
	cout << endl;

	return;
}

/****************************************************************************
*																			*
*	Function:	encrypted													*
*																			*
*	Purpose:	Encrypts the quote pulled from the outside source and		*
*				takes the randomize letters to make the random quote		*
*																			*
****************************************************************************/
string encrypted(string quote, string key)
{
	string encrypt = quote;

	for (int i = 0; i < quote.length(); i++)	// This giant for loop goes through the quote with the random key of letters and changes each letter according to match for when the user solves the puzzle
												// it will be the correct quote with the changed quote.
	{
		if (quote[i] == 'A')
		{
			encrypt[i] =  key[0];

		}
		else if (quote[i] == 'B')
			{
			encrypt[i] = key[1];

			}
		else if (quote[i] ==  'C')
		{
			encrypt[i] = key[2];

		}
		else if (quote[i] == 'D')
		{
			encrypt[i] = key[3];

		}
		else if (quote[i] == 'E')
		{
			encrypt[i] = key[4];

		}
		else if (quote[i] == 'F')
		{
			encrypt[i] = key[5];

		}
		else if (quote[i] == 'G')
		{
			encrypt[i] = key[6];

		}
		else if (quote[i] == 'H')
		{
			encrypt[i] = key[7];

		}
		else if (quote[i] == 'I')
		{
			encrypt[i] = key[8];

		}
		else if (quote[i] == 'J')
		{
			encrypt[i] = key[9];

		}
		else if (quote[i] == 'K')
		{
			encrypt[i] = key[10];

		}
		else if (quote[i] == 'L')
		{
			encrypt[i] = key[11];

		}
		else if (quote[i] == 'M')
		{
			encrypt[i] = key[12];

		}
		else if (quote[i] == 'N')
		{
			encrypt[i] = key[13];

		}
		else if (quote[i] == 'O')
		{
			encrypt[i] = key[14];

		}
		else if (quote[i] == 'P')
		{
			encrypt[i] = key[15];

		}
		else if (quote[i] == 'Q')
		{
			 encrypt[i] = key[16];

		}
		else if (quote[i] == 'R')
		{
			encrypt[i] = key[17];

		}
		else if (quote[i] == 'S')
		{
			encrypt[i] = key[18];

		}
		else if (quote[i] == 'T')
		{
			 encrypt[i] = key[19];

		}
		else if (quote[i] == 'U')
		{
		 encrypt[i] = key[20];

		}
		else if (quote[i] == 'V')
		{
		encrypt[i] = key[21];

		}
		else if (quote[i] == 'W')
		{
		encrypt[i] = key[22];

		}
		else if (quote[i] == 'X')
		{
		encrypt[i] = key[23];

		}
		else if (quote[i] == 'Y')
		{
		encrypt[i] = key[24];

		}
		else if (quote[i] == 'Z')
		{
		 encrypt[i] = key[25];		// Goes through each letter and test to see if it matches and if it does it will loop back to next letter of the quote skipping all others char besides letters

		}
	}

	return encrypt;

}

/****************************************************************************
*																			*
*	Function:	fillUnderscores												*
*																			*
*	Purpose:	Takes the orignal quote and makes it all underscores		*
*																			*
****************************************************************************/
string fillUnderscores(string quote)
{
	string underscore = quote;

	for (int i = 0; i < underscore.length(); i++)
	{	
		if (isalpha(underscore[i]))
			underscore[i] = '_';
		}
	return underscore;
}

/****************************************************************************
*																			*
*	Function:	replaceLetter												*
*																			*
*	Purpose:	Takes the underscore quote and replaces the letters			*
*	according to the input of what the user would like to change and what	*
	letter to change it with.												*
*																			*
****************************************************************************/
void replaceLetter(string encrypted, string& answer, char encrypt_char, char replaced_char)
{
	for (int i = 0; i < encrypted.length(); i++)
	{
		if (encrypted[i] == encrypt_char)			// This for loop goes through the encrypted quote and changes the letters accordingly as the user wants
			answer[i] = replaced_char; 
	}

	if (replaced_char == '.')
	{
		for(int i =0; i < answer.length(); i++ )		// If the user types a "." it allows the program to replace the value as like a redo button
			if (answer[i] == replaced_char)
				answer[i] = '_';
	}
	cout << encrypted << endl;
	cout << answer << endl;

	return;
}

char encrypt_char;
string User_answer;
const char SENTINEL = '?';
/****************************************************************************
*																			*
*	Function:	main														*
*																			*
*	Purpose:	Starts the game with the while loop repeating the questions *
*	to the user prompting them to change the letters as they please			*
*																			*
****************************************************************************/
int main()
{
	srand((unsigned int)time(0));

	cout << "Welcome to Cyrptoquote" << endl;

	cout << " " << endl;

	cout << "Guess the letters to complete the quote:" << endl;

	cout << " " << endl;

	string output_quote = getQuote();

	string output_permute = permute();

	cout << encrypted(output_quote, output_permute) << endl;
	
	cout << " " << endl;

	cout << fillUnderscores(output_quote) << endl;

	cout << " " << endl;

	string output_encrypt = encrypted(output_quote, output_permute); 

	frequencies(output_encrypt);										// shows the frequencies of each letter

	string User_answer = fillUnderscores(output_quote);


	while (true)
	{
		cout << "Enter the encrypted letter you would like to replace or ? to quit: " << endl;

		char encrypt_char;

		cin >> encrypt_char;

		cout << " " << endl;

		if (encrypt_char == '?')
		{
			cout << output_quote << endl;		// If the user is tired of playing they can type ? to see the answer and the program will end
			
			break;
		}

		cout << "Enter the letter to replace it with: " << endl;

		char replaced_char;

		cin >> replaced_char;

		cout << " " << endl;

		replaceLetter(output_encrypt, User_answer, encrypt_char, replaced_char); // inputs the function into the while loop to repeat the same function until the while loop is closed

		cout << " " << endl;

		if (User_answer == output_quote)
		{
			cout << "Great Job you solved the puzzle!!!" << endl; // This allows if the user solves the puzzle it will notify them and end the program
			break;
		}

	}

	system("pause");
	return 0;
}