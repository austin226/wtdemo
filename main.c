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
 * a given input file. argv[1] is the filename,
 * and argv[2] is the transform. Alternatively,
 * if these are not present, they will be
 * prompted inside main.
 */
int main(int argc, char** argv) {
	char wavelet_filename[ARG_LEN], transform_name[ARG_LEN];
	/* TODO make sure args match ARG_LEN or less */

	if (argc > 3) {
		/* Too many arguments specified. */
		printf("Too many args!");
		/* TODO usage message */
		return (EXIT_SUCCESS);
	}
	else if (argc == 3) {
		/* File and transform specified. */
		strcpy(wavelet_filename, argv[1]);
		strcpy(transform_name, argv[2]);
	}
	else if (argc == 2) {
		/* File specified, no transform. */
		strcpy(wavelet_filename, argv[1]);

		/* Prompt for tranform */
		printf("Select transform: ");
		scanf("%s", &transform_name);
	}
	else {
		/* Nothing specified. Prompt for info. */

		/* Prompt for a wave file */
		printf("Filename of wavelet data: ");
		scanf("%s", &wavelet_filename);

		/* Prompt for tranform */
		printf("Select transform: ");
		scanf("%s", &transform_name);
	}

	printf("file %s, trans %s\n", wavelet_filename, transform_name);


	return (EXIT_SUCCESS);
}

