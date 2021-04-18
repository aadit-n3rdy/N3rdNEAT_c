#include "../include/neural_node.h"

#include <stdio.h>

int neural_node_calc(struct neural_node *node) {
	if (!node->updated) {
		for (int i = 0; i < node->from_count; i++) {
			if (!node->connections_from[i].from->updated) {
				neural_node_calc(node->connections_from[i].from);
			}
			node->value += node->connections_from[i].weight * node->connections_from[i].from->value;
		}
	}
	return 0;
}

int neural_node_init(struct neural_node *node, float height) {
	node->height = height;
	node->value = 0;
	node->updated = false;
	node->from_count = 0;
	node->from_space = 0;
	node->connections_from = NULL;
}

