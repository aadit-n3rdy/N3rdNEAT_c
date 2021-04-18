#include "../include/neural_network.h"
#include "../include/neural_node.h"

#include <stdlib.h>
#include <stdio.h>

int n3rd_neat_init(struct n3rd_neat *network, unsigned int input, unsigned int output) {
	if (network == NULL) {
		printf("ERROR: NULL passed to n3rd_neat_init\n");
		return -1;
	}
	network->input_count = input;
	network->output_count = output;
	network->node_count = input + output;
	network->node_space = network->node_count + (8 - network->node_count % 8);
	network->nodes = calloc(network->node_space, sizeof(struct neural_node));
	if (network->nodes == NULL) {
		printf("ERROR: Could not allocate momoey in n3rd_neat_init\n");
		return 1;
	}
	return 0;
}


int n3rd_neat_add_node(struct n3rd_neat *network, unsigned int from_node_index, unsigned int to_node_index) {
	if (network == NULL) {
		printf("ERROR: NULL passed to n3rd_neat_add_node\n");
		return -1;
	}
	if (from_node_index >= network->node_count || to_node_index >= network->node_count) {
		printf("ERROR: Invalid indices passed to n3rd_neat_add_node\n");
		return -2;
	}
	if (network->nodes[from_node_index].height >= network->nodes[to_node_index].height) {
		printf("ERROR: No connection from node of higher height to node of lower height\n");
		return -3;
	}
	bool connection_exists = false;
	unsigned int connection_count = network->nodes[to_node_index].from_count;
	for (unsigned int i = 0; i < connection_count; i++) {
		if (network->nodes[to_node_index].connections_from[i].from == &network->nodes[from_node_index]) {
			connection_exists = true;
			break;
		}
	}
	if (!connection_exists) {
		printf("ERROR: Tried adding node to non-existent connection\n");
		return -1;
	}
	if (network->node_space < network->node_count-1) {
		network->nodes = realloc(network->nodes, sizeof(struct neural_node) * network->node_space + 8);
		if (network->nodes == NULL) {
			printf("ERROR: Could not allocate memory in n3rd_neat_add_node\n");
			return 1;
		}
	}
	network->node_count += 1;
	neural_node_init(&network->nodes[network->node_count-1], 
			(network->nodes[from_node_index].height + network->nodes[to_node_index].height)/2.0f);
	return 0;
}

int n3rd_neat_add_connection(struct n3rd_neat *network, unsigned int from_node_index, float weight, unsigned int to_node_index)
{
	struct neural_node *from_node;
	struct neural_node *to_node;
	from_node = network->nodes[from_node_index];
	to_node = network->nodes[to_node_index];
	int connection_count = to_node->from_count;
	for (int i = 0; i < connection_count; i++) {
		if (to_node->connections_from[i].from == from_node) {
			printf("ERROR: Tried to add connection between connected nodes\n");
			return -1; /*TODO: Add separate error code*/
		}
	}
	if (from_space == connection_count) {
		to_node->connections_from = realloc(sizeof(struct neural_connection) * (from_size + 8));
		if (connections_from == NULL) {
			printf("ERROR: Could not reallocate memory for neural_connection\n");
			return -1; /*TODO: Change error code*/
		}
		from_size += 8;
		to_node->connections[connection_count].weight = weight;
		to_node->connections[connection_count].from = from_node;
		to_node0->from_count++;
	}
}
