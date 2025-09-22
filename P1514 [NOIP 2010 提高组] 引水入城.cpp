#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, m;
int l[N][N], h[N][N], r[N][N], vis[N][N];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs ( int x, int y )
{
	vis[x][y] = 1;

	for ( int i = 0; i < 4; i++ ) {
		int nx = x + d[i][0];
		int ny = y + d[i][1];

		if ( nx < 1 || nx > n || ny < 1 || ny > m ) {
			continue;
		}

		if ( !vis[nx][ny] && h[x][y] > h[nx][ny] ) {
			dfs ( nx, ny );
		}

		// 仅更新可到达的邻点范围
		if ( h[x][y] > h[nx][ny] ) {
			l[x][y] = min ( l[x][y], l[nx][ny] );
			r[x][y] = max ( r[x][y], r[nx][ny] );
		}
	}
}

int main()
{
	cin >> n >> m;
	memset ( l, 0x3f, sizeof ( l ) );
	memset ( r, 0, sizeof ( r ) );
	memset ( vis, 0, sizeof ( vis ) );

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= m; j++ ) {
			cin >> h[i][j];

			if ( i == n ) {
				l[i][j] = r[i][j] = j;
			}
		}
	}

	for ( int j = 1; j <= m; j++ ) {
		if ( !vis[1][j] ) {
			dfs ( 1, j );
		}
	}

	int unvis = 0;

	for ( int j = 1; j <= m; j++ ) {
		if ( !vis[n][j] ) {
			unvis++;
		}
	}

	if ( unvis ) {
		cout << 0 << endl << unvis;
		return 0;
	}

	int current = 1;
	int max_reach = 0;
	int ans = 0;

	while ( current <= m ) {
		for ( int j = 1; j <= m; j++ ) {
			if ( l[1][j] <= current ) {
				max_reach = max ( max_reach, r[1][j] );
			}
		}

		current = max_reach + 1;
		ans++;
	}

	cout << 1 << endl << ans;
	return 0;
}
