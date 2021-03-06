#include <iostream>
#include <time.h>
using namespace std;
void connect(int* a, int first, int last)
{
	int middle, start, final, j;
	int* mas = new int[1001];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	for (j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (a[start] < a[final])))
		{
			mas[j] = a[start];
			start++;
		}
		else
		{
			mas[j] = a[final];
			final++;
		}
	for (j = first; j <= last; j++) a[j] = mas[j];
	delete[]mas;
};
void Sort(int* a, int first, int last)
{
	{
		if (first < last)
		{
			Sort(a, first, (first + last) / 2);
			Sort(a, (first + last) / 2 + 1, last);
			connect(a, first, last);
		}
	}
};
int main()
{
	setlocale(LC_ALL, "Rus");
	int i, n;
	cout << "Ðàçìåð ìàññèâà: "; cin >> n;
	int* a = new int[1001];
	clock_t start, end;
	start = clock();
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 101;
		cout << a[i] << "  ";
	}
	Sort(a, 0, n);
	cout << endl;
	for (i = 1; i <= n; i++) cout << a[i] << "  ";
	cout << endl;
	end = clock();
	printf("Âðåìÿ âûïîëíåíèå ïðîãðàììû %.4f\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	delete[]a;
}