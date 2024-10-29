#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>

// Control points for the Bezier curve
int x[4] = {200, 300, 250, 350};
int y[4] = {150, 100, 200, 300};

// Function to draw the Bezier curve
void bezier() {
    int i;
    double t, xt, yt;

    // Loop through t from 0 to 1 to calculate points on the curve
    for (t = 0.0; t <= 1.0; t += 0.0005) {
        xt = pow(1-t, 3)*x[0] + 3*t*pow(1-t, 2)*x[1] + 3*pow(t, 2)*(1-t)*x[2] + pow(t, 3)*x[3];
        yt = pow(1-t, 3)*y[0] + 3*t*pow(1-t, 2)*y[1] + 3*pow(t, 2)*(1-t)*y[2] + pow(t, 3)*y[3];
        putpixel(xt, yt, WHITE);
    }

    // Mark the control points
    for (i = 0; i < 4; i++) {
        putpixel(x[i], y[i], YELLOW);
    }

    getch(); // Wait for user input
    closegraph(); // Close the graphics window
}

void main() {
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); // Adjust the path to BGI files if necessary

    // Call the Bezier function to draw the curve
    bezier();
}
