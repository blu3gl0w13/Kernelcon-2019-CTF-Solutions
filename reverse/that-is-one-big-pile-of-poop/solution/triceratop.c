#include <stdio.h>
#include <stdlib.h>

int hideMe(char);
int unHideMe(int);

int hideMe(char a) {
	return a ^ 0xef;
}

int unHideMe(int b) {
	return b ^= 0xef;
}
