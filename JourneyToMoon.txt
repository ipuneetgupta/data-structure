#include <iostream>
#include<list>
using namespace std;


class Graph{
    int V;
    list<int> *l;
    public:
      Graph(int v){
          V=v;
          l=new list<int>[V];
      }
      void addEdge(int u,int v){
          l[u].push_back(v);
          l[v].push_back(u);
      }
      void dfsHelper(int i,bool Visited[],int &C_size){
            Visited[i]=true;
            C_size++;
            for(auto neigh:l[i]){
                if(!Visited[neigh]){
                    dfsHelper(neigh,Visited,C_size);
                }
            }
      }
      int dfsMoon(){
          bool *Visited=new bool[V];
          for(int i=0;i<V;i++){
              Visited[i]=false;
          }
          int TotalWays=(V)*(V-1)/2;
          for(int i=0;i<V;i++){
              int C_size=0;//countrysize
              if(Visited[i]==false){
                  dfsHelper(i,Visited,C_size);
                //  cout<<C_size<<endl;
                TotalWays-=(C_size)*(C_size-1)/2;
              }
          }
          return TotalWays;
      }
};
int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(0,4);
    cout<<g.dfsMoon();
}
