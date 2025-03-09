#include <stdio.h>
#include <math.h>

/*
Chatflow Wireless offers customers 600 weekday minutes for a flat rate of 39.99. Night (8 p.m. to 7 a.m.) and weekend minutes are free, but additional weekday minutes cost 0.40 each. There are taxes of 5.25% on all charges. Write a program that prompts the user to enter the number of weekday minutes, night minutes, and weekend minutes used, and calculates the monthly bill and average cost of a minute before taxes. The program should display with labels all the input data, the pretax bill and average minute cost, the taxes, and the total bill. Store all monetary values as whole cents (rounding the taxes and average minute cost), and divide by 100 for display of results.
*/

#define fixed_cost 3999
#define tax 105.25/100
#define max_minutes 600

float price_counter(int work_hours){
    float total_cost;
    if(work_hours > max_minutes) total_cost = (float) (fixed_cost + (work_hours - max_minutes)*40)/100;
    else total_cost = (float) fixed_cost/100;
    return total_cost;
}

int main(){
    int work_hours, night_hours, weekend_hours;
    printf("Hello-hello, welcome to the radio Chatflow where you will get free 600 minutes every week!\n(for more time, we will charge 0.40 cents per extra hour)\nPlease input your radio usage in work hours (by minutes) => ");
    scanf("%d", &work_hours);

    printf("Please input your radio usage in night hours (by minutes) => ");
    scanf("%d", &night_hours);

    printf("Please input your radio usage in weekend hours (by minutes) => ");
    scanf("%d", &weekend_hours);

    printf("\nWe recorded that you have used our services for the total of %d minutes ", work_hours);
    if (work_hours > max_minutes) printf("(which is %d minutes more than the limit we've set)\n", work_hours-600);
    else printf("for this weekend\n");
    printf("Which includes %d minutes of night hours (8 PM - 7 AM)\n", night_hours);
    printf("And also %d minutes on the weekend\n", weekend_hours);

    printf("Thus, the net price shall be $%.2f\n", price_counter(work_hours));

    float tax_included = round(price_counter(work_hours) * tax);
    printf("With the tax of 5.25%%, the total amount you must pay is $%.2f\n", tax_included);
}