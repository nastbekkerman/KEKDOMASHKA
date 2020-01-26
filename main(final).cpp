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
        for (int i = 0; i <= n; i++) {
            adj[i] = new int[n + 1];
            for (int j = 0; j <= n; j++) {
                adj[i][j] = 0;
            }
        }
    }


    bool Search(int top) {
        int i = 1;
        while (adj[0][i] != top && i < n + 1) {
            i++;
        }
        if (i == n + 1) {
            return false;
        } else {
            if (adj[0][i] == top) {
                return true;
            }
        }

    }

    int add_top(int top) {
        int i = 1;
        while (adj[0][i] != 0 && i < n + 1) {
            if (adj[0][i] == top) {
                return 1;
            }
            i++;
        }
        if (i == n + 1) {
            return 1;
        }
        adj[0][i] = top;
        adj[i][0] = top;
    }

    int del_top(int top) {
        if (this->Search(top) == true) {
            int i = 1;
            while (adj[0][i] != top && i < n + 1) {
                i++;
            }
            if (i == n + 1) {
                return 1;
            }
            for (int k = 0; k <= n; k++) {
                adj[k][i] = 0;
                adj[i][k] = 0;
            }
        }
    }

    int add_arc(int top1, int top2) {
        int i = 1;
        int j = 1;
        if (top1 == top2) {
            return 1;
        }
        while (adj[0][i] != top2 && i <=n + 1) {
            i++;
        }
        while (adj[j][0] != top1 && j < n + 1) {
            j++;
        }
        if (i == n + 1) {
            return 1;
        }
        if (j == n + 1) {
            return 1;
        }
        if (adj[j][i] != 1) {
            adj[j][i] = 1;

        }

    }

    int del_arc(int top1, int top2) {
        int i = 1;
        int j = 1;
        if (top1 == top2) {
            return 1;
        }
        while (adj[0][i] != top2 && i < n + 1) {
            i++;
        }
        while (adj[j][0] != top1 && j < n + 1) {
            j++;
        }
        if (i == n + 1) {
            return 1;
        }
        if (j == n + 1) {
            return 1;
        }
        if (adj[j][i] != 0) {
            adj[j][i] = 0;

        }
    }

    /*
     * Print the graph
     */
    void display() {
        //int i, j;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++)
                cout << adj[i][j] << "  ";
            cout << endl;

        }
        cout << endl;
    }
    void PrintColumn(int column){
        cout<<adj[column][0]<<" ";
    }
    bool retTop(int i,int j, int m){
       if( adj[i][j]==m){return true;}
       else{return false;}

    }//чекнуть на вершины больше n
    int returneTop(int i,int j){
       return adj[i][j];

    }//чекнуть на вершины больше n
    int getsize(){
        return this->n;
    }
    int add_arc_loop(int top) {
        int i = 1;
        while (adj[0][i] != top && i < n + 1) {
            i++;
        }
        if (i == n + 1) {
            return 1;
        }
        if (adj[i][i] != 1) {
            adj[i][i] = 1;

        }

    }

    int value_top(int top1,int top2){
        int i = 1;
        int j=1;
        int k=0;
        while (adj[0][i] != top2 && i < n + 1) {
            i++;
        }
        if (i == n + 1) {
            return 1;
        }
        while (adj[j][0] != top1 && j < n + 1) {
            j++;
        }
        if (j == n + 1) {
            return 1;
        }
        k=adj[j][i];
        return k;
    }
    int add_arc_RQ(int i,int j){
        if (adj[i][j]!=1){
            adj[i][j]=1;
        }
    }
    int *BFS(int start) {
        AdjacencyMatrix S(n);
        int *visited = new int[n];
        int q = start;
        int h=0;
        int k=0;
        int y=0;
        int p=1;
        S.add_top(q);
        while (visited[h] != 0 && h < n + 1) {
            visited[h] = 0;
            h++;
        }

        visited[0] = q;//первая помеченная вершина
        for (int i = 1; i <n + 1; i++) {
            for (int j = 1; j <n + 1; j++) {//заполняем строку массива
                if (i>1){
                p=visited[i-2];
                } else {
                    p=visited[0];
                }
                if ((adj[q][j]==1)||(adj[p][j]==1)){
                    S.add_top(adj[0][j]);
                    S.add_arc(q,adj[0][j]);
                }
                }
            for (int m=1;m<n+1;m++){
                if(S.retTop(i,m,1)==true){
                    k++;
                }
                if(k==1){
                    while(visited[y]!=0 && y<n+1){
                        if (S.retTop(0,m,visited[y])==true){
                            k=0;
                        }
                        y++;
                    }
                    if(k==1){
                        q=S.returneTop(0,m);
                        visited[i]=S.returneTop(0,m);
                        k++;
                    }
                }y=0;
               /* if (S.retTop(i,m,1)==true)*/

            }y=0; k=0;

        }

        S.display();

        return visited;
    }
    int StrongComponent(){
        int sum=0;
        //
        //Создаём матрицу R
        //
        AdjacencyMatrix R(n);
        for(int p=1;p<n+1;p++){//добавляем вершины в матрицу R
            R.add_top(adj[0][p]);
        }
        for (int i=1; i<n+1; i++){

            int *h=this->BFS(i);
            for (int j=1; j<n+1;j++){
               R.add_arc_loop(adj[0][j]);
                for(int k=0; k<n+1;k++){
                    if(h[k]==j){
                        R.add_arc(i,j);
                    }
                }
            }
        }cout<<"R:"<<endl;
        R.display();

        //
        //Создаём матрицу Q
        //
        AdjacencyMatrix Q(n);
        for(int p=1;p<n+1;p++){//добавляем вершины в матрицу R
            Q.add_top(adj[0][p]);
        }
        for (int i=1; i<n+1; i++){
            for (int j=1; j<n+1;j++){
                Q.add_arc_loop(adj[0][j]);
                    if(R.retTop(i,j,1)){
                        Q.add_arc(j,i);
                    }
            }
        }cout<<"Q:"<<endl;
        Q.display();
        //
        //Создаём матрицу RQ
        //
        AdjacencyMatrix RQ(n);
        for(int p=1;p<n+1;p++){//добавляем вершины в матрицу R
            RQ.add_top(adj[0][p]);
        }
        cout<<"RQ:"<<endl;
        for (int m=1; m<n+1; m++){
            for (int z=1; z<n+1;z++){
                sum= R.value_top(m,z)*Q.value_top(m,z);
               if(sum==1) {
                       RQ.add_arc_RQ(m,z);
               }
            }
        }
        cout<<"RQ:"<<endl;
        RQ.display();
//
//Создаём матрицу RQ
//
        AdjacencyMatrix StrComp(n);
        for (int i=1; i<n+1; i++) {
            for (int j = 1; j < n + 1; j++) {
            if (RQ.returneTop(i,j)==1){
                StrComp.add_top(adj[0][j]);
                StrComp.add_arc_loop(adj[0][j]);
                StrComp.add_arc(adj[i][0],adj[0][j]);
               // StrComp.add_arc(adj[0][j],adj[j][0]);
            }
            }

        }StrComp.display();
    }



};

int main() {
    AdjacencyMatrix adj(7);
    adj.add_top(1);
    adj.add_top(2);
    adj.add_top(3);
    adj.add_top(4);
    adj.add_top(5);
    adj.add_top(6);
    adj.add_top(7);
    adj.add_arc(1, 2);
    adj.add_arc(2, 4);
    adj.add_arc(2, 5);
    adj.add_arc(4, 1);
    adj.add_arc(3,6);
    adj.add_arc(3,5);
    adj.add_arc(5,3);
    adj.add_arc(6,7);
    adj.add_arc(6,5);
    adj.display();
    int *h = adj.BFS(1);
    for (int i = 0; i < adj.getsize(); i++) {
        cout << " " << h[i];
    }cout << endl;
    adj.StrongComponent();

    return 0;

}
