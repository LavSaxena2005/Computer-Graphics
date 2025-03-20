#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawEllipse(int xc, int yc, int rx, int ry) {
    int x, y;
    float d1, d2;
    x = 0;
    y = ry;

    d1 = ry * ry - rx * rx * ry + 0.25 * rx * rx;
    while (rx * rx * y > ry * ry * x) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        if (d1 < 0) {
            x++;
            d1 += 2 * ry * ry * x + ry * ry;
        } else {
            x++;
            y--;
            d1 += 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
        }
    }
    d2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);
    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        if (d2 > 0) {
            y--;
            d2 += rx * rx - 2 * rx * rx * y;
        } else {
            y--;
            x++;
            d2 += ry * ry * x - 2 * rx * rx * y + rx * rx;
        }
    }
}

int main() {
    int xc = 320;
    int yc = 250;
    int rx = 100;
    int ry = 50;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    drawEllipse(xc, yc, rx, ry);

    // Fill the ellipse with green color
    setfillstyle(SOLID_FILL, 17);
    floodfill(xc, yc, WHITE); // Start filling from the center of the ellipse

    getch();
    closegraph();
    return 0;
}
