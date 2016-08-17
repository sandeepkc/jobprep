#include<cstdio>
#include<cstdlib>

int pts[200];
bool direction[200]; 
/* Will hold a boolean 1 if it is R else 0*/

void solve(int speed, char *init) {
    int L = 0;
    while (init[L] != '\0') ++L;
    
    // printf("speed: %d\n", speed);
    // printf("init: %s\n", init);

    int N = 0;
    for (int i = 0; i < L; i++) {
	if (init[i] != '.') {
	    pts[N] = i;
	    direction[N] = init[i] == 'R';
	    ++N;
	}
    }

    bool again;
    do {
	again = false;
	char line[200];
	for (int i = 0; i < L; i++) line[i] = '.';
	line[L] = '\0';

	for (int i = 0; i < N; i++) {
	    if (pts[i] >= 0 and pts[i] < L) {
                /* If the index is in range, 
                   print X at appropriate position in line */
		line[pts[i]] = 'X';
 
                /* Update the next position */
		if (direction[i]) pts[i] += speed;
		else pts[i] -= speed;
	    }
	}
	printf("%s\n", line);
	for (int i = 0; i < N; i++) {
            /* Check if the particles are all out or not */
	    again = again or (pts[i] < L and pts[i] >= 0);
	}
    } while (again);

    if (N != 0) {
	char line[200];
	for (int i = 0; i < L; i++) line[i] = '.';
	line[L] = '\0';
	printf("%s\n", line);
    }
}

int main (int argc, char **argv) {
    if (argc < 2) {
	printf("usage: %s input-file-name\n", argv[0]);
	exit(0);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
	printf("unable to read the input file: %s\n", argv[1]);
	exit(0);
    }

    int speed;
    char init[200];
    while (fscanf(input_file, "%d %s\n", &speed, init) != -1) {
	solve(speed, init);
	printf("\n");
    }
}
