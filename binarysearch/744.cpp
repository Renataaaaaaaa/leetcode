#include <vector>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    int lo = 0;
    int hi = letters.size() - 1;
    int mid;
    while(hi >= lo){
        mid = (lo + hi) / 2;
        if (letters[mid] > target){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    if (lo > 0 && lo <= letters.size() - 1){
        return letters[lo];
    }else{
        return letters[0];
    }
}