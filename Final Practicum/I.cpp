#include <bits/stdc++.h> 
using namespace std; 


int main(){ 
    string str;
    cin >> str;
    int flag = -1;

    stack<char> myStack;
    char c;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(' || str[i] == '<' || str[i] == '{' || str[i] == '['){
           myStack.push(str[i]);
           continue; 
        }

        if(myStack.empty()){
            flag = 0;
            break; // No need to continue if stack is empty
        }

        if(str[i] == ')'){
            c = myStack.top();
            myStack.pop();
            if(c == '{' || c == '[' || c == '<'){
                flag = 0;
                break;
            }
        }
        else if(str[i] == '}'){
            c = myStack.top();
            myStack.pop();
            if(c == '(' || c == '[' || c == '<'){
                flag = 0;
                break;
            }
        }
        else if(str[i] == ']'){
            c = myStack.top();
            myStack.pop();
            if(c == '(' || c == '{' || c == '<'){
                flag = 0;
                break;
            }
        }
        else if(str[i] == '>'){
            c = myStack.top();
            myStack.pop();
            if(c == '(' || c == '{' || c == '['){
                flag = 0;
                break;
            }
        }
    }
    
    if(flag == 0 || !myStack.empty()){
        cout << "Belum ditutup" << endl;
    }
    else{
        cout << "Sudah ditutup" << endl;
    }

    return 0;
}
