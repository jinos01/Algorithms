#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream instream;

	instream.open("input.txt");
	int numtest;

	instream >> numtest;

	for (int i = 0; i < numtest; i++)
	{
		int a, b, n, w; // a는 하루 양사료 b는 하루 염소사료 n은 양+염소 w는 총 사료

		instream >> a >> b >> n >> w;

		int x, y ; //x는 양 마리수 y는 염소 마리수
		int check = 0;
		int result_x;
		int result_y;
		for (int k = 1; k <= n; k++)
		{
			x = k;
			y = n - k;
			
			if ((a*x) + (b*y) == w && x > 0 && y > 0)
			{
				check++;
				result_x = x;
				result_y = y;
			}
			
		}
		if (check == 1)
		{
			cout << result_x << " " << result_y << endl;
		}
		else
			cout << "-1" << endl;
			
		

	}
	return 0;
}