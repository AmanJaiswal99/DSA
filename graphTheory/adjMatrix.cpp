#include <iostream>
using namespace std;

int main(){
    int n,m;
    cout << "enter number of nodes in the graph" << endl;
    cin >> n;
    cout << "enter number of edges in the graph" << endl;
    cin >> m;
    cout << "enter the pair of nodes repesenting edges" << endl;
    
    int adj[n+1][n+1] = {0};

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u][v]=1;
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(adj[i][j]==1){
                cout << "edge goes from " << i << " to " << j << endl;
            }
        }
    }
    return 0;
}