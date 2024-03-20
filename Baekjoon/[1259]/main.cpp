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

bool isPellindrome(string s){
    int len = s.length();
    for(int i = 0; i < len / 2; i++){
        if(s[i] != s[len - i - 1]){
            return false;
        }
    }
    return true;
}

int main(){

    FASTIO

    while(true){
        string s;
        cin >> s;

        if(s == "0"){
            break;
        }

        if(isPellindrome(s)){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }

    return 0;
}