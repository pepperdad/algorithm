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

vector<int> v;

int dp(int start, int remain_count, int even_count){

    if(start == v.size()) {
        return even_count;
    }

    for(int i=start; i<v.size(); i++){
        if(v[i] % 2 == 0){
            return dp(i+1, remain_count, even_count+1);
        } 
        else{
            if(remain_count == 0) return even_count;
            return dp(i+1, remain_count-1, even_count);
            
        }
    }
}

int main(){

    FASTIO

    int N, K;

    cin >> N >> K;

    for(int i=1; i <= N; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    int longest_even_sequence = 0;

    for (int i = 0; i < v.size(); i++) {

        if(v[i] % 2 == 0){
            longest_even_sequence = max(longest_even_sequence, dp(i+1, K, 1));

        }
        else{
            longest_even_sequence = max(longest_even_sequence, dp(i+1, K-1, 0));
        }
    }

    cout << longest_even_sequence;

    return 0;
}

