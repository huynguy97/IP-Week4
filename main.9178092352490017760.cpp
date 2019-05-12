#include <iostream>

using namespace std;

//                                                            

enum Month {January = 1, February, March, April, May, June, July, August, September, October, November, December} ;

/*                                                                          
                                                                            
                                                           
*/
int easter_base ( int year )
{
    const int A     = year % 19 ;
    const int B     = year / 100 ;
    const int C     = year % 100 ;
    const int D     = B / 4 ;
    const int E     = B % 4 ;
    const int F     = (B + 8) / 25 ;
    const int G     = (B - F + 1) / 3 ;
    const int H     = (19 * A + B - D - G + 15) % 30 ;
    const int I     = C / 4 ;
    const int K     = C % 4 ;
    const int L     = (32 + 2 * E + 2 * I - H - K) % 7 ;
    const int M     = (A + 11 * H + 22 * L) / 451 ;
    return H + L - 7 * M + 114 ;
}

/*                                                                                    
                   
*/
int easter_day ( int year )
{
    return (easter_base (year) % 31) + 1 ;
}

/*                                                                                   
*/
Month easter_month ( int year )
{
    return static_cast<Month> (easter_base (year) / 31) ;
}

/*                                                                   
                                 
                                                                   */
bool is_leap_year ( int year )
{
    return year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0);
}

int number_of_days_in_month ( int year, Month month )
{
switch (month) {
    default:
        return 31;

    case April:
    case June:
    case September:
    case November:
        return 30;

    case February:
        if (is_leap_year(year)) {
            return 29;
        } else {
            return 28;
        }

    }
}

Month month_at_number(int i){
    Month month;
    switch(i){
        case 1: month = January; break;
        case 2: month = February; break;
        case 3: month = March; break;
        case 4: month = April; break;
        case 5: month = May; break;
        case 6: month = June; break;
        case 7: month = July; break;
        case 8: month = August; break;
        case 9: month = September; break;
        case 10: month = October; break;
        case 11: month = November; break;
        case 12: month = December; break;
    }
    return month;
}

void cout_month(Month month){
    switch(month){
        case January: cout << "January"; break;
        case February: cout << "February"; break;
        case March: cout << "March"; break;
        case April: cout << "April"; break;
        case May: cout << "May"; break;
        case June: cout << "June"; break;
        case July: cout << "July"; break;
        case August: cout << "August"; break;
        case September: cout << "September"; break;
        case October: cout << "October"; break;
        case November: cout << "November"; break;
        case December: cout << "December"; break;
    }
}

int day_number_in_year(int day, Month month, int year){
    Month current_month;
    for(int i = 1; i < (int)month; i++){
        current_month = month_at_number(i);
        int day_in_month = number_of_days_in_month(year, current_month);
        day += day_in_month;
    }
    return day;
}

Month month_in_year_of_day_number(int day_number, int year){
    int i = 1;
    Month current_month;
    while(day_number > number_of_days_in_month(year, month_at_number(i))){
        current_month = month_at_number(i);
        int days_in_month = number_of_days_in_month(year, current_month);
        day_number -= days_in_month;
        i++;
    }
    return month_at_number(i);
}

int day_in_month_of_day_number(int day_number, int year){
    int i = 1;
    Month current_month;
    while(day_number > number_of_days_in_month(year, month_at_number(i))){
        current_month = month_at_number(i);
        int days_in_month = number_of_days_in_month(year, current_month);
        day_number -= days_in_month;
        i++;
    }
    return day_number;
}

/*                                                                   
                                                
                                                                   */
void show_holy_days (int year)
{
    int day_number_easter = day_number_in_year(easter_day(year), easter_month(year), year);
    int day_number_carnaval = day_number_easter - 49;
    int day_number_gf = day_number_easter - 2;
    int day_number_whit = day_number_easter + 49;
    int day_number_ad = day_number_whit - 10;

    cout << "Carnival: (" ;
    cout_month(month_in_year_of_day_number(day_number_carnaval, year));
    cout << ", " << day_in_month_of_day_number(day_number_carnaval, year) << ")" << endl;
    cout << "Good Friday: (";
    cout_month(month_in_year_of_day_number(day_number_gf, year));
    cout << ", " << day_in_month_of_day_number(day_number_gf, year) << ")" << endl;
    cout << "Easter: (";
    cout_month(easter_month(year));
    cout << ", " << easter_day(year) << ")" << endl;
    cout << "Ascension day: (";
    cout_month(month_in_year_of_day_number(day_number_ad, year));
    cout << ", " << day_in_month_of_day_number(day_number_ad, year) << ")" << endl;
    cout << "Whitsuntide: (";
    cout_month(month_in_year_of_day_number(day_number_whit, year));
    cout << ", " << day_in_month_of_day_number(day_number_whit, year) << ")" << endl;
}

int main()
{
    int year;
    cout << "For what year do you want the dates of the holy days?"<< endl;
    cin >> year;
    show_holy_days(year) ;
    return 0;
}

