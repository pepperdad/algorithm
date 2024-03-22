#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int friends_count = friends.size();
    vector<vector<int>> board(friends_count, vector<int>(friends_count));
    map<string, int> gift_points;
    map<string, int> friend_to_number;
    
    for(int i=0; i<friends_count; i++){
        friend_to_number[friends[i]] = i;
    }   
    
    for(int i =0; i<gifts.size(); i++){
        string record = gifts[i];
        
        int blank_num = record.find(" ");
        string giver = record.substr(0, blank_num);
        string taker = record.substr(blank_num+1, record.length());
        
        board[friend_to_number[giver]][friend_to_number[taker]] += 1;
        gift_points[giver] += 1;
        gift_points[taker] -= 1;
    }
    
    for(int i=0; i<friends_count; i++){
        int gift_count = 0;
        for(int j=0; j<friends_count; j++){
            if(i != j){
                if(board[i][j] - board[j][i] > 0) gift_count++;
                else if (board[i][j] - board[j][i] == 0){
                    if(gift_points[friends[i]] > gift_points[friends[j]] > 0){
                        gift_count++;
                    }
                }
            }
        }
        answer = max(answer, gift_count);
    }    
    
    return answer;
}