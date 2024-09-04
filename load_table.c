#include "Version.h"
//#if !defined(MYLOADTABLE)
//#warning("using solution load_table")
//#else
//#warning("using my load_table.c")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

#define MAX_LINELEN 100 
#define FILE_OPEN_ERR_MSG "error in load_table while opening file %s\n"
#define DUPLICATE_ID_MSG "load_table duplicate entry: %s\n"
#define INSERTION_ERROR_MSG "load_table could not create node for %s\n"

int load_table(node **htable, unsigned long int tabsz, char *filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
        	fprintf(stderr, FILE_OPEN_ERR_MSG, filename);
        	return -1;
        }
	char buf[MAX_LINELEN + 1];
	while (fgets(buf, MAX_LINELEN + 1, fp) == buf) {
		char *id = strtok(buf, ",");
       	        char *heightstr = strtok(NULL, ",");
                char *xstr = strtok(NULL, ",");
                char *ystr = strtok(NULL, ",");

                unsigned long height = strtoul(heightstr, NULL, 10);
                unsigned long xcoord = strtoul(xstr, NULL, 10);
                unsigned long ycoord = strtoul(ystr, NULL, 10);

       
                unsigned long index = hash(id) % tabsz;
                node *chain = htable[index];

		if (node_lookup(chain, id) != NULL) {
                     fprintf(stderr, DUPLICATE_ID_MSG, id);
                     continue; 
                }

		node *new_node = insert_node(id, height, xcoord, ycoord, chain);
                if (new_node == NULL) {
                     fprintf(stderr, INSERTION_ERROR_MSG, id);
                     fclose(fp);
                     return -1;
                }

		htable[index] = new_node;

	}
	fclose(fp);
	return 0;
}
//#endif
