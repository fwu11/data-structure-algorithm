void insertionSort(vector<int> &A){
    int n = A.size();
    int key,j;
    for(int i = 1; i < n; i++){
        key = A[i];
        for(j= i-1; j >= 0 && A[j] > key; j--){
            A[j+1] = A[j];
        }
        A[j+1] = key;
    }
}
