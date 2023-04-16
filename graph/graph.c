#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "graph.h"

struct graph *cdsc_graph_init(size_t nodes) {
    struct graph *g = malloc(sizeof(struct graph));
    g->adj_matrix = calloc(sizeof(bool *), g->nodes);
    // add some memory checks
    int i;
    for (i = 0; i < g->nodes; i++) {
	g->adj_matrix[i] = calloc(sizeof(bool), g->nodes);
    }
    return g;
}

void *cdsc_graph_nuke(struct graph *g);

bool cdsc_graph_insert(struct graph *g, void *node1, void *node2);
void *cdsc_graph_delete(struct graph *g, void *node);
bool cdsc_graph_search(struct graph *g, void *node1, void *node2);

size_t cdsc_graph_len(struct graph *g) {
    return g->nodes;
}

bool cdsc_graph_is_emtpy(struct graph *g) {
    if (!g->nodes) {
	return true;
    } else {
	return false;
    }
}
