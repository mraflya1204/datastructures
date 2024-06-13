#include <iostream>
#define MOD 1000000007
using namespace std;

long long solve(unsigned int n) {
    if (n <= 1) {
        return 1;
    }

    long long res = 1;
    for (unsigned int i = 2; i <= n; i++) {
        res = (res % MOD * i % MOD) % MOD;
    }
    
    return res % MOD;
}

int main() {
    int N;  cin >> N;
    long long int solution = solve(N);
    cout << solution;
    return 0;
}
