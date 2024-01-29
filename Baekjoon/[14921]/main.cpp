#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;

vector<int> liquid;

int main(){

    FASTIO
    int N;
    cin >> N;

    liquid = vector<int>(N);

    for(int i=0; i<N; i++){
        cin >> liquid[i];
    }

    int left = 0, right = N-1;
    int res = 2000000000;

    bool bu = 0;

    for(int i=0; i<N; i++){
        if(left >= right) break;    
        if(liquid[left] + liquid[right] == 0){
            cout << 0;
            return 0;
        }
        else if(liquid[left] + liquid[right] > 0){
            if(abs(res) > abs(liquid[left] + liquid[right])){
                bu = true;
                res = min(abs(res), abs(liquid[left] + liquid[right]));
            }
            right--;
        }
        else{
            if(abs(res) > abs(liquid[left] + liquid[right])){
                bu = false;
                res = min(abs(res), abs(liquid[left] + liquid[right]));
            }
            left++;
        }
    }

    if(bu) cout << res;
    else cout << -res;
    return 0;
}