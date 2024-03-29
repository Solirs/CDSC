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
    for (i = 0; i < nodes; i++) {
	g->adj_list[i] = NULL;
    }
    return g;
}

// Adds and undirected edge between two nodes
int cdsc_graph_insert(graph *g, int source, int target) {
    // Create a new node and connect it to the graph
    node *new_node = cdcsc_node_init(target);
    new_node->next = g->adj_list[source];
    g->adj_list[source] = new_node;

    // Two-way connection
    new_node = cdcsc_node_init(source);
    new_node->next = g->adj_list[target];
    g->adj_list[target] = new_node;
    return 1;
}

// Free all nodes of the graph and the graph itself
int cdsc_graph_nuke(graph *g) {
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
    return 1;
}

// Remove a single edge between two nodes of the graph
int cdsc_graph_delete(graph *g, int source, int target) {
    node *current = g->adj_list[source];
    node *prev = NULL;
    while (current != NULL && current->dest != target) {
	prev = current;
	current = current->next;
    }

    // Remove node target from the list after it was found
    if (current != NULL) {
	if (prev == NULL) {
	    g->adj_list[source] = current->next;
	}

	else {
	    prev->next = current->next;
	}
	free(current);
    }
    // Repeat the same process for the other direction
    current = g->adj_list[target];
    prev = NULL;

    while (current != NULL && current->dest != source) {
	prev = current;
	current = current->next;
    }

    if (current != NULL) {
	if (prev == NULL) {
	    g->adj_list[target] = current->next;
	}

	else {
	    prev->next = current->next;
	}
	free(current);
    }
    return 1;
}

bool cdsc_graph_search(graph * g, void *node1, void *node2);

// Return number of nodes in the graph
size_t cdsc_graph_len(graph *g) {
    return g->nodes;
}

// Check if there are any nodes present in the graph
bool cdsc_graph_is_emtpy(graph *g) {
    if (!g->nodes) {
	return true;
    } else {
	return false;
    }
}
