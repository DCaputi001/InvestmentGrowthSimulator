#include <iostream>
#include <iomanip>
#include "InvestmentAccount.h"

/**
 * Displays the account details, as well as account balances and interest earned for each year.
 * @param account - the investment account.
 * @param numberOfYears - the number of years to display the information for.
 */

void displayOutput(InvestmentAccount account, int numberOfYears); 

int main() {
    double initial_investment;
    double monthly_deposit;
    double annual_interest_rate;
    int years;

    // Input validation for initial investment amount
    cout << "Initial Investment Amount: "; // Prompt the user for the initial investment amount
    cin >> initial_investment; // Read the initial investment amount
    while (initial_investment < 0) {
        cout << "Please enter a positive number for the initial investment amount: ";
        cin >> initial_investment;
    }

    // Input validation for monthly deposit
    cout << "Monthly Deposit: "; // Prompt the user for the monthly deposit amount
    cin >> monthly_deposit; // Read the monthly deposit amount
    while (monthly_deposit < 0) {
        cout << "Please enter a positive number for the monthly deposit amount: ";
        cin >> monthly_deposit;
    }

    // Input validation for annual interest rate
    cout << "Annual Interest: "; // Prompt the user for the annual interest rate
    cin >> annual_interest_rate; // Read the annual interest rate
    while (annual_interest_rate < 0) {
        cout << "Please enter a positive number for the annual interest rate: ";
        cin >> annual_interest_rate;
    }

    // Input validation for number of years
    cout << "Number of Years: "; // Prompt the user for the number of years
    cin >> years; // Read the number of years
    while (years < 0) {
        cout << "Please enter a positive number for the number of years: ";
        cin >> years;
    }

    // Creates two InvestmentAccount variables
    InvestmentAccount accountWithoutDeposit(initial_investment, annual_interest_rate);
    InvestmentAccount accountWithDeposit(initial_investment, annual_interest_rate, monthly_deposit);

    cout << "Press any key to continue..." << endl;
    cin.ignore();
    cin.get();

    // Display the output for each investment account
    displayOutput(accountWithoutDeposit, years);
    displayOutput(accountWithDeposit, years);

    return 0;
}
/*Set the format to fixed with 2 decimal places
Output for accounts with and without deposits*/

void displayOutput(InvestmentAccount account, int numberOfYears) {
    cout << fixed << setprecision(2);

    if (account.getMonthlyDeposit() > 0) {
        cout << "Balance and Interest With Additional $" << account.getMonthlyDeposit() << " Monthly Deposits" << endl;
    }
    else {
        cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    }

    cout << "Year\t" << setw(20) << left << "Year End Balance" << "\t" << "Year End Earned Interest" << endl; //output the header using set() for proper alignment 

    double previousBalance = account.getInitialAmount();

    for (int year = 1; year <= numberOfYears; ++year) {
        double yearEndBalance = account.getEndingBalance(year);
        double yearEndInterest = yearEndBalance - previousBalance - (account.getMonthlyDeposit() * 12);
        previousBalance = yearEndBalance;
        
        cout << year << "\t$ " << setw(18) << left << yearEndBalance << "\t$ " << yearEndInterest << endl;//output the balances and used set() for proper alignment 
    }
}

