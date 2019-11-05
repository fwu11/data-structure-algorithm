// Input:
// First line consists of two space separated integers denoting N and M.
// Each of the following M lines consists of two space separated integers X and Y denoting there is an from X directed towards Y.

// Output:
// Print N space separated integers denoting the topological sort (any order)
// if there are multiple ordering print the lexicographically smallest one -> use pq instead

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topo_sort(vector<vector<int>> adjacent_list, int num_vertex){
	vector<int> in_degree(num_vertex+1,0);
	vector<int> result;

	for(auto node: adjacent_list){
		for(auto v : node){
			in_degree[v]++;
		}
	}

	queue<int> q;
	// push vertex with indegree of 0 into the queue
	for(int i = 1; i < in_degree.size(); i++){
		if(in_degree[i] == 0){
			q.push(i);
		}
	}

	// take one vertex into the toposort and the indegree of other edges minus one.
	while(!q.empty()){
		int node = q.front();
		q.pop();
		result.push_back(node);

		for(auto neighbor : adjacent_list[node]){
			in_degree[neighbor]--;
			if(in_degree[neighbor] == 0){
				q.push(neighbor);
			}
		}
	}
	// in the previous step
	// when we pop from the queue, we can remove that edge from the graph
	// and there are edges remain in the graph -> the graph has at least one cycle
	return result;
}

int main(){
	int x,y;
	int num_vertex, num_edge;
	// store the edges in adjacent_list
	cin >> num_vertex >> num_edge;
	
    vector<vector<int>> adjacent_list(num_vertex+1);

	for(int i = 0; i < num_edge; i++){
		cin >> x >> y;
		adjacent_list[x].push_back(y);
	}

	vector<int> result = topo_sort(adjacent_list, num_vertex);

    for(int num : result){
        cout << num << " ";
    }

	return 0;
}

