#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> s;
    
    for(int i=0; i<moves.size(); i++){
        
        bool flag = false;
        for(int j=0; j<board.size(); j++){
            for(int k=0; k<board[j].size(); k++){
                if(moves[i] == k+1 && board[j][k] != 0){
                    if(!s.empty() && s.top() == board[j][k]){
                        s.pop();
                        answer += 2;
                        board[j][k] = 0;
                    }
                    else {
                        s.push(board[j][k]);
                        board[j][k] = 0;
                    }
                    
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
    }
    return answer;
}