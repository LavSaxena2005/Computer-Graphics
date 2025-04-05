#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int a[3][3], b[3][3], result[3][3];
    int i, j, k;

    clrscr();
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("Enter elements of first 3X3 matrix:\n");
    for(i = 0; i < 3; i++) {
	for(j = 0; j < 3; j++) {
	    scanf("%d", &a[i][j]);
	}
    }
    bar3d(a[0][0],a[0][1],a[1][0],a[1][1],a[2][0],a[2][1]);
    printf("Enter elements of second 3X3  matrix:\n");
    for(i = 0; i < 3; i++) {
	for(j = 0; j < 3; j++) {
	    scanf("%d", &b[i][j]);
	}
    }

 for(i = 0; i < 3; i++) {
	for(j = 0; j < 3; j++) {
	    result[i][j] = 0;
	    for(k = 0; k < 3; k++) {
		result[i][j] += a[i][k] * b[k][j];
	    }
	}
    }

    bar3d(result[0][0], result[0][1], result[1][0], result[1][1], result[2][0], result[2][1]);

    printf("\nResultant matrix:\n");
    for(i = 0; i < 3; i++) {
	for(j = 0; j < 3; j++) {
	    printf("%d ", result[i][j]);
	}
	printf("\n");
    }
    getch();
    closegraph();
}