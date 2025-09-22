#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

//二分答案加dfs 但是应该注意二分和dfs时的逻辑严谨性 注意细节的地方 引以为戒。
using namespace std;

const int N = 1e6;
using ll = long long ;

int n, m;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int vis[1005][1005];
bool check ( const vector<vector<int>>&a, int x, int y, int d ) {
	queue<pair<int, int>>q;
	q.push ( make_pair ( x, y ) );
	vis[x][y] = 1;
	
	while ( !q.empty() ) {
		int nx = q.front().first, ny = q.front().second;
		q.pop();
		
		for ( int i = 0; i < 4; i++ ) {
			int dx = nx + dir[i][0], dy = ny + dir[i][1];
			
			if ( dx < 1 || dx > n || dy < 1 || dy > m || vis[dx][dy] || a[dx][dy] > d ) continue;
			
			vis[dx][dy] = 1;
			
			if ( dx == n ) return 1;
			else q.push ( make_pair ( dx, dy ) );
		}
	}
	return 0;
}
int main() {
	cin >> n >> m;
	vector<vector<int>>a ( n + 1, vector<int> ( m + 1, 0 ) );
	int maxn = 0;
	
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= m; j++ ) {
			cin >> a[i][j];
			
			if ( a[i][j] > maxn ) maxn = a[i][j];
		}
	}
	int l = 0, r = maxn;
	int ans = -1;
	
	while ( l <= r ) {
//	cout << l << ' ' << r << endl;
		int mid = ( l + r ) / 2;
		memset ( vis, 0, sizeof vis );
		
		if ( check ( a, 1, 1, mid ) ) {
			ans = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans ;
}
