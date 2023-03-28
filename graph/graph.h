#ifndef CDSC_GRAPH
#define CDSC_GRAPH
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct graph {
	void **adj_matrix;
	int nodes;
};

struct graph *cdsc_graph_init(size_t nodes);
void *cdsc_graph_nuke(struct graph *g);

bool cdsc_graph_insert(struct graph *g, void *node1, void *node2);
void *cdsc_graph_delete(struct graph *g, void *node);
bool cdsc_graph_search(struct graph *g, void* node1, void* node2);

size_t cdsc_graph_len(struct graph *g);
bool cdsc_graph_is_emtpy(struct graph *g);

#endif
