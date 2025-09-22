#include<stdio.h>
#include<iostream>
#include<queue>
#include<string>
#include<cmath>
#include<algorithm>
#include<string.h>
using namespace std;
using ll = long long;

#include <iostream>
#include <bitset>
using namespace std;

int main() {
	unsigned long long n, k;
	cin >> n >> k;
	
	// 计算格雷码值
	unsigned long long gray = k ^ (k >> 1);
	
	// 输出n位二进制字符串
	cout << bitset<64>(gray).to_string().substr(64 - n) << endl;
	
	return 0;
}
