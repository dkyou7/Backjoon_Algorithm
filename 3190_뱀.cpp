#include<iostream>
#include<queue>
#include<vector>
#include<deque>
#include<tuple>

using namespace std;

// 북 서 남 동
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
// 입력.
// 보드의 크기 N=(max)100 , 사과의 갯수 K=(max)100, 사과의 위치 정보를 나타낼 배열 지정해주자.
int apple[100][100];
int snake[100][100];
int N, K, L, dir;
// 변환 정보를 알고있을 vector변수 필요할듯.
queue<pair<int, char>> info;
deque<pair<int, int>> q;

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << snake[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	// K줄만큼 사과의 위치가 주어진다. (y,x)의 정보로 주어진다.
	cin >> N >> K;
	while (K--) {
		int y, x;
		cin >> y >> x;
		// 사과의 위치는 모두 다르며, 0,0에는 사과가 없음.
		// 맨 위 맨 좌측을 1,1이라고 하는것으로 보아 하나씩 빼줘야 할 듯.
		apple[y - 1][x - 1] = 1;
	}
	// L 만큼 방향 변환 횟수가 주어진다.
	cin >> L;

	while (L--) {
		int X;
		char C;
		cin >> X >> C;
		info.push({ X,C });
	}
	// 뱀은 맨 위 좌측(0,0) 에 존재하며 길이는 1이다. 맨 처음에 방향은 오른쪽을 향한다. dir=3이네. - 조건 5
	// 1. 먼저 초기값 등록 해준다. 사과는 없음.
	snake[0][0] = 1;
	dir = 3;
	q.push_front({ 0,0 });

	int time = 0;
	while (!q.empty()) {
		time++;
		int y, x;
		tie(y, x) = q.front();
		int ny, nx;
		tie(ny, nx) = make_pair(y + dy[dir], x + dx[dir]);
		// 벽 , 또는 자기 자신과 부딪히면 게임이 끝난다. - 조건 2
		if (!(0 <= ny && ny < N && 0 <= nx && nx < N) || snake[ny][nx] == 1) {
			// 게임이 몇초에 끝나는지 구하여라 - 문제. time 구하는 문제.
			cout << time << endl;
			break;
		}
		// 실질적으로 뱀 정보 업데이트 하기
		snake[ny][nx] = 1;
		q.push_front({ ny,nx });

		// 뱀은 매 초마다 이동을 하는데 규칙을 따른다. - 조건 6
		// 1. 몸 길이를 먼저 늘여 머리를 다음칸에 위치시킨다.
		// 2. 머리가 위치한 곳에 사과가 있는지 if문으로 따져보자
		// 있으면 사과는 없어지고 길이는 줄지 않는다. 
		if (apple[ny][nx] == 1) {
			apple[ny][nx] = 0;
		}
		else {
			// 없으면 몸 길이를 줄이는데 꼬리를 줄인다. deque 자료구조를 쓰면 효과적일 것 같아.	
			pair<int, int>tail = q.back();
			snake[tail.first][tail.second] = 0;
			q.pop_back();
		}

		/*cout << time << endl;
		print();*/
		// 디버깅하다 발견!!! info가 없으면 그냥 넘어가야됨
		if (info.empty()) {
			continue;
		}

		// x 초가 끝나면 , c 방향으로 변함. L이면 좌측.dir= (dir+3)%4; 아니면 우측. dir=(dir+1)%4;
		int t = info.front().first;
		if (time == t) {
			char c = info.front().second;
			if (c == 'L') {
				dir = (dir + 1) % 4;
			}
			else {
				dir = (dir + 3) % 4;
			}

			info.pop();
		}

	}

	return 0;
}