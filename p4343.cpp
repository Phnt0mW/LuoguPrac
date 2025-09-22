#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<climits>

using namespace std;
using ll = long long;
const int N = 1e6 + 10;

int l, k, a[N];
int check ( ll n ) {
	ll cnt = 0, cnt1 = 0;

	for ( int i = 1; i <= l; i++ ) {
		if ( cnt + a[i] >= 0 )
			cnt += a[i];
		else cnt = 0;

		if ( cnt >= n ) {
			cnt = 0;
			cnt1++;
		}
	}

	if ( cnt1 > k ) return 1;
	else if ( cnt1 == k ) return 0;
	else return -1;
}
int main() {
	cin >> l >> k;
	ll sum = 0;

	for ( int i = 1; i <= l; i++ ) {
		cin >> a[i];

		if ( a[i] > 0 ) sum += a[i];
	}

	ll le = 1, ri = sum;
	ll ans1 = -1, ans2 = -1;

	while ( le < ri ) {
		if ( le == ri || ri - le == 1 ) {
			if ( !check ( le ) ) ans1 = le;
			else if ( !check ( ri ) ) {
				ans1 = ri;
			}

			break;
		}

		ll mid = ( le + ri ) / 2;
		int jud = check ( mid );

		if ( jud == 1 ) {
			le = mid;
		} else if ( jud == -1 ) {
			ri = mid;
		} else {
			ri = mid;
		}
	}

	le = 1, ri = sum;

	while ( le < ri ) {
		if ( le == ri || ri - le == 1 ) {
			if ( !check ( ri ) ) ans2 = ri;
			else if ( !check ( le ) ) {
				ans2 = le;
			}

			break;
		}

		ll mid = ( le + ri ) / 2;
		int jud = check ( mid );

		if ( jud == 1 ) {
			le = mid;
		} else if ( jud == -1 ) {
			ri = mid;
		} else {
			le = mid;
		}
	}

	if ( ans1 == -1 && ans2 == -1 ) {
		cout << -1;
	} else cout << ans1 << ' ' << ans2;
}
