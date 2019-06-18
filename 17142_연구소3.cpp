#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int M, N;

vector<int> tmp;
vector<pair<int, int>> virus;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int result = 987654321;
const int Max = 50;
bool flag;

void dfs(vector<vector<int>> &a, int count) {
	int n = a.size();
	vector<vector<int>>copy(n, vector<int>(n));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy[i][j] = a[i][j];
		}
	}
	queue<pair<int, int>>q;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i]) {
			q.push(virus[i]);
			copy[virus[i].first][virus[i].second] = 3;
		}
	}
	int time = 0;
	while (!q.empty()) {
		if (!count) {
			flag = true;
			result = min(result, time);
			break;
		}
		//else {
		//	for (int i = 0; i < N; i++) {
		//		for (int j = 0; j < N; j++) {
		//			cout << copy[i][j] << "  ";
		//		}
		//		cout << endl;
		//	}
		//	cout << endl;
		//}
		int size = q.size();
		time++;
		for (int i = 0; i < size; i++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (0 <= ny && ny < N && 0 <= nx && nx < N) {
					if (copy[ny][nx] == 1 || copy[ny][nx]==3) {
						continue;
					}
					else {
						if (!copy[ny][nx]) {
							count--;
						}
						q.push({ ny,nx });
						copy[ny][nx] = 3;
					}
				}
			}
		}
	}
	return;
}
int main() {
	cin >> N >> M;
	int count = 0;
	vector<vector<int>>a(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else if (a[i][j] == 0) {
				count++;
			}
		}
	}
	tmp.resize(virus.size());
	for (int i = 0; i < tmp.size(); i++) {
		tmp[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		tmp[i] = 1;
	}
	sort(tmp.begin(), tmp.end());
	do {
		dfs(a,count);
	} while (next_permutation(tmp.begin(), tmp.end()));
	
	if (flag) {
		cout << result << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}