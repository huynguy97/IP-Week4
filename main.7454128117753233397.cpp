//                        
//                       

#include <iostream>

using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;
string months [12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
string getMonthName(Month m) {
    return months[m-1];
}

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
    return (year%4 == 0 && !(year%100 == 0 && year%400 != 0));
}

int number_of_days_in_month ( int year, Month month )
{
    if (month%2 == 0)
    {
        if (month == February)
        {
            if (is_leap_year(year))
            {
                return 29;
            }
            return 28;
        }
        return 30;
    }
    return 31;
}

/*                                                                   
                                                
                                                                   */

int day_in_year (int year, Month month, int day)
{
    int d = 0;
    Month m = January;
    while (m < month) {
        d += number_of_days_in_month(year, m);
        m = static_cast<Month>(static_cast<int>(m) + 1);
    }
    return (d + day);
}

int carnival_start (int year)
{
    int d = day_in_year(year, easter_month(year), easter_day(year));
    d = d-49;
    return d;
}

int carnival_end (int year)
{
    int d = day_in_year(year, easter_month(year), easter_day(year));
    d = d-47;
    return d;
}

int good_friday (int year)
{
    int d = day_in_year(year, easter_month(year), easter_day(year));
    d = d-2;
    return d;
}

int whitsuntide (int year)
{
    int d = day_in_year(year, easter_month(year), easter_day(year));
    d = d+49;
    return d;
}

int ascension_day (int year)
{
    int d = day_in_year(year, easter_month(year), easter_day(year));
    d = d+39;
    return d;
}

int day_in_year_to_day_in_month(int year, int yearday)
{
    Month m = January;
    while (yearday >= number_of_days_in_month(year, m))
    {
        yearday -= number_of_days_in_month(year, m);
        m = static_cast<Month>(static_cast<int>(m)+1);
    }
    return yearday;
}

Month day_in_year_to_month_in_year(int year, int yearday) {
    Month m = January;
    while (yearday >= number_of_days_in_month(year, m)) {
        yearday -= number_of_days_in_month(year, m);
        m = static_cast<Month>(static_cast<int>(m)+1);
    }
    return m;
}

void show_holy_days ()
{
    int year;
    cout << "Enter a year:\n> ";
    cin >> year;
    cout << "Easter: " << getMonthName(easter_month(year)) << " " << easter_day(year) << "\n";
    cout << "Carnival start: " << getMonthName(day_in_year_to_month_in_year(year, carnival_start(year))) << " " << day_in_year_to_day_in_month(year, carnival_start(year)) << "\n";
    cout << "Carnival end: " << getMonthName(day_in_year_to_month_in_year(year, carnival_end(year))) << " " << day_in_year_to_day_in_month(year, carnival_end(year)) << "\n";
    cout << "Good friday: " << getMonthName(day_in_year_to_month_in_year(year, good_friday(year))) << " " << day_in_year_to_day_in_month(year, good_friday(year)) << "\n";
    cout << "Whitsuntide: " << getMonthName(day_in_year_to_month_in_year(year, whitsuntide(year))) << " " << day_in_year_to_day_in_month(year, whitsuntide(year)) << "\n";
    cout << "Ascension day: " << getMonthName(day_in_year_to_month_in_year(year, ascension_day(year))) << " " << day_in_year_to_day_in_month(year, ascension_day(year)) << "\n";

}

int main()
{
    show_holy_days();
    return 0;
}

