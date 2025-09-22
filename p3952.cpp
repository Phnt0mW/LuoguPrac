//时间复杂度，麻烦的模拟题，需要考虑几个因素
#include<bits/stdc++.h>
using namespace std;

struct node {
	int n;
	char name;

} a[101]; //存储每一个f操作的信息

bool vis['z' + 1]; //标记变量的使用

int main() {
	int t;
	for (cin >> t; t--; cout << '\n') {
		memset(vis, 0, sizeof vis);
		int l, w = 0, ans = 0, sum = 0, sum0 = 0;
		bool err = 0;
		stack<int>q;
		string s;
		cin >> l >> s;
		if (s[2] == 'n')                    // 解析预期复杂度
			for (int i = 4; s[i] != ')'; i++)
				w = w * 10 + (s[i] - '0');
		for (int i = 1; i <= l; i++) {
			char opt;
			cin >> opt;
			if (opt == 'F') {
				char nm;
				cin >> nm;
				if (vis[nm] == 1)err = 1;
				else vis[nm] = 1;
				a[i].name = nm;
				string str_x, str_y;
				cin >> str_x >> str_y;
				int x = 0, y = 0;
				for (int j = 0; j < str_x.size(); j++)x = x * 10 + (str_x[j] - '0');
				for (int j = 0; j < str_y.size(); j++)y = y * 10 + (str_y[j] - '0');
				if (str_x == "n" && str_y != "n" || (str_x != "n" && str_y != "n" && x > y))a[i].n = -1; // 无效循环
				else if (str_x == "n")a[i].n = 0; // n到n，复杂度为常量
				else if (str_y == "n")a[i].n = 1; // 常量到n，复杂度为线性
				else a[i].n = 0;              // 常量到常量，复杂度为常量
				if (a[i].n == -1)sum0++;      // 无效循环计数
				if (a[i].n == 1)sum++;        // 线性循环计数
				q.push(i);

			} else {
				if (q.empty()) {
					err = 1;
					continue;
				}
				if (!sum0) ans = max(ans, sum);
				if (a[q.top()].n == -1)sum0--;
				if (a[q.top()].n == 1)sum--;
				vis[a[q.top()].name] = 0;
				q.pop();
			}
		}
		if (!q.empty())err = 1;
		if (err)cout << "ERR";
		else cout << ((w == ans) ? "Yes" : "No");


	}
	return 0;
}


