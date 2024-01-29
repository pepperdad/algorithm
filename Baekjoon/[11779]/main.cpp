#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <queue>
#define MAX_N 1000+5
#define endl "\n"
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;

const int INF = 987654321;
vector<pair<int,pair<int,int>>> graph;
int dist[MAX_N];
vector<int> v[MAX_N];
priority_queue<pair<int,pair<int, int>>> pq;
vector<int> res;

void dijikstra(int start){
    dist[start] = 0;

    for (auto e : graph) {
        if(e.first == start) {
            pq.push({ -e.second.second, {start, e.second.first } });
        }
    }

    while (!pq.empty()) {
		int cost = -pq.top().first; 
		int now = pq.top().second.second;
		int prior = pq.top().second.first;
		pq.pop();

		if (dist[now] != INF) continue;
		dist[now] = cost;
		v[now].push_back(prior);

		for (auto e : graph) {
			if (e.first == now) {
				pq.push({ -(cost + e.second.second), {now, e.second.first} });
			}
		}
	}
}

void printroute(int now) {
	if(v[now].size() != 0 ){
		printroute(v[now][0]);
		res.push_back(now);
	}

	else res.push_back(now);
}

int main() {
    FASTIO
    
    fill(&dist[0], &dist[MAX_N - 1], INF);

    int n, m, s, e;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({a, {b, c}});
    }

    cin >> s >> e;

    dijikstra(s);
    cout << dist[e] << endl;

    printroute(e);
	cout << res.size() << endl;

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

    return 0;
}