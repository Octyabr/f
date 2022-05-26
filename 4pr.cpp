#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n, i, j, q;
    int position = 0;
    cout << "Введите размер массива: "; cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << "  ";
    }
    cout << endl;
    cout << "Введите число которые надо найти: "; cin >> q;
    if (arr[n - 1] != q)
    {
        arr[n - 1] = q;
        for (; arr[position] != q; position++);  //Поиск
        position++;
    }
    else {
        cout << n;
        return 0;
    }
    cout << "Позиция введенного числа равна: " << position;
}