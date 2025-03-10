#include <stdio.h>
#include <math.h>

/*
.  The table below summarizes three commonly used mathematical models of 
nonvertical straight lines. Mode Equation Given
Two-point form (x1, y1), (x2, y2)
Point-slope form y − y1 = m(x − x1) m, (x1, y1)
Slope-intercept form y = mx + b m, b

Design and implement a program that permits the user to convert either 
two-point form or point-slope form into slope-intercept form. Your program should interact with the user as follows:
Select the form that you would like to convert to slope-intercept 
form:
1) Two-point form (you know two points on the line)
2) Point-slope form (you know the line's slope and one point)
=> 2
Enter the slope=> 4.2
Enter the x-y coordinates of the point separated by a space=> 1 1
Point-slope form  y – 1.00 = 4.20(x – 1.00)
Slope-intercept form  y = 4.20x – 3.20
Do another conversion (Y or N)=> Y
Select the form that you would like to convert to slope-intercept 
form:
1) Two-point form (you know two points on the line)
2) Point-slope form (you know the line's slope and one point)
=> 1
Enter  the  x-y  coordinates  of  the  first  point  separated  by  a  
space=> 4 3
Enter the x-y coordinates of the second point separated by a 
space=> -2 1
Two-point form
    (1.00 – 3.00)
m = --------------
    (-2.00 – 4.00)
Slope-intercept form
y = 0.33x + 1.66
Do another conversion (Y or N)=> N
Implement the following functions:
get_problem—Displays the user menu, then inputs and returns as the func-
tion value the problem number selected.
get2_pt—Prompts the user for the x-y coordinates of both points, inputs the 
four coordinates, and returns them to the calling function through output 
parameters.
get_pt_slope—Prompts the user for the slope and x-y coordinates of the 
point, inputs the three values, and returns them to the calling function 
through output parameters.
M06_HANL8814_08_GE_C06.indd   389 05/06/15   5:06 PM
390 Chapter 6 • Pointers and Modular Programming
slope_intcpt_from2_pt—Takes four input parameters, the x-y coordinates 
of two points, and returns through output parameters the slope (m) and 
y-intercept (b).
intcpt_from_pt_slope—Takes three input parameters, the x-y coordinates of 
one point and the slope, and returns as the function value the y-intercept.
display2_pt—Takes four input parameters, the x-y coordinates of two 
points, and displays the two-point line equation with a heading.
display_pt_slope—Takes three input parameters, the x-y coordinates of one 
point and the slope, and displays the point-slope line equation with a heading.
display_slope_intcpt—Takes two input parameters, the slope and y- 
intercept, and displays the slope-intercept line equation with a heading
*/

void get2_pt (double *x1, double *y1, double *x2, double *y2){
    printf("Enter the x-y coordinates of the first point separated by a space => ");
    scanf("%lf %lf", x1, y1);

    printf("Enter the x-y coordinates of the second point separated by a space => ");
    scanf("%lf %lf", x2, y2);

    printf("\n");
}

void slope_intcpt_from2_pt(double *x1, double *y1, double *x2, double *y2, double *slope, double *intcpt){
    *slope = (*y2 - *y1)/(*x2 - *x1);
    // y = mx + b dimana b adalah intcpt
    // y - y1 = m (x - x1)
    // y = mx + (- mx1 + y1)
    // b = (-mx1 + y1)
    *intcpt = (- *slope * *x1) + *y1;
}    

void get_pt_slope(double *slope, double *x1, double *y1){
    printf("Enter the slope => ");
    scanf("%lf", slope);

    printf("Enter the x-y coordinates of the first point separated by a space => ");
    scanf("%lf %lf", x1, y1);

    printf("\n");
}

void intcpt_from_pt_slope(double *slope, double *x1, double *y1, double *intcpt){
    *intcpt = (- *slope * *x1) + *y1;
}

void display2_pt (double *x1, double *y1, double *x2, double *y2){
    printf("\nTwo -point form\n");
    printf("    (%.2lf - %.2lf)\n", *y2, *y1);
    printf("m = ---------------\n");
    printf("    (%.2lf - %.2lf)\n", *x2, *x1);
}

void display_pt_slope (double *slope, double *x1, double *y1, double *intcpt){
    printf("\nPoint-slope form\n");
    printf("y - %.2lf = %.2lf (x - %.2lf)\n", *y1, *slope, *x1);
}

void display_slope_intcpt (double *slope, double *intcpt){
    printf("\nSlope-intercept form\n");
    if(*intcpt > 0)printf("y = %.2lfx + %.2lf\n", *slope, *intcpt);
    else if(*intcpt < 0)printf("y = %.2lfx - %.2lf\n", *slope, fabs(*intcpt));
    else if(*intcpt == 0)printf("y = %.2lfx\n", *slope);
}

void get_problem(int *input){
    do { // do do dod baby shark do do do do 
    printf("\nSelect the form that you would like to convert to slope-intercept form:\n");
    printf("1) Two-point form (you know two points on the line)\n");
    printf("2) Point-slope form (you know the line's slope and one point)\n");
    printf("==> ");
    
    int cekInput = scanf("%d", input);

    if(*input == 1) printf("\n");
    else if (*input == 2) printf("\n");
    else if (cekInput != 1){
        printf("Please dont enter weird stuff\n");
        while(getchar() != '\n');
        }
    else printf("Please only enter 1 or 2\n");
    }
    while (*input != 1 && *input != 2);
}

int main(){
    int input;
    char repeat;
    double x1, y1, x2, y2, slope, intcpt;
    do{
        get_problem (&input);
        if (input == 1){
            get2_pt(&x1, &y1, &x2, &y2);
            slope_intcpt_from2_pt(&x1, &y1, &x2, &y2, &slope, &intcpt);
            // printf("%.2lf %.2lf", slope, intcpt);
            display2_pt(&x1, &y1, &x2, &y2);
            display_slope_intcpt(&slope, &intcpt);
            printf("\nDo another conversion (Y or N) ==> ");
        }
        else if (input == 2){
            get_pt_slope(&slope, &x1, &x2);
            intcpt_from_pt_slope(&slope, &x1, &x2, &intcpt);
            // printf("%.2lf %.2lf", slope, intcpt);
            display_pt_slope(&slope, &x1, &x2, &intcpt);
            display_slope_intcpt(&slope, &intcpt);
            printf("\nDo another conversion (Y or N) ==> ");
        }
        
        while(getchar() != '\n');

        scanf("%c", &repeat);
    } while (repeat == 'Y');
}