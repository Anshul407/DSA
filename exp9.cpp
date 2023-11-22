#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int> > arr;
void add(int i,int j){
    arr[i][j]=1;
    arr[j][i]=1;
}
void dfs(vector<bool>&vis,int node){
    cout<<node<<" ";
    vis[node]=1;
    for(int i=0;i<arr[node].size();i++){
        if(arr[node][i]==1&&(!vis[i])){
            dfs(vis,i);
        }
    }

}
void bfs(vector<bool>&vis,int node){
    cout<<node<<" ";
    vis[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int nod=q.front();
        q.pop();
        cout<<nod<<" ";
        for(int i=0;i<arr[nod].size();i++){
            if(!vis[i]&&arr[nod][i]==1){
                q.push(i);
                vis[i]=1;
            }
        }
    }

}
int main(int argc, char const *argv[])
{
     arr = vector<vector<int> >(20, vector<int>(20, 0));
    add(1,2);
    add(1,3);
    add(2,4);
    add(3,5);
    vector<bool>vis(20,false);
    bfs(vis,1);
   
    
    return 0;
}
