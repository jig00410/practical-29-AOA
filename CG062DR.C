#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main() {
    int graphdriver = DETECT, graphmode;
    int x1, y1, x2, y2, xn, yn;  // Declare all variables at the start
    int x_relative, y_relative;  // For relative translation
    double r11, r12, th;         // Only the necessary variables for rotation

    // Initialize graphics mode
    initgraph(&graphdriver, &graphmode, "C:\\TURBOC3\\BGI");

    // Input line end points
    printf("Enter the 2 line end points (x1, y1, x2, y2): ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    // Draw the original line
    line(x1, y1, x2, y2);

    // Input the rotation angle
    printf("\nEnter the rotation angle (in degrees): ");
    scanf("%lf", &th);

    // Calculate rotation matrix coefficients
    r11 = cos((th * M_PI) / 180);  // M_PI is from math.h
    r12 = sin((th * M_PI) / 180);

    // Translate second point relative to the first point (pivot)
    x_relative = x2 - x1;
    y_relative = y2 - y1;

    // Apply rotation matrix to the second point
    xn = x1 + (x_relative * r11 - y_relative * r12);  // New x-coordinate
    yn = y1 + (x_relative * r12 + y_relative * r11);  // New y-coordinate

    // Draw the rotated line
    line(x1, y1, xn, yn);

    getch();  // Wait for a key press
    closegraph();  // Close the graphics window
}
