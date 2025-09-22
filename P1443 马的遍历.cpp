#include<stdio.h>
#include<iostream>
#include<queue>
#include<string>
#include<cmath>
#include<algorithm>
#include<string.h>
using namespace std;
using ll = long long;

int n, m, x, y;
int a[405][405];
int d[8][2] = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, -1}, {-2, 1}};
queue < pair<pair<int, int >, int >> q;
void bfs ( )
{
	q.push ( make_pair ( make_pair ( x, y ), 0 ) );
	while ( q.size() ) {
		int xx = q.front().first.first;
		int yy = q.front().first.second;
		int st = q.front().second;
		q.pop();
		if ( xx>n || xx < 1 || yy > m || yy < 1 || a[xx][yy] != -1 ) continue;
		a[xx][yy] = st;

		for ( int i = 0; i < 8; i++ ) {
			q.push ( make_pair ( make_pair ( xx + d[i][0], yy + d[i][1] ), st + 1 ) );
		}
	}
}

int main()
{
	memset ( a, -1, sizeof a );
	cin >> n >> m >> x >> y;
	bfs();

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= m; j++ ) {
			printf ( "%d ", a[i][j] );
		}

		printf ( "\n" );
	}
}
