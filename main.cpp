#include <iostream>
#include <iomanip>
using namespace std;

const int f_day=5, f_month=1, f_year=1970; //  Constant global variables

void print_month_year(const string& month, int year){
    cout << setw(14-(month.length())/2 + month.length()) << month << " " << year << endl;
}

bool is_leap(int year){
    if ((year%4==0 && year%100!=0) || year%400==0){
        return true;
    }
    return false;
}

string num2month(int num){
    switch (num) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
    }
}

int month2count(int month, bool is_leap){
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            return (is_leap)?(29):(28);
        default:
            return 30;
    }
}

void print_header(int month, int year){
    cout << "----------------------------------" << endl;
    print_month_year(num2month(month), year);
    cout << "----------------------------------" << endl;
}

void print_weekdays(){
    cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
}

void print_days(int month, int year, int empty){
    for (int i=1; i<=empty;i++){
        cout << setw(2) << " " << "   ";
    }
    for (int i=1; i<= month2count(month, year); i++){
        cout << setw(2) << i << "   ";
        if ((i+empty)%7==0)
            cout << endl;
    }

}

void print_main(int c_day, int month, int year){
    print_weekdays();
    print_days(month, year, c_day-1);
}

int calc_days(int month, int year){
    int sum=0;

    // Adding whole years
    for (int i=f_year; i<year; i++){
        sum += (is_leap(i))?(366):(365);
    }

    // Adding whole month
    for (int i=f_month; i<month; i++){
        sum += month2count(i, is_leap(year));
    }

    return sum;
}

void print_calendar(int c_day, int c_month, int c_year){
    cout << endl;
    print_header(c_month, c_year);
    print_main(c_day,c_month, c_year);
    cout << endl << "----------------------------------" << endl;
    cout << endl;
}

int main() {

    int c_day, c_month, c_year;

    cout << "\n 1. January\n 2. February\n 3. Mart\n 4. April\n 5. May\n 6. June\n 7. July\n 8. August\n 9. September\n 10. October\n 11. November\n 12. December\n\nChoose the month:";
    cin >> c_month;

    cout << "Enter the year:";
    cin >> c_year;

    c_day = f_day + calc_days(c_month,c_year)%7;

    if (c_day > 7)
        c_day -= 7;

    print_calendar(c_day, c_month, c_year);


    return 0;
}
