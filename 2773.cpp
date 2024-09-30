//Happy 2006
//Problem 2773

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int m, k;
int pri[1000005];
int gcd(int a, int b)
{
	if (b == 0)return a;
	return gcd(b, a % b);
}
int main()
{
	while (cin >> m >> k)
	{
		memset(pri, 0, sizeof(pri));
		int cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			if (gcd(m, i) == 1)
			{
				pri[++cnt] = i;
			}
		}
		if (k % cnt != 0)
			cout << m * (k / cnt) + pri[k % cnt] << endl;
		else
			cout << m * (k / cnt - 1) + pri[cnt] << endl;
	}
}