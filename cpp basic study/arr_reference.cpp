#include <iostream>
using namespace std;

int main()	//레퍼런스의 배열은 불가능하지만, 배열들의 레퍼런스는 가능하다
{
	int arr[3] = {1, 2, 3 };
	int (&ref)[3] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	cout << arr[0] << arr[1] << arr[2] << '\n';
	return (0);
}