#include<iostream>
#include<deque>
#include<vector>
#include<queue>

using namespace std;
// 우 하 좌 상
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

int N, K, L;

int apple[100][100];
int snakeMap[100][100];
queue<pair<int, char>> dirInfo;

int main() {
	cin >> N >> K;

	while (K--) {
		int y, x;
		cin >> y >> x;
		apple[y - 1][x - 1] = 1;
	}
	cin >> L;
	while (L--) {
		int time;
		char dir;
		cin >> time >> dir;
		dirInfo.push({ time,dir });
	}
	int dir = 0;
	deque<pair<int, int>> snake;
	snake.push_front({ 0,0 });
	int time = 0;
	while (!snake.empty()) {
		time++;
		int y = snake.front().first;
		int x = snake.front().second;
		snakeMap[y][x] = 1;

		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// 몸통에 박거나 벽에 박으면 관둔다.
		if (!(0 <= ny && ny < N && 0 <= nx && nx < N) || snakeMap[ny][nx] == 1) {
			break;
		}
		snakeMap[ny][nx] = 1;
		snake.push_front({ ny,nx });
		if (apple[ny][nx] == 1) {
			// 사과가 있는 경우
			apple[ny][nx] = 0;
		}
		else {
			pair<int, int> tail = snake.back();
			snake.pop_back();
			snakeMap[tail.first][tail.second] = 0;
		}
		if (!dirInfo.empty()) {
			int tInfo = dirInfo.front().first;
			if (time == tInfo) {
				char cInfo = dirInfo.front().second;
				if (cInfo == 'D') {
					dir = (dir + 1) % 4;
				}
				else {
					dir = (dir + 3) % 4;
				}
				dirInfo.pop();
			}
		}
	}

	cout << time << endl;

	return 0;
}