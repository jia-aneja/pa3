#ifndef _NODE_H
#define _NODE_H

#ifndef __ASSEMBLER__

typedef struct node {
	char *id;
	unsigned long height;
	unsigned long xcoord;
	unsigned long ycoord;
	struct node *next;
} node;

extern node *node_lookup(node *front, char *id);
extern node *insert_node(char *id, unsigned long height, unsigned long xcoord, unsigned long ycoord, node *front);
extern int load_table(node **htable, unsigned long tabsz, char *filename);
extern unsigned long hash(char *id);
extern void delete_table(node **htable, unsigned long tabsz);
extern void print_info(node **htable, unsigned long tabsz);
#else
.equ	NULL, 0
//.equ	NODE_ID_OFFSET,     __fill in__
//.equ	NODE_HEIGHT_OFFSET, __fill in with relative calculation__
//.equ	NODE_XCOORD_OFFSET, __fill in with relative calculation__
//.equ	NODE_YCOORD_OFFSET, __fill in with relative calculation__
//.equ	NODE_NEXT_OFFSET,   __fill in with relative calculation__
//.equ	NODE_PAD_OFFSET,    __fill in with relative calculation__
//.equ	NODE_STRUCT_SIZE,   __fill in with relative calculation__
#endif
#endif
