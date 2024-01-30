#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;

const int INF = 987654321;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1 ,0 ,0};
vector<vector<int>> map;

void dfs(int y, int x){
    map[y][x] = 0;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= map.size() || nx < 0 || nx >= map[0].size()) continue;

        if(map[ny][nx] == 0) continue;

        dfs(ny, nx);
    }
}

int main(){

    FASTIO

    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int m, n, k, cnt = 0;
        cin >> m >> n >> k;

        map = vector<vector<int>>(n, vector<int>(m, 0));

        for(int j=0; j<k; j++){
            int x, y;
            cin >> x >> y;

            map[y][x] = 1;
        }

        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(map[j][k] == 1){
                    dfs(j, k);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}