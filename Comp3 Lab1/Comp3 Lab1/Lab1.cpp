
//Computing 3 Lab 1
//Group 11
//Jaelyn Dones, Alex Kashian, Wesley Hogan, and Patrick Crowley-Poirier

#include <iostream>
using namespace std;

double calculateTotal(double interestRate, double amount, double months)
{
    // Amount of Loan
    double year = months / 12;
    double total = (amount / ((1.0 - (interestRate / 100.0)) * year));
    return total;
}

int main()
{
    double interestRate, amount, months;
    double total, payment;
    bool continueOn = true;

    while (continueOn == true)
    {
        cout << "Please enter the annual interest rate as a percentage (e.g., 15 for 15%) (enter 0 to quit):";
        cin >> interestRate;
        if (interestRate == 0) // Exiting loop if 0 is inputted
        {
            continueOn = false;
            break;
        }
        while (interestRate < 0)
        {
            cerr << "Invalid input, please try again:" << endl;
            cin >> interestRate;
        }

        cout << "Please enter the amount you would like to receive: ";
        cin >> amount;
        while (amount <= 0)
        {
            cerr << "Invalid input, please try again:" << endl;
            cin >> amount;
        }

        cout << "Please enter loan period in months: ";
        cin >> months;
        while (months <= 0)
        {
            cerr << "Invalid input, please try again:" << endl;
            cin >> months;
        }

        total = calculateTotal(interestRate, amount, months);
        cout << "The total amount of your loan (including interest at " << interestRate << "% per annum) is: $" << total << endl;
        payment = total / months;
        cout << "Your monthly payment for " << months << " months will be: $" << payment << endl;
    }

    return 0;
}