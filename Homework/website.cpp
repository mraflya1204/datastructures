```C
//LeetCode Website Thing
struct node{
    string site;
    node *next = NULL;
    node *prev = NULL;
};

class BrowserHistory {
public:
    node *current = new node;

    BrowserHistory(string homepage) {
        current->site = homepage;
    }
    
    void visit(string url) {
        node *temp = new node;
        temp->site = url;
        current->next = temp;
        temp->prev = current;
        current = temp;
    }
    
    string back(int steps) {
        for(int i = 0; i < steps; i++){
            if(current->prev != NULL){
                current = current->prev;
            }
            else break;
        }
        return current->site;
    }
    
    string forward(int steps) {
        for(int i = 0; i < steps; i++){
            if(current->next != NULL){
                current = current->next;
            }
            else break;
        }
        return current->site;
    }
};
```
