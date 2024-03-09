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

int N, M;
vector<int> x;
vector<int> prime;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void func(int cnt, int idx, int sum)
{
	if (cnt == M){
        if(isPrime(sum))
			prime.push_back(sum);
		return;
	}

	for (int i = idx; i < N; i++)
		func(cnt + 1, i + 1, sum + x[i]);
}

int main(){

    FASTIO

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        x.push_back(a);
    }
    
    func(0, 0, 0);

    sort(prime.begin(), prime.end());
    prime.erase(unique(prime.begin(), prime.end()), prime.end());

    if(prime.size() == 0) cout << -1;
    else {
        for(int i = 0; i < prime.size(); i++){
            cout << prime[i] << endl;
        }
    }

    return 0;
}