#include "Version.h"

//#if defined(MYNODELOOKUP_S)
//#warning("using my node_lookup.S")
//#else
//#warning("using my Cnode_lookup.c")

#include <string.h>
#include "node.h"

node *node_lookup(node *front, char *id) {
	while(front != NULL) {
		if (strcmp(front->id, id) == 0) {
            		return front; 
        	}
        	front = front->next;
	} 
	return NULL; 
}
//#endif
