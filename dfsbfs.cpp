#include<iostream>
#include<vector>
#include<queue>
#include<limits>
using namespace std;

vector<bool>visited;
vector<vector<int>>graph;
void dfs(int v)
{
    visited[v] = true;
    cout<<v<<" ";

    for(auto child:graph[v])
    {
        if(!(visited[child]))
        {
            dfs(child);
        }
    }
}

queue<int>q;
void bfs()
{
    if(q.empty())
    {
        return;
    }

    int v = q.front();
    q.pop();

    cout<<v<<" ";

    for(int child:graph[v])
    {
        if(!visited[child])
        {
            visited[child] = true;
            q.push(child);
        }
    }

    bfs();
}

int main()
{
    int E,V;

    cout<<"Enter number of vertices : \n";
    cin>>V;

    cout<<"Enter number of Edges : \n";
    cin>>E;
    
    graph.resize(V+1);
    visited.resize(V+1);
    for(int i = 0; i < E; i++)
    {
        int v1,v2;
        cout<<"Enter vertice 1 : \n";
        cin>>v1;
        cout<<"Enter vertice 2 : \n";
        cin>>v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

        cout<<"Edge added successfully \n";
    }

    for(int i = 1; i < graph.size(); ++i)
    {
        cout<<i<<" : ";
        for(int j = 0; j < graph[i].size(); ++j)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    int start;
    cout<<"Enter starting vertex : \n";
    cin>>start;

    cout<<"Dfs traversal \n";
    dfs(start);
    
     cout<<endl;
     for(int i = 0; i < V+1; ++i)
     {
         visited[i] = false;
     }
    q.push(start);
    visited[start] = true;

    cout<<"Bfs traversal \n";
    bfs();
    cout<<endl;
    return 0;

}