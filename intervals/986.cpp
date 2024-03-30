#include <vector>
#include <iostream>
#include <ctype.h>
#include <numeric>
#include <unordered_set>
using namespace std;


// vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
//     vector<vector<int>> res;

//     for (int i = 0; i < firstList.size(); i++){
//         for (int j = 0; j < secondList.size(); j++){
//             if (secondList[j][0] > firstList[i][1] || secondList[j][1] < firstList[i][0]){
//                 continue;;
//             }
//             res.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
//         }
//     }
//     return res;
// }
vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    vector<vector<int>> res;
    int i = 0;
    int j = 0;
    while(i < firstList.size() && j < secondList.size()){
        int start = max(firstList[i][0], secondList[j][0]);
        int end = min(firstList[i][1], secondList[j][1]);
        if (start <= end){
            res.push_back({start, end});
        }
        if (firstList[i][1] > secondList[j][1]){
            j++;
        }else{
            i++;
        }
    }
    return res;
}

int main(){
    vector<vector<int>> firstList = {{0,2}, {5,10}, {13,23}, {24,25}};
    vector<vector<int>> secondList = {{1,5}, {8,12}, {15,24}, {25,26}};
    for (auto list : intervalIntersection(firstList, secondList)){
        for (auto item: list){
            cout << item << " ";
        }
        cout << endl;
    }
}