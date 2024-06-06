
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
#include <cstdlib>
#include <list>
#include <stack>
#include <queue>
#include <unordered_set>
class Twit{
    public:
        Twit(){

        };
        Twit(int id_para, int timestamp_para){
            id = id_para;
            timestamp = timestamp_para;
        }
        int id;
        int timestamp;
        Twit* next = nullptr;
};
class User{
    public:
        User(){
            
        }
        User(int id_para) {
            id = id_para;
        }
        // User(const User& obj){
        //     id = obj.id;
        // }
        int id;
        unordered_set<int> follows;
        Twit* head = nullptr;
};


class Twitter {
public:
    unordered_map<int, User*> usermap;
    int timestamp = 0;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        if (usermap.find(userId) == usermap.end()){
            usermap[userId] = new User(userId);
        }
        
        // cout << "usermapid " << usermap[1]->id << endl;
        Twit* head = usermap[userId]->head;
        Twit* newTwit = new Twit(tweetId, ++timestamp);
        newTwit->next = head;
        usermap[userId]->head = newTwit;
    }
    struct Compare {
        bool operator()(const Twit* t1, const Twit* t2) const {
            return t1->timestamp < t2->timestamp; //min heap
        }
    };
    vector<int> getNewsFeed(int userId) {
        if (usermap.find(userId) == usermap.end()){
            usermap[userId] = new User(userId);
            return {};
        }
        priority_queue<Twit*, vector<Twit*>, Compare > queue;
        // std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, Compare> minHeap;
        if (usermap[userId]->head != nullptr){
            queue.push(usermap[userId]->head);
        }
        
        for(auto followee: usermap[userId]->follows){
            if (usermap[followee]->head != nullptr){
                queue.push(usermap[followee]->head);
            }
        }
        vector<int> res;
        for(int i = 0; ((i < 10) & (!queue.empty())); i++){
            Twit* top = queue.top();
            res.push_back(top->id);
            if (top->next != nullptr){
                queue.push(top->next);
            }
            queue.pop();
        }
        // reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (usermap.find(followerId) == usermap.end()){
            usermap[followerId] = new User(followerId);
        }
        if (usermap.find(followeeId) == usermap.end()){
            usermap[followeeId] = new User(followeeId);
        }
        usermap[followerId]->follows.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        usermap[followerId]->follows.erase(followeeId);
    }
};
int main(){
    Twitter* obj = new Twitter();
    obj->postTweet(1,5);
    obj->postTweet(1,3);
    for(auto item: obj->getNewsFeed(1)){
        cout << item << " ";
    }
    cout << endl;
    // obj->follow(1,2);
    // obj->postTweet(2,6);
    // for(auto item: obj->getNewsFeed(1)){
    //     cout << item  << " ";
    // }
    // cout << endl;
    // obj->unfollow(1,2);
    // for(auto item: obj->getNewsFeed(1)){
    //     cout << item << " ";
    // }
    // cout << endl;
}