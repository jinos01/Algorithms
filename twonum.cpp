#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int v[1000001];

int main() {

	ifstream instream;
	instream.open("input.txt");
	int numtest;

	instream >> numtest;
	
	while (numtest --) {
		int n, k;
		instream >> n >> k;
		int num;
		for (int i = 0; i < n; i++) {
			instream >> num;
			v[i] = num;
			
		}
		sort(v, v + n);
		int gap = 200000000;
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			int * lower_bound_it = lower_bound(v, v + n, k - v[i]);
			if (*lower_bound_it > v[i]) {
				if (abs(k - v[i] - *lower_bound_it) < gap) {
					gap = abs(k - v[i] - *lower_bound_it);
					cnt = 1;
				}
				else if (abs(k - v[i] - *lower_bound_it) == gap)
					cnt++;
			}
			if (lower_bound_it != v)
				lower_bound_it--;
			if (*lower_bound_it > v[i]) {
				if (abs(k - v[i] - *lower_bound_it) < gap) {
					gap = abs(k - v[i] - *lower_bound_it);
					cnt = 1;
				}
				else if (abs(k - v[i] - *lower_bound_it) == gap)
					cnt++;
			}
		}
		cout << cnt << endl;
		
	}
	return 0;
}