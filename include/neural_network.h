#ifndef N3RDNEAT_NEURAL_NETWORK_H
#define N3RDNEAT_NEURAL_NETWORK_H

#include "neural_node.h"

#include "stdlib.h"

struct n3rd_neat {
	struct neural_node *nodes;
	unsigned int node_count;
	unsigned int input_count;
	unsigned int output_count;
	unsigned int node_space;
};

int n3rd_neat_mutate(struct n3rd_neat *network); /* Mutate the network by adding a node, adding a connection, or modifying a node */
int n3rd_neat_calc(struct n3rd_neat *network, float* input); /* Update all noads in the network */
int n3rd_neat_get_value(struct n3rd_neat *network, unsigned int index, float *value); /* Get the calculated value at index index */
int n3rd_neat_init(struct n3rd_neat *network, unsigned int input_count, unsigned int output_count); /* Initialise the network and allocate memory */
int n3rd_neat_add_node(struct n3rd_neat *network, unsigned int from_node_index, unsigned int to_node_index);
int n3rd_neat_add_connection(struct n3rd_neat *network, unsigned int from_node_index, float weight, unsigned int to_node_index);
int n3rd_neat_mutate_connection(struct n3rd_neat *network, unsigned int from_node_index, unsigned int to_node_index);

#endif
