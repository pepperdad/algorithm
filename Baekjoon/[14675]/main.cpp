#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;

vector<vector<int>> tree; 

int main(){

    FASTIO
    int N, q;
    cin >> N;

    tree = vector<vector<int>>(N+1);

    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    cin >> q;

    for(int i=0; i<q; i++){
        int t, k;
        cin >> t >> k;
        if(t == 1){
            if(tree[k].size() >= 2){
                cout << "yes\n";
            }
            else
                cout << "no\n";
        }
        else if(t == 2){
            cout << "yes\n";
        }
    }

    return 0;
}