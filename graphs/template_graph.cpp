#include<iostream>
using namespace std;


template <typename T>
class Graph{
  public:
  unordered_map<T,list<pair<T,T>>> adjList; // Adjacency list to
  void addEdge(T u,T v,T wt,bool direction){
    if (direction == 1){
      adjList[u].push_back(make_pair(v,wt));
    }
    else{
      adjList[u].push_back(make_pair(v,wt));
      adjList[v].push_back(make_pair(u,wt));
    }
  }
  void display(){
    for (auto i :  adjList) {
      cout << i.first << "- { ";
      for (auto j : i.first){
        cout << j.first << "," << j.second;
      }
      cout<< "} " ;
    }
  }
}