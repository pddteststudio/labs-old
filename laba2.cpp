#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double a, c, z;
	double x, y, phi;
	int choice;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter c: ";
	cin >> c;
	cout << "Enter z: ";
	cin >> z;

	if (z <= 1.0) {
		x = z * z + 1.0;
		cout << "z <= 1 -> x = z * z + 1.0\n";
	}
	else {
		x = 1.0 / sqrt(z - 1.0);
		cout << "z > 1  -> x = 1.0 / sqrt(z - 1.0)\n";
	}

	cout << "Choose phi(x): 1) 2x  2) x^2  3) x/3 : ";
	cin >> choice;
	switch (choice) {
	case 1:
		phi = 2.0 * x;
		cout << "phi(x) = 2x\n";
		break;
	case 2:
		phi = x * x;
		cout << "phi(x) = x^2\n";
		break;
	case 3:
		phi = x / 3.0;
		cout << "phi(x) = x/3\n";
		break;
	default:
		phi = 2.0 * x;
		cout << "Invalid value. phi(x)=2x\n";
	}

	y = a * log(fabs(x)) + exp(x) + c * pow(sin(pow(phi, 2.0) - 1.0), 3.0);

	cout << "Result: " << y << endl;
	return 0; 
}
