#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<sstream>
#include<cmath>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;

const int INF = 987654321;

int M, N;
vector<vector<int>> board(1000 + 5, vector<int>(1000 + 5, 0));
vector<vector<bool>> visited(1000 + 5, vector<bool>(1000 + 5, false));
vector<pair<int,int>> graph;

bool dfs(int x, int y){

    if(y == M) return true;
    
    if(x < 0 || x >= N || y < 0 || y >= M) return false;
    if(visited[x][y]) return false;
    if(board[x][y] == 1) return false;

    visited[x][y] = true;

    if(dfs(x-1, y)) return true;
    if(dfs(x+1, y)) return true;
    if(dfs(x, y-1)) return true;
    if(dfs(x, y+1)) return true;

    return false;
}

int main(){

    FASTIO

    cin >> M >> N;

    for(int i = 0; i < M; i++){
        string s;
        cin >> s;

        for(int j = 0; j < N; j++){
            board[j][i] = s[j] - '0';

            if(i == 0 && board[i][j] == 0){
                graph.push_back({j, i});
            }
        }
    }

    for(int i = 0; i < graph.size(); i++){
        int x = graph[i].first;
        int y = graph[i].second;

        if(dfs(x, y)){
            cout << "YES" << endl;
            return 0;
        }

        visited = vector<vector<bool>>(1000 + 5, vector<bool>(1000 + 5, false));
    }

    cout << "NO" << endl;

    return 0;
}