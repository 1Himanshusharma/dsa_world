#include<iostream>
using namespace std;
#include<list>
#include<unordered_map>
#include<vector>


class graph{
  private:
  unordered_map<int,list<pair<int,int>>> adjlist;
  // wehere now list is storing the pair of element and associated wight
  public:
  void addEdge(int u,int v,int wt,int direction){
    if (direction == 1){
      // this means that graph is a directed graphs
      adjlist[u].push_back(make_pair(v,wt));
    }
    else{
      // direction == 0
      // undirected graph
      adjlist[u].push_back(make_pair(v,wt));
      adjlist[v].push_back(make_pair(u,wt));
    }
  }

  void display(){
    for (auto i : adjlist){
      cout << i.first << "-> " << "{ ";
      for (auto j : i.second){
        cout << "(" << j.first  << ","<< j.second << ")" << ",";
      }
      cout << " }";
      cout << endl;
    }
  }
};
int main(){
  graph g;
  g.addEdge(0,1,10,1);
  g.addEdge(0,2,12,1);
  g.addEdge(1,3,43,1);
  g.addEdge(4,7,18,1);
  g.display();
}