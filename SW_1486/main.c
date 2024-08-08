#pragma warning(disable:4996)

#include <stdio.h>

int N;
int B;

int officer[21] = { 0, };
int sum = 0;

int smallest = 987654321;

void simul(int a) {



	if (smallest == 0) {
		return;
	}

	if (sum >= B) {
		if (smallest > sum - B) {
			smallest = sum - B;
		}
		return;
	}

	if (a == N) {
		return;
	}

	for (int i = a; i < N; i++) {
		sum += officer[i];
		simul(i+1);
		sum -= officer[i];
		
	}

	return;
}


int main() {
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case) {

		sum = 0;
		smallest = 987654321;


		printf("#%d ", test_case);

		scanf("%d %d", &N, &B);
		for (int i = 0; i < N; i++) {
			scanf("%d", &officer[i]);
		}

		if (N == 1) {
			printf("%d\n", officer[0] - B);
		}
		else {
			simul(0);
			printf("%d\n", smallest);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}