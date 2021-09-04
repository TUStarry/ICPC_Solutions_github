#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	while (t--) {
		int ma[250][250];
		char size;
		int n;
		cin >> size >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ma[i][j] = 0;

        string str[n];
		for (int i = 0; i < n; i++)
			cin >> str[i];

		int num;
		cin >> num;
		string n1, n2;
		int c1, c2;
		for (int i = 0; i < num; i++) {
			cin >> n1 >> n2;
			for (int j = 0; j < n; j++) {
				if (str[j] == n1)
					c1 = j;
				else if (str[j] == n2)
					c2 = j;
			}
			if (size == 'D')
				ma[c1][c2] = 1;
			else if (size == 'U') {
				ma[c1][c2] = 1;
				ma[c2][c1] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << ma[i][j] << ' ';
			cout << endl;
		}
		if (size == 'D') {			
			for (int k = 0; k < n; k++) {
				int c1 = 0, c2 = 0;
				cout << str[k];
				for (int i = 0; i < n; i++) {
					if (ma[k][i] == 1)
						c1++;
					if (ma[i][k] == 1)
						c2++;
				}
				if (c1 || c2) {
					cout << ": " << c1 << ' ' << c2 << ' ' << c1 + c2;
				}
				cout << endl;
			}
		}
		else if (size == 'U') {
			for (int k = 0; k < n; k++) {
				int c1 = 0, c2 = 0;
				cout << str[k];
				for (int i = 0; i < n; i++) {
					if (ma[k][i] == 1)
						c1++;
				}
				if (c1) {
					cout << ": " << c1;
				}
				cout << endl;
			}
		}
	}
	return 0;
}
