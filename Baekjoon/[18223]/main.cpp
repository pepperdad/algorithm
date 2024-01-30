#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;

const int INF = 987654321;
vector<pair<int,pair<int,int>>> graph;
priority_queue<pair<int,pair<int, int>>> pq;
int dist[5005];
vector<int> v[5005];
vector<int> res;
int V, E, P;
bool flag = false;

int dijikstra(int start, int end){
    fill(&dist[0], &dist[5005 - 1], INF);

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

		if (dist[now] != INF || dist[now] == cost) continue;
		dist[now] = cost;
		v[now].push_back(prior);

		for (auto e : graph) {
			if (e.first == now) {
				pq.push({ -(cost + e.second.second), {now, e.second.first} });
			}
		}
	}

    return dist[end];
}

int main(){

    FASTIO

    cin >> V >> E >> P;

    if(P == 1){
        cout << "SAVE HIM";
        return 0;
    }

    for(int i=0; i<E; i++){
        int a, b, c;
        cin >> a >> b >> c;

        graph.push_back({a, {b, c}});
        graph.push_back({b, {a, c}});
    }

    if(dijikstra(1,P) + dijikstra(P,V) <= dijikstra(1,V)){
        cout << "SAVE HIM";
    }
    else cout << "GOOD BYE";

    return 0;
}