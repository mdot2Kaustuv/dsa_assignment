# include <stdio.h>
#define MAX 100

void bfs(int graph[MAX][MAX], int visited[MAX], int start, int n) {
    int queue[MAX];
    int front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}




void dfs(int graph[MAX][MAX], int visited[MAX], int current, int n) {
    visited[current] = 1;
    printf("%d ", current);

    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, n);
        }
        }
        }
    


// conncet two vertices 
void addedge(int graph[MAX][MAX], int i, int j) {
    graph[i][j] = 1;
      graph[j][i] = 1; 
}

void displaygraph(int graph[MAX][MAX], int n) {
       for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    }



int main(){
int graph[MAX][MAX] = {0};
int visited[MAX] = {0};
int n = 5;
addedge(graph, 0, 1);
addedge(graph, 0, 2);   
addedge(graph, 1, 3);
addedge(graph, 1, 4);   

displaygraph(graph, n);
printf("\nBFS Traversal: ");
bfs(graph, visited, 0, n);

printf("\nDFS Traversal : ");
for (int i = 0; i < n; i++) {
    visited[i] = 0;
}
dfs(graph, visited, 0, n);
printf("\n");


}

