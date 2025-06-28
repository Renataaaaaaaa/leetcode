#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


void buildGraph(vector<string>& equations, unordered_map<char, vector<char>>& graph){
    for (int i = 0; i < equations.size(); i++){
        if (equations[i][1] == '='){
            char start = equations[i][0];
            char end = equations[i][3];
            graph[start].push_back(end);
            graph[end].push_back(start);
        }
    }
}
bool dfs(unordered_map<char, vector<char>>& graph, char s, char d, set<char>& visited){
    if (s == d){
        return true;
    }
    visited.insert(s);
    for(auto point: graph[s]){
        if (visited.find(point) == visited.end()){
            if (dfs(graph, point, d, visited)){
                return true;
            }
        }
    }
    return false;
}
bool equationsPossible(vector<string>& equations) {
    unordered_map<char, vector<char>> graph;
    buildGraph(equations, graph);
    for(auto equation: equations){
        if (equation[1] == '!'){
            set<char> visited;
            if (dfs(graph, equation[0], equation[3], visited)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<string> equations = {"c==c","b==d","x!=z"};
    cout << equationsPossible(equations) << endl;
}