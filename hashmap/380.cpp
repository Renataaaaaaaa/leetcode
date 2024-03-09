#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public: 
    vector<int> nums;
    unordered_map<int, int> mapName;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mapName.find(val) == mapName.end()){
            nums.push_back(val);
            mapName[val] = nums.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (mapName.find(val) != mapName.end()){
            int tmp = nums[nums.size() - 1];
            nums[mapName.at(val)] = tmp;
            nums.erase(nums.begin() + nums.size() - 1);
            mapName[tmp] = mapName.at(val);
            mapName.erase(val);

            return true;
        }
        return false;
    }
    
    int getRandom() {
        cout << nums.size() << endl;
        return nums[rand() % nums.size()];
    }
};