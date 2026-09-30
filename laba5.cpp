#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size!" << endl;
        return 0;
    }

    int* a = new int[n];
    int prod = 1;
    int first = -1, last = -1;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            if (first == -1) first = i;
            last = i;
        }
    }

    if (first != -1 && last != -1 && last - first > 1) {
        for (int i = first + 1; i < last; i++)
            prod *= a[i];
        cout << "Product = " << prod << endl;
    }
    else {
        cout << "Not enough negative elements" << endl;
    }

    delete[] a;
    return 0;
}
