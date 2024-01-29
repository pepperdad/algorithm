#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;

int main(){

    FASTIO

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    for(int i=-999; i<=999; i++){
        for(int j=-999; j<=999; j++){
            if(a*i + b*j == c){
                if(d*i + e*j == f){
                    cout << i << " " << j << "\n";
                    return 0;
                }
            }
        }
    }


    return 0;
}