#include <map>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
queue<int> team;
map<int,int> on_team;

int main() {
    int t;
    scanf("%d", &t);
    vector<queue<int>> teamQueue(t);
    
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        for(int j = 0; j < n; j++) {
            int id;
            scanf("%d", &id);
            on_team[id] = i;
        }
    }
    char ch[20];
    while(scanf("%s", ch) != EOF) {
        if(ch[0] == 'D') {
            int can_team = team.front();
            printf("%d\n", teamQueue[can_team].front());
            teamQueue[can_team].pop();
            if(teamQueue[can_team].empty()) {
                team.pop();
            }
        }
        else {
            int id;
            scanf("%d", &id);
            int id_team = on_team[id];
            if(teamQueue[id_team].empty()) {
                team.push(id_team);
            }
            teamQueue[id_team].push(id);
        }
    }
    return 0;
}