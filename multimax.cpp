#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>



using namespace std;

int main()
{
	

	ifstream instream;

	instream.open("input.txt");

	int numtest;

	instream >> numtest;

	for (int i = 0; i < numtest; i++)
	{
		int num;
		instream >> num;
		vector<int> vec(num);
		vector<int> max(7);
		for (int j = 0; j < num; j++)
		{
			int n;
			instream >> n;
			vec[j] = n;
		}
		sort(vec.begin(), vec.end());
		
		max[0] = vec[0] * vec[1];
		max[1] = vec[num - 1] * vec[num - 2];
		max[2] = vec[num - 1] * vec[num - 2] * vec[num - 3];
		max[3] = vec[num - 1] * vec[num - 2] * vec[0];
		max[4] = vec[0] * vec[1] * vec[num - 1];
		max[5] = vec[0] * vec[1] * vec[2];
		max[6] = vec[0] * vec[num - 1];

		sort(max.begin(), max.end());

		cout << max[6] << endl;
	
	}
	return 0;
}