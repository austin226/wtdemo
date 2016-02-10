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

void do_wave_init(char *signal, char *wavelet) {
	wave_object wo;
	wo = wave_init(wavelet);
	if (wo->filtlength < 0) {
		printf("Invalid wavelet filter.\n");
		return;
	}
	wave_summary(wo);
}

/*
 * Performs a wavelet transform function on
 * a given input signal. argv[1] is the input signal,
 * and argv[2] is the wavelet. Alternatively,
 * if these are not present, they will be
 * prompted inside main.
 */
int main(int argc, char** argv) {
	char signal_name[ARG_LEN], wavelet_name[ARG_LEN];
	/* TODO make sure args match ARG_LEN or less */

	if (argc > 3) {
		/* Too many arguments specified. */
		printf("Too many args!");
		/* TODO usage message */
		return (EXIT_SUCCESS);
	}
	else if (argc == 3) {
		/* Signal and wavelet specified. */
		strcpy(signal_name, argv[1]);
		strcpy(wavelet_name, argv[2]);
	}
	else if (argc == 2) {
		/* Signal specified, no wavelet. */
		strcpy(signal_name, argv[1]);

		/* Prompt for wavelet */
		printf("Select wavelet: ");
		scanf("%s", &wavelet_name);
	}
	else {
		/* Nothing specified. Prompt for info. */

		/* Prompt for a signal */
		printf("Name of signal: ");
		scanf("%s", &signal_name);

		/* Prompt for wavelet */
		printf("Select wavelet: ");
		scanf("%s", &wavelet_name);
	}

	printf("signal %s, trans %s\n", signal_name, wavelet_name);

	do_wave_init(signal_name, wavelet_name);

	return (EXIT_SUCCESS);
}

