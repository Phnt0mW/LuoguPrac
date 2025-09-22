#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int n;
int a[N][N], b[N][N];
int main()

{
	cin >> n;
	memset ( a, 0, sizeof a );
	memset ( b, 0, sizeof b );

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= i; j++ ) {
			cin >> a[i][j];
		}
	}

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= i; j++ ) {
			b[i][j] = max ( b[i - 1][j], b[i - 1][j - 1] ) + a[i][j];
		}
	}

	int maxn = 0;

	for ( int i = 1; i <= n; i++ ) {
		if ( b[n][i] > maxn ) {
			maxn = b[n][i];
		}
	}
	cout<<maxn;
}
