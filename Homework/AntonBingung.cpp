#include <iostream>
#include <deque>
#include <cstring> // Include this for strcmp
using namespace std;

int main() {
    deque<string> myDQ;
    int N; cin >> N; 

    for(int i = 0; i < N; i++){
        char cmd[100]; cin >> cmd; 

        if(strcmp(cmd, "goto")==0){
            char where[100]; cin >> where;
            myDQ.push_back(where);
        }
        else if(strcmp(cmd, "whereami")==0){
            if(myDQ.empty()){
                cout << "i am nowhere" << endl;
            }
            else{
                cout << "home/anton";
                for(const auto& location : myDQ) {
                    cout << "/" << location;
                }
                cout << endl;
            }
        }
        else if(strcmp(cmd, "goback")==0){
            if(myDQ.empty()){
                cout << "cannot go back" << endl;
            }
            else{
                myDQ.pop_back();
            }
        }
    }
    return 0;
}
