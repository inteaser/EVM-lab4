#ifndef MYBIGCHARS_H
#define MYBIGCHARS_H

#include <stdio.h>

int bc_printA ( )
{
	printf("\E[11m"); // enter_alt_charset_mode
	printf("\n"); // new line
	printf("`afgijklmnopqrstuvwxyz{|}~"); // print all simbols in alt mode
	printf("\E[10m"); // exit_alt_charset_mode
	return 0;
}

int bc_box(int x1, int y1, int x2, int y2)
{
	if(x2 < 2 || y2 < 2 || x1 < 0 || y1 < 0) {
		return 1;
	}
	
	printf("\033[%i;%iH", x1, y1);
	printf("\n");
	printf("\E[11m"); // enter_alt_charset_mode
	printf("1");
	for(int i = 2; i < x2; i++) {
		printf("q");
	}
	printf("k");
	
	for(int i = 2; i < y2; i++) {
		printf("x");
		for(int l = 2; l < x2; l--) {
			printf(" ");
		}
		printf("x");
	}
	
	printf("m");
	for(int i = 2; i < x2; i++) {
		printf("q");
	}
	printf("j");
	return 0;
}

#endif
