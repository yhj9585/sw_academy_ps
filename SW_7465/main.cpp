#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

int N; int M;

int parent[110];
int treetype[110];
int treedepth[110];
int grouptree[110];

int treen = 0;
int treenumber = 0;

int findparent(int pos) {
	if (parent[pos] == pos) {
		return pos;
	}
	return findparent(parent[pos]);
}

int main(void) {
	int test_case;
	int T;
	int temp1; int temp2;
	int parentPos1; int parentPos2;
	int tree1; int tree2;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case) {
		scanf("%d %d", &N, &M);

		memset(parent,    0, sizeof parent); 
		memset(treetype,  0, sizeof treetype);
		memset(treedepth, 0, sizeof treedepth);
		memset(grouptree, 0, sizeof grouptree);

		treen = 0;
		treenumber = 0;

		for (int i = 0; i < M; i++) {
			scanf("%d %d", &temp1, &temp2);

			if ((treetype[temp1] == 0) && (treetype[temp2] == 0)) {
				treen++; treenumber++;
				treetype[temp1] = treen; treetype[temp2] = treen;

				parent[temp2] = temp1;
				parent[temp1] = temp1;

				grouptree[treen] = treen;
				treedepth[grouptree[treen]] = 2;
			}
			else if ((treetype[temp1] == 0) && (treetype[temp2] != 0)) {
				// find parent temp2
				parentPos2 = findparent(temp2);

				parent[temp1] = parentPos2;
				treetype[temp1] = treetype[temp2];
			}
			else if ((treetype[temp1] != 0) && (treetype[temp2] == 0)) {
				// find parent temp1
				parentPos1 = findparent(temp1);

				parent[temp2] = parentPos1;
				treetype[temp2] = treetype[temp1];
			}
			else {
				parentPos1 = findparent(temp1);
				parentPos2 = findparent(temp2);

				tree1 = grouptree[treetype[parentPos1]];
				tree2 = grouptree[treetype[parentPos2]];

				if (tree1 == tree2) {
					continue;
				}

				treenumber--;

				// find parent (깊은거 부모에 연결)

				if (treedepth[tree1] >= treedepth[tree2]) {
					if (treedepth[tree1] == treedepth[tree2]) {
						treedepth[tree1]++;
					}
					parent[parentPos2] = parentPos1;
					grouptree[treetype[temp2]] = grouptree[treetype[temp1]];
				}
				else {
					parent[parentPos1] = parentPos2;
					grouptree[treetype[temp1]] = grouptree[treetype[temp2]];
				}
			}
		}

		for (int x = 1; x <= N; x++) {
			if (treetype[x] == 0) {
				treenumber++;
			}
		}


		printf("#%d %d\n", test_case, treenumber);
	}
	return 0; 
}