//Find max 10 numbers in a list having 10M entrie

#include <bits/stdc++.h>
using namespace std;

int main () {
    priority_queue <int, vector <int>, greater <int>> pq;
    
    //entering first 10 entires in the prioirity queue
    int i = 0, x;
    for (; i < 10; i ++) {
        cin >> x;
        pq.push(x);
    }

    //entering rest of the entries
    for (; i < 10000000; i ++) {
        cin >> x;
        if (x > pq.top()) {
            pq.pop();
            pq.push(x);
        }
    }

    //the priority queue contains now the maximum 10 entries from 10M entries
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}