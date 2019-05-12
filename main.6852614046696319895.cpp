#include <iostream>

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
bool is_leap_year ( int year )
{
    return (year%400==0||year%4==0&&year%100!=0);
}

int number_of_days_in_month ( int year, Month month )
{
    switch (month)
    {
    case 1: return 31;
    case 2: if(is_leap_year(year))
                return 29;
            else
                return 28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    default: return 0;

    }
}

/*                                                                   
                                                
                                                                   */
int calculate_postive_month(int day, Month month, int days, int year)
{
    days+=day;
    while(days>number_of_days_in_month(year,month))
    {
        days-=number_of_days_in_month(year, month);
        month=static_cast<Month>(month+1);
    }
    return month;
}

int calculate_postive_day(int day, Month month, int days, int year)
{
    days+=day;
    while(days>number_of_days_in_month(year, month))
    {
        days-=number_of_days_in_month(year, month);
        month=static_cast<Month>(month+1);
    }
    return days;
}

void show_holy_days ()
{
    int year;
    cout<<"What year do you want to know the Holydays from?"<<endl;
    cin>>year;
    int easterday=easter_day(year);
    Month eastermonth=easter_month(year);
    cout<<"Witsontide is on "<<calculate_postive_month(easterday,eastermonth, 49, year)<<", "<<calculate_postive_day(easterday, eastermonth, 49, year)<<endl;

}

int main()
{
    show_holy_days() ;
    return 0;
}

