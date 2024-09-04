#include "Version.h"
//#if !defined(MYDELTTABLE)
//#warning("using solution delete_table")
//#else
//#warning("using my delete_table.c")

#include <stdlib.h>
#include "node.h"

void delete_table(node **htable, unsigned long tabsz) {
	for (unsigned long i = 0; i < tabsz; i++) {
        	node *current = htable[i];
        
        	while (current != NULL) {
            	node *next_node = current->next; 
            	free(current->id); 
            	free(current);     
            	current = next_node; 
        	}
    	}
    	free(htable);
}
//#endif
