#include<bits/stdc++.h>
using namespace std;
# define n 3

struct Node{
    Node* parent;
    int level;
    int cost;
    vector<int> state;
    int matrix[n][n];
    int x;
    int y;
};

struct compare{
    bool operator()(const Node* a,const Node* b){
        return (a->cost+a->level)>(b->cost+b->level);
    }
};

int findCost(int initial[n][n],int final[n][n]){
    int notEqual=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(initial[i][j]!=0 && initial[i][j]!=final[i][j]){
                notEqual++;
            }
        }
    }
    return notEqual;
}

bool isSafe(int x,int y){
    return (x>=0 && x<n && y>=0 && y<n);
}
void printMatrix(int matrix[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }cout<<endl;
    }
}

void printPath(Node* root){
    if(root==NULL){
        return;
    }
    printPath(root->parent);
    printMatrix(root->matrix);
    // cout<<"Atharva"<<"\n";
    cout<<endl;
}
Node* newNode(int matrix[n][n],int x,int y,int newX,int newY,int level,Node* parent){
    Node* node = new Node;
    node->parent=parent;
    memcpy(node->matrix,matrix,sizeof node->matrix);
    swap(node->matrix[x][y],node->matrix[newX][newY]);
    node->cost = INT_MAX;
    node->level=level;
    node->x=newX;
    node->y=newY;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            (node->state).push_back((node->matrix)[i][j]);
        }
    }
    return node;
}

vector<int> dr={1,0,-1,0};
vector<int> dc={0,-1,0,1};

void solve(int initial[n][n],int final[n][n],int x,int y){
    priority_queue<Node*,vector<Node*>,compare> pq;
    Node* root=newNode(initial,x,y,x,y,0,NULL); // creating new node 
    root->cost=findCost(initial,final);// finding cost 
    pq.push(root);
    set<vector<int>> st; // to not duplicate matrices
    st.insert(root->state);
    while(!pq.empty()){
        Node* node=pq.top();
        pq.pop();
        // answer found
        if(node->cost==0){
            printPath(node);
            return;
        }
        int i=node->x;
        int j=node->y;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(isSafe(nr,nc)){
                Node* child=newNode(node->matrix,i,j,nr,nc,node->level+1,node);
                child->cost=findCost(child->matrix,final);
                if(st.find(child->state)==st.end()){
                    pq.push(child);
                    st.insert(child->state);
                }
            }
        }
    }
}



int main(){
    int initial[n][n];
    int x=0,y=0;
    cout<<"Enter initial matrix:"<<endl;
    for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
            cin>>initial[i][j];
             if(initial[i][j]==0){
                x=i;
                y=j;
            }
        }
    }
    cout<<"Enter final matrix:"<<endl;
    int final[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>final[i][j];
        }
    }
    cout<<"Answer:"<<endl;
    solve(initial,final,x,y);
    return 0;
}