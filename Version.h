// Version.h
// version 08/22/2024

#define MYDELTTABLE      // when defined will use your delete_table.c
#define MYLOADTABLE      // when defined will use your load_table.c
#define MYPRINTINFO      // when defined will use your print_info.c
#define MYMAIN           // when defined will use your lookup.c

//#define MYHASH_S         // when defined will use your hash.S

// node_lookup and insert_node do **NOT** have solution versions provided
// if you comment out the _S definitions, it will use **YOUR** C version
// this means that you should implement Cnode_lookup.c and 
//   Cinsert_node.c first, before doing any other component of the
//   assignment, as these are necessary to test the rest of the program

//#define MYNODELOOKUP_S   // when defined will use your node_lookup.S

//#define MYINSTNODE_S     // when defined will use your insert_node.S
