#include <iostream>
#include <iomanip>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(void)
{
	fastio;
	const double	pi = 3.141592;
	double	a;
	double	b;
	
	cin >> a >> b;
	cout << fixed << setprecision(6);
	cout << 2 * a + 2 * b * pi << '\n';
}