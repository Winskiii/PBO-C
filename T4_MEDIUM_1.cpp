#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
 
int getNum() {
	int res = 0, b = 0;
	char c;
	
	while(1)
    {
		c=getchar_unlocked();
		if(c=='-') b = 1;
		if(c==' '||c=='\n') continue;
		else break;
	}
	if(c!='-')res=c-'0';
	while(1)
    {
		c=getchar_unlocked();
		if(c>='0' && c<='9') res =10 * res +c -'0';
		else break;
	}
	if(b==1) res *= -1;
	return res;
}
char getChar() {
    char c = getchar_unlocked();
    while (c == ' ' || c == '\n') {
        c = getchar_unlocked();
    }
    return c;
}
char* getString() {
    char* input = NULL;
    int capacity = 0, length = 0;
    char c;
 
    while (1) {
        c = getchar_unlocked();
        if (c == '\n' || c == ' ' || c == EOF) {
            if (length > 0) {
                break;
            }
            continue;
        }
        if (length + 1 >= capacity) {
            capacity = (capacity == 0) ? 16 : capacity * 2;
            input = (char*)realloc(input, capacity * sizeof(char));
        }
        input[length++] = c;
    }
    if (input != NULL) {
        input[length] = '\0';
    }
    return input;
}
int main() {
    int t;
    t = getNum();
 
    while (t--) {
        int n;
        char c;
        n = getNum();
        c = getChar();
        char* s;
        s = getString();
 
        priority_queue<int>pq;
        pq.push(0);
        int distance = n; 
        bool flag = false;
 
        for (int i = 0; i < n; i++) {
            if (!flag && s[i] == c) {
                distance = 0;
                flag = true;
            } 
            if (flag && s[i] == 'x') {
                pq.push(distance);
                flag = false;
            }
            distance++;
        }
        if (flag) {
            for (int i = 0; i < n; i++) {
                if (s[i] == 'x') {
                    pq.push(distance); 
                    break;
                }
                distance++;
            }
        }
        cout << pq.top() << endl;
    } 
    return 0;
}