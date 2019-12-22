int binarySearch(vecot<int> &A, int target){
	int start = 0; 
	int end = A.size()-1;

	while(start + 1 < end){
		int mid = start + (end-start)/2;
		if(A[mid] < target){
			start = mid;
		}else if(A[mid] > target){
			end = mid;
		}else{
			return mid;
		}
	}

	if(A[start] == target){
		return start;
	}
	return end;
}