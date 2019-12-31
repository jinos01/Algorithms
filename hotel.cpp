#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream instream;

	instream.open("input.txt");

	int numTest;
	instream >> numTest;

	for (int i = 0; i < numTest; i++)
	{
		int h, w, n;
		instream >> h >> w >> n;
		
		
		n = n - 1;
		int Y = n % h +1;
		int X = n / h +1;

		cout << Y;
		if (X < 10)
			cout << "0" << X << endl;
		else
			cout << X << endl;
		
	}
	return 0; 
}