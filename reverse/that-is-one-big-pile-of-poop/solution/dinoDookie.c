#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hideMe(char a);
char unHideMe(int a);

int main(int argc, char *argv[]) {
	char a[] = { hideMe('k'), hideMe('e'), hideMe('r'), hideMe('n'), hideMe('e'), hideMe('l'), hideMe('{'), hideMe('e'), hideMe('1'), hideMe('0'), hideMe('c'), hideMe('f'), hideMe('0'), hideMe('8'), hideMe('2'), hideMe('2'), hideMe('d'), hideMe('a'), hideMe('a'), hideMe('7'), hideMe('b'), hideMe('5'), hideMe('1'), hideMe('e'), hideMe('f'), hideMe('a'), hideMe('a'), hideMe('9'), hideMe('3'), hideMe('5'), hideMe('0'), hideMe('d'), hideMe('9'), hideMe('7'), hideMe('b'), hideMe('6'), hideMe('e'), hideMe('7'), hideMe('b'), hideMe('}'), hideMe('\0') };
	char *b = "smellyflag";
	char *c = "stinkyflag";
	char *d = "smellystinkyflag";

	if (getenv("SUSPECT") == NULL) {
		printf("\nYou aren't even close to finding big piles of poop...\n");
	}
	else if (strcmp(getenv("SUSPECT"), "t-rex") == 0) {
		printf("\nDefinitely not, there's berries here....\n");
	}
	else if (strcmp(getenv("SUSPECT"), "brontosaurus") == 0 ) {
		printf("\nMaybe, though I would expect more evidence of leaves...\n");
	}
	else if (strcmp(getenv("SUSPECT"), "velociraptor") == 0 ) {
		printf("\nNope, not evidence of meaty victims here...\n");
	}
	else if (strcmp(getenv("SUSPECT"), "stegasauraus") == 0 ) {
		printf("\nHmmm, a possibility, but not likely due to the type of berries found....\n");
	}
	else if (strcmp(getenv("SUSPECT"), "triceratops") == 0 ) {
		printf("\nYes, you might be onto something...\n");
		if(argc < 3 && argc > 0) {
			char *clue = argv[1];
			if(strcmp(b, clue) == 0) {
				printf("%s", a);
			}
			else if (strcmp(c, clue) == 0) {
				printf("%s", a);
			}
			else if (strcmp(d, clue) == 0) {
				for (int i = 0;i < sizeof(a); i++) {
					a[i] = unHideMe(a[i]);
				}

				printf("\n%s\n\n", a);
			}
			else {
				printf("\nEwwww, you got an arm full of poo!\n");
			}
		}
	}
	else if (strcmp(getenv("SUSPECT"), "veggiesaurus") == 0) {
		printf("\nEwwww poo berries...\n");
	}
	else if (strcmp(getenv("SUSPECT"), "meatasaurus") == 0) {
		printf("\nNope, we found poo berries...\n");
	}
	else if (strcmp(getenv("SUSPECT"), "pteradactyl") == 0) {
		printf("\nGet real, this size of a pile would weigh a bird like that down...\n");
	}
	else {
		printf("\nYou just got an arm full of poo, nothing else\n");
	}
	return 0;
}
