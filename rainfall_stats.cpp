/*******************************************************************************
*  Program name: rainfall_stats.cpp
*  Author: ...
*  Date last updated: 09/28/2021
*  Purpose: takes the rainfall data from each month and calculates the
            Average, Driest MONTH and the Wettest MONTH.
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// function returns the average based on the passed arguments
double average(double amount, int months = 12)
{
    return (amount / months);
}

int main()
{
    // define all the arrays and variables
    double month_data[13];

    // the size of the array is 13 because then the idex is equal to the month.
    // 1 = Jan, 2 = Feb...
    string month[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    double total_rainfall = 0;
    int j = 1, k = 1, max_month, min_month;
    string units = "inches";

    // format the input interface
    cout << "enter the rainfall amount in inches for each month" << endl
         << endl;
    cout << setw(7) << "Month:"
         << "    "
         << "Amount" << endl;

    // for loop that takes input for each month.
    for (int i = 1; i <= 12; i++)
    {
        cout << setw(6) << month[i] << ":    ";
        cin >> month_data[i];
        total_rainfall += month_data[i];

        // this, if loop finds the highest value
        if (month_data[i] > month_data[i - j])
        {
            if (i == 12)
            {
                max_month = i;
            }
            j = 1;
        }
        else
        {
            if (i == 12)
            {
                max_month = i - j;
            }
            j += 1;
        }

        // this, if loop waits until i > 1, then finds the lowest value
        if (i > 1)
        {

            if (month_data[i] < month_data[i - k])
            {
                if (i == 12)
                {
                    min_month = i;
                }
                k = 1;
            }
            else
            {
                if (i == 12)
                {
                    min_month = i - k;
                }
                k++;
            }
        }
    }

    // format the output
    cout << endl
         << setw(7) << "Tot:"
         << "    " << setw(9)
         << fixed << setprecision(2) << total_rainfall
         << setw(10) << units << endl;
    cout << setw(7) << "Avg:"
         << "    "
         << setw(9) << average(total_rainfall) // calls the function
         << setw(10) << units << endl;
    cout << endl
         << "   Driest Month\n"
         << setw(6) << month[min_month] << ":    "
         << setw(9) << month_data[min_month]
         << setw(10) << units << endl;
    cout << endl
         << "   Wettest Month\n"
         << setw(6) << month[max_month] << ":    "
         << setw(9) << month_data[max_month]
         << setw(10) << units << endl;
    cout << endl;
}