#include<iostream>

using namespace std;

const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";

bool IsTheSameWords(char** words, int n, char* word);
int FindMaxLengthSubstring(char* str);
char* FindFixLengthSubstring(char* begin, int length);
char** FindAllFixLengthSubstring(char* str, int length, int& k);
void DisplayArray(char**, int n);

int main()
{
	const int length = 256;
	cout << "Your text is: " << endl;
	char* string = "If your ! mouse is unava or; 12345 %& *&"
		" if you - prefer to use your keyboard, "
		" you can use the followin keyboard... ";
	cout << string << endl;
	int k = 0;
	int max = FindMaxLengthSubstring(string);
	char** words = FindAllFixLengthSubstring(string, max, k);

	DisplayArray(words, k);

	for (int i = 0; i < k; i++)
	{
		delete[] words[i];
	}
	delete[] words;
	return 0;
}

int FindMaxLengthSubstring(char* str)
{
	char* pword = strpbrk(str, alphabet);
	int maxLength = 0;
	while (pword)
	{
		int currLength = strspn(pword, alphabet);
		if (currLength > maxLength)
			maxLength = currLength;
		pword += currLength;
		pword = strpbrk(pword, alphabet);
	}
	return maxLength;
}

char* FindFixLengthSubstring(char* begin, int length)
{
	char* pword = strpbrk(begin, alphabet);
	while (pword)
	{
		int currLength = strspn(pword, alphabet);
		if (currLength == length)
		{
			return pword;
		}
		pword += currLength;
		pword = strpbrk(pword, alphabet);
	}
	return NULL;//nullptr
}

char** FindAllFixLengthSubstring(char* str, int length, int& k)
{
	char* pword = FindFixLengthSubstring(str, length);
	char** words = new char*[strlen(str) / 2];
	k = 0;
	char* tempword = new char[length + 1];
	tempword[length] = '\0';
	while (pword != NULL)
	{
		strncpy(tempword, pword, length);
		if (!IsTheSameWords(words, k, tempword))
		{
			words[k] = new char[length + 1];
			strcpy(words[k], tempword);
			k++;
		}
		pword += length;
		pword = FindFixLengthSubstring(pword, length);
	}
	delete[] tempword;
	return words;
}

bool IsTheSameWords(char** words, int n, char* word)
{
	for (int i = 0; i < n; i++)
	{
		if (!strcmp(words[i], word)) return true;
	}
	return false;
}

void DisplayArray(char** a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
}
