#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double average(double amount, int months = 12)
{
    return (amount / months);
}

int main()
{
    double month_data[13];
    string month[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    double total_rainfall = 0;
    int j = 1, k = 1, max_month, min_month;
    string units = "inches";

    cout << "enter the rainfall amount in inches for each month" << endl
         << endl;
    cout << setw(7) << "Month:"
         << "    "
         << "Amount" << endl;
    for (int i = 1; i <= 12; i++)
    {
        cout << setw(6) << month[i] << ":    ";
        cin >> month_data[i];
        total_rainfall += month_data[i];
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

    cout << endl
         << setw(7) << "Tot:"
         << "    " << setw(9)
         << fixed << setprecision(2) << total_rainfall
         << setw(10) << units << endl;
    cout << setw(7) << "Avg:"
         << "    "
         << setw(9) << average(total_rainfall)
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