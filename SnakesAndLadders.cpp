#include<bits/stdc++.h>
using namespace std;

class graph{
private:
    vector<vector<int> > edges;
    int nodes;
public:
    graph(int n){
        nodes=n;
        for(int i=0;i<=n;i++){
            vector<int> temp;
            edges.push_back(temp);
        }
    }
    void addEdge(int n1,int n2){
        edges[n1].push_back(n2);
        edges[n2].push_back(n1);
    }
    void bfs(int node,vector<bool>& vis){
        queue<int> q;
        q.push(node);
        while(q.empty()==false){
            int currNode = q.front();
            q.pop();
            vis[currNode]=true;
            cout<<currNode<<" ";
            for(auto x:edges[currNode]){
                if(vis[x]==false){
                    q.push(x);
                    vis[x]=true;
                }
            }
        }
    }

    void bfsDistance(int node){
        vector<int> dist(nodes+1,INT_MAX);
        queue<int> q;
        dist[node] = 0;
        q.push(node);
        while(q.empty()==false){
            int currNode = q.front();
            q.pop();
            for(auto x:edges[currNode]){
                if(dist[x]>(dist[currNode]+1)){
                    dist[x]=(dist[currNode]+1);
                    q.push(x);
                }
            }
        }
        cout<<"\nDistance of all the nodes from source node "<<node<<" is :\n";
        for(int i=0;i<(nodes+1);i++){
            cout<<i<<" : "<<dist[i]<<"\n";
        }
    }
    void printList(){
        for(int i=1;i<=nodes;i++){
            cout<<i<<" : ";
            for(auto x:edges[i]){
                cout<<x<<" ";
            }
            cout<<"\n";
        }
    }
    void bfs1(int node,int n,vector<vector<int> >& list, vector<int>& dist,vector<bool>& canBeVis){
        if(canBeVis[1]==false){
            return;
        }
        queue<int> q;
        q.push(node);
        while(q.empty()==false){
            int currNode = q.front();
            q.pop();
            for(auto x:list[currNode]){
                if(x<=n and canBeVis[x]==true and dist[x]>(dist[currNode]+1)){
                    dist[x]=dist[currNode]+1;
                    q.push(x);
                }
            }
        }
    }
    int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
        vector<bool> canBeVis(n+1,true);
        for(auto x:snakes){
            canBeVis[x.first]=false;
        }
        vector<int> dist(n+1,INT_MAX);
        dist[1]=0;
        vector<vector<int> > list;
        for(int i=0;i<=n;i++){
            vector<int> temp;
            if(i!=0 && i!=n){
                for(int j=1;j<=6;j++){
                    temp.push_back(i+j);
                }
            }
            list.push_back(temp);
        }
        for(auto x:ladders){
            list[x.first].push_back(x.second);
        }
        bfs1(1,n,list,dist,canBeVis);
        return dist[n]-1;
    }
};

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    int n=36;
    vector<pair<int,int> > snakes;
    pair<int,int> p1;
    p1.first = 17;
    p1.second = 4;
    pair<int,int> p2;
    p2.first = 20;
    p2.second = 6;
    pair<int,int> p3;
    p3.first = 34;
    p3.second = 12;
    pair<int,int> p4;
    p4.first = 24;
    p4.second = 16;
    pair<int,int> p5;
    p5.first = 32;
    p5.second = 30;
    snakes.push_back(p1);
    snakes.push_back(p2);
    snakes.push_back(p3);
    snakes.push_back(p4);
    snakes.push_back(p5);

    vector<pair<int,int> > ladders;
    
    pair<int,int> p6;
    p6.first = 2;
    p6.second = 15;
    pair<int,int> p7;
    p7.first = 5;
    p7.second = 7;
    pair<int,int> p8;
    p8.first = 9;
    p8.second = 27;
    pair<int,int> p9;
    p9.first = 18;
    p9.second = 29;
    pair<int,int> p10;
    p10.first = 25;
    p10.second = 35;
    ladders.push_back(p6);
    ladders.push_back(p7);
    ladders.push_back(p8);
    ladders.push_back(p9);
    ladders.push_back(p10);
    graph g(36);
    cout<<g.min_dice_throws(36,snakes,ladders);
}
