#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


void bfs(int start, int N) {
	int c[500]; // 방문 

	queue<int> q;
	q.push(start);
	c[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < node[x].size(); i++) {
			int y = node[x][i];
			if (!c[y]) {
				q.push(y);
				c[y] = true;
			}
		}
	}
}





int main()
{
	ifstream instream;
	instream.open("input.txt");

	int N; // the total number of nodes in the level, including the gateways
	int L; // the number of links
	int E; // the number of exit gateways
	cin >> N >> L >> E; cin.ignore();

	vector<int> node[N + 1];
	int arr[20];

	for (int i = 0; i < L; i++) {
		int N1; // N1 and N2 defines a link between these nodes
		int N2;
		cin >> N1 >> N2; cin.ignore();
		node[N1].push_back[N2];
		node[N2].push_back[N1];
	}
	for (int i = 0; i < E; i++) {
		int EI; // the index of a gateway node
		cin >> EI; cin.ignore();
		arr[i] = EI; // 출구저장 
	}

	// game loop
	while (1) {
		int SI; // The index of the node on which the Skynet agent is positioned this turn
		cin >> SI; cin.ignore();
		bfs(SI, N);
		
			// Write an action using cout. DON'T FORGET THE "<< endl"
			// To debug: cerr << "Debug messages..." << endl;


			// Example: 0 1 are the indices of the nodes you wish to sever the link between
		cout << "0 1" << endl;
	}
}