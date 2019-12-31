#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> list;


void check(int num)
{
	if (num == 1)
	{
		cout << "HAPPY" << endl;
		return;
	}
	for (int i = 0; i < list.size(); i++)
	{
		if (num == list[i])
		{
			cout << "UNHAPPY" << endl;
			return;
		}
	}
	
	list.push_back(num);

	int sum = 0;
	int a = num;

	while (a != 0)
	{
		sum = sum + (a % 10)*(a % 10);
		a = a / 10;
	}
	
	check(sum);
	list.clear();
}

int main(void) {
	ifstream instream;
	instream.open("input.txt");

	int numtest;
	instream >> numtest;
	int num;

	for (int i = 0; i < numtest; i++)
	{
		
		instream >> num;
		check(num);
	}
	

	return 0;
}




