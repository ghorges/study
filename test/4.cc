#include <bits/stdc++.h>
#define ll long long
using namespace std;

char data[6][6];
int getData[6][6];
int getMux(int i, int j) {
	int num[4];
	if (i - 1 >= 0) {
		num[0] = getData[i - 1][j];
	}
	if (i + 1 < 6) {
		num[1] = getData[i + 1][j];
	}
	if (j - 1 >= 0) {
		num[2] = getData[i][j - 1];
	}
	if (j + 1 < 6) {
		num[3] = getData[i][j + 1];
	}
	sort(num, num + 4);
	return num[3] - 1;
}
void ddfs(int i, int j) {
	if (i < 0 || i >= 6 || j < 0 || j >= 6) {
		return;
	}
	if ((i - 1) >= 0 && data[i-1][j] == '#' && getData[i-1][j] == 0) {
		getData[i - 1][j] = getMux(i - 1, j);
		ddfs(i - 1, j);
	}
	if ((i + 1) < 6 && data[i+1][j] == '#' && getData[i+1][j] == 0) {
		getData[i + 1][j] = getMux(i + 1, j);
		ddfs(i + 1, j);
	}
	if ((j - 1) >= 0 && data[i][j - 1] == '#' && getData[i][j - 1] == 0) {
		getData[i][j - 1] = getMux(i, j - 1);
		ddfs(i, j - 1);
	}
	if ((j + 1) < 6 && data[i][j + 1] == '#' && getData[i][j + 1] == 0) {
		getData[i][j + 1] = getMux(i, j + 1);
		ddfs(i, j + 1);
	}
}

void dfs() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (data[i][j] == '#') {
				getData[i][j] = 6;
				ddfs(i, j);			
			}
		}
	}
}

int main() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> data[i][j];
		}
	}
	ll num = 1;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (getData[i][j] != 0) {
				num *= getData[i][j];
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << getData[i][j] << " ";
		}
		cout << endl;
	}
	cout << num % 1000000009 << endl;
	return 0;
}
