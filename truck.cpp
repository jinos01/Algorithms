#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ifstream instream;
	instream.open("input.txt");

	int numtest;
	instream >> numtest;
	for (int i = 0; i < numtest; i++)
	{
		int n, w, L;
		instream >> n >> w >> L;
		vector < int > trucks(n);
		int num;

		for (int j = 0; j < n; j++) {
			instream >> num;
			trucks[j] = num;
		}
		queue < int > q;

		int ans = 0;
		int totalWeight = 0;
		for (int j = 0; j < w; j++)
			q.push(0);
		for (int j = 0; j < n; j++) {
			while (totalWeight - q.front() + trucks[j] > L) {
				totalWeight -= q.front();
				q.pop();
				q.push(0);
				ans++;
			}
			ans++;
			totalWeight -= q.front();
			q.pop();
			q.push(trucks[j]);
			totalWeight += trucks[j];
		}
		cout << ans + w << endl;
	}
	return 0;
}