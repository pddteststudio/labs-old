#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main() {
    double a, b, h;
    int n;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter h: ";
    cin >> h;
    cout << "Enter n: ";
    cin >> n;

    int steps = (b - a) / h;

    for (int i = 0; i <= steps; ++i) {
        double x = a + i * h;

        double S = 1.0;

        double x_power = 1.0;
        double fact = 1.0;
        for (int k = 1; k <= n; ++k) {
            x_power *= x; // x^k
            fact *= k; // k!
            S += cos(k * M_PI / 4.0) * (x_power / fact);
        }

        double Y = cos(x * sin(M_PI / 4.0)) * exp(x * cos(M_PI / 4.0));

        double diff = fabs(Y - S);

        cout << "x = " << x << "  S(x) = " << S << "  Y(x) = " << Y << "  |Y-S| = " << diff << endl;
    }

    return 0;
}
