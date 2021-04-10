/* not implemented yet*/

int j = 0
for(int i = 0; i < n; i++){
 
  // 挪动i的时候，看看j最多挪动到哪儿 
  // j代表的是subarray右端点的index+1的位置。因此j-i是subarray的长度。
  while( j < n && 当前subarray不满足条件){
    j++;
    拓宽当前subarray
  }
  
  if 当前subarray满足条件{
    打擂台，看看是不是最优的  
  }
}
