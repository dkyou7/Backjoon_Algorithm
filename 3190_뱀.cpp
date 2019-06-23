#include<iostream>
#include<queue>
#include<vector>
#include<deque>
#include<tuple>

using namespace std;

// �� �� �� ��
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
// �Է�.
// ������ ũ�� N=(max)100 , ����� ���� K=(max)100, ����� ��ġ ������ ��Ÿ�� �迭 ����������.
int apple[100][100];
int snake[100][100];
int N, K, L, dir;
// ��ȯ ������ �˰����� vector���� �ʿ��ҵ�.
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
	// K�ٸ�ŭ ����� ��ġ�� �־�����. (y,x)�� ������ �־�����.
	cin >> N >> K;
	while (K--) {
		int y, x;
		cin >> y >> x;
		// ����� ��ġ�� ��� �ٸ���, 0,0���� ����� ����.
		// �� �� �� ������ 1,1�̶�� �ϴ°����� ���� �ϳ��� ����� �� ��.
		apple[y - 1][x - 1] = 1;
	}
	// L ��ŭ ���� ��ȯ Ƚ���� �־�����.
	cin >> L;

	while (L--) {
		int X;
		char C;
		cin >> X >> C;
		info.push({ X,C });
	}
	// ���� �� �� ����(0,0) �� �����ϸ� ���̴� 1�̴�. �� ó���� ������ �������� ���Ѵ�. dir=3�̳�. - ���� 5
	// 1. ���� �ʱⰪ ��� ���ش�. ����� ����.
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
		// �� , �Ǵ� �ڱ� �ڽŰ� �ε����� ������ ������. - ���� 2
		if (!(0 <= ny && ny < N && 0 <= nx && nx < N) || snake[ny][nx] == 1) {
			// ������ ���ʿ� �������� ���Ͽ��� - ����. time ���ϴ� ����.
			cout << time << endl;
			break;
		}
		// ���������� �� ���� ������Ʈ �ϱ�
		snake[ny][nx] = 1;
		q.push_front({ ny,nx });

		// ���� �� �ʸ��� �̵��� �ϴµ� ��Ģ�� ������. - ���� 6
		// 1. �� ���̸� ���� �ÿ� �Ӹ��� ����ĭ�� ��ġ��Ų��.
		// 2. �Ӹ��� ��ġ�� ���� ����� �ִ��� if������ ��������
		// ������ ����� �������� ���̴� ���� �ʴ´�. 
		if (apple[ny][nx] == 1) {
			apple[ny][nx] = 0;
		}
		else {
			// ������ �� ���̸� ���̴µ� ������ ���δ�. deque �ڷᱸ���� ���� ȿ������ �� ����.	
			pair<int, int>tail = q.back();
			snake[tail.first][tail.second] = 0;
			q.pop_back();
		}

		/*cout << time << endl;
		print();*/
		// ������ϴ� �߰�!!! info�� ������ �׳� �Ѿ�ߵ�
		if (info.empty()) {
			continue;
		}

		// x �ʰ� ������ , c �������� ����. L�̸� ����.dir= (dir+3)%4; �ƴϸ� ����. dir=(dir+1)%4;
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