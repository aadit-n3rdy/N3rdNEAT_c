
#include "../include/neural_connection.h"
#include "../include/neural_node.h"

int neural_connection_init(struct neural_connection *connection, struct neural_node *from_node, float weight) {
	connection->from = from_node;
	connection->weight = weight;
	return 0;
}
