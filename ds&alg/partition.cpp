// partition so that 
// All elements < pivot are moved to the left
// All elements >= pivot are moved to the right
void partition (vector<int>& A, int pivot){
	int l = 0;
	int r = A.size()-1;

	while(l <= r){
		while(l <= r && A[l] < pivot){
			l++:
		}

		while(l <= r && A[r] >= pivot){
			r--;
		}

		if(l <= r){
			swap(A[l++],A[r--]);
		}

	}
}