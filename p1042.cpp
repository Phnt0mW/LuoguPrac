#include<bits/stdc++.h>
using namespace std;

const int maxn = 100000;

int p11[maxn][2], p21[maxn][2];
int main() {
	char c;
	int cnt1 = 0, cnt2 = 0;
	while (cin >> c) {
		if (c == '\n')continue;
		if (c == 'E')break;
		if (c == 'W') {
			p11[cnt1][0] += 1;
			p21[cnt2][0] += 1;
		}
		if (c == 'L') {
			p11[cnt1][1] += 1;
			p21[cnt2][1] += 1;
		}
		if (max(p11[cnt1][0], p11[cnt1][1]) >= 11 && fabs(p11[cnt1][0] - p11[cnt1][1]) >= 2) {
			cnt1++;
		}
		if (max(p21[cnt2][0], p21[cnt2][1]) >= 21 && fabs(p21[cnt2][0] - p21[cnt2][1]) >= 2) {
			cnt2++;
		}

	}
	for (int i = 0; i <= cnt1; i++) {
		printf("%d:%d\n", p11[i][0], p11[i][1]);

	}
	printf("\n");
	for (int i = 0; i <= cnt2; i++) {
		printf("%d:%d\n", p21[i][0], p21[i][1]);

	}

}
