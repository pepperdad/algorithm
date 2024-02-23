#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<sstream>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;

const int INF = 987654321;

int main(){

    FASTIO

    int N;

    cin >> N;
    
    for(int i=1; i<=N; i++){
        int sum = i;
        int temp = i;
        while(temp){
            sum += temp%10;
            temp /= 10;
        }

        if(sum == N){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}