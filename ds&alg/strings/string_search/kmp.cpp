// O(m+n)

vector<int> preprocess(string s){
    int n = s.size();
    vector<int> v(n,);
    int j = -1;

    for(int i = 1;i < n; i++){
        //next not equal, go to current v[i]
        while(j>=0 && s[i] != s[j+1]) j = v[i];
        if(s[i] == s[j+1]) j++;
        v[i] = j;
    }

    return v;
}

int KMP(string pattern, string s) {
    int m = pattern.size();
    int n = s.size();

    vector<int> lps= preprocess(pattern);
    int j = -1;

    for(int i = 0; i < n; i++){
        while(j>=0 && s[i] != pattern[j+1]) j = lps[i];
        if(s[i] == pattern[j+1]) j++;
        
        if(j == m-1) return i-m+1;
    }

    return -1;
}
