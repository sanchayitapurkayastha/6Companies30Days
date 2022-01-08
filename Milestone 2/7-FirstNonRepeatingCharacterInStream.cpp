//First non-repeating character in stream

class Solution {
	public:
		string FirstNonRepeating(string A){
		    int m [26] = {0};
		    queue <char> q;
		    
		    for (int i = 0; A[i]; i ++) {
		        q.push(A[i]);
		        m[A[i] - 'a'] ++;
		        
		        while (!q.empty())
		            if (m[q.front() - 'a'] > 1)   q.pop();
		            
		            else {
		                A[i] = q.front();
		                break;
		            }
		        
		        if (q.empty())  A[i] = '#';
		    }
		    
		    return A; 
		}

};
