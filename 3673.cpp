//Cow Multiplication
//Problem 3673

#include<iostream>
#include<string>
using namespace std;

string str1, str2;
int i, j, sum;

int main()
{
	while (cin >> str1 >> str2)
	{
		sum = 0;
		for (i = 0; i < str1.length(); ++i)
		{
			for (j = 0; j < str2.length(); ++j)
			{
				sum += (str1[i] - 48) * (str2[j] - 48);
			}
		}
		cout << sum << endl;
	}
	return 0;
}