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
    int last = 0;
    int current = 0;
    for (vector<int>::size_type i = 1; i<asteroids.size(); i++){
        if (balls.size() == 0){
            balls.push(asteroids[i]);
            continue;
        }else{
            last = balls.top();

        }
        current = asteroids[i];
        cout << "current " << current << endl;
        bool push_current = true;
        while((last > 0 and current < 0) && (abs(current) >= abs(last))){ //last is over
            cout << "kill last " << last << endl;
            balls.pop();
            cout << "21" << endl;
            cout << (balls.size() == 0) << endl;
            if (abs(current) == abs(last)){
                push_current = false;
            }
            if (balls.size() == 0){
                break;
            }
            if (abs(current) == abs(last)){
                push_current = false;
                break;
            }else{
                push_current = true;
            }
            last = balls.top();

        }
        cout << (! ((last > 0 and current < 0) && (abs(current) <= abs(last)))) << endl;
        if (push_current && ! ((last > 0 and current < 0) && (abs(current) <= abs(last)))){ //current is pushed
            cout << "push current" << current << endl;
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