void mergeSort(vector<int> &A, int l, int r, vector<int> &tmp){
	if(l >= r) return;
	int mid = l + (r-l)/2;
	mergeSort(A,l,mid,tmp);
	mergeSort(A,mid+1,r,tmp);
	merge(A,l,mid,r,tmp);
}


void merge(vector<int> &A, int start, int mid, int end, vector<int> &tmp){
	int l = start;
	int r = end;
	int index = start;

	while(l <= mid && r <= end){
		if(A[l] <= A[r]){
			tmp[index++] = A[l++];
		}else{
			tmp[index++] = A[r++];
		}
	}

	while(l <= mid) tmp[index++] = A[l++];
	while(r <= end) tmp[index++] = A[r++];
	for(index = start; index <= end; index++){
		A[index] = tmp[index];
	}
}
