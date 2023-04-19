#include "graph.h"
#include <stdio.h>

int main() {
    graph *g = cdsc_graph_init(4);
    cdsc_graph_insert(g, 0, 1);
    cdsc_graph_insert(g, 1, 2);
    cdsc_graph_insert(g, 0, 2);
    cdsc_graph_insert(g, 2, 3);

    cdsc_graph_delete(g, 3, 0);

    cdsc_graph_nuke(g);
}
