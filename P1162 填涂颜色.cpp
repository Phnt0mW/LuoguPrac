#include<stdio.h>
#include<iostream>
#include<queue>
#include<string>
#include<cmath>
#include<algorithm>
#include<string.h>
using namespace std;
using ll = long long;

int m[35][35];
int n;
int d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int vis[901];
queue<pair<int, int>>q;
void bfs ( int mark, int x, int y )
{
	q.push ( make_pair ( x, y ) );
	while ( q.size() ) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if ( m[x][y] ) {
			continue;
		}

		if ( x < 1 || y < 1 || x>n || y > n ) {
			vis[mark] = 1;
			continue;
		}

		m[x][y] = mark;

		for ( int i = 0; i < 4; i++ ) {
			q.push ( make_pair ( x + d[i][0], y + d[i][1] ) );
		}
	}
}

int main()
{
	cin >> n;
	memset ( m, 0, sizeof m );
	memset ( vis, 0, sizeof vis );

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			cin >> m[i][j];
		}
	}

	int cnt = 2;

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			if ( m[i][j] == 0 ) {
				bfs ( cnt++, i, j );
			}
		}
	}

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			if ( m[i][j] == 1 ) {
				cout << 1 << ' ';

			} else
				if ( m[i][j] && vis[m[i][j]] == 1 ) {
					cout << 0 << ' ';

				} else {
					cout << 2 << ' ';
				}
		}

		cout << endl;
	}
}
