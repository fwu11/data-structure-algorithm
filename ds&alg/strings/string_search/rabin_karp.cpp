// O(m+n)
// for a multiple pattern search

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int HASH_SIZE = 1000000;
        
        if (n == 0){
            return 0;
        }
        
        int power = 1;
        for (int i = 0; i < n; i++){
            power = (power*32) % HASH_SIZE;
        }
        int needleCode = 0;
        for (int i = 0; i < needle.size(); i++){
            needleCode = (1LL*32*needleCode + needle[i]) %HASH_SIZE;
        }
        
        int hashCode = 0;        
        for (int i = 0; i < haystack.size(); i++){
            //abc + d
            hashCode = (hashCode * 32 + haystack[i])% HASH_SIZE;
            if (i < n - 1){
                continue;
            }
            //abcd-a
            if (i >= n){
                hashCode = hashCode - (power * haystack[i-n]) % HASH_SIZE;
                if (hashCode < 0){
                    hashCode += HASH_SIZE;
                }
            }
            if(hashCode == needleCode){
                return i-n+1;
            }
        }
        return -1;
    }
};