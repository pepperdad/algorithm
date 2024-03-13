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

int main(){

    FASTIO

    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        string t1, t2;
        cin >> t1 >> t2;

        int maxLen = max(t1.length(), t2.length());

        if(t1.length() < maxLen){
            t1 = string(maxLen - t1.length(), '0') + t1;
        } 
        if(t2.length() < maxLen) {
            t2 = string(maxLen - t2.length(), '0') + t2;
        } 

        // cout << t1 << " " << t2 << endl;

        reverse(t1.begin(), t1.end());
        reverse(t2.begin(), t2.end());


        string result = "";
        bool upper = false;

        for(int i = 0; i < maxLen; i++){
            // cout << t1[i] << " " << t2[i] << endl;

            if(t1[i] == '1' && t2[i] == '1'){
                if(upper) result += '1';
                else result += '0';

                upper = true;
            }
            else if(t1[i] == '0' && t2[i] == '0'){
                if(upper) {
                    result += '1';
                    upper = false;
                }
                else result += '0';
            }
            else{
                if(upper) {
                    result += '0';
                    upper = true;
                }
                else {
                    result += '1';
                    upper = false;
                }
            }
        }

        reverse(result.begin(), result.end());

        if(upper) cout << "1" + result << endl;
        else {
            while(result[0] == '0'){
                result = result.substr(1);
            }
            
            if (result == "") cout << "0" << endl;
            else cout << result << endl;
        }
    }

    return 0;
}