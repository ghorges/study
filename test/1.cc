#include <iostream>

using namespace std;

int k, n;
int num[105];

int main() {
	cin >> k >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int p = k;
	int count = 0;
	for (int i = 0; i < n; i++) {
		p -= num[i];
		if (p == 0) {
			cout << "paradox" << endl;
			return 0;
		}
		if (p < 0) {
			p += num[i];
			p = num[i] - p;
			count++;
		}
	}	
	cout << p << " " << count << endl;
	return 0;
} 
