#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int main() {

    int vertices = 0;
    int edges = 0;
    int loc1 = 0;
    int loc2 = 0;
    int count = 0;

    //Gather user input for vertices, edgess.
    cin >> vertices;
    cin >> edges;

    //Create initial varibles from user input
    list<int> adj[vertices];
    vector<int> inDegree(vertices);
    vector<int> order(vertices);
    vector <int> results;

    for (int i = 0; i < edges; i++) {
        cin >> loc1;
        cin >> loc2;
        adj[loc1].push_back(loc2);
    }

    for (int i = 0; i < vertices; i++) {
        list<int>::iterator itr;

        for (itr = adj[i].begin(); itr != adj[i].end(); itr++) {
            inDegree[*itr]++;
        }
    }

    //Copy into order from degree
    order = inDegree;

    queue<int> q;
    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        results.push_back(u);

        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)

            if (--order[*itr] == 0)
                q.push(*itr);

        count++;
    }

    for (int i = 0; i < vertices; i++) {
        cout << "In-degree[" << i << "]:" << inDegree[i] << endl;
    }

    //Print topological order
    if(results.size() == 0)
        cout << "No Order:";
    else
        cout << "Order:" << results[0];
    for (int i = 0; i < results.size(); i++) {
        if (i != 0) {
            cout << "->" << results[i];
        }
    }
    cout << endl;
    return 0;
}