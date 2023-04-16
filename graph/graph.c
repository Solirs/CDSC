#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "graph.h"

// Internal function for node initialization
node *cdcsc_node_init(int dest) {
	node *new_node = (node *) malloc(sizeof(node));
	new_node->next = NULL;
	new_node->dest = dest;
	return new_node;
}

// Constructor for graph with adjacency list
graph *cdsc_graph_init(size_t nodes) {
	graph *g = (graph *) malloc(sizeof(graph));
	g->nodes = nodes;
	g->adj_list = (node **) malloc(nodes * sizeof(node *));
	int i;
	for(i = 0; i < nodes; i++) {
		g->adj_list[i] = NULL;
	}
	return g;
}

// Adds and undirected edge between two nodes
void cdsc_graph_insert(graph *g, int source, int target) {
	// Create a new node and connect it to the graph
	node *new_node = cdcsc_node_init(target);
	new_node->next = g->adj_list[source];
	g->adj_list[source] = new_node;

	// Two-way connection
	new_node = cdcsc_node_init(source);
	new_node->next = g->adj_list[target];
	g->adj_list[target] = new_node;
}

void cdsc_graph_nuke(graph *g) {
	for (int i = 0; i < g->nodes; i++) {
		node *current = g->adj_list[i];
		while (current != NULL) {
			node *next = current->next;
			free(current);
			current = next;	
		}
	}
	free(g->adj_list);
	free(g);
}

void *cdsc_graph_delete(graph *g, void *node);
bool cdsc_graph_search(graph *g, void* node1, void* node2);

size_t cdsc_graph_len(graph *g) {
	return g->nodes;
}

bool cdsc_graph_is_emtpy(graph *g) {
	if (!g->nodes) {
		return true;
	}
	else {
		return false;
	}
}

