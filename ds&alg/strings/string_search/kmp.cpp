// O(m+n)

vector<int> preprocess(string s){
    int n = s.size();
    vector<int> v(n,0);
    v[0] = -1;
    int j = -1;

    for(int i = 1;i < n; i++){
        //next not equal, go to current v[i]
        while(j>=0 && s[i] != s[j+1]) j = v[j];
        if(s[i] == s[j+1]) j++;
        v[i] = j;
    }

    return v;
}

int KMP(string haystack, string needle) {
    if(needle.size()==0){
        return 0;
    }

    int m = needle.size();
    int n = haystack.size();

    vector<int> lps= preprocess(needle);
    int j = -1;

    for(int i = 0; i < n; i++){
        while(j>=0 && haystack[i] != needle[j+1]) j = lps[j];
        if(haystack[i] == needle[j+1]) j++;
        if(j == m-1) return i-m+1;
    }

    return -1;
}
