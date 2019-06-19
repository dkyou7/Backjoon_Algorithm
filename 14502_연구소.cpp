#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

const int Max = 8;
int M, N;
int arr[Max][Max];
vector<pair<int,int>> virus;
vector<pair<int, int>> a;
vector<int> tmp;

int bfs(int ans,int count) {
	vector<vector<int>> copy(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy[i][j] = arr[i][j];
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i]) {
			copy[a[i].first][a[i].second] = 1;
			count--;
		}
	}
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
	}
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && copy[ny][nx]==0) {
				q.push({ ny,nx });
				copy[ny][nx] = 1;
				count--;
			}
		}
	}
	return count;
}

int main() {
	cin >> N >> M;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else if (arr[i][j] == 1) {
				continue;
			}
			else {
				a.push_back({ i,j });
				count++;
			}
		}
	}
	tmp.resize(count);
	for (int i = 0; i < count; i++) {
		tmp[i] = 0;
	}
	for (int i = 0; i < 3; i++) {
		tmp[i] = 1;
	}
	sort(tmp.begin(), tmp.end());
	int ans = -1;
	do {
		int tmp = bfs(ans, count);
		ans = max(ans,tmp);
	} while (next_permutation(tmp.begin(), tmp.end()));
	cout << ans << endl;
	return 0;
}