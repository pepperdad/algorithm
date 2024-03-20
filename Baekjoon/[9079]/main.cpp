#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<sstream>
#include<cmath>
#include<cstring>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;

const int INF = 987654321;

vector<vector<int>> board(3, vector<int>(3));
bool visited[512 + 5];


int maze_to_int(){
    int ret = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ret = ret * 2 + board[i][j];
        }
    }
    return ret;
}

void int_to_maze(int n){
    for(int i=2; i>=0; i--){
        for(int j=2; j>=0; j--){
            board[i][j] = n % 2;
            n /= 2;
        }
    }
}

bool isCorrect(){
    int val = board[0][0];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] != val){
                return false;
            }
        }
    }

    return true;
}

void col_change(int col){
    for (int i=0; i<3; i++) {
		board[i][col] = (board[i][col] == 1 ? 0 : 1);
	}
}

void row_change(int row) {
	for (int i = 0; i < 3; i++) {
		board[row][i] = (board[row][i] == 1 ? 0 : 1);
	}
}

void cross_change(int dir) {
	for (int i = 0; i < 3; i++) {
		if (dir == 0) {
			board[i][i] = (board[i][i] == 1 ? 0 : 1);
		}
		else {
			board[i][2 - i] = (board[i][2 - i] == 1 ? 0 : 1);
		}
	}
}

int bfs(){
    
    queue<pair<int, int>> q;
    int first = maze_to_int();
    q.push({first, 0});

    visited[first] = true;

    while(!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        int_to_maze(now);

        if (isCorrect()) {
			return cnt;
		}

        // 열 변환
        for(int i=0; i<3; i++){
            col_change(i);
            int next = maze_to_int();

            if (!visited[next]) {
				visited[next] = true;
				q.push({ next ,cnt + 1 });
			}
			col_change(i);
        }

        // 행 변환
        for (int i=0; i<3; i++) {
            row_change(i);
            int next = maze_to_int();

            if (!visited[next]) {
                visited[next] = true;
                q.push({ next, cnt + 1 });
            }
            row_change(i);
        }

        // 대각선 변환
        for (int i=0; i<2; i++) {
            cross_change(i);
            int next = maze_to_int();

            if (!visited[next]) {
                visited[next] = true;
                q.push({ next, cnt + 1 });
            }
            cross_change(i);
        }
    }

    return -1;
}

int main(){

    FASTIO

    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        
        memset(visited, 0, sizeof(visited));
        for(int j=0; j<9; j++){
            char c;
            cin >> c;

            if(c == 'H'){
                board[j / 3][j % 3] = 1;
            }
            else{
                board[j / 3][j % 3] = 0;
            }
        }

        cout << bfs() << endl;
    }

    return 0;
}