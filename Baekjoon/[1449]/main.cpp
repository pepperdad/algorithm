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

vector<int> v;
int N, L;
int result = 0;

void func(){
    int start = v[0];
    int end = v[0] + L - 1;

    for(int i=1; i<v.size(); i++){
        if(v[i] >= start && v[i] <= end){
            continue;
        }else{
            start = v[i];
            end = v[i] + L - 1;
            result++;
        }
    }

    cout << result + 1 << endl;
}

int main(){

    FASTIO

    cin >> N >> L;


    for(int i=0; i<N; i++){
        int num;
        cin >> num;

        v.push_back(num);
    }

    sort(v.begin(), v.end());

    func();

    return 0;
}