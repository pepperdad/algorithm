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

vector<vector<string>> dp(105, vector<string>(105, "0"));

string addNum(string s1, string s2){

    string result = "";
    if (s1.length() > s2.length()) {
		while (s1.length() != s2.length()) {
			s2 = "0" + s2;
		}
	}
	else {
		while (s1.length() != s2.length()) {
			s1 = "0" + s1;
		}
	}

	int sum = 0;
	for (int i = s1.length()-1; i >=0; i--) {
	
		sum += s1[i] - '0';
		sum += s2[i] - '0';
		
		result = to_string(sum % 10) + result;
		if (sum >= 10) {
			
			sum = 1;
		}
		else {
			sum = 0;
		}
	}
	if (sum == 1) {
		return "1" + result;
	}

	return result;
}

int main(){

    FASTIO

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=100; i++){
        dp[i][0] = "1";
        dp[i][1] = to_string(i);
        dp[i][i-1] = to_string(i);
        dp[i][i] = "1";
    }

    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            dp[i][j] = addNum(dp[i-1][j], dp[i-1][j-1]);
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}