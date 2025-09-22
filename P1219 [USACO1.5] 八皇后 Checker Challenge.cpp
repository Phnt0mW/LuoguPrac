#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<string.h>

using namespace std;
using ll = long long;
const int N = 5e4 + 10;

int n;
int ans[20], sum = 0;
int lie[20], dui1[30], dui2[30];

void dfs ( int x ) {
	if ( x > n ) {
		sum++;

		if ( sum <= 3 ) {
			for ( int i = 1; i <= n; i++ ) {
				cout << ans[i] << ' ';
			}

			cout << endl;
		}

		return;
	}

	for ( int i = 1; i <= n; i++ ) {
		if ( !lie[i] && !dui1[n + i - x] && !dui2[x + i] ) {
			lie[i] = 1, dui1[n + i - x] = 1, dui2[x + i] = 1;
			ans[x] = i;
			dfs ( x + 1 );
			lie[i] = 0, dui1[n + i - x] = 0, dui2[x + i] = 0;
		}
	}

	return;
}
int main() {
	cin >> n;
	memset ( ans, 0, sizeof ans );
	memset ( dui1, 0, sizeof dui1 );
	memset ( dui2, 0, sizeof dui2 );
	dfs ( 1 );
	cout << sum;
	return 0;
}
