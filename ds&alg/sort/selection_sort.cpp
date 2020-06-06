void selectionSort(vector<int> &A){
  int n = A.size();
  int min_idx;
  for(int i = 0; i < n-1; i++){
    min_idx = i;
    for(int j = i+1; j < n; j++){
      if(A[j] < A[min_idx]){
        min_idx = j;
      }
    }
    swap(A[min_idx],A[i]);
  }
}
