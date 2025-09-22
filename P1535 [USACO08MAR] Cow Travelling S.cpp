#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int xd, yd, xx, yy;
char a[105][105];
int b[105][105][20];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs ( int x, int y, int ti )
{
	if ( b[x][y][ti] ) {
		return b[x][y][ti];
	}

	if ( ti > t ) {
		return 0;
	}

	if ( ti == t && x == xd && y == yd	) {
		return 1;
	}

	if ( abs ( x - xd ) + abs ( y - yd ) > t - ti ) {
		return 0;
	}

	int ans = 0;

	for ( int i = 0; i < 4; i++ ) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if ( nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '*' ) {
			continue;
		}

		ans += dfs ( nx, ny, ti + 1 );
	}

	b[x][y][ti] = ans;
	return ans;
}

int main()
{
	memset ( b, 0, sizeof b );
	cin >> n >> m >> t;

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= m; j++ ) {
			cin >> a[i][j];
		}
	}

	cin >> xx >> yy >> xd >> yd;
	cout << dfs ( xx, yy, 0 );
}
