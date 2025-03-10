#include <stdio.h>
#include <math.h>

/* Write a program to create an output file containing a customized loan amorti- zation table. Your program will prompt the user to enter the amount borrowed (the principal), the annual interest rate, and the number of payments (n). To calculate the monthly payment, it will use the formula from Programming Project 1 in Chapter 3. This payment must be rounded to the nearest cent. After the payment has been rounded to the nearest cent, the program will write to the output file n lines showing how the debt is paid off. Each month part of the payment is the monthly interest on the principal balance, and the rest is applied to the principal. Because the payment and each month's inter- est are rounded, the final payment will be a bit different and must be calcu- lated as the sum of the final interest payment and the final principal balance. Here is a sample table for a $1,000 loan borrowed at a 9% annual interest rate and paid back over 6 months. */

void calculateLoan(double principal, double interest, double payments){
    double interestAmount, remainingDebt, monthlyPrincipal;
    double monthlyInterest = interest / 100 / 12;
    
    // Formula for amortizing loan = P * r(1+r)^n / ((1+r)^n - 1)
    double monthlyPayment = principal * interest/100/12 * pow((1 + interest/100/12), payments)/(pow(1 + interest/100/12, payments)-1);
    
    printf("\nPrincipal\t$%.2lf\tPayment\t$%.2lf\nAnnual Interest %.1lf%%\t\tTerm %.0lf months\n\n", principal, monthlyPayment, interest, payments);
    printf("Payment\t\tInterest\tPrincipal\tPrincipal Balance\n");

    for (int i = 1; i <= payments; i++){
        if(i==1) interestAmount = monthlyInterest * principal;  // first payment interest calculation
        else interestAmount = monthlyInterest * remainingDebt;  // subsequent payments use remaining balance
        
        monthlyPrincipal = monthlyPayment - interestAmount;
        if (i==1) remainingDebt = principal - monthlyPrincipal;
        else remainingDebt -= monthlyPrincipal;

        printf("%d\t\t%.2lf\t\t$%.2lf\t\t$%.2lf\n", i, interestAmount, monthlyPrincipal, remainingDebt);

        if(i==payments){
            printf("Final Payment = $%.2lf", monthlyPayment);
        }
    }
}

int main(){
    double principal, interest, payments;
    printf("Enter loan amount in dollars, interest rate percentage, and number of payments\n//example: 1000 9 6\n");
    scanf("%lf %lf %lf", &principal, &interest, &payments);

    // Using void function for cleaner organization
    calculateLoan(principal, interest, payments);
    return 0;
}