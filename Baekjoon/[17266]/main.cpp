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

int N, M;
vector<int> x;

bool is_possible(int mid) {
	if (x[0] - 0 > mid || N - x[x.size() - 1] > mid) return false;
	for (int i = 0; i < x.size() - 1; i++) {
		if ((x[i + 1] - x[i]) > mid * 2) return false;
	}
	return true;
}

int main(){

    FASTIO

    cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		x.push_back(a);
	}

	int left = 0, right = 1e9 + 2, ret = -1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (is_possible(mid)) {
			ret = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout << ret;

    return 0;
}