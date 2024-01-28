#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

    int N, M, R;

    cin >> N >> M >> R;

    int arr[300][300];

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    int group = min(N, M)/2;

    for(int i=0; i<group; i++){
        int r = R % (2*(N+M-4*i)-4);

        for(int j=0; j<r; j++){
            int temp = arr[i][i];
            for(int k=i; k<M-i-1; k++){
                arr[i][k] = arr[i][k+1];
            }
            for(int k=i; k<N-i-1; k++){
                arr[k][M-i-1] = arr[k+1][M-i-1];
            }
            for(int k=M-i-1; k>i; k--){
                arr[N-i-1][k] = arr[N-i-1][k-1];
            }
            for(int k=N-i-1; k>i; k--){
                arr[k][i] = arr[k-1][i];
            }
            arr[i+1][i] = temp;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}