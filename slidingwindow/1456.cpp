#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

int maxVowels(string s, int k) {
    int vowel_nums = 0;
    int vowel_nums_max = 0;
    int left = 0;
    
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    for (int right = 0; right < s.size(); right++){
        vowel_nums = find(vowels.begin(), vowels.end(), s[right]) == vowels.end() ? vowel_nums : vowel_nums + 1;
        if (right - left + 1 > k ){
            vowel_nums = find(vowels.begin(), vowels.end(), s[left]) == vowels.end() ? vowel_nums : vowel_nums - 1;
            left++;
        }
        vowel_nums_max = max(vowel_nums, vowel_nums_max);
    }
    return vowel_nums_max;
}

int main(){
    string s = "leetcode";
    cout << maxVowels(s, 10) << endl;
}