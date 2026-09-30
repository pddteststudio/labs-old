#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double x, y, z, w, a, b, c;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    cout << "Enter z: ";
    cin >> z;

    a = pow(x, 6) + pow(log(y), 2);
    b = pow(a, 1.0 / 3.0);
    c = exp(fabs(x - y)) * pow(fabs(x - y), x + y) / (atan(x) + atan(z));
    w = b + c;

    cout << "Result: " << w << endl;
}
