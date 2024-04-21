#ifndef CDSC_SKIPLIST_
#define CDSC_SKIPLIST_

#include "../doublylinkedlist/doublylinkedlist.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

typedef struct cdsc_sl{
    struct cdsc_doublylinkedlist *layers;
    double layer_up_chance;
    
} cdsc_sl;

// This is what is contained in the layer doublylinkedlists, points to the node above and below + holds the actual data.
struct cdsc_sl_data{
	void* data;
	struct cdsc_doublylinkedlist_node* below;
	struct cdsc_doublylinkedlist_node* above;
	
	// Whether the node is a fake node or not.
	bool invis;
};

struct cdsc_sl* cdsc_sl_init(int layers, double layer_up_chance);
int cdsc_sl_insert(struct cdsc_sl* skiplist, int data);
int cdsc_sl_at(cdsc_sl* skiplist, int layer, int at);
int cdsc_sl_data_from_node(struct cdsc_doublylinkedlist_node* nd);
#endif
