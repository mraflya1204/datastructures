#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    long N; 
    cin >> N;

    queue<long> numbers;
    for (long i = 0; i < N; ++i) {
        long num;
        cin >> num;
        numbers.push(num);
    }
    
    long totalLevel = log2(N) - 1;
    bool flag = (totalLevel % 2 == 0); 

    while (numbers.size() > 1) {
        queue<long> next_level;
        while (!numbers.empty()) {
            long first = numbers.front();
            numbers.pop();
            if (!numbers.empty()) {
                long second = numbers.front();
                numbers.pop();
                if (flag) {
                    next_level.push(max(first, second));
                }
                else {
                    next_level.push(min(first, second));
                }
            }
            else {
                next_level.push(first);
            }
        }
        flag = !flag; 
        numbers = next_level;
    }

    cout << numbers.front() << endl;

    return 0;
}
