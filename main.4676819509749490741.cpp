
#include <iostream>
#include <string>
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
Month_easter_month ( int year )
{
    return static_cast<Month> (easter_base (year) / 31) ;
}

/*                                                                   
                                 
                                                                   */

bool is_leap_year(int year) //              
{
    if(year % 4==0 )
    {
        if(year%100==0)
        {
            if(year%400==0)
            {
                return true;
            }
            else
                return false;
            }
        return true;
    }
    else
        return false;
}

int number_of_days_in_month (int year, Month month)
{
    if(is_leap_year(year) & month == 2)
    {
            return 29;
    }
    if(month%2==0)
    {
        if(month==2)
        {
            return 28;
        }
        else
            return 30;
    }
    else
        return 31;
}

/*                                                                   
                                                
                                                                   */

int number_of_days_in_year(int day, Month month, int Year)
{
    int dagen = day;
    static_cast<int>(month);
    for (int i = 1; i <= month; i++ )
        {
            int dagen = dagen + number_of_days_in_month(Year, month);
            int month = month - i;
        }
    return dagen ;
}
int convert1(int day_feast, int year)
{
    int i = 0;
    while ((day_feast - number_of_days_in_month (year, static_cast<Month>(i))) >= 0)
    {
        i ++;
        day_feast = day_feast - number_of_days_in_month(year,static_cast<Month> (i));
    }

    return i;
}
int convert2(int day_feast, int year)
{
    int i = 0;
    while ((day_feast - number_of_days_in_month (year, static_cast<Month>(i))) >= 0)
    {
        i ++;
        day_feast = day_feast - number_of_days_in_month(year,static_cast<Month> (i));

    }
    day_feast = day_feast + number_of_days_in_month(year,static_cast<Month> (i));
    return day_feast;
}

void show_holy_days (int year)
{
    int day_east   = easter_day (year); //             
    int Month_east = Month_easter_month (year); //                
    Month maand = static_cast<Month>(Month_east);
    int days = number_of_days_in_year(day_east, maand, year);
    cout << days << "days" << endl;
    int Carnival = days - 7*7 ;
    int Good_Friday = days - 2 ;
    int Whitsuntide = days + 7*7;
    int  Ascension_Day = Whitsuntide - 10;

    cout << "Carnival valt op "            << convert2(Carnival,year)           << " - " << convert1(Carnival, year)      << endl;
    cout << "Goede vrijdag valt op  "      << convert2(Good_Friday,year)        << " -" << convert1(Good_Friday, year)    << endl;
    cout << "Whitsuntide valt op "         << convert2(Whitsuntide,year)        << " - " << convert1(Whitsuntide, year)   << endl;
    cout << "Ascension_Day valt op  "      << convert2(Ascension_Day,year)      << " - " << convert1(Ascension_Day, year) << endl;

}

int main()

{
    int year;
    cout << "Uit welk jaar wilt u het jaar weten ";
    cin >> year;
    show_holy_days(year);
    return 0;
}

