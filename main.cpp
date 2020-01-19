#include <iostream>
#include <cstdlib>

using namespace std;

class AdjacencyMatrix
{
private:
    int n;
    int **adj;
public:
    AdjacencyMatrix(int n)
    {
        this->n = n;
        adj = new int *[n+1];
        for (int i = 0; i < n+1; i++)
        {
            adj[i] = new int[n+1];
            for (int j = 0; j < n+1; j++)
            {
                adj[i][j] = 0;
            }
        }
    }
   bool Search(int top){
        int i=1;
        while (adj[0][i] != 0 && i<n+2 && i!=top) {
            i++;
        }
        if (i == n + 2) {
            return false;
        }
        if(i==top && adj[0][i] != 0){
            return true;
        }


    }
    int add_top(int top )
    {
        int i = 1;
        while (adj[0][i] != 0 && i<n+2) {
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
        int p=top;
        if(Search(p)==true) {
            for (int k = 0; k <= n + 1; k++) {
                if (adj[k][p] != 0) adj[k][p] = 0;
                if (adj[p][k]!=0) adj[p][k] = 0;
            }
        }
        return 0;
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
    }
};
int main()
{
    AdjacencyMatrix adj(5);
    adj.add_top(1);
    adj.add_top(2);
    adj.add_top(3);
    adj.add_top(4);
    adj.display();
    adj.del_top(3);
    adj.display();

    return 0;
}
