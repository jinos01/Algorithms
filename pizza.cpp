#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

long long arr[1001][1001];
long long sum[1001][1001];


int main()
{
	ifstream instream;
	instream.open("input.txt");

	int numtest;

	instream >> numtest;
	
	
	for (int i = 0; i < numtest; i++)
	{
		int row, col;
		instream >> row >> col;
		

		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < col; k++)
			{
				instream >> arr[j][k];
				sum[j][k] = 0;
			}

		}
		for (int j = 0; j < row; j++)
		{
			int a = j;
			int b = 0;

			for (int k = 0; k < col; k++)
			{
				if (arr[j][k] > arr[a][b])
				{
					a = j;
					b = k;
				}
			}
			sum[a][b] = arr[a][b];
		}

		for (int j = 0; j < col; j++)
		{
			int a = j;
			int b = 0;
			for (int k = 0; k < row; k++)
			{
				if (arr[k][j] > arr[b][a])
				{
					a = j;
					b = k;
				}
			}
			sum[b][a] = arr[b][a];
		}

		long long total = 0;
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < col; k++)
			{
				if (sum[j][k] == 0)
					total += arr[j][k];
			}
		}
		cout << total << endl;
	}
	return 0;
}