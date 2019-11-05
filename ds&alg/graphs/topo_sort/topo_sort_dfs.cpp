// Input:
// First line consists of two space separated integers denoting N and M.
// Each of the following M lines consists of two space separated integers X and Y denoting there is an from X directed towards Y.

// Output:
// Print N space separated integers denoting the topological sort (any order)


// check if the graph has cycle
#include <iostream>
#include <vector>

using namespace std;

enum State {UNKNOWN,VISITING,VISITED};
vector<int> result;
vector<int> v;

bool topo_sort(vector<vector<int>> adjacent_list, int cur){
	if(v[cur] == VISITING) return false;
    if(v[cur] == VISITED) return true;
        
    v[cur] = VISITING;
    for(int t : adjacent_list[cur])
        if(!topo_sort(adjacent_list,t)) return false;
    v[cur] = VISITED;
    result.push_back(cur);
    return true;
}


int main(){
	int x,y;
	int num_vertex, num_edge;
	// store the edges in adjacent_list
	cin >> num_vertex >> num_edge;
	
    vector<vector<int>> adjacent_list(num_vertex+1);
    v = vector<int>(num_vertex+1,UNKNOWN);

	for(int i = 0; i < num_edge; i++){
		cin >> x >> y;
		adjacent_list[x].push_back(y);
	}

	for(int i = 1; i <= num_vertex; i++){
		topo_sort(adjacent_list, i);
	}

    for(int i = result.size() - 1; i >= 0; i--){
        cout << result[i] << " ";
    }

	return 0;
}