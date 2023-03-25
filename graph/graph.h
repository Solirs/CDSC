#ifndef CDSC_GRAPH
#define CDSC_GRAPH
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct graph_node {
	graph_node *neighboirs;
	void *value;
};

struct graph {
	graph_node *nodes;
	size_t len;
};

struct graph cdsc_graph_init(void);
void *cdsc_graph_nuke(graph *g);

bool cdsc_graph_insert(graph *g, void *node1, void *node2);
void *cdsc_graph_delete(graph *g, void *node);
bool cdsc_graph_search(graph *g, void *node);

size_t cdsc_graph_len(graph *g);
bool cdsc_graph_is_emtpy(graph *g)

#endif
