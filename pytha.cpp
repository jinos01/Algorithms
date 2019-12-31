#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


int main()
{
	ifstream instream;

	instream.open("input.txt");
	
	int numtest;
	instream >> numtest;
	
	

	for (int i = 0; i < numtest; i++)
	{
		int n, m;

		instream >> n >> m; //n = ������ m = ��ü ��� ��
		
		double sum[1001][2] = {};
		double result[1001] = {};
		
		for (int j = 0; j < m; j++)
		{
			int a, b, p, q; //��a  p����  ��b q����
			instream >> a >> b >> p >> q;

			sum[a][0] += p; // ��a ����
			sum[a][1] += q; // ��a ����
			sum[b][0] += q; // ��b ����
			sum[b][1] += p; // ��b ���� 
		}
		for (int k = 1; k < n + 1; k++)
		{
			if (sum[k][0] == 0 && sum[k][1])
				result[k] = 0;
			else
				result[k] = (sum[k][0] * sum[k][0]) / ((sum[k][0] * sum[k][0]) + (sum[k][1] * sum[k][1]));
		}

		sort(result,result+n+1);
		
		cout << int(result[n] * 1000) << endl << int(result[1] * 1000) << endl;

	}
	

}