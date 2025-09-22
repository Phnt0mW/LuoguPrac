#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 1e9;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int m, n;
int board[105][105]; // -1 无色，0 红，1 黄
int dist[105][105][2][2]; // x, y, magicUsed, color

struct Node {
	int x, y, cost;
	int magicUsed;
	int color;
	
	Node(int x_, int y_, int cost_, int magicUsed_, int color_)
	: x(x_), y(y_), cost(cost_), magicUsed(magicUsed_), color(color_) {}
	
	bool operator>(const Node &rhs) const {
		return cost > rhs.cost;
	}
};

int main() {
	cin >> m >> n;
	memset(board, -1, sizeof(board));
	for (int i = 0; i < 105; ++i)
		for (int j = 0; j < 105; ++j)
			for (int k = 0; k < 2; ++k)
				for (int c = 0; c < 2; ++c)
					dist[i][j][k][c] = INF;
	
	for (int i = 0; i < n; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		board[x][y] = c;
	}
	
	int startColor = board[1][1];
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	dist[1][1][0][startColor] = 0;
	pq.emplace(1, 1, 0, 0, startColor);
	
	while (!pq.empty()) {
		Node curr = pq.top(); pq.pop();
		int x = curr.x, y = curr.y, cost = curr.cost;
		int magic = curr.magicUsed, color = curr.color;
		
		if (x == m && y == m) {
			cout << cost << endl;
			return 0;
		}
		
		if (cost > dist[x][y][magic][color]) continue;
		
		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 1 || nx > m || ny < 1 || ny > m) continue;
			
			int nextCell = board[nx][ny];
			if (nextCell != -1) {
				int ncost = cost + (nextCell != color);
				if (ncost < dist[nx][ny][0][nextCell]) {
					dist[nx][ny][0][nextCell] = ncost;
					pq.emplace(nx, ny, ncost, 0, nextCell);
				}
			} else if (magic == 0) {
				int ncost = cost + 2; // 用魔法染色
				if (ncost < dist[nx][ny][1][color]) {
					dist[nx][ny][1][color] = ncost;
					pq.emplace(nx, ny, ncost, 1, color);
				}
			}
		}
	}
	
	cout << -1 << endl;
	return 0;
}

