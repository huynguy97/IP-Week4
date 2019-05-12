#include <iostream>

//                                                      
//                                                  

using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;

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
//                                                     
bool is_leap_year(int year)
{
    if (year % 100 == 0 && year % 400 != 0) {
        return false;
    } else {
        return year % 4 == 0;
    }
}

//                                                   
int number_of_days_in_month(int year, Month month)
{
    switch(month) {
    case April:
    case June:
    case September:
    case November:
        return 30;
    case February:
        if (is_leap_year(year))
            return 29;
        else
            return 28;
    default:
        return 31;
    }
}

/*                                                                   
                                                
                                                                   */
//                                              
int ask_for_year()
{
    cout << "Give a year: ";
    int year;
    cin >> year;
    return year;
}

//                                                                                          
int count_days_from_day(int day, Month month, int year, int day_amount)
{
    day += day_amount;
    while (day > number_of_days_in_month(year, month)) {
        day -= number_of_days_in_month(year, month);
        month = static_cast<Month>(month + 1);
    }
    while (day < 1) {
        month = static_cast<Month>(month - 1);
        day += number_of_days_in_month(year, month);
    }

    return day;
}

//                                                                                          
Month count_days_from_month(int day, Month month, int year, int day_amount)
{
    day += day_amount;
    while (day > number_of_days_in_month(year, month)) {
        day -= number_of_days_in_month(year, month);
        month = static_cast<Month>(month + 1);
    }
    while (day < 1) {
        month = static_cast<Month>(month - 1);
        day += number_of_days_in_month(year, month);
    }

    return month;
}

//                                                          
string month_name(Month month)
{
    switch (month)
    {
    case January:
        return "January";
    case February:
        return "February";
    case March:
        return "March";
    case April:
        return "April";
    case May:
        return "May";
    case June:
        return "June";
    case July:
        return "July";
    case August:
        return "August";
    case September:
        return "September";
    case October:
        return "October";
    case November:
        return "November";
    case December:
        return "December";
    default:
        return "?";
    }
}

//                                                                                          
void show_date_from_to(string name, int begin_day, Month begin_month, int end_day, Month end_month)
{
    cout << name << " is from " << month_name(begin_month) << ' ' << begin_day << " until " << month_name(end_month) << ' ' << end_day << '\n';
}

//                                                            
void show_date(string name, int day, Month month)
{
    cout << name << " is on " << month_name(month) << ' ' << day << '\n';
}

//                                                                                                           
void show_holy_days()
{
    int year = ask_for_year();

    int easter_d = easter_day(year);
    Month easter_m = easter_month(year);
    int begin_carnival_day = count_days_from_day(easter_d, easter_m, year, -7*7);
    Month begin_carnival_month = count_days_from_month(easter_d, easter_m, year, -7*7);
    int end_carnival_day = count_days_from_day(begin_carnival_day, begin_carnival_month, year, 2);
    Month end_carnival_month = count_days_from_month(begin_carnival_day, begin_carnival_month, year, 2);
    int good_friday_day = count_days_from_day(easter_d, easter_m, year, -2);
    Month good_friday_month = count_days_from_month(easter_d, easter_m, year, -2);
    int whitsuntide_day = count_days_from_day(easter_d, easter_m, year, 7*7);
    Month whitsuntide_month = count_days_from_month(easter_d, easter_m, year, 7*7);
    int ascension_day = count_days_from_day(whitsuntide_day, whitsuntide_month, year, -10);
    Month ascension_month = count_days_from_month(whitsuntide_day, whitsuntide_month, year, -10);

    cout << "\nIn the year " << year << '\n';
    show_date_from_to("Carnival", begin_carnival_day, begin_carnival_month, end_carnival_day, end_carnival_month);
    show_date("Good Friday", good_friday_day, good_friday_month);
    show_date("Easter", easter_d, easter_m);
    show_date("Ascension Day", ascension_day, ascension_month);
    show_date("Whitsuntide", whitsuntide_day, whitsuntide_month);
}

int main()
{
    show_holy_days() ;
    return 0;
}

