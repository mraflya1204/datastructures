#include <iostream>
#include <map>
#include <stack>
#include <cstring>

using namespace std;

int main() {
    int N; scanf("%d", &N);
    map<string, stack<string>> logsMap;

    for (int i = 0; i < N; i++) {
        char cmd[100]; scanf("%s", cmd);
        if (strcmp(cmd, "CREATE") == 0) {
            char consume[100]; scanf("%s", consume);
            char name[100]; scanf("%s", name);
            logsMap[name] = stack<string>();
        } else if (strcmp(cmd, "WRITE") == 0) {
            char name[100]; scanf("%s", name);
            char log[100]; scanf("%s", log);
            logsMap[name].push(log);
        } else if (strcmp(cmd, "READ") == 0) {
            char consume[100]; scanf("%s", consume);
            char name[100]; scanf("%s", name);
            
            if (logsMap.find(name) == logsMap.end()) {
                printf("Topic is empty\n");
            } else {
                if (!logsMap[name].empty()) {
                    printf("%s\n", logsMap[name].top().c_str());
                    logsMap[name].pop(); 
                } else {
                    printf("Topic is empty\n");
                }
            }
        }
    }
    return 0;
}
