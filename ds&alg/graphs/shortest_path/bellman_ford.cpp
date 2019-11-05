// input
// Given 2 integers N and M. N represents the number of vertices in the graph. M represents the number of edges between any 2 vertices.
// Then M lines follow, each line has 3 space separated integers a, b, w where a and b represents an edge from a vertex a to a vertex b and w respresents the weight of that edge. 

// output
// Print the shortest distances from the source vertex 1 to all other vertices

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> bellman_ford(vector<vector<int>> edges, int num_vertex, int num_edge, int src){
	vector<int> dist(1+num_vertex,1e9);
	dist[src] = 0;

	for(int i = 1; i < num_vertex; i++){
		for(auto edge : edges){
			// relax
			dist[edge[2]] = min (dist[edge[2]], dist[edge[1]] + edge[0]);
		}
	}
	return dist;
};

int main(){
	int x,y,weight;
	int num_vertex, num_edge;

	vector<vector<int>> edges;

	cin >> num_vertex >> num_edge;

	for(int i = 0; i < num_edge; i++){
		cin >> x >> y >> weight;
		edges.push_back({weight, x, y});
	}

	vector<int> dist = bellman_ford(edges, num_vertex, num_edge, 1);

	for(int i = 2; i <= num_vertex; i++){
		cout << dist[i] << " ";
	}

	return 0;

}