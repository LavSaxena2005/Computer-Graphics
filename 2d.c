#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int a[3][2], b[2][2], result[3][2];
    int i, j, k;

    clrscr();
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    printf("Enter elements of first 2x2 matrix:\n");
    for(i = 0; i < 3; i++) {
	for(j = 0; j < 2; j++) {
	    scanf("%d", &a[i][j]);
	}
    }
line(a[0][0], a[0][1], a[1][0], a[1][1]);
line(a[1][0], a[1][1], a[2][0], a[2][1]);
line(a[2][0], a[2][1], a[0][0], a[0][1]);
    printf("Enter elements of second 2x2 matrix:\n");
    for(i = 0; i < 2; i++) {
	for(j = 0; j < 2; j++) {
	    scanf("%d", &b[i][j]);
	}
    }

    for(i = 0; i < 3; i++) {
	for(j = 0; j < 2; j++) {
	    result[i][j] = 0;
	    for(k = 0; k < 2; k++) {
		result[i][j] += a[i][k] * b[k][j];
	    }
	}
    }

    printf("\nResultant matrix:\n");
    for(i = 0; i < 3; i++) {
	for(j = 0; j < 2; j++) {
	    printf("%d ", result[i][j]);
	}
	printf("\n");
    }

    line(result[0][0], result[0][1], result[1][0], result[1][1]);
    line(result[1][0], result[1][1], result[2][0], result[2][1]);
    line(result[2][0], result[2][1], result[0][0], result[0][1]);

    getch();
    closegraph();
}
