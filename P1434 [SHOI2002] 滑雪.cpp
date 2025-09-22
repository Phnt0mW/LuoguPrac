#include <bits/stdc++.h>
using namespace std;

int r, c;
int h[105][105];
int dist[105][105];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dfs ( int x, int y )
{
	if ( dist[x][y] != -1 ) {
		return dist[x][y];
	}

	for ( int i = 0; i < 4; i++ ) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if ( nx < 1 || nx > r || ny < 1||ny>c || h[nx][ny] >= h[x][y] ) {
			continue;
		}

		dist[x][y] = max ( dfs ( nx, ny ) +1, dist[x][y] );
	}

	if ( dist[x][y] == -1 ) {
		dist[x][y] = 0;
	}

	return	dist[x][y];
}

int main()
{
	cin >> r >> c;

	for ( int i = 1; i <= r; i++ ) {
		for ( int j = 1; j <= c; j++ ) {
			cin >> h[i][j];
		}
	}

	memset ( dist, -1, sizeof dist );

	for ( int i = 1; i <= r; i++ ) {
		for ( int j = 1; j <= c; j++ ) {
			if ( dist[i][j] == -1 ) {
				dfs ( i, j );
			}
		}
	}

	int maxn = 0;

	for ( int i = 1; i <= r; i++ ) {
		for ( int j = 1; j <= c; j++ ) {
			if ( dist[i][j] > maxn ) {
				maxn = dist[i][j];
			}
		}
	}

	cout << maxn + 1;
}
