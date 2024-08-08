#pragma warning(disable:4996)

#include<iostream>
#include<queue>

using namespace std;

#define INF 1987654321;

int N;
int map[101][101] = { 0, };

int mov[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};

int dist[101][101] = {0,};


void di() {
	priority_queue<pair<int, pair<int, int>>> pqueue;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = INF;
		}
	}

	dist[0][0] = 0;

	pqueue.push(make_pair(0, make_pair(0, 0)));

	while (!pqueue.empty()) {
		int nowdist = -pqueue.top().first;
		auto nownode = pqueue.top().second;
		pqueue.pop();

		if (nowdist != dist[nownode.first][nownode.second]) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nxty = nownode.first + mov[i][0];
			int nxtx = nownode.second + mov[i][1];

			if (nxty >= N || nxty < 0 || nxtx >= N || nxtx < 0) {
				continue;
			}

			int nxtdist = nowdist + map[nxty][nxtx];

			if (nxtdist < dist[nxty][nxtx]) {
				dist[nxty][nxtx] = nxtdist;
				pqueue.push(make_pair(-nxtdist, make_pair(nxty, nxtx)));
			}
		}



	}


}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &map[i][j]);
			}
		}

		di();
		printf("#%d %d\n", test_case, dist[N - 1][N - 1]);

	}
	return 0;
}