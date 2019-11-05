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
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
private:
	vector<int> fathers;
	vector<int> ranks;

public:
	DisjointSet(int n){
		fathers = vector<int> (n+1, 0);
		ranks = vector<int> (n+1, 0);
		for(int i = 0; i <= n; i++){
			fathers[i] = i;
		}
	}

	void Union(int x, int y){
		int f_x = Find(x);
		int f_y = Find(y);

		if(f_x != f_y){
			if(ranks[f_x] > ranks[f_y]){
				fathers[f_y] = f_x;
			}else if (ranks[f_x] < ranks[f_y]){
				fathers[f_x] = f_y;
			}else if (ranks[f_x] == ranks[f_y]){
				fathers[f_y] = f_x;
				ranks[f_x] += 1;
			}
		}
	}

	int Find(int x){
		if(x != fathers[x]){
			fathers[x] = Find(fathers[x]);
		}
		return fathers[x];
	}
};


int kruskal(vector<vector<int>>& edges, int num_vertex, int num_edge){
	int total_weight = 0;
	// sort by the weight
	sort(edges.begin(),edges.end());
	DisjointSet unionfind(num_vertex);

	for(auto edge : edges){
		// if both end of the edge is in the same root, not add to it.
		if(unionfind.Find(edge[1]) != unionfind.Find(edge[2])){
			unionfind.Union(edge[1],edge[2]);
			total_weight += edge[0];
		}
	}
	return total_weight;
}

int main(){

	int x,y,weight;
	int num_vertex, num_edge;
	vector<vector<int>> edges;

	cin >> num_vertex >> num_edge;

	for(int i = 0; i < num_edge; i++){
		cin >> x >> y >> weight;
		edges.push_back({weight, x, y});
	}

	cout << kruskal(edges, num_vertex, num_edge) << endl;

	return 0;

}