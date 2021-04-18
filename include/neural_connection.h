#ifndef N3RDNEAT_NEURAL_CONNECTION_H
#define N3RDNEAT_NEURAL_CONNECTION_H

#include "neural_node.h"

struct neural_connection {
	struct neural_node *from;
	float weight;
};

int neural_connection_init(struct neural_connection *connection, struct neural_node *from_node, float weight);

#endif
