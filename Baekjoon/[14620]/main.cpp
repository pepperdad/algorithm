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

int N;
int price[20][20];
int now[20][20];
int minPrice = INF;

void func(int cnt, int sum)
{
	if (cnt == 3){
        minPrice = min(minPrice, sum);
		return;
	}

	for (int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(i > 1 && i < N && j > 1 && j < N) {
                if(now[i][j] == 1 && now[i+1][j] == 1 && now[i-1][j] == 1 && now[i][j+1] == 1 && now[i][j-1] == 1){
                    now[i][j] = 0;
                    now[i + 1][j] = 0;
                    now[i - 1][j] = 0;
                    now[i][j + 1] = 0;
                    now[i][j - 1] = 0;
                    func(cnt + 1, sum + price[i][j] + price[i+1][j] + price[i-1][j] + price[i][j+1] + price[i][j-1]);
                    now[i][j] = 1;
                    now[i + 1][j] = 1;
                    now[i - 1][j] = 1;
                    now[i][j + 1] = 1;
                    now[i][j - 1] = 1;
                }
            }
}

int main(){

    FASTIO

    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int q;
            cin >> q;
            price[i][j] = q;
            now[i][j] = 1;
        }
    }

    
    func(0, 0);
    cout << minPrice;

    return 0;
}   