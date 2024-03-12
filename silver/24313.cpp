#include <iostream>

int    main() {
    int a1, a0, c, n0; std::cin >> a1 >> a0 >> c >> n0;

	if (c >= a1 && a1*n0 + a0 <=c*n0)
		std::cout << 1 << '\n';
	else
		std::cout << 0 << '\n';
}
