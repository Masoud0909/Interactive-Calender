/************************************************
(The code prints a 12-month calendar for a given year,
with the user providing the year and the day of the week for January 1st.
It uses separate functions to calculate the maximum days in a month,
find the name of a month, and find the name of a day of the week.)
----------------------------------------------------
print the complete 12-month calendar for a particular year.
The user will be asked to enter the year, as well as the day of the week for the 1st of January. The program will then have a loop that executes 12 times, each time calling a function that prints one month. At the end, the program prints the day of the week when the year ends. Note that the day of the week for the first of a particular month will be one following the last day of the week for the previous month.
************************************************/


#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int find_max_days(int month, int year) {
    int max_days;
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: max_days = 31; break;
    case 4: case 6: case 9: case 11: max_days = 30; break;
    case 2: if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0)
        max_days = 28;
          else max_days = 29; break;
    default: break;
    }
    return max_days;
}

string month_name(int month) {
    string mth;
    switch (month) {
    case 1: mth = "January"; break;
    case 2: mth = "February"; break;
    case 3: mth = "March"; break;
    case 4: mth = "April"; break;
    case 5: mth = "May"; break;
    case 6: mth = "June"; break;
    case 7: mth = "July"; break;
    case 8: mth = "August"; break;
    case 9: mth = "September"; break;
    case 10: mth = "October"; break;
    case 11: mth = "November"; break;
    case 12: mth = "December"; break;
    }
    return mth;
}

string day_of_week(int pos) {
    switch (pos % 7) {
    case 1: return "Sunday";
    case 2: return "Monday";
    case 3: return "Tuesday";
    case 4: return "Wednesday";
    case 5: return "Thursday";
    case 6: return "Friday";
    case 0: return "Saturday";
    }
    return "";
}

void draw_month(int& first, int month, int year) {
    int max_days = find_max_days(month, year);
    string mth = month_name(month);

    cout << "\n        Calendar for month " << mth << " of " << year << endl << endl;
    cout << " Sun Mon Tue Wed Thu Fri Sat\n";

    int day = 1;
    cout << setw(first * 4) << day;
    int pos = first;
    for (day = 2; day <= max_days; day++) {
        if (pos % 7 == 0)
            cout << endl;
        cout << setw(4) << day;
        pos++;
    }

    cout << "\n\nThe month ends on a " << day_of_week(pos) << endl;
    first = pos % 7 + 1;
}

int main() {
    cout << "which year? ";
    int year;
    cin >> year;
    cout << "enter the day of the week for the 1st of January (1=Sun, 2=Mon etc) ";
    int first;
    cin >> first;

    for (int month = 1; month <= 12; month++)
        draw_month(first, month, year);

    cout << "The year ends on a " << day_of_week(first) << endl;

    getch();
}


