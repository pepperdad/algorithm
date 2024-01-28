#include<iostream>

using namespace std;

int main(){

    int res = 0;
    int count;
    cin >> res;

    if(res % 2  == 1) count = 2;
    else count = 1;

    if(res == 1 || res == 2 || res == 4) {
        cout << 1 << endl;
        return 0;
    }

    if(res == 3) {
        cout << 2 << endl;
        return 0;
    }

    for(int i = 3; i <= res; i=i+2){
        if(res % i ==0){
            if(res / i > 1){
                // cout << res << i << endl;
                count++;
            }
        }
    }
    
    cout << count << endl;

    return 0;
}