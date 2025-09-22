#include<stdio.h>
#include<iostream>

#include<cmath>
#include<climits>
#include<iomanip>

using namespace std;
using ll = long long;
const int N = 1e5 + 10;

struct point {
	double x, y;
} p[2 * N];
int cmpx(const void* x, const void* y) {
	point* p1 = (point*)x;
	point* p2 = (point*)y;
	
	return (p1->x - p2->x) > 0 ? 1 : -1;
}
int cmpy(const void* x, const void* y) {
	point* p1 = (point*)x;
	point* p2 = (point*)y;
	
	return (p1->y - p2->y) > 0 ? 1 : -1;
}
double dist(point x, point y) {
	return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}
double bl(point p[], int n) {
	double mind = LLONG_MAX;
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double tmp = dist(p[i], p[j]);
			
			if (tmp < mind) mind = tmp;
		}
	}
	
	return mind;
}
double stmin(point p[], int n, double m) {
	double mind = m;
	qsort(p, n, sizeof(point), cmpy);
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n && fabs(p[i].y - p[j].y) < m; j++) {
			double tmp = dist(p[i], p[j]);
			
			if (tmp < mind) mind = tmp;
		}
	}
	
	return mind;
}
double BiSear(point p[], int l, int r) {
	if (r - l <= 2) return bl(p + l, r - l + 1);
	
	int mid = (l + r) / 2;
	point midp = p[mid];
	double dl = BiSear(p, l, mid);
	double dr = BiSear(p, mid + 1, r);
	double md = min(dl, dr);
	point st[2 * N];
	int j = 0;
	
	for (int i = l; i <= r; i++) {
		if (fabs(p[i].x - midp.x) < md) {
			st[j++] = p[i];
		}
	}
	
	double md1 = stmin(st, j, md);
	return min(md, md1);
}
int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	
	qsort(p, n, sizeof(point), cmpx);
	double ans = BiSear(p, 0, n - 1);
	cout << fixed << setprecision(4) << ans;
}
