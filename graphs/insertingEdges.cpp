#include<iostream>
#include<list>
using namespace std;
#include<unordered_map>
#include<vector>

class Graph{
  private:
  unordered_map<int,list<int>> adjlist;
  public:
  void addEdge(int u,int v,int direction){
    // direction represent that graph is direceted or not
    if (direction == 1){
      // means that we have directed graph
      adjlist[u].push_back(v);
    }
    else{
      // direction == 0
      // undirected graph case
      adjlist[u].push_back(v);
      adjlist[v].push_back(u);
    }
  }
  void display_graph(){
    for (auto i : adjlist){
      cout << i.first << "->"  << "{ ";
      for (auto j : i.second){
        cout << j << " ";
      }
      cout << " }" << endl;
    }
  }

};
int main(){
  Graph g;
  g.addEdge(2,4,1);
  g.addEdge(3,6,1);
  g.display_graph();

}