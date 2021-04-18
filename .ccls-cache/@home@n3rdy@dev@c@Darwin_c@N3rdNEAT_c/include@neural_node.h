#ifndef N3RDNEAT_NEURAL_NODE_H
#define N3RDNEAT_NEURAL_NODE_H

#include "neural_connection.h"

#include <stdbool.h>

struct neural_node {
	float value;
	bool updated;
	float height;
	unsigned int from_count;
	unsigned int from_space;
	struct neural_connection *connections_from;
};

int neural_node_calc(neural_node *node);
int neural_node_init(neural_node *node, float height);

#endif
