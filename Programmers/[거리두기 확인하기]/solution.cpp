#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<vector<int>> board(10, vector<int>(10));
vector<vector<int>> min_distance(10, vector<int>(10));
vector<pair<int,int>> check;
vector<int> answer;

void func(){
    for(int i=0; i<check.size(); i++){
        int now_x = check[i].first;
        int now_y = check[i].second;
        
        // cout << "x: " << now_x << " y: " << now_y << "\n";
        
        if(i == check.size() - 1) min_distance[now_x][now_y] = 10;
        
        for(int j=i+1; j<check.size(); j++){
            int check_x = check[j].first;
            int check_y = check[j].second;
            
            int dis = abs(now_x - check_x) + abs(now_y - check_y);
            
            // cout << "x: " << check_x << " y: " << check_y << " dis: " << dis << "\n";
            
            if(dis <= 1) {
                return;
            }
            else if(dis <= 2){
                if(abs(now_x - check_x) == 1 && abs(now_y - check_y) == 1){
                    if(now_x < check_x && now_y < check_y){
                        if(board[min(now_x, check_x)][max(now_y, check_y)] == 1 && board[max(now_x, check_x)][min(now_y, check_y)] == 1) {
                            min_distance[now_x][now_y] = 10;
                        } else min_distance[now_x][now_y] = dis;
                    } else {
                        if(board[min(now_x, check_x)][min(now_y, check_y)] == 1 && board[max(now_x, check_x)][max(now_y, check_y)] == 1) {
                                min_distance[now_x][now_y] = 10;
                        } else min_distance[now_x][now_y] = dis;
                    }
                } else {
                    if(abs(now_x - check_x) > abs(now_y - check_y)) {
                        if(board[(now_x + check_x)/2][now_y] == 1){
                            min_distance[now_x][now_y] = 10;
                        } else {
                            min_distance[now_x][now_y] = dis;
                        }
                    } else {
                        if(board[now_x][(now_y + check_y)/2] == 1){
                            min_distance[now_x][now_y] = 10;
                        } else {
                            min_distance[now_x][now_y] = dis;
                        }
                    }
                }
            }
            else {
                if(min_distance[now_x][now_y] == 0) min_distance[now_x][now_y] = 10;
                else {
                    min_distance[now_x][now_y] = min(min_distance[now_x][now_y], dis);
                }
            }
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    
    for(int i=0; i<5; i++){
        board = vector<vector<int>> (10, vector<int>(10));
        min_distance = vector<vector<int>> (10, vector<int>(10));
        check.clear();
        
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                // cout << places[i][j][k] << " ";
                if(places[i][j][k] == 'P'){
                    board[j][k] = 0;
                    check.push_back({j, k});
                } 
                else if(places[i][j][k] == 'X') {
                    board[j][k] = 1;
                    min_distance[j][k] = 10;
                }
                else if(places[i][j][k] == 'O') {
                    board[j][k] = 2;
                    min_distance[j][k] = 10;
                }
            }
        }
        
        func();
        
        bool isLong = true;
        
        // for(int j=0; j<5; j++){
        //     for(int k=0; k<5; k++){
        //         cout << min_distance[j][k] << " ";
        //     }
        //     cout << "\n";
        // }
        
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                if(min_distance[j][k] <= 2){
                    isLong = false;
                    answer.push_back(0);
                    break;
                }
            }       
            if(!isLong) break;
        }
        if(isLong) answer.push_back(1);
    }
    
    // for(int i=0; i<answer.size(); i++){
    //     cout << answer[i] << " ";
    // }
    
    return answer;
}