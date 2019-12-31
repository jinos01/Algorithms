#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool palindrome(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != input[input.length() - i - 1])
			return false;
	}
	return true;
}

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
		int sum = 0;
		int origin = num;
		for (int j = 2; j <= 64; j++)
		{
			num = origin;
			string input;
			string result[100];
			int count = 0;
			for (int k = 0; num > 0; k++)
			{
				result[k] = num % j;
				num = num / j;
				count++;
			}
			for (int p = 0; p < count; p++)
			{
				input = input + result[p];

			}
			
			if (palindrome(input) == 1)
			{
				sum++;
				cout << palindrome(input) << endl;
				break;
			}
		}
		if (sum == 0)
		{
			cout << "0" << endl;
		}

	}
	return 0;
}