#pragma warning(disable:4996)

#include<iostream>
#include<cmath>

using namespace std;

int N = 0;

typedef struct Node {
	char data;
	int left;
	int right;
}Node;

Node tree[100];

void inorder(int pos) {
	if (tree[pos].left != NULL) {
		inorder(tree[pos].left);
	}
	printf("%c", tree[pos].data);
	if (tree[pos].right != NULL) {
		inorder(tree[pos].right);
	}

	return;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);

	int temp;  char tempchar;
	int temp1; int temp2;

	int height = 0; int tmpheight = 0;


	for (test_case = 1; test_case <= 10; ++test_case) {
		printf("#%d ", test_case);

		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &temp);
			getchar();
			scanf("%1c", &tempchar);

			if (i*2 + 1 <= N) {
				scanf("%d %d", &temp1, &temp2);
				tree[i].left = temp1;
				tree[i].right = temp2;
			}
			else if (i * 2 == N) {
				scanf("%d", &temp1);
				tree[i].left = temp1;
				tree[i].right = NULL;
			}
			else {
				tree[i].left = NULL;
				tree[i].right = NULL;
			}
			
			tree[i].data = tempchar;
		}
		inorder(1);
		printf("\n");
	}
	
	return 0;
}