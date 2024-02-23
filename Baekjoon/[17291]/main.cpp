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

priority_queue<int> pq;
priority_queue<int> pq2;


int main(){

    FASTIO

    int N;
    cin >> N;

    pq.push(-3);

    for(int i=2; i<=N; i++){

        int size = pq.size();

        for(int j=0;j<size;j++){
            if(i % 2 == 0) pq2.push(-4);
            else pq2.push(-3);

            int t = pq.top();
            pq.pop();

            if(t+1 != 0){
                pq2.push(t+1);
            }
        }
        pq = pq2;
        
        while(!pq2.empty()) pq2.pop();
    }

    cout << pq.size();


    return 0;
}