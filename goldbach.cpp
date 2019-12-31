#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int Prime(int a) {
	for (int i = 2; i <= sqrt(a); i++) {
		
		if (a % i == 0) {
			return 0;
			break;
		}
	}
	return a;
}



int main(void)
{
	ifstream instream;
	int numtest;

	instream.open("input.txt");


	instream >> numtest;
	for (int i = 0; i < numtest; i++)
	{
		int num;
		instream >> num;
		int x = num;

		int a = x / 2;
		int b = x / 2;
		while (a >= 1) {
			if (Prime(a) != 0 && Prime(b) != 0) {
				cout << a << " " << b << endl;
				break;
			}
			else {
				a -= 1;
				b += 1;
			}
		}		
	}
	return 0;
}