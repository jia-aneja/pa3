#include "Version.h"

//#if defined(MYINSTNODE_S)
//#warning("using my insert_node.S")
//#else
//#warning("using my Cinsert_node.c")

#include <stdlib.h>
#include <string.h>
#include "node.h"

node *insert_node(char *id, unsigned long height, unsigned long x, unsigned long y, node *front) {
	node *new_node = (node *)malloc(sizeof(node));
    	if (new_node == NULL) {
        	return NULL; 
    	}

    	new_node->id = strdup(id);
    	if (new_node->id == NULL) {
        	free(new_node); 
        	return NULL;
    	}

    	new_node->height = height;
    	new_node->xcoord = x;
    	new_node->ycoord = y;
    	new_node->next = front;

    	return new_node;
}
//#endif
