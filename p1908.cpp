#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
using ll = long long ;

//洛谷p1908 归并排序的模版题
ll cnt = 0;
void msort ( vector<int>&a, int l, int r ) {
	vector<int>t;
	int mid = ( l + r ) / 2;
	int i = l, j = mid + 1;

	if ( l >= r ) return ;
	else {
		msort ( a, l, mid );
		msort ( a, mid + 1, r );
	}

	while ( i <= mid && j <= r ) {
		if ( a[i] > a[j] ) {
			t.push_back ( a[j++] );
			cnt += mid - i + 1;
		} else {
			t.push_back ( a[i++] );
		}
	}

	while ( i <= mid ) {
		t.push_back ( ( a[i++] ) );
	}

	while ( j <= r ) {
		t.push_back ( ( a[j++] ) );
	}

	for ( int i = l, k = 0; i <= r; i++, k++ ) {
		a[i] = t[k];
	}

	return;
}
int main() {
	int n;
	cin >> n ;
	vector<int>a ( n + 1 );

	for ( int i = 1; i <= n; i++ ) cin >> a[i];

	msort ( a, 1, n );
	cout << cnt;
}
