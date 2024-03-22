#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<string> oper = {"+", "-", "*"};
vector<pair<char, int>> list;
vector<long long> numbers_tmp;
long long answer = -1;
int count_decrease[100] ={0, };

long long calWithOper(string s, long long num1, long long num2){
    if(s == "+"){
        return num1 + num2;
    } else if(s == "-"){
        return num1 - num2;
    } else {
        return num1 * num2;
    }
}

void func(string prior){
    priority_queue<pair<int, int>> pq;
    
    vector<long long> numbers = numbers_tmp;
    
    for(int i=0; i<list.size(); i++){
        if(list[i].first == prior[0]){
            pq.push({0, -list[i].second});
        } else if(list[i].first == prior[1]){
            pq.push({-1, -list[i].second});
        } else if(list[i].first == prior[2]){
            pq.push({-2, -list[i].second});
        }
    }
    
    while(!pq.empty()){
        int oper_num = -pq.top().first;
        int number_num = -pq.top().second;
        pq.pop();

        int decre = 0;
        for(int i=number_num; i>=0; i--){
            decre += count_decrease[i];
        }

        
        numbers[number_num-1-decre] = calWithOper(string(1, prior[oper_num]), numbers[number_num-1-decre], numbers[number_num-decre]);

        for(int i=number_num-decre; i<numbers.size() - 1; i++){
            numbers[i] = numbers[i+1];
        }

        count_decrease[number_num] += 1;
        numbers.pop_back();
    }
    
    answer = max(answer, abs(numbers[0]));
    return;
}

long long solution(string expression) {
    
    string tmp = "";
    for(int i=0; i<expression.size(); i++){
        if(find(oper.begin(), oper.end(), string(1, expression[i])) != oper.end()){
            list.push_back({expression[i], list.size() + 1});
            numbers_tmp.push_back(stoi(tmp));
            tmp = "";
        } else{
            tmp += expression[i];
            
            if(i == expression.size()-1){
                numbers_tmp.push_back(stoi(tmp));
            }
        }
    }
    
    func("+*-");
    func("+-*");
    func("*+-");
    func("*-+");
    func("-+*");
    func("-*+");
    
    return answer;
}

int main(){

    solution("100-200*300-500+20");

    return 0;
}