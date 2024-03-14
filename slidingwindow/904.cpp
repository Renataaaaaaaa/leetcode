#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;


int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> map;
    int left = 0; 
    // int right = 0;

    int res = 0;
    int res_max = 0;
    for(int right = 0; right < fruits.size(); right++){
        ++map[fruits[right]];
        while(map.size() > 2){
            auto it = map.find(fruits[left]);
            (*it).second--;
            if ((*it).second == 0){
                map.erase(fruits[left]);
            }
            left++;
        }
        res = right - left + 1;
        res_max = max(res, res_max);
    }
    return res_max;
}

int main(){
    vector<int> data = {1,2,3};
    cout << totalFruit(data) << endl;

}