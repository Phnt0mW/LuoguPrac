#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<climits>

using namespace std;
using ll = long long ;

ll a[200005][2], b[200005][2];
ll n, m, s;
ll sum	= 0;
bool CalVal ( ll w ) {
	ll sum1[200005], sum2[200005];
	memset ( sum1, 0, sizeof sum1 );
	memset ( sum2, 0, sizeof sum2 );
	
	for ( int i = 1; i <= n; i++ ) {
		sum1[i] = sum1[i - 1] + ( ( a[i][0] >= w ) ? 1 : 0 ) * a[i][1];
		sum2[i] = sum2[i - 1] + ( ( a[i][0] >= w ) ? 1 : 0 );
	}
	
	sum = 0;
	
	for ( int i = 1; i <= m; i++ ) {
		ll l = b[i][0], r = b[i][1];
		ll tmp1 = ( sum2[r] - sum2[l - 1] );
		ll tmp2 = ( sum1[r] - sum1[l - 1] );
		sum += tmp1 * tmp2;
	}
	
	if ( sum > s ) return 1;
	else return 0;
}
int main() {
	cin >> n >> m >> s;
	ll maxw = 0;
	
	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i][0] >> a[i][1];
		
		if ( a[i][0] > maxw ) maxw = a[i][0];
	}
	
	for ( int i = 1; i <= m; i++ ) {
		cin >> b[i][0] >> b[i][1];
	}
	
	ll l = 0, r = maxw;
	ll ans = LLONG_MAX;
	
	while ( l <= r ) {
		ll mid = ( l + r ) / 2;
		
		if ( CalVal ( mid ) ) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
		
		ans = min ( ans, llabs ( ( s - sum ) ) );
	}
	
	cout << ans;
}
