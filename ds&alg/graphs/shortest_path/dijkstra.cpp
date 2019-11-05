// input
// Given 2 integers N and M. N represents the number of vertices in the graph. M represents the number of edges between any 2 vertices.
// Then M lines follow, each line has 3 space separated integers a, b, w where a and b represents an edge from a vertex a to a vertex b and w respresents the weight of that edge. 

// output
// Print the shortest distances from the source vertex 1 to all other vertices

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


// <dist,vertex>
typedef pair<int,int> Node;

vector<int> dijkstra(vector<vector<Node>>& adjacent_list, int num_vertex, int num_edge, int src) {

    vector<int> dist(num_vertex+1,1e9);

    priority_queue<Node,vector<Node>,greater<Node>> minHeap;
    minHeap.push({0,src});
    
    while(!minHeap.empty()){
        int v = minHeap.top().second;
        int d = minHeap.top().first;
        minHeap.pop();
        
        // this is a workaround method to replace the decrease-key step;
        // the idea is only if it is popped from the heap and dist is not overwritten, its value is the shortest one
        // otherwise it may not be the shortest one and will be pushed into the heap
        // heap in this case will have more different distances with same vertex than the decrease key method
        if(dist[v] != 1e9) continue;
        dist[v] = d;
        for(Node& node : adjacent_list[v]){
            // relax
            if(d + node.first < dist[node.second]){
                minHeap.push({d+node.first, node.second});
            }
        }
    }
    return dist;
}

int main(){
	int x,y,weight;
	int num_vertex, num_edge;
	// store the edges in adjacent_list
	cin >> num_vertex >> num_edge;
	
    vector<vector<Node>> adjacent_list(num_vertex+1);


	for(int i = 0; i < num_edge; i++){
		cin >> x >> y >> weight;
		adjacent_list[x].push_back({weight, y});
	}

	vector<int> dist = dijkstra(adjacent_list, num_vertex, num_edge, 1);

    for(int i = 2; i <= num_vertex; i++){
        cout << dist[i] << " ";
    }

	return 0;
}