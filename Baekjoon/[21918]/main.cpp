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

vector<int> bulbs;

void func(int a, int b, int c){
    if(a == 1){
        bulbs[b] = c;
    }
    else if(a == 2){
        for(int i = b; i <= c; i++){
            bulbs[i] = !bulbs[i];
        }
    }
    else if(a == 3){
        for(int i = b; i <= c; i++){
            bulbs[i] = 0;
        }
    }
    else if(a == 4){
        for(int i = b; i <= c; i++){
            bulbs[i] = 1;
        }
    }
}


int main(){

    FASTIO

    int N, M;
    cin >> N >> M;

    bulbs.resize(N + 1, 0);

    for(int i = 1; i <= N; i++){
        cin >> bulbs[i];
    }

    for(int i = 1; i <= M; i++){
        int a, b, c;
        cin >> a >> b >> c;

        func(a, b, c);
    }

    for(int i = 1; i <= N; i++){
        cout << bulbs[i] << " ";
    }

    return 0;
}