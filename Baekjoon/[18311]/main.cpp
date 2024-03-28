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

    int N;
    long long K;
    cin >> N >> K;

    long long sum = 0;

    vector<int> v;
    v.push_back(0);

    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);

        sum += num;
    }

    if(sum > K){
        long long val = 0;
        for(int i=0; i<v.size();i++){
            val += v[i+1];

            if(val > K){
                cout << i+1 << endl;
                break;
            } else {
                continue;
            }
        }
    }
    else{
        int check_num = K - sum;
        int val = 0;

        for(int i=v.size()-1; i>0; i--){
            // cout << "i:" << i << " " << v[i] << endl;
            val += v[i];

            if(val > check_num){
                cout << i << endl;
                break;
            } else {
                continue;
            }
        }
    }

    return 0;
}