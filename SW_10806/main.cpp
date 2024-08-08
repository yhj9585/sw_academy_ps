#include <stdio.h>
#include <cstring>
#include <map>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

typedef struct node {
	int num = 0;
	int d = 0;
	int depth = 0;

	node() {};
	node(int num, int d, int depth) : num(num), d(d), depth(depth) {}
}node;

bool compare(node a, node b) {
	if ((a.num + a.d) != (b.num + b.d)) {
		return (a.num + a.d) > (b.num + b.d);
	}
	if (a.depth != b.depth) {
		return a.depth < b.depth;
	}
	if (a.d != b.d) {
		return a.d > b.d;
	}
	return a.num > b.num;
}

int numbers[12] = { 0, };
node heap[1000] = {  };
int tail = 0;

void push(node newnode) {
	tail++;
	heap[tail] = newnode;

	int pos = tail;
	int parent = (pos / 2);
	node temp;

	if (tail == 1) {
		return;
	}

	while ((parent != 0) && (compare(heap[pos], heap[parent]))) {
		temp = heap[pos];
		heap[pos] = heap[parent];
		heap[parent] = temp;
		pos = (pos / 2);
		parent = (pos / 2);
	}
	return;
}

void pop() {
	if (tail == 0) {
		return;
	}

	node temp;
	int pos = 1;
	int left;
	int right;

	heap[1] = heap[tail];
	tail--;

	left = pos * 2;
	right = (pos * 2) + 1;
	int large = pos;
	int fin = 0;

	while (fin == 0) {
		if ((left <= tail) && compare(heap[left], heap[large])) { // 둘다 없을때
			large = left;
		}
		if ((right <= tail) && compare(heap[right], heap[large])) {
			large = right;
		}
		if (large == pos) {
			break;
		}
		else {
			temp = heap[pos];
			heap[pos] = heap[large];
			heap[large] = temp;

			pos = large;
			left = pos * 2;
			right = (pos * 2) + 1;
		}
	}
	return;
}


map<pair<int,int>, int> chk;

int main(void) {
	int test_case;
	int T;

	int N; // num of A[n]

	int X; // first num
	int D; // add
	int K; // to num

	//freopen("input.txt", "r", stdin);
	//setbuf(stdout, NULL);

	scanf("%d", &T);

	int smallest = 1000000001;
	int end = 0;
	int temp = 0;

	for (test_case = 1; test_case <= T; ++test_case) {
		//pqueue = priority_queue<node, vector<node>, cmp> ();
		//memset(heap, -1, sizeof heap);
		tail = 0;

		smallest = 1000000001;

		chk.clear();

		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &numbers[i]);
			if (smallest > numbers[i]) {
				smallest = numbers[i];
			}
		}

		sort(numbers, numbers + N);


		scanf("%d", &K);

		if (smallest > K) {
			printf("#%d %d\n", test_case,  K);
			continue;
		}

		X = 0;
		D = 1;
		node newnode(X, D, 0);

		//chk[make_pair(newnode.num, newnode.d)] = 1;
		push(newnode);

		end = 0;

		if ((smallest * 2) > K) {
			for (int i = N - 1; i >= 0; i--) {
				if (numbers[i] <= K) {
					printf("#%d %d\n", test_case, K - numbers[i]);
					end = 1;
					break;
				}
			}
			if (end == 1) {
				continue;
			}
		}

		while (tail != 0) {
			end = 0;
			auto nowx = heap[1];
			pop();

			temp = nowx.d * smallest;

			if (nowx.num + temp > K) {
				printf("#%d %d\n", test_case, ((K - nowx.num) / nowx.d) + nowx.depth);
				break;
			}

			if (nowx.num + nowx.d == K) {
				printf("#%d %d\n", test_case, nowx.depth + 1);
				break;
			}

			node newnode(nowx.num + nowx.d, nowx.d, nowx.depth + 1);
			//if (chk.find({newnode.num, newnode.d}) == chk.end()) {
				push(newnode);
			//	chk[make_pair(newnode.num, newnode.d)] = 1;
			//}


			if (temp > K) {
				continue;
			}

			for (int i = N-1; i >= 0; i--) {
				temp = nowx.d * numbers[i];

				if ((nowx.num + temp) > K) {
					continue;
				}
				if ((nowx.num + temp) == K) {
					printf("#%d %d\n", test_case, nowx.depth + 1);
					end = 1;
					break;
				}
				else {
					if ((K - nowx.num) % temp != 0) {
						continue;
					}

					node newnode(nowx.num, temp, nowx.depth);
			//		if (chk.find({ newnode.num, newnode.d }) == chk.end()) {
						push(newnode);
			//			chk[make_pair(newnode.num, newnode.d)] = 1;
						break;
			//		}
				}
			}
			if (end == 1) {
				break;
			}
		}
	}


	return 0;
}