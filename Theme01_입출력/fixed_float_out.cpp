#include <iostream>
#include <iomanip>      // std::setprecision
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

void Print() {
	cout << 0.000123456789 << '\n';
	cout << 0.123456789123 << '\n';
	cout << 123.456789123 << '\n';
	cout << 123456.789123 << '\n';
	cout << 123456789.123 << '\n';
	cout << '\n';
}

int main() {
	fastio;
	cout << fixed;
	Print();
	cout << setprecision(10);
	Print();
}