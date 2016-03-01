#include <iostream>
#include <string.h>
using namespace std;

void ChangeString(char*, char*, char*);
bool TheSame(char*, char*, int, int);
void ReplaceSubtring(char*, char*, char*);

int main()
{
	while (true)
	{
		const int length = 256;
		char string[length], substring1[length], substring2[length];
		cout << "Enter the string: ";
		cin.getline(string, length, '\n');
		cout << "Enter the substring for replacing: ";
		cin.getline(substring1, length, '\n');
		cout << "Enter the substring which you want to replace: ";
		cin.getline(substring2, length, '\n');
		system("cls");

		cout << "\n\t***STRING IS:***\n";
		cout << string;
		ChangeString(string, substring1, substring2);
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

void DeleteSubtring(char* string, char* str1, char* str2)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* pWord = strpbrk(string, symbols);
	while (pWord)
	{
		int length1 = strspn(pWord, symbols);
		int length2 = strspn(str1, symbols);
		if (TheSame(pWord, str1, length1, length2))
		{
			strcpy(pWord, pWord + length1);
			ReplaceSubtring(pWord, str2, symbols);
		}
		else
			pWord += length2;
		pWord = strpbrk(pWord, symbols);
	}
}
void ReplaceSubtring(char* string, char* str1, char*symbols)
{
	int length = strspn(string, symbols);
	str1 = string;
	string += length;
}


bool TheSame(char*str1, char*str2, int len1, int len2)
{
	if (len1 != len2)
		return false;
	int n = len1;
	for (int i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}
