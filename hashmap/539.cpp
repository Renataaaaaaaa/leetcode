#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;


vector<string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

int findMinDifference(vector<string>& timePoints) {
    const int timeSlot = 1440; //0 ~ 1440
    bool myMap [timeSlot] =  {false};
    //00:00 23:59
    for (auto s: timePoints){
        std::vector<std::string> tokens = split(s, ':');
        int index = stoi(tokens[0]) * 60 + stoi(tokens[1]);
        if (myMap[index]){
            return 0;
        }
        myMap[index] = true;
    }

    int prev_i = -1;
    int res = INT32_MAX;
    int first_time = 0;
    for (int i = 0; i < timeSlot; i++){
        if (myMap[i]){
            if (prev_i == -1){
                first_time = i;
                prev_i = i;
            }else{
                res = min(i - prev_i, res);
                prev_i = i;
            }
        }
    }
    res = min(res, first_time + 1440 - prev_i);
    return res;
}

int main(){
    vector<string> data = {"00:00","23:59","00:00"};
    cout << findMinDifference(data) << endl;
}