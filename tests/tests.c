#include "../include/neural_node.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
	struct neural_node *nodes = calloc(3, sizeof(struct neural_node));
	nodes[0].value = 10;
	nodes[0].updated = true;
	nodes[1].value = 20;
	nodes[1].updated = true;
	nodes[2].from_count = 2;
	nodes[2].connections_from = calloc(2, sizeof(struct neural_connection));
	nodes[2].connections_from[0].from = &nodes[0];
	nodes[2].connections_from[0].weight = 1.0;
	nodes[2].connections_from[1].from = &nodes[1];
	nodes[2].connections_from[1].weight = 2.0;
	neural_node_calc(&nodes[2]);
	printf("Result from TEST 1: %f", nodes[2].value);
	return 0;
}
