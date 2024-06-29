#pragma once
#include <string>

using namespace std;


class InvestmentAccount
{
public:
    /*constructor to initialize an investment account with no monthly deposit
    @param initialAmount - the initial investment amount
    @param annualInterestRate - the annual interest rate as a percentage*/
    
    /*constuctor to initliaze an investment account with a monthly deposit.
    @param initialAmount - the inital investment amount
    @param annualInterestRate - the annual interest rate as a percentage
    @param monthlyDeposit - the amount user deposits monthly*/

    InvestmentAccount(double initialAmount, double annualInterestRate); 
    InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit);

    /*Calculate the ending balance after a given number of years
    @param numberOfYears - the number of years to calculate for
    @return - the ending balance*/

    /* Calculate the interest earned for a given number of years
    @param numberOfYears - the number of years to calculate for
    @returns - the interest earned */

    double getEndingBalance(int numberOfYears);  
    double getInterestEarned(int numberOfYears);

    /*Get the formatted ending balance after a given number of years
    @param numberOfYears - the number of years to calculate for
    @returns - the formatted ending balance*/

    /*Get the formatted interest earned for a given number of years
    @param numberOfYears - the number of years to calculate for
    @returns - the formatted interest earned*/

    string getEndingBalanceFormatted(int numberOfYears);  
    string getInterestEarnedFormatted(int numberOfYears); 


    double getInitialAmount();
    double getMonthlyDeposit();
    double getAnnualInterestRate();

    /*Round a value to a specified number of decimal places
    @param value - the value to round
    @param places - the number of decimal places
    @returns - the rounded value*/

    double round(double value, int places);

    /*Format a double value as a string with two decimal places
    @param value - the value to format
    @returns - the formatted string */

    string format(double value);

private:
    double initialAmount;
    double monthlyDeposit;
    double annualInterestRate;

    /*Calculate the power of a base raised to an exponent
    @param base - the base value
    @param exponent - the exponent value
    @returns - the result of base^exponent*/

    double power(int base, int exponent);
};
