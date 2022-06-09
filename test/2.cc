#include <bits/stdc++.h>

using namespace std;

map<int, int> data;
int n;

int count(int a, int b) {
	if (a < b) {
		return a * 10 + b;
	}
	return b * 10 + a;
}

int getNum(int a, int b, int c) {
	int num[3];
	num[0] = a;
	num[1] = b;
	num[2] = c;
	sort(num, num + 3);
	return 10000*num[0] + 100*num[1] + num[2];
}

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a,b,c,d,e,f;
		cin >> a >> b >> c >> d >> e >> f;
		int sum1 = count(a, b);
		int t = getNum(count(a, b), count(c, d), count(e, f));
		cout << "t is " << t << endl;
		data[t]++;
	}
	int num[1005];
	int j = 0;
	for (auto &i : data) {
		num[j++] = i.second;
	}
	sort(num, num + n, cmp);
	cout << j << endl;
	for (int i = 0; i < j; i++) {
		cout << num[i];
		if (i == j - 1) {
			cout << endl;
		} else {
			cout << " ";
		}
	}
	return 0;
}
