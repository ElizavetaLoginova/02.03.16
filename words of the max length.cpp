#include <iostream>
#include <string.h>
using namespace std;

void ChangeString(char*, int);
int MaxLength(char*);

int main()
{
	while (true)
	{
		const int length = 256;
		cout << "Your text is: " << endl;
		char* string = "If your ! mouse is unava or; 12345 %& *&"
			" if you - prefer to use your keyboard, "
			" you can use the followin keyboard... ";
		cout << string << endl;


		int n;
		n = MaxLength(string);
		cout << endl << "Length: " << n;
		cout << endl << "The most long words are: " << endl;
		ChangeString(string, n);
		system("pause");

		char yes;
		cout << "Would you like to countinie? Press y/Y: " << endl;
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
			continue;
		break;
	}
	return 0;
}

void ChangeString(char* str, int len)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* pWord = strpbrk(str, symbols);
	char arrayOfWords[80] = "";

	while (pWord)
	{
		int length = strspn(pWord, symbols);
		if (length == len)
		{
			char *word = new char[len + 1];
			word[len] = '\0';
			word = strncpy(word, pWord, len);
			cout << word << " ";
			pWord += len;
		}
		else
		{

			pWord += length;
			pWord = strpbrk(pWord, symbols);
		}

	}
}


int MaxLength(char* str)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* pWord = strpbrk(str, symbols);
	int max = 0;
	while (pWord)
	{
		int length = strspn(pWord, symbols);
		if (max < length)
			max = length;
		pWord += length;
		pWord = strpbrk(pWord, symbols);
	}
	return max;
}
