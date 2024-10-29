#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main() {
    int graphdriver = DETECT, graphmode, errorcode;
    int x1, y1, x2, y2, x, y;

    // Input line coordinates
    printf("Enter the 2 line end points (x1, y1, x2, y2): ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    // Initialize graphics mode
    initgraph(&graphdriver, &graphmode, "C:\\TURBOC3\\BGI");

    // Draw the original line
    line(x1, y1, x2, y2);

    // Input translation coordinates
    printf("Enter translation coordinates (x, y): ");
    scanf("%d%d", &x, &y);

    // Apply translation to the line
    x1 = x1 + x;
    y1 = y1 + y;
    x2 = x2 + x;
    y2 = y2 + y;

    // Display translated line
    printf("Line after translation\n");
    line(x1, y1, x2, y2);

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
}
