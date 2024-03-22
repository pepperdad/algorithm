#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int eight_count = 0;
int line_count = 0;
int donut_count = 0;
vector<int> eight_graph;
bool flag = false;
vector<int> given[1000005];
vector<int> taken[1000005];

void func(int start_node, int now){
    // cout << "now: " << now << endl;
    if(given[now].size() == 0) {
        line_count++;
        // cout << "line count up: " << line_count << endl;
        return;
    }
    else {
        if(eight_graph.end() != find(eight_graph.begin(), eight_graph.end(), now)){
            eight_count++;
            // cout << "eight count up: " << eight_count << endl;
            return;
        }
        else if (start_node == now) {
            if(!flag) {
                flag = true;
                func(start_node, given[now][0]);
            } else{
                donut_count++;
                // cout << "donut count up: " << donut_count << endl;
                return;
            }
        }
        else {
            func(start_node, given[now][0]);
        }
    }
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;

    int center_node;
    
    for(int i=0; i<edges.size(); i++){
        given[edges[i][0]].push_back(edges[i][1]);
        taken[edges[i][1]].push_back(edges[i][0]);
    }
        
    // center node 찾기
    for(int i=0; i<edges.size() + 2; i++){
        if(given[i].size() >= 2){
            if(taken[i].size() == 0){
                center_node = i;
            }
            else {
                eight_graph.push_back(i);
            }
        }
    }
    
    vector<int> check;
    
    for(int i=0; i<given[center_node].size(); i++){
        check.push_back(given[center_node][i]);
    }
    
    // for(int i=0; i<5; i++){
    //     cout << i <<"번째 ";
    //     for(int j=0; j<given[i].size(); j++){
    //         cout << given[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    for(int i=0; i<check.size(); i++){
        func(check[i], check[i]);
        flag = false;
    }
        
    // cout << donut_count << " " << line_count << " " << eight_count; 
    
    return {center_node, donut_count, line_count, eight_count};
}