#include <stdio.h>

/*
Calculates the center of gravity for a system of 3D point masses.

Each point mass has a 3D location (x,y,z) and a mass value.
For a system of n point masses, the center of gravity C is calculated as:
C = (m1*p1 + m2*p2 + ... + mn*pn) / (m1 + m2 + ... + mn)

The program reads point-mass systems from an input file until EOF.
For each system, it displays:
- The location matrix (each row is a point)
- The mass vector
- The number of points (n)
- The calculated center of gravity

Requirements:
- n must be between 3 and 10
- Each data set includes the number of points, locations, and masses
*/

// Reads point mass data from user input
void get_point_mass(double location[][3], double mass[], int *n) {
    do {
        printf("Enter number of point masses (3-10): ");
        scanf("%d", n);
        
        if (*n < 3 || *n > 10) {
            printf("Error: Number must be between 3 and 10.\n");
        }
    } while (*n < 3 || *n > 10);
    
    printf("Enter location coordinates and mass for each point (x y z mass):\n");
    for (int i = 0; i < *n; i++) {
        printf("Point %d: ", i + 1);
        scanf("%lf %lf %lf %lf", &location[i][0], &location[i][1], &location[i][2], &mass[i]);
    }
}

// Calculates the center of gravity for a system of point masses
void center_grav(double location[][3], double mass[], int n, double center[]) {
    double total_mass = 0;
    center[0] = center[1] = center[2] = 0;
    
    // Calculate weighted sum of coordinates
    for (int i = 0; i < n; i++) {
        total_mass += mass[i];
        center[0] += mass[i] * location[i][0];  // x-coordinate
        center[1] += mass[i] * location[i][1];  // y-coordinate
        center[2] += mass[i] * location[i][2];  // z-coordinate
    }
    
    // Divide by total mass to get center of gravity
    center[0] /= total_mass;
    center[1] /= total_mass;
    center[2] /= total_mass;
}

// Displays the point mass system and center of gravity
void write_point_mass(double location[][3], double mass[], int n, double center[]) {
    printf("\nLocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("  %.2lf %.2lf %.2lf\n", location[i][0], location[i][1], location[i][2]);
    }
    
    printf("Mass Vector:\n");
    for (int i = 0; i < n; i++) {
        printf("  %.2lf\n", mass[i]);
    }
    
    printf("Number of Points: %d\n", n);
    printf("Center of Gravity: (%.2lf, %.2lf, %.2lf)\n", center[0], center[1], center[2]);
}

int main() {
    int n;
    double location[10][3], mass[10], center[3];
    
    get_point_mass(location, mass, &n);
    center_grav(location, mass, n, center);
    write_point_mass(location, mass, n, center);
    
    return 0;
}