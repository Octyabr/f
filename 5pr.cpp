#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int key, n, i, j, buff;
    cout << "Ââåäèòå ðàçìåð ìàññèâà: "; cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << "  ";
    }
    cout << endl;
    for (i = 1; i < n; i++)
    {
        buff = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > buff; j--)
            arr[j + 1] = arr[j];

        arr[j + 1] = buff;
    }
    cout << "Îòñîðòèðîâàííûé ìàññèâ" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl << "Ââåäèòå êëþ÷: ";

    cin >> key;

    bool flag = false;
    int l = 0;
    int r = n - 1;
    int mid;

    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2;

        if (arr[mid] == key) flag = true;
        if (arr[mid] > key) r = mid - 1;
        else l = mid + 1;
    }

    if (flag) cout << "Èíäåêñ ýëåìåíòà " << key << " â ìàññèâå ðàâåí: " << mid + 1 << endl;
    return 0;
}