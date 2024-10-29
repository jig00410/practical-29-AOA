#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawline(int x0, int y0, int x1, int y1) {
    int dx, dy, p, x, y;

    // Swap coordinates if x1 < x0 to ensure it works for all cases
    if (x0 > x1) {
        int temp = x0;
        x0 = x1;
        x1 = temp;
        temp = y0;
        y0 = y1;
        y1 = temp;
    }

    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;

    p = 2 * dy - dx;

    while (x <= x1) {
        putpixel(x, y, WHITE);  // Use WHITE color for line
        if (p >= 0) {
            y++;
            p = p + 2 * dy - 2 * dx;
        } else {
            p = p + 2 * dy;
        }
        x++;
    }
}

int main() {
    int gdriver = DETECT, gmode;
    int x0, y0, x1, y1;

    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

    // Input coordinates
    printf("Enter the coordinates of the first point: ");
    scanf("%d%d", &x0, &y0);
    printf("Enter the coordinates of the second point: ");
    scanf("%d%d", &x1, &y1);

    // Draw the line
    drawline(x0, y0, x1, y1);

    getch();
    closegraph();  // Close the graphics window

    return 0;
}
