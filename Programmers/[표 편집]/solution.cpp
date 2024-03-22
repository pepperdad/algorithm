#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
bool is_same_board[1000001];

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<string> board;
    stack<pair<string, string>> tmp;
    int now_row = k;

    int end = n-1;
    
    for(int i=0; i<n; i++){
        board.push_back(to_string(i));
    }

    for(int i=0; i<cmd.size(); i++){
        cout << cmd[i] << " " << now_row;
        if(cmd[i][0] == 'U'){
            now_row -= stoi(cmd[i].substr(2));
        } else if(cmd[i][0] == 'D'){
            now_row += stoi(cmd[i].substr(2));
        } else if(cmd[i][0] == 'C'){
            string key = board[now_row];

            tmp.push({key, to_string(stoi(key)+1)});
            
            auto it = find(board.begin(), board.end(), key);
            
            if(board[now_row] == board[board.size()-1]){
                now_row -= 1;
            }
    
            board.erase(it);
        } else if(cmd[i][0] == 'Z'){
            string add_key = tmp.top().first;
            string sub_key = tmp.top().second;
            tmp.pop();

            if(stoi(sub_key) <= now_row) now_row += 1;
            
            auto it = find(board.begin(), board.end(), sub_key);
            board.insert(it, add_key);
        }

        cout << " => " << now_row << "\n";

        for(int j=0; j<board.size(); j++){
            cout << board[j] << " ";
        }
        cout << "\n";
    }
    
    while(!tmp.empty()){
        int key = stoi(tmp.top().first);
        is_same_board[key] = true;
        tmp.pop();
    }
    
    for(int i=0; i<n; i++){
        if(is_same_board[i]) answer += "X";
        else answer += "O";
    }
    
    cout << answer;
    return answer;
}