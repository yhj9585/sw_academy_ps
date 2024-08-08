#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

int heap[200011] = { -1, };
int tail = 0;


void push(int num) {
	tail++;
	heap[tail] = num;

	int pos = tail;
	int parent = (pos / 2);
	int temp;

	if (tail == 1) {
		return;
	}

	while ((parent != 0) && (heap[pos] > heap[parent])) {
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

	int temp;
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

		if ((left <= tail) && heap[left] > heap[large]) { // 둘다 없을때
			large = left;
		} 
		if ((right <= tail) && heap[right] > heap[large]) {
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


int top() {
	if (tail == 0) {
		return -1;
	}

	return heap[1];
}

int main(void) {
	int test_case;
	int T;
	int N;

	int temp1; 
	int temp2;

	freopen("test.txt", "r", stdin);
	
	
	//setbuf(stdout, NULL);
	
	scanf("%d", &T);
	int teasdf = 1;

	for (test_case = 1; test_case <= T; ++test_case) {
		tail = 0;
		memset(heap, -1, sizeof(heap));

		scanf("%d", &N);

		printf("#%d", test_case);
		
		for (int i = 0; i < N; i++) {
			scanf("%d", &temp1);
			if (temp1 == 1) {
				scanf("%d", &temp2);
				push(temp2);
			}
			else {
				if (tail != 0) {
					printf(" %d", top());
					pop();
				}
				else {
					printf(" -1");
				}
			}

			/*
			if (i == 4999) {
				for (int j = 0; j < tail; j++) {
					if (j == teasdf) {
						printf("\n");
						teasdf *= 2;
					}
					printf("%d ", heap[j]);
				}
			}*/

		}




		printf("\n");
	}
	


	/*
	FILE* fp;
	fp = fopen("test.txt", "w");

	for (int i = 1; i <= 5000; i++) {
		fprintf(fp, "%d %d\n", 1, i); 
	}
	for (int i = 1; i <= 5000; i++) {
		fprintf(fp, "2\n");
	}
	fclose(fp);
	*/

	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}