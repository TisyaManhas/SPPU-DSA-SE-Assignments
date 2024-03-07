/* Program BFT and DFT using adjacency matrix as input */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
    
void input(int a,int b)
{
    adj[a][b]=1;
    adj[b][a]=1;
}
void bft(int s,int v,vector <bool> visited)
{
    queue<int> q;
    q.push(s);

    visited[s]=true;

    while(!q.empty())
    {
        int start=q.front();
        q.pop();
        cout<<start<<" ";
    
    for(int i=0;i<v;i++)   
    {
        
        if(adj[start][i]==1 and (!visited[i]))
        {
            visited[i]=true;
            q.push(i);
        }
    }      
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
}


void dft(int s,int v,vector <bool> &visited)
{
    cout<<s<<" ";
    visited[s]=true;

    for(int i=0;i<v;i++)
    {
        if(adj[s][i]==1 and (!visited[i]))
        {
        visited[i]=true;
        dft(i,v,visited);
        }
    }
}


int main()
{
    int v=5;             // number of vertices

    adj= vector<vector<int>> (v,vector<int>(v,0));

    input(0,1);
    input(0,4);
    input(1,2);
    input(2,3);
    input(3,4);

    vector<bool> visited(v,false);

    cout<<"Breadth First Traversal: "<<endl;
    bft(0,v,visited);
    cout<<endl;
    cout<<"Depth First Traversal: "<<endl;
    dft(0,v,visited); 
}