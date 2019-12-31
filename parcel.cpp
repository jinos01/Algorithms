#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream instream;

	instream.open("input.txt");
	int numtest;
	instream >> numtest;

	for (int t = 0; t < numtest; t++)
	{

		const int NONE = -1;
		int w, n;
		bool able = false;
		vector<int> A, S;
		instream >> w >> n;
		A.resize(n);
		S.resize(w, NONE);

		for (int i = 0; i < n; i++)
			instream >> A[i];
		sort(A.begin(), A.end());

		for (int i = 0; i < n && A[i] < w; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int s = A[i] + A[j];
				if (s >= w) break;
				if (S[s] == NONE) S[s] = i;
			}
		}
		for (int s = 1; s < w && !able; s++)
		{
			int i = S[s], k = S[w - s];
			if (i == NONE || k == NONE) continue;
			if (s - A[i] < A[k]) able = true;
		}
		if (able) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}