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

    int n;
    cin >> n;

    int divWithFive = n / 5;
    int restWithFive = n - divWithFive * 5;
    
    if(restWithFive == 0){
        cout << divWithFive;
        return 0;
    }

    while(restWithFive > 0){
        int divWithTwo = restWithFive / 2;
        if(divWithFive * 5 + divWithTwo * 2 == n){
            cout << divWithFive + divWithTwo;
            return 0;
        }
        else{
            divWithFive--;
            restWithFive = n - divWithFive * 5;
        }

        if(divWithFive < 0){
            cout << -1;
            return 0;
        }
    }

    return 0;
}