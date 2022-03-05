#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    Node *parent;
    int distant = 0;
    bool burnt = false;
};

void bfs(int n, vector<vector<int>> &arr, int start, Node burn[], queue<int> q) {
    int iter;
    for (int i = 0; i < arr[start].size(); i++) {
        iter = arr[start][i] - 1;
        if (!burn[iter].burnt) {
            q.push(iter);
            burn[iter].distant = burn[start].distant + 1;
            burn[iter].parent = &burn[start];
            burn[iter].burnt = true;
        }
    }
    burn[start].burnt = true;
    if (!q.empty()) {
        int next = q.front();
        q.pop();
        bfs(n, arr, next, burn, q);
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    Node burn[n];
    auto matrix = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        matrix[a - 1].push_back(b);
        matrix[b - 1].push_back(a);
    }
    queue<int> q;
    burn[0].distant = 0;
    burn[0].burnt = true;
    bfs(n, matrix, 0, burn, q);
    for (int i = 1; i < n; i++) {
        if (!burn[i].burnt) {
            bfs(n, matrix, i, burn, q);
        }
    }
    for (int j = 0; j < n; j++) {
        cout << burn[j].distant << " ";
    }
}
    /*ifstream in("pathbge1.in");
    ofstream out;
    out.open("pathbge1.out", std::ios::app);
    if (in.is_open()) {
        int n, m, a, b;
        in >> n >> m;
        Node burn[n];
        vector matrix = vector<vector<int>>(n, vector<int>());
        for (int i = 0; i < m; i++) {
            in >> a >> b;
            matrix[a - 1].push_back(b);
            matrix[b - 1].push_back(a);
        }
        queue<int> q;
        burn[0].distant = 0;
        burn[0].burnt = true;
        bfs(n, matrix, 0, burn, q);
        for (int i = 1; i < n; i++) {
            if (!burn[i].burnt) {
                bfs(n, matrix, i, burn, q);
            }
        }
        for (int j = 0; j < n; j++) {
            out << burn[j].distant << " ";
        }
        return 0;
    }
}*/
