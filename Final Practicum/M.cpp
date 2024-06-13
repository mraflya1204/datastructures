#include <iostream>
#include <string>
using namespace std;

bool isDuplicate(string names[], int size, string name) {
    for (int i = 0; i < size; ++i) {
        if (names[i] == name) {
            return true;
        }
    }
    return false;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        string names[100];
        int V; cin >> V;
        int E; cin >> E;

        int uniqueCount = 0;
        for (int i = 0; i < E*2; ++i) {
            string name; cin >> name;
            if (!isDuplicate(names, uniqueCount, name)) {
                names[uniqueCount++] = name;
            }
        }

        if(uniqueCount != V){
            cout << "Menyirkel" << endl;
        }
        else{
            cout << "Tidak Menyirkel" << endl;
        }
    }

    return 0;
}
