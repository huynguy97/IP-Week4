#include <iostream>

/*
                         
                            
*/

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

bool is_leap_year ( int year )
{
    year = year % 400;
    if(year == 0)
    {
        return true;
    }
    year = year % 100;
    if(year == 0)
    {
        return false;
    }
    year = year % 4;
    if(year == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//                                     
int number_of_days_in_month ( int year, Month month )
{
    switch(month)
    {
        case January:   return 31;
        case February:  if(is_leap_year(year))
                        {
                            return 29;
                        }
                        else
                        {
                            return 28;
                        };
        case March:     return 31;
        case April:     return 30;
        case May:       return 31;
        case June:      return 30;
        case July:      return 31;
        case August:    return 31;
        case September: return 30;
        case October:   return 31;
        case November:  return 30;
        case December:  return 31;

    }
}

//                                           
//                                                                         
int count_to_day (int day, Month month, int year, int cnt) {
    //                                                             
    day = day + cnt;
    //                                                           
    //                                                                      
    //                                     
    do
    {
        if(day < 1)
        {
            month = static_cast<Month>(month -1);
            day = day + number_of_days_in_month(year,month);
        }
        if(day > number_of_days_in_month(year,month))
        {
            day = day - number_of_days_in_month(year,month);
            month = static_cast<Month>(month +1);
        }
    } while (day < 1 || day > number_of_days_in_month(year,month));
    return day;
}
Month count_to_month (int day, Month month, int year, int cnt) {
    day = day + cnt;
    do
    {
        if(day < 1)
        {
            month = static_cast<Month>(month -1);
            day = day + number_of_days_in_month(year,month);
        }
        else if(day > number_of_days_in_month(year,month))
        {
            day = day - number_of_days_in_month(year,month);
            month = static_cast<Month>(month +1);
        }
    } while (1 > day || day > number_of_days_in_month(year,month));
    return month;
}

void show_holy_days (int year) {
    //                              
    //                                        
    const int Easter_day = easter_day(year);
    const Month Easter_month = easter_month(year);

    int Carnival_day = count_to_day(Easter_day,Easter_month,year,-7*7 );
    int Carnival_month = count_to_month(Easter_day,Easter_month,year,-7*7 );
    int Carnival_end_day = count_to_day(Easter_day,Easter_month,year,-7*7 + 2);
    int Carnival_end_month = count_to_month(Easter_day,Easter_month,year,-7*7 + 2);
    cout << "Carnaval starts at " << Carnival_day << "-" << Carnival_month << "\n";
    cout << "and ends at " << Carnival_end_day << "-" << Carnival_end_month << "\n";

    cout << "Easter is at " << Easter_day << "-" << Easter_month << "\n";

    int Good_friday_day = count_to_day(Easter_day,Easter_month,year,-2);
    int Good_friday_month = count_to_month(Easter_day,Easter_month,year,-2);
    cout << "Good friday is at " << Good_friday_day << "-" << Good_friday_month << "\n";

    int Ascension_day = count_to_day(Easter_day,Easter_month,year,7*7 - 10);
    int Ascension_month = count_to_month(Easter_day,Easter_month,year,7*7 - 10);
    cout << "Ascension is at " << Ascension_day << "-" << Ascension_month << "\n";

    int Whitsuntide_day = count_to_day(Easter_day,Easter_month,year,7*7);
    int Whitsuntide_month = count_to_month(Easter_day,Easter_month,year,7*7);
    cout << "Whitsuntide is at " << Whitsuntide_day << "-" << Whitsuntide_month << "\n";
}

int main() {
    //                                                    
    cout << "Welcome holy man!\n";
    cout << "We are here to help you keep track of your holy days\n";
    cout << "We will give you the dates on which to have your festivities\n";
    cout << "All that we require is a year, eg 2018\n\n";
    cout << "Please give us the year of your festivities\n";

    int year;
    cin >> year;

    show_holy_days(year);

    cout << "Dates are given in Day-Month, have a holy day!\n";
    return 0;
}

