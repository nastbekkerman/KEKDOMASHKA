#include <iostream>
#include <cstdlib>

using namespace std;

class AdjacencyMatrix {
private:
    int n;
    int **adj;
public:
    AdjacencyMatrix(int n) {
        this->n = n;
        adj = new int *[n + 1];
        for (int i = 0; i < n + 1; i++) {
            adj[i] = new int[n + 1];
            for (int j = 0; j < n + 1; j++) {
                adj[i][j] = 0;
            }
        }
    }

    bool Search(int top) {
        int i = 1;
        while (adj[0][i] != top && i < n + 2) {
            i++;
        }
        if (i == n + 2) {
            return false;
        }
        if (adj[0][i] == top) {
            return true;
        }

    }

    int add_top(int top) {
        int i = 1;
        while (adj[0][i] != 0 && i < n + 2) {
            i++;
        }
        if (i == n + 2) {
            return 1;
        }
        adj[0][i] = top;
        adj[i][0] = top;
    }

    int del_top(int top)
    {
        if (Search(top)==true) {
            int i = 1;
            while (adj[0][i] != top && i < n + 2) {
                i++;
            }
            if (i == n + 2) {
                return 1;
            }
            for (int k = 0; k <= n; k++) {
                adj[k][i] = 0;
                adj[i][k] = 0;
            }
        }
    }

    int add_arc(int top1, int top2){
       if (Search(top1)==true&& Search(top2)==true) {
           if (adj[top1][top2] != 1) {
               adj[top1][top2] = 1;
           }
       }
    }
    int del_arc(int top1, int top2){
        if (Search(top1)==true&& Search(top2)==true) {
            if (adj[top1][top2] != 0) {
                adj[top1][top2] = 0;
            }
        }
    }
    /*
     * Print the graph
     */
    void display()
    {
        int i, j;
        for (i = 0; i < n+1; i++)
        {
            for (j = 0; j < n+1; j++)
                cout << adj[i][j] << "  ";
            cout << endl;

        }
        cout << endl;
    }
    /*void BFS(int start)
    {

        vector<bool> visited(v, false);
        vector<int> q;
        q.push_back(start);

        // Set source as visited
        visited[start] = true;

        int vis;
        while (!q.empty()) {
            vis = q[0];

            // Print the current node
            cout << vis << " ";
            q.erase(q.begin());

            // For every adjacent vertex to the current vertex
            for (int i = 0; i < v; i++) {
                if (adj[vis][i] == 1 && (!visited[i])) {

                    // Push the adjacent node to the queue
                    q.push_back(i);

                    // Set
                    visited[i] = true;
                }
            }
        }
    }*/
};
int main()
{
    AdjacencyMatrix adj(6);
    adj.add_top(1);
    adj.add_top(2);
    adj.add_top(3);
    adj.add_top(4);
    adj.add_top(5);
    adj.add_top(6);
    adj.add_arc(1,2);
    adj.add_arc(1,4);
    adj.add_arc(2,3);
    adj.add_arc(2,5);
    adj.add_arc(2,6);
    adj.add_arc(3,6);
    adj.add_arc(4,2);
    adj.add_arc(4,5);
    adj.add_arc(5,1);
    adj.add_arc(5,3);

    adj.display();
    adj.del_arc(5,3);
    adj.display();
    return 0;
}
