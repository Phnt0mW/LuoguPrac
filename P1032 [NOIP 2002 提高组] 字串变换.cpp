#include<bits/stdc++.h>
using namespace std;

const int N = 20;
int n = 0;
string s, t, a[N], b[N];
map<string, bool>vis;
void bfs()
{
	queue<pair<string, int>>q;
	q.push ( make_pair ( s, 0 ) );
	while ( q.size() ) {
		string now = q.front().first;
		int st = q.front().second;
		q.pop();
		if ( now == t ) { cout << st; return; }

		if ( st >= 10 ) continue;
		string tmp = now;

		for ( int i = 0; i < n; i++ ) {
			now = tmp;

			while ( 1 ) {
				int p = now.find ( a[i] );

				if ( p == -1 ) {
					break;
				}

				if ( p != -1 ) {
					string nn = tmp;
					nn.replace ( p, a[i].size(), b[i] );
					now[p] = ' ';

					if ( vis[nn] == 0 ) {
						vis[nn] = 1;
						q.push ( make_pair (nn, st + 1 ) );
					}
				}
			}
		}
	}

	cout << "NO ANSWER!";
}

int main()
{
	cin >> s >> t;

	while ( cin >> a[n] >> b[n] ) {
		n++;
	}

	if ( n == 0 && s != t ) {
		cout << "NO ANSWER!";
	}

	bfs();
	return 0;
}
