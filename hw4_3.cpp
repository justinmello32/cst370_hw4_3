/*
 * Title: hw4_3.cpp
 * Abstract: This program conducts the topological
 *           sorting based on the Kahn’s algorithm.
 * Author: Justin Mello
 * ID: 2002
 * Date: 04/01/2021
 */

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
    int counter = 0;

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
        list<int>::iterator itArray;

        for (itArray = adj[i].begin(); itArray != adj[i].end(); itArray++) {
            inDegree[*itArray]++;
        }
    }

    //Copy into order from degree
    order = inDegree;

    queue<int> tempQueue;
    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) {
            tempQueue.push(i);
        }
    }

    while (!tempQueue.empty())
    {
        list<int>::iterator itr;
        int singleResult = tempQueue.front();
        tempQueue.pop();
        results.push_back(singleResult);

        for (itr = adj[singleResult].begin(); itr != adj[singleResult].end(); itr++)

            if (--order[*itr] == 0)
                tempQueue.push(*itr);

        counter++;
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