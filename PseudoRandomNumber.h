#include <stdio.h>

int myrandf(){
	static int ri = 1;
	ri = ri * 48828125 + 19;
	if(ri < 0)
		ri = (ri + 2147483647) + 1;
	return ri;
}
