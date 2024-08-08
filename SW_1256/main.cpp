#pragma warning(disable:4996)

#include<iostream>
#include<cstring>
#include<vector>
#include<string>


int K = 0;
using namespace std;

int enddepth = 0;
char ended[500] = { 0, };

class Trie {
	static constexpr size_t m = 27;
	static constexpr char offset = 'a';

	struct trieNode {
		int child[m];
		bool end;
        char data;
		trieNode() {
			memset(child, -1, sizeof(int) * m);
			end = false;
            data = '\0';
		}
	};

	vector<trieNode> nodes;

	public:
		Trie() : nodes(1) {}
		void init() {
            nodes.clear();
			nodes.resize(1);
			nodes[0] = trieNode();
		}


    void insert(string& str) {
        int node_id = 0;
        for (const auto& c : str) {
            if (nodes[node_id].child[c - offset] == -1) {
                nodes[node_id].child[c - offset] = nodes.size();
                nodes.emplace_back();
            }
            node_id = nodes[node_id].child[c - offset];
            nodes[node_id].data = c;
        }
        nodes[node_id].end = true;
    }

    int cnt = 0;
    bool end = false;
    void search(int pos, int depth) {


        if (nodes[pos].end == true) {
            /*
            for (int i = 0; i < depth; i++) {
                printf("%c", ended[i]);
            }
            printf("\n");
            */
            cnt++;
            if (cnt == K) {
                //printf("------\n");
                end = true;
                enddepth = depth;

                ended[depth-1] = nodes[pos].data;
                return;
            }
        }


        for (int i = 0; i < m; i++) {
            if (nodes[pos].child[i] != -1) {
                // ended[depth] = nodes[nodes[pos].child[i]].data;
                search(nodes[pos].child[i], depth+1);

                if (end == true) {
                    break;
                }
            }
        }
        
        if (end == true && depth != 0) {
            ended[depth-1] =  nodes[pos].data;
            return;
        }

    }
};

int main(int argc, char** argv) {
	int test_case;
	int T;

    char temp[500];

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case) {
        Trie nowTrie;

        memset(ended, 0, sizeof ended);
        enddepth = 0;

        scanf("%d", &K);

        scanf("%s", &temp);
        string temps(temp);

        for (int i = 0; i < temps.size(); i++) {
            string sub1 = temps.substr(i);

            nowTrie.insert(sub1);


        }

        nowTrie.search(0,0);
        if (enddepth != 0) {
            printf("#%d %s\n", test_case, ended);
        }
        else {
            printf("#%d none\n", test_case);
        }

	}
	return 0;
}