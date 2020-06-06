void heapify(vector<int> &A, int n, int i){
    while(i<n){
        int father_index = i;
        int l = 2*i+1;
        int r = 2*i+2;
        
        if(l < n && A[l] > A[father_index]){
            father_index = l;
        }
        if(r < n && A[r] > A[father_index]){
            father_index = r;
        }
        
        if(father_index == i) break;
        swap(A[father_index], A[i]);
        i = father_index;
    }
}
void heapSort(vector<int> &A){
    int n = A.size();
    
    // build heap
    for(int i = n/2-1; i >= 0; i--){
        heapify(A, n, i);
    }
    
    // extract an element from heap
    for(int i = n-1; i >= 0; i--){
        swap(A[0],A[i]);
        heapify(A, i, 0);
    }
}
