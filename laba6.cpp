#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size!" << endl;
        return 0;
    }

    double** a = new double* [n];
    for (int i = 0; i < n; i++)
        a[i] = new double[n];

    cout << "Enter matrix elements (by row):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nMatrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    double sum_below = 0.0;
    double prod_above = 1.0;
    bool has_below = false;
    bool has_above = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                sum_below += a[i][j];
                has_below = true;
            }
            else if (i < j) {
                prod_above *= a[i][j];
                has_above = true;
            }
        }
    }

    if (has_below) {
        cout << "Sum below diagonal = " << sum_below << endl;
    }
    else {
        cout << "No elements below diagonal" << endl;
    }

    if (has_above) {
        cout << "Product above diagonal = " << prod_above << endl;
    }
    else {
        cout << "No elements above diagonal" << endl;
    }

    for (int i = 0; i < n; i++) delete[] a[i];
    delete[] a;

    return 0;
}
