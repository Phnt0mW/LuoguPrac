#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll mp[26][26];
bool jud[26][26];
int main()
{
	int x, y, x1, y1;
	cin >> x >> y >> x1 >> y1;
	x++;
	y++;
	x1++;
	y1++;
	x++;
	y++;
	x1++;
	y1++;
	memset ( jud, 0, sizeof jud );
	memset ( mp, 0, sizeof mp );
	jud[x1][y1] = 1;
	jud[x1 + 2][y1 + 1] = 1;
	jud[x1 + 2][y1 - 1] = 1;
	jud[x1 - 2][y1 + 1] = 1;
	jud[x1 - 2][y1 - 1] = 1;
	jud[x1 + 1][y1 + 2] = 1;
	jud[x1 + 1][y1 - 2] = 1;
	jud[x1 - 1][y1 + 2] = 1;
	jud[x1 - 1][y1 - 2] = 1;
	mp[1][2] = 1;

	for ( int i = 2; i <= x; i++ ) {
		for ( int j = 2; j <= y; j++ ) {
			if ( !jud[i][j] )
			{ mp[i][j] = mp[i - 1][j] + mp[i][j-1]; }
		}
	}
	cout<<mp[x][y];
}
