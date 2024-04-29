#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

int sisa = 0;

int main() {
    int N, M; 
    cin >> N >> M;
    stack<int> myStack1;
    stack<int> myStack2;

    for(int i = 0; i < N; i++) {
        int x; 
        cin >> x;
        myStack1.push(x);
    }
    for(int i = 0; i < M; i++) {
        int x; 
        cin >> x;
        myStack2.push(x);
    }

    while (!myStack1.empty() || !myStack2.empty() || sisa != 0) {
        int res = sisa;

        if (!myStack1.empty()) {
            res += myStack1.top();
            myStack1.pop();
        }
        if (!myStack2.empty()) {
            res += myStack2.top();
            myStack2.pop();
        }

        sisa = res / 10;
        res %= 10;

        cout << res;
    }

    return 0;
}
