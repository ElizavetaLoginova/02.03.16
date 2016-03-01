#include <iostream>
#include <string.h>
using namespace std;

void ChangeString(char*, char*);
bool TheSame(char*str, char*word, int, int);

int main()
{
	while (true)
	{
		const int length = 256;
		char string[length], words[length];
		cout << "Enter the string: ";
		cin.getline(string, length, '\n');
		cout << "Enter words through the gap: ";
		cin.getline(words, length, '\n');
		system("cls");

		cout << "\n\t***STRING IS:***\n";
		cout << string;
		ChangeString(string, words);
		cout << "\n\t***STRING IS:***\n";
		cout << string;
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

void ChangeString(char* str, char* words)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* pWord = strpbrk(str, symbols);
	char*  oneWord = strpbrk(words, symbols);

	while (oneWord)
	{
		int len = strspn(oneWord, symbols);
		pWord = strpbrk(str, symbols);
		while (pWord)
		{
			int length = strspn(pWord, symbols);
			if (TheSame(pWord, oneWord, length, len))
				strcpy(pWord, pWord + length);
			else
				pWord += length;
			pWord = strpbrk(pWord, symbols);
		}
		oneWord += len;
		oneWord = strpbrk(oneWord, symbols);
	}
}

bool TheSame(char*str, char*word, int length, int len)
{
	if (length != len)
		return false;
	int n = length;
	for (int i = 0; i < n; i++)
	{
		if (str[i] != word[i])
			return false;
	}
	return true;
}
