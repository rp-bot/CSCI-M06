/*******************************************************************************
*  Program name: annual_temp_stats.cpp
*  Author: ...
*  Date last updated: 09/26/2021
*  Purpose: takes the temperature data from each month and calculates the
            Average HIGH, Average LOW, HIGHEST MONTH and the LOWEST MONTH.
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

double getData()
{
}

int main()
{
    int max_month, min_month, k;

    double rainfall_data_low[13], rainfall_data_high[13];
    static string month[2][13] = {
        {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"},
        {"", "", "", "", "", "", "",
         "", "", "", "", "", ""}};
    cout << "enter the HIGH and LOW temperatures for each month" << endl;
    cout << setw(7) << "Month:"
         << "    "
         << "H,L" << endl;
    for (int i = 1; i <= 12; i++)
    {
        cout << setw(6) << month[0][i] << ":    ";
        int j = 0;
        char comma;
        cin >> rainfall_data_low[i] >> comma >> rainfall_data_high[i];
    }
}