#include <iostream>
using namespace std;

char* FindFirstEnter(char*, int);

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
		cout << "Enter the number of elements: " << endl;
		cin >> n;

		cout << FindFirstEnter(string, n);

		char yes;
		cout << "Would you like to countinie? Press y/Y: " << endl;
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
			continue;
		break;
	}
	return 0;
}

char* FindFirstEnter(char*str, int len)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* pWord = strpbrk(str, symbols);
	char* arrayOfWords = "";
	char *word;
	while (pWord)
	{
		int length = strspn(pWord, symbols);
		if (length == len)
		{
			word = new char[len + 1];
			word[len] = '\0';
			word = strncpy(word, pWord, len);
			return word;
		}
		else
		{
			pWord += length;
			pWord = strpbrk(pWord, symbols);
		}
	}
}
