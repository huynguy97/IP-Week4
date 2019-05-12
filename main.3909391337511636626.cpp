#include <iostream>
#include <cmath>

using namespace std;

//                                                 

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
    const int i     = C / 4 ;
    const int K     = C % 4 ;
    const int L     = (32 + 2 * E + 2 * i - H - K) % 7 ;
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
bool is_leap_year ( int year )
{
    if ((year % 4 == 0) && (year % 100 != 0))
    {
        return true;
    }
    if ((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))
    {
        return true;
    }
    return false;
}

//                                                                                 
int number_of_days_in_month ( int year, Month month )
{
if ((month==April) || (month==June) || (month==September) || (month==November))
    {
       return 31;
    }
        else if (month==February)
        {
            if (is_leap_year(year))
                {
                return 29;
                }
            else
                {
                return 28;
                }
        }
            else
            {
                return 31 ;
            }
}

/*                                                                   
                                                
                                                                   */

//                                                                              
int day_number_easter(int year)
{
    int m=easter_month(year);
    int d=easter_day(year);
    int day;
        if (is_leap_year(year))
        {
            if (m==3)
            {
                return 31+29+d;
            }
            else if (m==4)
            {
                return 31+29+31+d;
            }
        }
        else if (m==3)
            {
                return 31+28+d;
            }
            else if (m==4)
            {
                return 31+28+31+d;
            }
}

//                                                                                                  
int date_day_number (int year, int  day)
{
    int date;
    int i = 1;
        while (day >= 0)
        {
        day=day - number_of_days_in_month(year,static_cast <Month> (i));
        i=i+1;
        }
    date=day + number_of_days_in_month(year, static_cast <Month> (i));
    return date;
}

//                                                         
int month_day_number (int year, int  day)
{
    int date;
    int i = 0;
        while (day >= 0)
        {
        day=day - number_of_days_in_month(year,static_cast <Month> (i));
        i=i+1;
        }
    date=day + number_of_days_in_month(year, static_cast <Month> (i));
    return i;
}

//                                                                                                      
void show_holy_days (int year)
{
    int date;
    int day;
    int i=0;
    cout << "\nEaster: (" << easter_day(year) << ", " << easter_month(year) << ")";
    day = day_number_easter(year);

    int Carnival=day-49;
    date = date_day_number(year, Carnival);
    i = month_day_number(year, Carnival);
    cout << "\nCarnival: (" << date << ", " << i << ")";

    int Goodfriday=day_number_easter(year)-2;
    date = date_day_number(year, Goodfriday);
    i = month_day_number(year, Goodfriday);

    cout << "\nGood friday: (" << date << ", " << i << ")";
    int Ascension=day_number_easter(year)+39;
    date = date_day_number(year, Ascension);
    i = month_day_number(year, Ascension);

    cout << "\nAscension day: (" << date << ", " << i << ")";
    int Whitsuntide=day_number_easter(year)+49;
    date = date_day_number(year, Whitsuntide);
    i = month_day_number(year, Whitsuntide);
    cout << "\nWhitsuntide: (" << date << ", " << i << ")";
}

int main()
{
    cout << "Give the year: " ;
    int year ;
    cin >> year ;
    if(is_leap_year(year))
        cout << "iTS A LEAP YEAR";
    else
        cout << "iTS NOT A LEAP YEAR";
    show_holy_days(year);
}

