#include <iostream>
#include <cstdlib>
#include <vector>
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
    int BFS(int start){
        int e=0;
        int k=1;
        int m=0;
        AdjacencyMatrix S(n);
        int q=start;
        S.add_top(q);
        int *visited= new int[n];
        visited[0]=q;//первая помеченная вершина
        for (int i=1;i<=n+1;i++) {

           for(int j=1;j <= n+1;j++) {//заполняем строку массива
               if ((adj[q][j] == 1)||(adj[visited[k]][j] == 1)) {
                   S.add_top(j);
                   S.add_arc(q, j);//заполняем все дуги текущей помеченной вершины
                   m++;
               }
               if(m==1){//добавляем помеченные вершины в массив
                   while(visited[k]!=0 && k<n+2){
                       if (visited[k]==adj[0][j]){
                           e++;
                       }
                       k++;
                   }
                   if(e==0){
                       visited[k]=adj[0][j];
                       S.del_arc(q, adj[0][j]);//удаляем дугу
                       q=adj[0][j];
                       cout<<q<<endl;
                   }else{
                       S.del_arc(q, j);//удаляем дугу
                       m=0;
                   }
               }
           }


       }
        S.display();
        for(int p=0;p<=n;p++){
            cout<<visited[p]<< " ";
        }

    }

    /*int BFS(int start){
        AdjacencyMatrix S(n);
        int q=start;
        int *visited=new int[n];
        visited[0]=q;
        S.add_top(start);
        for (int i=0; i<=n+1;n++){
            for(int j=1; j<n+1; n++){
                if(adj[i][j]==1){
                    S.add_top(adj[0][j]);
                    S.add_arc(i,adj[0][j]);
                }

            }
        }
        S.display();//сука даже это нахуй не работает
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
    adj.add_arc(1,3);
    adj.add_arc(1,2);
    adj.add_arc(2,3);
    adj.add_arc(2,5);
    adj.add_arc(3,5);
    adj.add_arc(3,6);
    adj.add_arc(4,3);
    adj.add_arc(5,1);
    adj.add_arc(5,4);
    adj.add_arc(6,5);
    adj.display();
adj.BFS(1);

    return 0;
}
