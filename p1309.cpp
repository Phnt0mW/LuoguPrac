#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

queue<int>q1, q2;
struct player {
	int uid, pts, lvl;
} a[N], b[N];
bool cmp ( player a, player b ) {
	if ( a.pts == b.pts ) return a.uid < b.uid;
	else return a.pts > b.pts;
}
int n, r, q;
int main() {
	cin >> n >> r >> q;
	int n2 = 2 * n;

	for ( int i = 0; i < n2; i++ ) {
		cin >> a[i].pts;
	}

	for ( int i = 0; i < n2; i++ ) {
		cin >> a[i].lvl;
		a[i].uid = i ;
	}

	sort ( a, a + n2, cmp );

	for ( int i = 0; i < r; i++ ) {
		for ( int i = 0; i < n; i++ ) {
			int jj = a[i * 2].lvl > a[i * 2 + 1].lvl;
			a[i * 2].pts += jj;
			a[i * 2 + 1].pts += !jj;

			if ( jj > 0 ) {
				q1.push ( i * 2 );
				q2.push ( ( i * 2 + 1 ) );
			} else {
				q2.push ( i * 2 );
				q1.push ( ( i * 2 + 1 ) );
			}
		}

		for ( int i = 0; i < n2; i++ ) {
			if ( q1.empty() ) {
				b[i] = a[q2.front()];
				q2.pop();
			}

			if ( q2.empty() ) {
				b[i] = a[q1.front()];
				q1.pop();
			} else {
				if ( cmp ( a[q1.front()], a[q2.front() ] ) ) {
					b[i] = a[q1.front()];
					q1.pop();
				} else {
					b[i] = a[q2.front()];
					q2.pop();
				}
			}
		}

		memcpy ( a, b, sizeof b );
	}

	cout << a[q - 1].uid;
}
