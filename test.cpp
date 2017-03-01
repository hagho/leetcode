#include <iostream>
#include <x86intrin.h>
using namespace std;

int main() {
	cout << __builtin_popcount(3);
	return 0;
}
