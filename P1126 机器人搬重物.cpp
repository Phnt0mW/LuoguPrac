#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 51
#define MAX_M 51
#define INF 0x3f3f3f3f

// 方向：东、南、西、北
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char dir_char[4] = {'E', 'S', 'W', 'N'};

// 状态结构体
typedef struct {
	int row, col;     // 坐标
	int dir;          // 方向
	int step;         // 连续移动步数
	int time;         // 耗时
} State;

// 队列结构体
typedef struct {
	State data[MAX_N * MAX_M * 4 * 4];  // 队列存储状态
	int front, rear;                    // 队头队尾指针
} Queue;

// 初始化队列
void initQueue ( Queue *q )
{
	q->front = q->rear = 0;
}

// 入队
void enqueue ( Queue *q, State state )
{
	q->data[q->rear++] = state;
}

// 出队
State dequeue ( Queue *q )
{
	return q->data[q->front++];
}

// 判断队列是否为空
int isEmpty ( Queue *q )
{
	return q->front == q->rear;
}

// 方向转换：左转
int turnLeft ( int dir )
{
	return ( dir + 3 ) % 4;
}

// 方向转换：右转
int turnRight ( int dir )
{
	return ( dir + 1 ) % 4;
}

int main()
{
	int n, m;
	scanf ( "%d %d", &n, &m );
	// 存储地图，1表示障碍，0表示可行
	int map[MAX_N][MAX_M];

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= m; j++ ) {
			scanf ( "%d", &map[i][j] );
		}
	}

	// 起点和终点
	int start_row, start_col, end_row, end_col;
	char start_dir;
	scanf ( "%d %d %d %d %c", &start_row, &start_col, &end_row, &end_col, &start_dir );
	// 将起始方向转换为数字
	int dir;

	for ( dir = 0; dir < 4; dir++ ) {
		if ( dir_char[dir] == start_dir ) {
			break;
		}
	}

	// 访问标记：记录到达(row, col, dir)时的最小连续移动步数
	int visited[MAX_N][MAX_M][4];

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= m; j++ ) {
			for ( int d = 0; d < 4; d++ ) {
				visited[i][j][d] = INF;
			}
		}
	}

	// 初始化队列
	Queue q;
	initQueue ( &q );
	// 初始状态入队
	State start;
	start.row = start_row;
	start.col = start_col;
	start.dir = dir;
	start.step = 0;
	start.time = 0;
	enqueue ( &q, start );
	visited[start_row][start_col][dir] = 0;

	// BFS搜索
	while ( !isEmpty ( &q ) ) {
		State curr = dequeue ( &q );

		// 检查是否到达终点
		if ( curr.row == end_row && curr.col == end_col ) {
			printf ( "%d\n", curr.time );
			return 0;
		}

		// 1. 左转操作
		int new_dir = turnLeft ( curr.dir );

		if ( visited[curr.row][curr.col][new_dir] > 0 ) {
			visited[curr.row][curr.col][new_dir] = 0;
			State next;
			next.row = curr.row;
			next.col = curr.col;
			next.dir = new_dir;
			next.step = 0;
			next.time = curr.time + 1;
			enqueue ( &q, next );
		}

		// 2. 右转操作
		new_dir = turnRight ( curr.dir );

		if ( visited[curr.row][curr.col][new_dir] > 0 ) {
			visited[curr.row][curr.col][new_dir] = 0;
			State next;
			next.row = curr.row;
			next.col = curr.col;
			next.dir = new_dir;
			next.step = 0;
			next.time = curr.time + 1;
			enqueue ( &q, next );
		}

		// 3. 向前移动1-3步
		for ( int s = 1; s <= 3; s++ ) {
			int new_row = curr.row;
			int new_col = curr.col;
			int valid = 1;

			// 检查移动s步是否可行
			for ( int i = 1; i <= s; i++ ) {
				new_row += dx[curr.dir];
				new_col += dy[curr.dir];

				// 检查是否出界或遇到障碍
				if ( new_row < 1 || new_row > n || new_col < 1 || new_col > m || map[new_row][new_col] == 1 ) {
					valid = 0;
					break;
				}
			}

			if ( valid ) {
				if ( visited[new_row][new_col][curr.dir] > s ) {
					visited[new_row][new_col][curr.dir] = s;
					State next;
					next.row = new_row;
					next.col = new_col;
					next.dir = curr.dir;
					next.step = s;
					next.time = curr.time + 1;
					enqueue ( &q, next );
				}
			}
		}
	}

	// 无法到达终点
	printf ( "-1\n" );
	return 0;
}
