#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<string.h>

using namespace std;
using ll = long long;
const int N = 5e4+10;

int n, c;
ll a[50], b[50];
ll ans = -1;

void dfs ( int x, ll v )
	{
	if ( v > c )
		{
		return;
		}

	if ( v + b[x - 1] < c )
		{
		if ( v + b[x - 1] > ans )
			{ ans = v + b[x - 1]; }

		return ;
		}

	ans = max ( ans, v );

	for ( int i = 1; i < x; i++ )
		{
		dfs ( i, v + a[i] );
		}

	return ;
	}

int main()
	{
	cin >> n >> c;
	b[0] = 0;
	memset ( a, 0, sizeof a );

	for ( int i = 1; i <= n; i++ )
		{
		cin >> a[i];
		}

	sort ( a + 1, a + 1 + n );

	for ( int i = 1; i <= n; i++ )
		{
		b[i] = b[i - 1] + a[i];
		}

	dfs ( n + 1, 0 );
	cout << ans;
	}
