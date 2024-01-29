#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
int Q, leaf = 0;

void dfs(int node) {
    visited[node] = true;
   
    if(tree[node].size() == 0 || (tree[node].size() == 1 && tree[node][0] == Q)){
        leaf++;
    }

    for(int i=0; i<tree[node].size(); i++){
        int next = tree[node][i];

        if(next == Q) continue;
        if(!visited[next]) dfs(next);
    }
}

int main(){

    FASTIO
    
    int N, root;
    cin >> N;

    tree = vector<vector<int>>(N+5);
    visited = vector<bool>(N+1, false);

    for(int i=0; i<N; i++){
        int a;
        cin >> a;

        if(a == -1){ 
            root = i;
            continue;
        }

        tree[a].push_back(i);
    }

    cin >> Q;
    if(Q == root) {
        cout << 0;
        return 0;
    }
    dfs(root);

    cout << leaf;

    return 0;
}