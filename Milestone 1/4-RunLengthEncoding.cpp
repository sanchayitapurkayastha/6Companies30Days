/*Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″*/

string encode(string src) {     
  int n = src.size();
  string ans = "";
  
  for (int i = 0; i < n; i ++) {
      int count = 1;
      
      while (i+1 < n && src[i] == src[i+1]) {
          count ++;
          i ++;
      }
      
      ans += src[i] + to_string(count); 
  }
  
  return ans;
}     
 
