void partition(vector<int> &A, int low, int high) {
	int i = 0;
	int j = 0;
	int n = A.size() - 1;

	while(j <= n){
		if(A[j] < low){
			swap(A[j++],A[i++]);
		}else if(A[j] > high){
			swap(A[j],A[n--]);
		}else{	
			j++;
		}
	}
}