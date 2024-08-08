#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>

#pragma warning (disable:4996)

using namespace std;
int N = 0;

int coord[2][1001] = { -1, };
int parent[1001] = { -1, };
double E;

int already[1001][1001] = { 0, };

typedef struct line{
	long long pay = 0;
	int pre = 0; int nxt = 0;

	line() { pay = 0; pre = -1; nxt = -1; }
	line(long long pay, int pre, int nxt) : pay(pay), pre(pre), nxt(nxt) {};
}line;

bool linecomp(line s, line t) {
	if (s.pay != t.pay)
		return s.pay < t.pay;
	
	return false;
}

vector<line> linelist;

int rootfind(int pos) {
	if (parent[pos] == pos) {
		return pos;
	}

	return parent[pos] = rootfind(parent[pos]);
}

long long kruskal() {
	int pre; int nxt;
	line curline;
	int numofline = 0;
	long long payment = 0;
	int rootpre; int rootnxt;


	for (int i = 0; i < linelist.size(); i++) {
		curline = linelist[i];

		pre = curline.pre;
		nxt = curline.nxt;

		rootpre = rootfind(pre);
		rootnxt = rootfind(nxt);

		if (rootpre == rootnxt) {
			continue;
		}

		numofline++;
		payment += curline.pay;

		if (rootpre != rootnxt) {
			parent[rootnxt] = rootpre;
		}

		if (numofline + 1 == N) {
			return payment;
		}
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T; 
	int x; int y;
	long long pay;
	double result;

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		linelist.clear();

		pay = 0; result = 0;

		memset(coord,  -1, sizeof coord);
		memset(parent, -1, sizeof parent);
		memset(already, 0, sizeof already);

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> x;
			coord[0][i] = x;
		}
		for (int i = 0; i < N; i++) {
			cin >> y;
			coord[1][i] = y;
		}

		cin >> E;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (already[i][j] == 1) {
					continue;
				}

				pay = pow(coord[0][i] - coord[0][j], 2) + pow(coord[1][i] - coord[1][j], 2);
				already[i][j] = 1;
				already[j][i] = 1;

				linelist.push_back(line(pay, i, j));
			}
		}

		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}
		
		sort(linelist.begin(), linelist.end(), linecomp);

		result = kruskal() * E;
		long long output = (long long)(result + 0.5);


		printf("#%d %lld\n", test_case, output);
		
		




	}
	return 0;
}