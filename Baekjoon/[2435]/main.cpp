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

int main(){

    FASTIO

    int N, K;
    cin >> N >> K;

    vector<int> v;

    for(int i=0; i<N; i++){
        int num;
        cin >> num;

        v.push_back(num);
    }

    vector<int> sum;

    for(int i=0; i<N +1-K;i++){    
        int add = 0;

        for(int j=i; j<i+K; j++){
            // cout << "i:" << i << " j:" << j << " v[j]:" << v[j] << endl;
            add += v[j];
        }
        // cout << "add: " << add << endl;

        sum.push_back(add);
    }

    int max = -INF;

    for(int i=0; i<sum.size(); i++){
        if(sum[i] > max){
            max = sum[i];
        }
    }

    cout << max << endl;

    return 0;
}