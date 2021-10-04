#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cout << "enter the number of nodes" << endl;
    cin >> n;
    cout << "enter the number of edges" << endl;
    cin >> m;
    vector<int> adj[n+1];
    cout << "enter the edge pair" << endl;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}