#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<sstream>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;


int n, r, c;
int ans;

void Z(int y, int x, int size)
{
    if (y == r && x == c)
    {
        cout << ans;
        return;
    }

    // r,c가 현재 사분면에 존재한다면
    if (r < y + size && r >= y && c < x + size && c >= x)
    {
        // 1사분면 탐색
        Z(y, x, size / 2);
        // 2사분면 탐색
        Z(y, x + size / 2, size / 2);
        // 3사분면 탐색
        Z(y + size / 2, x, size / 2);
        // 4사분면 탐색
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else
    {
        ans += size * size;
    }
}

int main(){

    FASTIO

    cin >> n >> r >> c;
    int size = pow(2, n);
    Z(0, 0, size);

    return 0;
}