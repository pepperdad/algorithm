#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

    int a, b;
    int sum = 0;

    vector<int> num(9);

    for (int i = 0; i < 9; i++){
        cin >> num[i];
        sum += num[i];
    }

    for(int i = 0; i < 9; i++)
        for(int j = i + 1; j < 9; j++){
            if(sum - (num[i] + num[j])== 100){
                a = i;
                b = j;
            }
        }

    for(int i=0; i<9; i++)
        if(i != a && i != b)
            cout << num[i] << endl;

    return 0;
}