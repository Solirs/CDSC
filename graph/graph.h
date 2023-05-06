#ifndef CDSC_GRAPH
#define CDSC_GRAPH
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
	int dest;
	struct node *next;
} node;

typedef struct graph {
	node **adj_list;
	int nodes;
} graph;

graph *cdsc_graph_init(size_t nodes);
int cdsc_graph_nuke(graph *g);

int cdsc_graph_insert(graph *g, int source, int target);
int cdsc_graph_delete(graph *g, int source, int target);
bool cdsc_graph_search(graph *g, void* node1, void* node2);

size_t cdsc_graph_len(graph *g);
bool cdsc_graph_is_emtpy(graph *g);

#endif
