#include <iostream>
#include <fstream>


using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int henry(int child, int parent, int num) {
	int x;
	while (child != 1) {
		x = (parent % child == 0) ? (parent / child) : (parent / child + 1);
		child = child * x - parent;
		parent *= x;
		int g = gcd(child, parent);
		child /= g;
		parent /= g;
	}
	return parent;
}



int main()
{
	ifstream instream;
	instream.open("input.txt");

	int numtest;

	instream >> numtest;
	for (int i = 0; i < numtest; i++) {
		int child, parent;

		instream >> child >> parent;

		int n = gcd(child, parent);

		cout << henry(child, parent, 1) << endl;;

	}
	return 0;
}