// Input:
// First line consists of two space separated integers denoting N and M.
// Each of the following M lines consists of two space separated integers X and Y denoting there is an from X directed towards Y.

// Output:
// 2D array, each array stores one strongly connected component, or empty if none

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int idx = 0;
vector<int> dfn;
vector<int> low;
vector<vector<int>> ans;
stack<int> stk;
vector<int> in_stack;

void tarjan(vector<vector<int>> adjacent_list, int u){
    dfn[u] = low[u] = ++idx;
    stk.push(u);
    in_stack[u] = 1;

	// visit all neighbours
	for(auto v : adjacent_list[u]){
		// if node is not visited
        if(dfn[v] == -1){
        	tarjan(adjacent_list, v);
        	low[u] = min(low[u],low[v]);

        // if visited and in the stack
        }else if(in_stack[v]){
        	low[u] = min(low[u],dfn[v]);
        }
	}

	// identify the scc
	if(dfn[u] == low[u]){
		vector<int> scc;
		while(stk.top() != u){
            in_stack[stk.top()] = 0;
            scc.push_back(stk.top());
            stk.pop();
		}
        in_stack[stk.top()] = 0;
        scc.push_back(stk.top());
        stk.pop();
		ans.push_back(scc);
	}
}


int main(){
	int x,y;
	int num_vertex, num_edge;
	// store the edges in adjacent_list
	cin >> num_vertex >> num_edge;
	
    vector<vector<int>> adjacent_list(num_vertex+1);
    dfn = vector<int>(num_vertex+1, -1);
    low = vector<int>(num_vertex+1, -1);
    in_stack = vector<int>(num_vertex+1, 0);


	for(int i = 0; i < num_edge; i++){
		cin >> x >> y;
		adjacent_list[x].push_back(y);
	}

	for(int i = 1; i <= num_vertex; i++){
		// if current node is not visited, start the tarjan algorithm
		if(dfn[i] == -1){
			tarjan(adjacent_list, i);
		}
	}

    for(auto scc : ans){
    	for(auto vertex : scc){
    		cout << vertex << " ";
    	}
    	cout << endl;
    }

	return 0;
}