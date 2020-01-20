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
        while (adj[0][i] != 0 && i < n + 2 ) {
            if (adj[0][i] == top){
                return 1;
            }
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
        int i = 1;
        int j=1;
        if(top1==top2){
            return 1;
        }
        while (adj[0][i] != top2 && i < n + 2) {
            i++;
        }
        while (adj[j][0] != top1 && j < n + 2) {
            j++;
        }
        if (i == n + 2) {
            return 1;
        }
        if (j == n + 2) {
            return 1;
        }
        if (adj[j][i] !=1) {
            adj[j][i] = 1;

        }

    }
    int del_arc(int top1, int top2){
        int i = 1;
        int j=1;
        if(top1==top2){
            return 1;
        }
        while (adj[0][i] != top2 && i < n + 2) {
            i++;
        }
        while (adj[j][0] != top1 && j < n + 2) {
            j++;
        }
        if (i == n + 2) {
            return 1;
        }
        if (j == n + 2) {
            return 1;
        }
        if (adj[j][i] !=0) {
            adj[j][i] = 0;

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
    int BFS(int start){
        int i=1;
        AdjacencyMatrix S(n);
        int q=start;
        adj[q][q]=1;
        while (i<=n){
            i++;
            S.add_top(i);
        }
        for (int j=1;j<=n;j++){
            if(adj[q][j]==1 && j!=q){
                S.add_arc(q,j);
            }
        }


    }
};

int main()
{
    AdjacencyMatrix adj(6);
    adj.add_top(13);
    adj.add_top(2);
    adj.add_top(8);
    adj.add_top(1);
    adj.add_top(9);
    adj.add_top(5);
    adj.add_arc(13,2);
    adj.add_arc(9,5);
    adj.add_arc(9,1);
    adj.add_arc(1,1);
    adj.display();


    return 0;
}
