#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<string.h>

using namespace std;
using ll = long long;
const int N = 5e4+10;

int n, x, y, xx, yy;
int p[8][2];
double l[8];
double maxn = -1;
double dist ( int * a, int * b )
{
	return sqrt ( ( a[0] - b[0] ) * ( a[0] - b[0] ) + ( a[1] - b[1] ) * ( a[1] - b[1] ) ) ;
}

double cal ( int idn )
{
	int min1 = min ( abs ( p[idn][0] - x ), abs ( p[idn][0] - xx ) );
	int min2 = min ( abs ( p[idn][1] - y ), abs ( p[idn][1] - yy ) );
	int min3 = min ( min1, min2 );
	double mind = min3;

	for ( int i = 1; i <= n; i++ ) {
		if ( l[i] ) {
			if ( dist ( p[idn], p[i] ) <= l[i] ) {
				return -1;

			} else
				if ( dist ( p[idn], p[i] ) - l[i] < mind ) {
					mind = dist ( p[idn], p[i] ) - l[i];
				}
		}
	}

	return mind;
}

void dfs ( int num, double s )
{
	if ( num > n ) {
		if ( s > maxn ) {
			maxn = s;
		}

		return;
	}

	for ( int i = 1; i <= n; i++ ) {
		if ( l[i] == 0 ) {
			l[i] = cal ( i );
			dfs ( num + 1, l[i] == -1 ? s : s +3.1415926* l[i]*l[i] );
			l[i] = 0;
		}
	}
}

int main()
{
	cin >> n;
	cin >> x >> y >> xx >> yy;

	for ( int i = 1; i <= n; i++ ) {
		cin >> p[i][0] >> p[i][1];
	}

	memset ( l, 0, sizeof l );
	dfs ( 1, 0 );
	double sq = abs ( x - xx ) * abs ( y - yy );
	double ans = sq - maxn;
	ans += 0.5;
	int op = ans;
	cout << op ;
}
