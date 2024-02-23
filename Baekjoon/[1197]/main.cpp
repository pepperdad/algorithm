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

int parent[10001+5];

int find(int x) {
    if (parent[x] == x)return x;
    else return parent[x] = find(parent[x]); 
}

void uni(int x, int y) {
    x = find(x); 
    y = find(y); 
    parent[y] = x; 
}

bool sameparent(int x, int y) {
    x = find(x); 
    y = find(y); 
    if (x == y)return true;
    else return false; 
}

int main(){

    FASTIO

    int V, E, result = 0;
    vector<pair<int, pair<int, int>>> v; 

    cin >> V >> E;

    for(int i=0; i<E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}}); 
    }

    sort(v.begin(), v.end()); 

    for (int i = 1; i <= V; i++) parent[i] = i; 

    for (int i = 0; i < v.size(); i++) {

		if (!sameparent(v[i].second.first, v[i].second.second)) {
			uni(v[i].second.first, v[i].second.second); 
			result += v[i].first; 
		}
	}

	cout << result; 

    return 0;
}