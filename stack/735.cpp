#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> balls;
    if (asteroids.size() <= 1){
        return asteroids;
    }
    balls.push(asteroids[0]);
    int last = asteroids[0];
    int current = 0;
    for (vector<int>::size_type i = 1; i<asteroids.size(); i++){
        current = asteroids[i];
        while(balls.size() > 0 && (balls.top() > 0 and current < 0) && (abs(current) > abs(balls.top()))){ //last is over
            balls.pop();
        }
        if (balls.size() > 0 && (balls.top() > 0 and current < 0) && (abs(current) ==  abs(balls.top()))){
            balls.pop();
        } //both dead
        else if (balls.size() == 0 || !((balls.top() > 0 and current < 0) && abs(balls.top()) > abs(current))){
            balls.push(current);
        }
    }
    vector<int> res;
    while(balls.size() != 0){
        res.push_back(balls.top());
        balls.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    vector<int> data = {10,2,-5};
    // vector<int> data = {8,-8};
    for (auto item : asteroidCollision(data)){
        cout << item << endl;
    }
}