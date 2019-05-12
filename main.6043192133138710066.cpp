#include <iostream>
#include <math.h>

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
    return ( easter_base ( year ) % 31 ) + 1 ;
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
//                                                        
bool is_leap_year ( int year )
{
    if ( year % 4 == 0 && year % 100 != 0 )
      return true ;
      else
        if ( year % 100 == 0 && year % 400 == 0 )
            return true ;
          else
             return false ;
}

int number_of_days_in_month ( int year, Month month )
{
    if ( month == February )
    {
        if ( is_leap_year ( year ) )
            return 29 ;
        else
            return 28 ;
    }
    if ( month == September || month == June || month == November || month == April )
        return 30 ;
    else
        return 31 ;
}

/*                                                                   
                                                
                                                                   */
void calc_day ( int year , int day , int month , int target )
{
    int m = month ;
    int d = day ;

    if ( target > 0 )
    {
       while (target != 0)
       {
        if ( d < number_of_days_in_month ( year , ( Month ) m ) )
        {
            d ++ ;
        }
           else
            {
              d = 1 ;
              m = m + 1 ;
            }
        target -- ;
       }
    }
    else
        while (target != 0)
       {
        if ( d > 0 )
           d -- ;
        if ( d <= 0 )
            {
              m = m - 1 ;
              d = number_of_days_in_month ( year , ( Month ) m  )  ;
            }
        target ++ ;
       }
    cout << d << " / " << m << endl ;
}

void good_friday ( int year , int day , Month month )
{
    int m = month ;

    cout << "On the year " << year << " Good Friday will be on the " ;
    calc_day ( year, day, m, -2 ) ;
}
void carnival ( int year , int day , Month month )
{
    int m = month ;
    cout << "On the year " << year << " Carnival will be on the " ;
    calc_day ( year,day,m, -49 ) ;
    cout << "and it will end on Tuesday " ;
    calc_day ( year,day,m, -47 ) ;

}
void whitsuntide ( int year , int day , Month month )
{
    int m = month ;
    cout << "On the year " << year << " Whitsuntide will be on the " ;
    calc_day ( year,day,m, 49 ) ;
}

void ascension ( int year , int day , Month month )
{
    int m = month ;
    cout << "On the year " << year << " Ascension Day will be on the " ;
    calc_day ( year, day, m, 39 ) ;
}

void show_holy_days ( int year )
{
    int e_day ;
    Month e_month ;

    e_day = easter_day ( year ) ;
    e_month = easter_month ( year ) ;

    cout << "On the year " << year << " Easter will be on the " << e_day << " / " << e_month << endl ;

    good_friday ( year , e_day , e_month ) ;
    carnival ( year , e_day , e_month ) ;
    whitsuntide ( year , e_day , e_month ) ;
    ascension ( year , e_day , e_month ) ;

}

int main ()
{
    int year , days , monthNum ;
    Month month ;

    cout << "insert year " ;
    cin >> year ;

    if ( is_leap_year ( year ) )
        cout << "the year is leap!" << endl ;
    else
        cout << "the year is NOT leap!" << endl ;

    show_holy_days(year) ;

    return 0 ;
}

