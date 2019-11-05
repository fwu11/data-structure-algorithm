//Input:
//Given 2 integers N and M. N represents the number of vertices in the graph. M represents the number of edges between any 2 vertices.
//Then M lines follow, each line has 3 space separated integers a, b, w where a and b represents an edge from a vertex a to a vertex b and w respresents the weight of that edge. 

//Output:
//Print the summation of edges weights in the MST. 

//Constraints:
// 2 <= N <= 10000
// 1 <= M <= 100000
// 1 <= a,b <= N
// 1 <= w <= 1000

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> PAIR;

int prim (vector<vector<pair<int,int>>> adjacent_list, int num_vertex, int num_edge){
	vector<int> visited (num_vertex, 0);

	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> minHeap;

	// start with node 1, with weight of 0;
	minHeap.push({0,1});

	int total_weight = 0;
	
	while(!minHeap.empty()){
		PAIR node = minHeap.top();
		minHeap.pop();

		int x = node.second;

		// check for cycle
		if(visited[x] == 1) continue;

		total_weight += node.first;
		visited[x] = 1;

		//add the neighboring vertices into the heap
		// hence heap only keep the vertices that has edges connected to the spanning tree
		// similar workaround method to the dijkstra (no decrease key is implemented)
		for(int i = 0; i < adjacent_list[x].size(); i++){
			if(visited[adjacent_list[x][i].second] == 0){
				minHeap.push(adjacent_list[x][i]);
			}
		}
	}
	return total_weight;
}


int main(){

	int x,y,weight;
	int num_vertex, num_edge;
	// store the edges in adjacent_list
	cin >> num_vertex >> num_edge;
	vector<vector<pair<int,int>>> adjacent_list(num_vertex+1);
	
	for(int i = 0; i < num_edge; i++){
		cin >> x >> y >> weight;
		adjacent_list[x].push_back({weight, y});
		adjacent_list[y].push_back({weight, x});
	}

	cout << prim(adjacent_list, num_vertex, num_edge) << endl;

	return 0;

}