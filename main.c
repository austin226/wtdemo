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
 * argv[2] is the wavelet, and argv[3] is the transform.
 */
int main(int argc, char** argv) {
	/* For now, based on dwttest.c; TODO change to dynamic testing */

	char signal_name[ARG_LEN], wavelet_name[ARG_LEN], transform_name[ARG_LEN];

	int N, J;

	wave_object wo;
	wt_object wt;

	if (argc == 4) {
		/* TODO validate input */
		strcpy(signal_name, argv[1]);
		strcpy(wavelet_name, argv[2]);
		strcpy(transform_name, argv[3]);
	}
	else {
		/* TODO print usage */
		printf("Need args\n");
		return(EXIT_SUCCESS);
	}

	printf("signal %s, wavelet %s, trans %s\n", signal_name, wavelet_name, transform_name);

	/* init wavelet */
	wo = wave_init(wavelet_name);
	if (wo->filtlength < 0) {
		printf("Invalid wavelet filter.\n");
		wave_free(wo);
		return(EXIT_SUCCESS);
	}
	wave_summary(wo);
	
	/* init transform */
	N = 256; J = 3;	/* TODO */
	wt = wt_init(wo, transform_name, N, J);
	setDWTExtension(wt, "sym");
	setWTConv(wt, "direct");

	return (EXIT_SUCCESS);
}

