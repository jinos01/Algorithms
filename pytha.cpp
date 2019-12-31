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

		instream >> n >> m; //n = ÆÀ°³¼ö m = ÀüÃ¼ °æ±â ¼ö
		
		double sum[1001][2] = {};
		double result[1001] = {};
		
		for (int j = 0; j < m; j++)
		{
			int a, b, p, q; //ÆÀa  pµæÁ¡  ÆÀb qµæÁ¡
			instream >> a >> b >> p >> q;

			sum[a][0] += p; // ÆÀa µæÁ¡
			sum[a][1] += q; // ÆÀa ½ÇÁ¡
			sum[b][0] += q; // ÆÀb µæÁ¡
			sum[b][1] += p; // ÆÀb ½ÇÁ¡ 
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