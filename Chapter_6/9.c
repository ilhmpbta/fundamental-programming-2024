#include <stdio.h>
#define rho 1.23
/*
When an aircraft or an automobile is moving through the atmosphere, it must overcome a force called drag that works against the motion of the vehicle. The drag force can be expressed as
F =  1  CD * A * rho * V^2
where F is the force (in newtons), CD is the drag coefficient, A is the pro-jected area of the vehicle perpendicular to the velocity vector (in m2), rho is the density of the gas or fluid through which the body is traveling (kg/m3), and V is the body’s velocity. The drag coefficient CD has a complex derivation and is frequently an empirical quantity. Sometimes the drag coefficient has its own dependencies on velocities: For an automobile, the range is from approximately 0.2 (for a very streamlined vehicle) through about 0.5. For simplicity, assume a streamlined passenger vehicle is moving through air at sea level (where  = 1.23 kg/m3). Write a program that allows a user to input A and CD interactively and calls a function to compute and return the drag force. Your program should call the drag force function repeatedly and display a table showing the drag force for the input shape for a range of velocities from 0 m/s to 40 m/s in increments of 5 m/s
*/

void dragforce(double *F, double *CD, double *A, double *V){
    *F = 0.5 * (*CD) * (*A) * rho * (*V) * (*V);
}

int main(){
    double F, CD, A, V;
    printf("Input A (projected area in m^2) and CD (drag coefficient which usuually ranges from 0.2 and 0.5)\n==> ");
    scanf("%lf %lf", &A, &CD);

    printf("\n  F\t CD\t  A\t rho\t  V\n");
    for (V = 0; V <= 40; V+=5){
        dragforce(&F, &CD, &A, &V);
        printf("%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n", F, CD, A, rho, V);
    }
    printf("\n\nNote:\nF\t= drag force (N)\nCD\t= drag coefficient\nA\t= projected area (m^2)\nrho\t= 1.23 kg/m^3 (we assume passenger is moving through air at sea level)\nV\t= velocity (m/2)\n");

}