void bubble_sort(vector<int>& A){
    int n = A.size();
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n-i;j++){
            if(A[j-1] > A[j]){
                swap(A[j-1],A[j]);
            }
        }
    }
}
