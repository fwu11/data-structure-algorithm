// [l,r)

int binarySearch(vecot<int> &A, int target){
	int l = 0; 
	int r = A.size();

	while(l < r){
		int m = l + (r-l)/2;
		if(A[m] < target){
			l = m+1; //new range [m+1, r)
		}else if(A[m] > target){
			r = m;   //new range [l, m)
		}else{
			return m;
		}
	}

	return l
}