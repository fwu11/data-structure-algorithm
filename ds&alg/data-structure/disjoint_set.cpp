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

	// union by rank
	void join(int x, int y){
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

	// path compression
	int find(int x){
		if(x != fathers[x]){
			fathers[x] = Find(fathers[x]);
		}
		return fathers[x];
	}
};