#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива: ";
	int c = 3;
	int n;
	cin >> n;
	clock_t start, end;
	start = clock();
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << "  ";
	}
	cout << "\n";
	int buff = 0;
	int i, j;	
	while (c > 0)
	{
		for (int i = 0; i < n; i++)
		{
			int j = i;
			int temp = a[i];
			while ((j >= c) && (a[j - c] > temp))
			{
				a[j] = a[j - c];
				j = j - c;
			}
			a[j] = temp;
		}
		if (c > 1)
			c = c / 2;
		else if (c == 1)
			break;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
	end = clock();
	printf("Время выполнение программы %.4f (s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));

}