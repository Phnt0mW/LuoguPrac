#include<bits/stdc++.h>
using namespace std;


struct figure {
	int face;
	string name;

} f[100000 + 7];
int main() {
//	cout<<"hello"<<endl;
	int n, m, cnt = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> f[i].face >> f[i].name;
//		cout<<f[i].face<<f[i].name<<endl;
	}
	for (int i = 0; i < m; i++) {
		int ai, si;
		cin >> ai >> si;
		int tmp = ((ai ^ f[cnt].face) == 1 ? 1 : -1) * si;
		while (cnt + tmp > n) {
			tmp -= (n - cnt + 1);
			cnt = 1;
		}
		while (cnt + tmp < 1) {
			tmp += (cnt - 1 + 1);
			cnt = n;
		}
		cnt += tmp;
		//cout<<tmp<<endl;
//		cout<<cnt<<endl;
	}
	cout << f[cnt].name;
	return 0;



}
