#pragma warning (disable:4996)
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int M = 100003;
vector<vector<string>> hashtable;

int N1 = 0;
int N2 = 0;

unsigned long long hashing(string nowstring) {
	int sum = 0;
	int i = 0;
	int r = 1;


	while (nowstring[i] != '\0') {
		sum = (sum + (nowstring[i] - 96)*r)%M;
		r = (r * 31) % M;
		i++;
	}
	return sum;
}

bool find(string nowstring) {
	auto num = hashing(nowstring);

	for (auto n : hashtable[num]) {
		if (n == nowstring) {
			return true;
		}
	}
	return false;
}

int main(int argc, char** argv) {
	int test_case;
	int T;
	int cnt = 0;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	char tempc[60];
	string temp;
	for (test_case = 1; test_case <= T; ++test_case) {
		scanf("%d %d", &N1, &N2);

		cnt = 0;
		hashtable.clear();
		hashtable.resize(M + 1);

		for (int i = 0; i < N1; i++) {
			scanf("%s", tempc);

			string temp(tempc);
			hashtable[hashing(temp)].push_back(temp);
		}

		for (int i = 0; i < N2; i++) {
			scanf("%s", tempc);

			string temp(tempc);
			if (find(temp)) {
				cnt++;
			}
		}

		printf("#%d %d\n", test_case, cnt);
	}
	return 0;
}