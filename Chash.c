#include "Version.h"
#if !defined(MYHASH_S)
#warning("using solution hash")
#else
#warning("using hashfn from hash.S")

extern unsigned long hashfn(unsigned long, unsigned long);

unsigned long hash(char *str) {
	unsigned long hash = 0;
	unsigned int c;
	while ((c = (unsigned char)*str++) != '\0')
		hash = hashfn((unsigned long)c, hash);
		// hash = c + (hash << 6) + (hash << 16) - hash;
	return hash;
}
#endif
