#pragma warning(disable:4996)

#include <stdio.h>

int map[20][20] = { 0, };
int chk[20][20] = { 0, };

typedef struct pos {
	int y;
	int x;
}pos;

int move[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};

pos queue[400] = { 0, };
int ed; int st;

void push(pos nxtpos) {
	queue[st++] = nxtpos;
	return;
}
pos pop() {
	return queue[ed++];
}
int size() {
	return st - ed;
}

void reset() {
	st = 0;
	ed = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			chk[i][j] = 0;
		}
	}
	return;
}

int check(pos nxtpos) {
	if (nxtpos.y > 16 || nxtpos.x > 16 || nxtpos.y < 0 || nxtpos.x < 0) {
		return 0;
	}
	else if (map[nxtpos.y][nxtpos.x] == 1) {
		return 0;
	}
	else if (chk[nxtpos.y][nxtpos.x] == 1) {
		return 0;
	}
	else if (map[nxtpos.y][nxtpos.x] == 3) {
		return 2;
	}


	return 1;
}

void simul() {
	pos nxtpos = { 0, };
	pos nowpos = { 0, };



	while (size() != 0) {
		nowpos = pop();



		for (int i = 0; i < 4; i++) {
			nxtpos.y = nowpos.y + move[i][0];
			nxtpos.x = nowpos.x + move[i][1];

			if (check(nxtpos) == 1) {
				push(nxtpos);
				chk[nxtpos.y][nxtpos.x] = 1;
			}
			else if (check(nxtpos) == 2) {
				printf("1\n");
				return;
			}
			else {
				continue;
			}
		}


	}
	printf("0\n");
	return;
}


int main() {
	int test_case;
	int T = 10;

	freopen("input.txt", "r", stdin);
	//scanf("%d", &T);
	int temp;

	pos tempos = { 0, };

	for (test_case = 1; test_case <= T; ++test_case) {
		reset();

		scanf("%d", &temp);

		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {
					tempos.y = i;
					tempos.x = j;
					push(tempos);
					chk[i][j] = 1;
				}
			}
		}

		printf("#%d ", test_case);
		simul();


	}
	return 0;
}