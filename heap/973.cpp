#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;


vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    
}
int main(){
    vector<vector<int>> data = {{}, {}, {}};
    for (auto list: kClosest(data, 3)){
        for (auto item: list){
            cout << item;
        }
        cout << endl;
    }
}