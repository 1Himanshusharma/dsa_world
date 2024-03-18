#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
#include<list>



// for normal graph
class graph{
  private:
  unordered_map<int,list<int>> adjlist;
  public:
  void addEdge(int u,int v,int direction){
    if (direction == 1){
      adjlist[u].push_back(v); // push back the vertex to the list
    }
    else{
      // undirected graph
      adjlist[u].push_back(v);
      adjlist[v].push_back(u);
    }
  }
  void display(){
    for (auto i: adjlist){
      cout << i.first << "->" << "{ ";
      for (auto j : i.second){
        cout << j << ",";
      }
      cout << endl;
    }
  }
};

// for weighted graph
class graph2{
  private:
  unordered_map<int,list<pair<int,int>>> adjList;
  public:
  void addEdge(int u,int v,int wt,int direction){
    if (direction == 1){
      adjList[u].push_back(make_pair(v,wt));
      
    }
    else{
      // direction == 0
      // undirected graph
      adjList[u].push_back(make_pair(v,wt));
      adjList[v].push_back(make_pair(u,wt));
    }
  }
  void display(){
    for (auto i : adjList){
      cout << i.first << "-> " << "{ ";
      for (auto j : i.seocnd){
        cout << "(" << i.first << "," << i.second << "), ";

      }
      cout << endl;
    }
  }
};

int main(){
  graph2 g;

}