// level order traversal
// queue data structure is used
#include<bits/stdc++.h>
using namespace std;

int main (){

    queue<int> q;
    cout << "Breadth first search implementation using adjacency matrix." << endl;
    vector<int> visited = {0,0,0,0,0,0,0};
    vector<vector<int>> A = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    }; 
    int i=1;
    cout << i << " ";
    visited[i] = 1;
    q.push(i);

    while( !q.empty() ){
        int node = q.front();
        q.pop();
        for( int j=0 ; j<A.size() ; j++ ){
            if(A[node][j] == 1 && visited[j] == 0 ){
                cout << j << " ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    return 0;
}