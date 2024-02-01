#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<sstream>
#include<set>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;

const int INF = 987654321;

int main(){

    FASTIO

    int n, m, cnt = 0;
    cin >> n >> m;

    set<string> s;

    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        s.insert(str);
    }

    for(int i=0; i<m; i++){
        string str;
        cin >> str;
        auto pos = s.find(str);
        if(pos != s.end()) cnt++;
    }

    cout << cnt << endl;

    return 0;
}