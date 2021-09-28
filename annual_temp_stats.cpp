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

void getData(double rain_data_low[N], double rain_data_high[N],
             double tot_data[N][2], int m_index[N])
{
    for (int i = 1; i <= 12; i++)
    {
        m_index[i] = i;
        tot_data[i][0] = rain_data_low[i];
        tot_data[i][1] = rain_data_high[i];
    }
}

double averageHigh(double data[N][2])
{
    double total = 0;
    for (int i = 1; i <= 12; i++)
    {
        total += data[i][1];
    }
    return (total / 12);
}

double averageLow(double data[N][2])
{
    double total = 0;
    for (int i = 1; i <= 12; i++)
    {
        total += data[i][0];
    }
    return (total / 12);
}

int indexHighTemp(double data[N][2])
{
    int indexHigh = 0;
    int j = 0;
    for (int i = 1; i <= 12; i++)
    {

        if (data[i][1] > data[i - j][1])
        {
            if (i == 12)
            {
                return i;
            }
            j = 1;
        }
        else
        {
            if (i == 12)
            {
                return i - j;
            }
            j += 1;
        }
    }
    return 0;
}
int indexLowTemp(double data[N][2])
{
    int indexLow = 0;
    int j = 0;
    for (int i = 1; i <= 12; i++)
    {
        if (data[i][0] < data[i - j][0])
        {
            if (i == 12)
            {
                return i;
            }
            j = 1;
        }
        else
        {
            if (i == 12)
            {
                return i - j;
            }
            j += 1;
        }
    }
    return 0;
}
int main()
{
    int max_month, min_month, k, month_index[N];
    double rainfall_data_low[N], rainfall_data_high[N], total_data[N][2];
    double avgH, avgL;
    string month[N] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    cout << "enter the LOW and HIGH temperatures for each month" << endl;
    cout << setw(7) << "Month:"
         << "    "
         << "L,H"
         << endl
         << endl;
    for (int i = 1; i <= 12; i++)
    {
        cout << setw(6) << month[i] << ":    ";
        char comma;
        cin >> rainfall_data_low[i] >> comma >> rainfall_data_high[i];

        if (rainfall_data_low[i] > rainfall_data_high[i])
        {
            double temp = rainfall_data_high[i];
            rainfall_data_high[i] = rainfall_data_low[i];
            rainfall_data_low[i] = temp;
        }
    }

    getData(rainfall_data_low, rainfall_data_high, total_data, month_index);
    avgH = averageHigh(total_data);
    avgL = averageLow(total_data);
    max_month = indexHighTemp(total_data);
    min_month = indexLowTemp(total_data);
    cout << endl
         << " Average of Low temps   : " << avgL << endl
         << " Average of High temps  : " << avgH << endl
         << endl
         << " Lowest temperature     :" << endl
         << setw(23) << month[min_month] << " : "
         << total_data[min_month][0]
         << endl
         << " Highest temperature    :" << endl
         << setw(23) << month[max_month] << " : "
         << total_data[max_month][1];
    cout << endl
         << endl;
}