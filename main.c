/* 
 * File:   main.c
 * Author: Austin Almond
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wavelib/header/wavelib.h"

#define ARG_LEN 100

/*
 * Performs a wavelet transform function on
 * a given input signal. argv[1] is the input signal,
 * and argv[2] is the transform. Alternatively,
 * if these are not present, they will be
 * prompted inside main.
 */
int main(int argc, char** argv) {
	char signal_name[ARG_LEN], transform_name[ARG_LEN];
	/* TODO make sure args match ARG_LEN or less */

	if (argc > 3) {
		/* Too many arguments specified. */
		printf("Too many args!");
		/* TODO usage message */
		return (EXIT_SUCCESS);
	}
	else if (argc == 3) {
		/* Wavelet and transform specified. */
		strcpy(signal_name, argv[1]);
		strcpy(transform_name, argv[2]);
	}
	else if (argc == 2) {
		/* Wavelet specified, no transform. */
		strcpy(signal_name, argv[1]);

		/* Prompt for tranform */
		printf("Select transform: ");
		scanf("%s", &transform_name);
	}
	else {
		/* Nothing specified. Prompt for info. */

		/* Prompt for a wave file */
		printf("Name of signal: ");
		scanf("%s", &signal_name);

		/* Prompt for tranform */
		printf("Select transform: ");
		scanf("%s", &transform_name);
	}

	printf("signal %s, trans %s\n", signal_name, transform_name);


	return (EXIT_SUCCESS);
}

