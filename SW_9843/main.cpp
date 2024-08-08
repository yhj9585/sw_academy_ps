#include <cmath>
#include<iostream>

#pragma warning(disable:4996)

unsigned long long num;


using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	unsigned long long root;


	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case) {
		scanf("%lld", &num);
		
		root = floor(sqrt(num * 2));
		if (root * (root + 1) == num * 2) {
			printf("#%d %lld\n", test_case, root);
			continue;
		}
		else {
			printf("#%d -1\n", test_case);
		}



	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}