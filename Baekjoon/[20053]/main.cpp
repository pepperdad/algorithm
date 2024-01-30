#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;

int main(){

    FASTIO

    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        int n;
        cin >> n;

        int maxVal = -1000001, minVal = 1000001;

        for(int j=0; j<n; j++){
            int val;
            cin >> val;
            maxVal = max(maxVal, val);
            minVal = min(minVal, val);
        }

        cout << minVal << " " << maxVal << endl;
    }

    return 0;
}