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

    int last_true = 0;
    for (int j = timeSlot - 1; j >= 0 ; j--){
        if (myMap[j]){
            last_true = j;
            break;
        }
    }
    cout << last_true << endl;
    int prev_i = -1;
    int res = INT32_MAX;
    for (int i = 0; i <= last_true; i++){
        if (myMap[i]){
            int diff = 0;
            if (prev_i == -1){
                diff = i + 1440 - last_true;

            }else{
                diff = i - prev_i;
            }
            if (i - prev_i < res){
                res = diff;
            }
            prev_i = i;
        }
    }
    return res;
}