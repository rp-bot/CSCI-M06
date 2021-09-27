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
const int N = 13;

double **getData(double low_data[13], double high_data[13])
{
    double **get_data[N][2];
    for (int i = 1; i <= 12; i++)
    {
        get_data[i][0] = low_data[i];
        get_data[i][1] = high_data[i];
    }
    return get_data;
}

int main()
{
    int max_month, min_month, k;
    double rainfall_data_low[N], rainfall_data_high[N];
    string month[N] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    double **return_data;

    cout << "enter the HIGH and LOW temperatures for each month" << endl;
    cout << setw(7) << "Month:"
         << "    "
         << "H,L" << endl;
    for (int i = 1; i <= 12; i++)
    {
        cout << setw(6) << month[i] << ":    ";
        char comma;
        cin >> rainfall_data_low[i] >> comma >> rainfall_data_high[i];
    }

    return_data = getData(rainfall_data_low, rainfall_data_high);

    cout << return_data[1][0] << endl
         << return_data[1][1];

    cout << endl
         << endl;
}