#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main()
{
    int graphdriver = DETECT, graphmode, errorcode;
    int x2, y2, x1, y1, sx, sy;

    // Input for line endpoints
    printf("Enter the 2 line end points (x1, y1, x2, y2): ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    // Initialize the graphics mode
    initgraph(&graphdriver, &graphmode, "C:\\TURBOC3\\BGI");

    // Draw the original line
    line(x1, y1, x2, y2);

    // Input for scaling factors
    printf("Enter scaling factors (sx, sy): ");
    scanf("%d%d", &sx, &sy);

    // Scale the line endpoints
    x1 = x1 * sx;
    y1 = y1 * sy;
    x2 = x2 * sx;
    y2 = y2 * sy;

    // Draw the scaled line
    printf("Line after scaling\n");
    line(x1, y1, x2, y2);

    getch();  // Wait for user input to view result
    closegraph();  // Close the graphics window
}
