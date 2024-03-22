#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
    
map<string, pair<int,int>> my_map;
pair<int,int> left_thumb = {4,1};
pair<int,int> right_thumb = {4,3};
string main_hand;
string answer = "";

void func(int number){
    
    if(number == 1 || number == 4 || number == 7){
        left_thumb = my_map[to_string(number)];
        answer += "L";
    }
    
    else if(number == 3 || number == 6 || number == 9){
        right_thumb = my_map[to_string(number)];
        answer += "R";
    }
    else if(number == 2 || number == 5 || number == 8 || number == 0){
        int x = my_map[to_string(number)].first;
        int y = my_map[to_string(number)].second;
        
        int left_dis = abs(left_thumb.first-x) + abs(left_thumb.second-y);
        int right_dis = abs(right_thumb.first-x) + abs(right_thumb.second-y);
        
        if(left_dis > right_dis){
            answer += "R";
            right_thumb = my_map[to_string(number)];
        } 
        else if(left_dis < right_dis){
            answer += "L";
            left_thumb = my_map[to_string(number)];
        } else {
            if(main_hand == "left") {
                answer += "L";
                left_thumb = my_map[to_string(number)];
            }
            else {
                answer += "R";
                right_thumb = my_map[to_string(number)];
            }
        }
    }
}

string solution(vector<int> numbers, string hand) {
    
    main_hand = hand;
    
    my_map["1"] = {1,1};
    my_map["2"] = {1,2};
    my_map["3"] = {1,3};
    my_map["4"] = {2,1};
    my_map["5"] = {2,2};
    my_map["6"] = {2,3};
    my_map["7"] = {3,1};
    my_map["8"] = {3,2};
    my_map["9"] = {3,3};
    my_map["*"] = {4,1};
    my_map["0"] = {4,2};
    my_map["#"] = {4,3};
    
    for(int i=0; i<numbers.size();i++){
        func(numbers[i]);
    }
    
    return answer;
}