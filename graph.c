#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct graph_s {
	int *matrix;
	int maxsize;
} Graph;

Graph create_graph(int maxsize);
void add_edge(Graph G, int v1, int v2);
int is_adjacent(Graph G, int v1, int v2);
int get_adja_vertices(Graph G, int vertex, int *output);
void drop_graph(Graph G);

int main(){
	Graph gr = create_graph(MAXSIZE);
	add_edge(gr, 0, 1);
	add_edge(gr, 0, 2);
	add_edge(gr, 1, 2);
	add_edge(gr, 1, 3);

	int n = 0 , i;
	int output[MAXSIZE];
	n = get_adja_vertices(gr, 1, output);

	if (n == 0) printf("There is no adjacent vertex of node 1.\n");
	else {
		printf("The number of vertiex/vertices near 1 is: %d.\n", n);
		printf("Which is: ");
		for (i = 0; i < n; i++) printf("%5d", output[i]);
	}
	printf("\n");	
	return 0;
}

Graph create_graph(int maxsize){
	Graph G;
	G.matrix = (int *)malloc(sizeof(int)*maxsize*maxsize);
	if (G.matrix == NULL){
		printf("Allocation failed at %s:%s.\n", __FILE__, __LINE__);
		exit(1);
	}
	int i;
	for (i=0; i< maxsize*maxsize; i++) G.matrix[i] = 0;
	G.maxsize = maxsize;
	return G;
}

void add_edge(Graph G, int v1, int v2){
	G.matrix[v1*G.maxsize + v2] = 1;
	G.matrix[v2*G.maxsize + v1] = 1;
}

int is_adjacent(Graph G, int v1, int v2){
	return G.matrix[v1*G.maxsize + v2];
}

int get_adja_vertices(Graph G, int vertex, int *output){
	int i, count = 0, n = 0;
	for (i = 0; i < G.maxsize; i++){
		if (G.matrix[vertex*G.maxsize + i] == 1) {
			count++;
			output[n++] = i;
		}
	}
	return count;
}

void drop_graph(Graph G){
	free(G.matrix);
	G.matrix = NULL;
	G.maxsize = 0;
}