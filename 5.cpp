#include<iostream>
#include<vector>
#include<algorithm>
#include<queue> 
#include<climits>
using namespace std;

typedef pair<int,int> NodeWeight;

vector<int> dijkstra(int src, int n, const vector<vector<NodeWeight>>& graph){
       vector<int> dist(n,INT_MAX);
       dist[src] = 0;

       priority_queue<NodeWeight,vector<NodeWeight>, greater<NodeWeight>> pq;
       pq.push({0,src});

       while(!pq.empty()){
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if(currentDist > dist[currentNode]) continue;

        for(const auto& neighbor : graph[currentNode]){
            int nextNode = neighbor.first;
            int weight = neighbor.second;
        
           if(dist[currentNode] + weight < dist[nextNode]){
            dist[nextNode] = dist[currentNode] + weight;
            pq.push({dist[nextNode], nextNode});
           }
        }
       }

       return dist;

}

int main(){

    int n,m;
    cout<<"Enter the number of locations (nodes): ";
    cin>>n;
    cout<<"Enter the number of roads (edges): ";
    cin>>m;

    vector<vector<NodeWeight>> graph(n);

    cout<<"Enter the roads (u v w) where u and v are locations and w is travel time: "<< endl;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin>> u >> v >>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    int source, destination;
    cout<<"Enter the source and destination locations: ";
    cin>> source >> destination;

    vector<int> dist = dijkstra(source,n,graph);

    if(dist[destination] == INT_MAX){
        cout<<"No path exists from source to destination: "<<endl;
    }else{
       
        cout << "Shortest time from " << source << " to " << destination << " is: " << dist[destination] << endl;

    }

    return 0;
}