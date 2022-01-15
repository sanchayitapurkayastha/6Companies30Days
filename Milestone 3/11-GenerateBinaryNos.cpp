//Generate and print all binary numbers with decimal values from 1 to N.

vector<string> generate(int N)
{
	vector <string> v;
	
	queue <string> q;
	q.push("1");
	for (int i = 0; i < N; i ++) {
	    string temp = q.front();
	    q.pop();
	    
	    v.push_back(temp);
	    
	    q.push(temp + "0");
	    q.push(temp + "1");
	}
	
	return v;
}
