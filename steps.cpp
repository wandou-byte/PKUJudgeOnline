#include <iostream>

using namespace std;

int main()

{
	int n, from, to, distance, cnt, ans;

	cin >> n;

	while (n--)

	{
		cin >> from >> to;

		distance = to - from;

		cnt = ans = 0;;

		while (distance > 0)

		{
			distance -= ++cnt;

			++ans;

			if (distance > 0)

			{
				distance -= cnt;

				++ans;
			}
		}

		cout << ans << endl;
	}

	return 0;
}