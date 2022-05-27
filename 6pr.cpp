#include <iostream>
#include <fstream>
using namespace std;

int pos(const char* s, const char* p, int n)
{
	int i, j;
	int lenC, lenS;
	for (lenC = 0; p[lenC]; lenC++);
	for (lenS = 0; s[lenS]; lenS++);

	for (i = 0; i <= lenS - lenC; i++)
	{
		for (j = 0; s[i + j] == p[j]; j++);
		if (j - lenC == 1 && i == lenS - lenC && !(n - 1)) return i;
		if (j == lenC)
			if (n - 1) n--;
			else return i;
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	string a;
	char buff[5000];
	ifstream fin("d:\\text.txt");
	while (!fin.eof())
	{
		fin.getline(buff, sizeof(buff));
		cout << buff << endl;
	}
	cin >> a;//Вводим строку
	const char* s = buff;
	const char* p = a.c_str();
	int i, n = 0;
	for (i = 1; n != -1; i++)
	{
		n = pos(s, p, i);

		if (n >= 0)
			cout << n << endl;
	}
}