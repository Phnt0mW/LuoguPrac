#include<bits/stdc++.h>
using namespace std;


//#define ll long long
//typedef long long ll;
using ll = long long;

int countDigitTwo(int n) {
	int count = 0;
	// 处理负数情况，将其转换为正数（可选）
	n = (n < 0) ? -n : n;

	while (n > 0) {
		if (n % 10 == 2) {
			count++;
		}
		n /= 10;
	}
	return count;
}
int main() {
	int l, r;
	cin >> l >> r;
	ll sum = 0;
	for (int i = l; i <= r; i++) {
		int tmp = i;
		sum += countDigitTwo( tmp);


	}
	cout << sum;

}
