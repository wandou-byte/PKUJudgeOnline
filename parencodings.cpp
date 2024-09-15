//Parencodings
//Problem 1068

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int cases;
	cin >> cases;

	while (cases > 0) {
		int n;
		cin >> n;
		vector<int> pcode(n);
		for (int i = 0; i < n; ++i) {
			cin >> pcode[i];
		}

		string str;
		int balance = 0;
		for (int i = 0; i < n; ++i) {
			balance = pcode[i] - (i > 0 ? pcode[i - 1] : 0);
			for (int j = 0; j < balance; ++j) {
				str += "(";
			}
			str += ")";
		}

		vector<int> wcode(n);
		int i = 0, l = 0;
		while (l < n) {
			int j = str.find(')', i);
			if (j == string::npos) {
				break;
			}
			int t = 0;
			for (int k = j; k >= 0; --k) {
				if (str[k] == '(') {
					str[k] = ' ';
					break;
				}
				else if (str[k] == ')') {
					++t;
				}
			}
			wcode[l] = t;
			i = j + 1;
			++l;
		}

		for (int i = 0; i < n; ++i) {
			cout << wcode[i] << (i < n - 1 ? ' ' : '\n');
		}

		--cases;
	}
	return 0;
}