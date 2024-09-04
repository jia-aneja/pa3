#include "Version.h"
#if !defined(MYMAIN)
#warning("using solution main")
#else
#warning("using my lookup.c")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "node.h"

#define MIN_TAB_SZ 3
#define DEFAULT_TAB_SZ 1873
#define QUERY_SUCCESS_FORMAT "found tree id=%s, height=%lu, x=%lu, y=%lu\n"
#define QUERY_FAILURE_FORMAT "could not find tree with id=%s\n"

int main(int argc, char **argv) {
	int s_flag;
	unsigned long tabsz;
	//char *filename = NULL;
    	int opt;
	while ((opt = getopt(argc, argv, "st:")) != -1) {
        	switch (opt) {
            		case 's':
                		s_flag = 1;
                		break;
            		case 't':
                		tabsz = strtoul(optarg, NULL, 10);
                		if (tabsz < MIN_TAB_SZ) {
                    			tabsz = DEFAULT_TAB_SZ;
                		}
                		break;
            		default:
                		fprintf(stderr, "Usage: %s [-s] [-t tabsz] <filename>\n", argv[0]);
                		return EXIT_FAILURE;
        	}
    	}
		
	node **htable = calloc(tabsz, sizeof(node *));
	if (htable == NULL) {
		return EXIT_FAILURE;
	}
	
	// TODO: get filename and call load_table;
	
	
	char *filename =  argv[0];

	if (load_table(htable, tabsz, filename) != 0) {
		fprintf(stderr, "error in load_table\n");
		free(htable);
		return EXIT_FAILURE;
	}
	
	size_t bufsz = 0;
	char *buf = NULL; 
	
	// read one line at a time from stdin, do a lookup for that id
	// 
	ssize_t bytes;
	int successful_queries = 0;
	while ((bytes = getline(&buf, &bufsz, stdin)) > 0) {
		// replace the \n, if it exists (for hashing)
		if (buf[bytes - 1] == '\n') buf[bytes - 1] = '\0';

		unsigned long index = hash(buf) % tabsz;

		node *found = node_lookup(htable[index], buf);
                if (found) {
                     printf(QUERY_SUCCESS_FORMAT, found->id, found->height, found->xcoord, found->ycoord);
                     successful_queries++;
                } else {
                     printf(QUERY_FAILURE_FORMAT, buf);
                }	
	}
	printf("%d successful queries\n", successful_queries);

	// if -s called then print stats
	if (s_flag) {
		print_info(htable, tabsz); 
	}

	delete_table(htable, tabsz);
        free(htable);	
	free(buf);  // free the buffer allocated by getline()


	return EXIT_SUCCESS;
}
#endif
