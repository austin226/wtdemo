/* 
 * File:   main.c
 * Author: Austin Almond
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wavelib/header/wavelib.h"

#define ARG_LEN 100

double absmax(double *array, int N) {
        double max;
        int i;

        max = 0.0;
        for (i = 0; i < N; ++i) {
                if (fabs(array[i]) >= max) {
                        max = fabs(array[i]);
                }
        }

        return max;
}

/*
 * Performs a wavelet transform function on
 * a given input signal. argv[1] is the input signal,
 * argv[2] is the wavelet, and argv[3] is the transform.
 */
int main(int argc, char** argv) {
	/* For now, based on dwttest.c; TODO change to dynamic testing */

	char signal_name[ARG_LEN], wavelet_name[ARG_LEN], transform_name[ARG_LEN];

        double *inp, *out, *diff;
        int siglength, i, decompositions;

        FILE *ifp;
        double temp[1200];

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
		return(EXIT_FAILURE);
	}

        printf("Performing transformation '%s' with wavelet '%s' on signal '%s'\n\n", transform_name, wavelet_name, signal_name);

        /* init signal */
        ifp = fopen(signal_name, "r");
        i = 0;
        if (!ifp) {
                printf("Can't open file.\n");
                return (EXIT_FAILURE);
        }
        while (!feof(ifp)) {
                fscanf(ifp, "%lf \n", &temp[i]);
                i++;
        }

        inp = (double*)malloc(sizeof(double)* siglength);
        out = (double*)malloc(sizeof(double)* siglength);
        diff = (double*)malloc(sizeof(double)* siglength);

        for (i = 0; i < siglength; ++i) {
                inp[i] = temp[i];
                //printf("%g \n",inp[i]);
        }        

	/* init wavelet */
	wo = wave_init(wavelet_name);
	if (wo->filtlength < 0) {
		printf("Invalid wavelet filter.\n");
		wave_free(wo);
		return(EXIT_FAILURE);
	}
	
	/* init transform */
	siglength = 256; decompositions = 3;	/* TODO */
	wt = wt_init(wo, transform_name, siglength, decompositions);
	setDWTExtension(wt, "sym");
	setWTConv(wt, "direct");

        dwt(wt, inp);// Perform DWT
        printf("Wavelet transform output: \n");
        for (i = 0; i < wt->outlength; ++i) {
                printf("%g ",wt->output[i]);
        }

        printf("\n\nWavelet transform summary:\n");
        wt_summary(wt);// Prints the full summary.
        wave_free(wo);
        wt_free(wt);

        free(inp);
        free(out);
        free(diff);

	return (EXIT_SUCCESS);
}

