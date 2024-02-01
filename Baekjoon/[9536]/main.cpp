#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<sstream>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;

const int INF = 987654321;

int main(){

    FASTIO

    int t;
    cin >> t;
    cin.ignore();

    for(int i=0; i<t; i++){
        string s;
        getline(cin, s);

        // 입력값을 처리하는 로직 추가
        stringstream ss(s); // stringstream 객체 생성
        string word;
        vector<string> sounds;

        while(ss >> word) {
            sounds.push_back(word); // 공백을 기준으로 분리된 문자열을 sounds 벡터에 저장
        }

        vector<string> existSound;
        do{
            getline(cin, s);
            if(s == "what does the fox say?") break;

            stringstream ss(s);
            while(ss >> word) {
                existSound.push_back(word); 
            }
            string exists;
        } while(true);

        for(int j=0; j<sounds.size(); j++){
            if(find(existSound.begin(), existSound.end(), sounds[j]) == existSound.end()){
                cout << sounds[j] << " ";
            }
        }
    }

    return 0;
}