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

vector<pair<int, int>> potion;
int N, M, H;
int visited [11][11] = {0, };
pair<int,int> start;
int result = -INF;

void func(int nowX, int nowY, int hp, int sum){

    if(abs(nowX - start.first) + abs(nowY - start.second) <= hp){
        result = max(result, sum);
    }

    for(int i = 0; i < potion.size(); i++){
        int nextX = potion[i].first;
        int nextY = potion[i].second;

        int distance = abs(nowX - nextX) + abs(nowY - nextY);

        if(visited[nextX][nextY] == 0 && hp - distance >= 0){
            sum += 1;
            visited[nextX][nextY] = 1;
            func(nextX, nextY, hp - distance + H, sum);
            sum -= 1;
            visited[nextX][nextY] = 0;
        }
    }
}

int main(){

    FASTIO

    cin >> N >> M >> H;

    vector<vector<int>> map(N + 1, vector<int>(N + 1, 0));
    int sum = 0;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int q;
            cin >> q;
            map[i][j] = q;

            if(q == 1){
                start = {i, j};
            }
            else if(q == 2){
                potion.push_back({i, j});
            }
        }
    }

    func(start.first, start.second, M, sum);

    cout << result;

    return 0;
}