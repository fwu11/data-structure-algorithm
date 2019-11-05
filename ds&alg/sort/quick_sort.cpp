void quickSort(vector<int> & A, int left, int right){
	if(left >= right) return;

	int start = left;
	int end = right;
	int pivot = A[(left + right)/2];

	while(start <= end){
		while(start <= end && A[start] < pivot){
			start++;
		}

		while(start <= end && A[end] > pivot){
			end--;
		}

		if(start <= end){
			swap(A[start++],A[end--]);
		}
	}

	quickSort(A, left, end);
	quickSort(A, start, right);
}