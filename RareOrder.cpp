#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class CollatingSequenceSolver {
private:
    unordered_map<char, unordered_set<char>> graph;
    unordered_set<char> Chars;

    void topologicalSortUtil(char node, unordered_set<char>& visited, stack<char>& result) {
        visited.insert(node);

        for (const char& neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                topologicalSortUtil(neighbor, visited, result);
            }
        }
        result.push(node);
    }
    void topologicalSortAllChars(unordered_set<char>& visited, stack<char>& result) {
        for (char ch : Chars) {
            if (visited.find(ch) == visited.end()) {
                topologicalSortUtil(ch, visited, result);
            }
        }
    }

    string topologicalSort() {
        unordered_set<char> visited;
        stack<char> result;

        topologicalSortAllChars(visited, result);

        string collatingSequence;
        while (!result.empty()) {
            collatingSequence += result.top();
            result.pop();
        }
        return collatingSequence;
    }

public:
    void addCollatingRelation(const string& str1, const string& str2) {
        int len = min(str1.length(), str2.length());
        for (int i = 0; i < len; ++i) {
            if (str1[i] != str2[i]) {
                graph[str1[i]].insert(str2[i]);
                Chars.insert(str1[i]);
                Chars.insert(str2[i]);
                break;
            }
        }
    }
    void clear() {
        graph.clear();
        Chars.clear();
    }
    string solve() {
        return topologicalSort();
    }
};

int main() {
    string input;
    CollatingSequenceSolver solver;

    while (getline(cin, input) && input != "#") {
        string prev = input;
        while (getline(cin, input) && input != "#") {
            solver.addCollatingRelation(prev, input);
            prev = input;
        }
        string result = solver.solve();
        cout << result << endl;
        solver.clear(); 
    }
    return 0;
}
