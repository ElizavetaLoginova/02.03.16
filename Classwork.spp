#include <iostream>
#include <string.h>
using namespace std;

void ChangeString(char*, char*);
int Length(char*); 
bool TheSame(char*str, char*word);

int main()
{
	const int length = 256;
	char string[length], word[length];
	cout << "Enter the string: ";
	cin.getline(string, length,'\n');
	cout << "Enter the word: ";
	cin.getline(word, length, '\n');
	system("cls");

	//int n = Length(word);
	
	cout << "\n\t***STRING IS:***\n";
	cout << string;
	ChangeString(string, word);
	cout << "\n\t***STRING IS:***\n";
	cout << string;
	system("pause");
	return 0;
}

void ChangeString(char* str, char* word)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* pWord = strpbrk(str, symbols);
	while (pWord)
	{
		int length = strspn(pWord, symbols);
		if (TheSame(pWord, word))
			strcpy(pWord, pWord + length);
		else
			pWord += Length(word);
		pWord = strpbrk(pWord, symbols);
	}
}

bool TheSame(char*str, char*word)
{
	if (Length(str) != Length(word))
		return false;
	int n = Length(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] != word[i])
			return false;
	}
	return true;
}

int Length(char*str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}
