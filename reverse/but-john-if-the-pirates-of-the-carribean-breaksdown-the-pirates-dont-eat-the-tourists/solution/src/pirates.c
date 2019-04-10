#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

#define FFLAG "Yarggghhhh matey!!! Look harder ye skallywag!!!"
#define FFLAG2 "Ye shall be walkin the plank momentaaaaarily land lover..."
int main(void) {
	int i,j,k,h,l,m,n,o = 0;
	for (i = 0;i < 250; i++) {
		j += i - k;
		k += i + o;
		h += i - o + k * j;
		l += i + j + k + h - o;
		m += i - j + o - n;
		n = i - j + m;
		o = i + j * k;
	}
	if(i == 249) {
		printf("\n%s\n\n", FFLAG);
	}
	else {
		printf("\n%s\n\n", FFLAG2);
	}
	return 0;
}
