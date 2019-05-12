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

//                                       

//                                                                                                         
//                                                                                                       
//                                                                                                          
//                     

bool is_leap_year ( int year )
{
    if (year%4 == 0)
    {
        if (year%100 == 0)
        {
            if (year%400 == 0)
            {
                return true ;
            }

            else
            {
                return false ;
            }
        }

        else
        {
            return true ;
        }
    }

    return false ;
}

//                                                                                                                                                                                       
//                                                                                                        

int number_of_days_in_month ( int year, Month month )
{
    switch (month)
    {
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December: return 31; break;

        case April:
        case June:
        case September:
        case November: return 30; break;

        case February:
        if (is_leap_year(year)==true)
        {
            return 29; break;
        }

        else
        {
            return 28; break;
        }
    }
}

/*                                                                   
                                                
                                                                   */

//                                                                                                                                                                                      
//                                                                                                          

int Day_of_Year (int year)
{
    Month month_of_easter = easter_month(year) ;
    int i = 1 ;
    int sum = 0;

    while (i < month_of_easter)
    {
        sum = sum + number_of_days_in_month(year, (Month) i) ;
        i++ ;
    }

    sum = sum + easter_day(year) ;
    cout << sum << endl ;

    return sum ;
}

//                                                                                                       

void Print_Month_Day (int year, int day_nr)
{
    int i = 1 ;
    while (day_nr > number_of_days_in_month(year, (Month) i))
    {
        day_nr = day_nr - number_of_days_in_month(year, (Month) i) ;
        i++ ;
    }

    cout << "Month: " << i << "\tDay nr.: " << day_nr << endl ;
}

//                                                                                          

void show_holy_days (int year)
{
    int sum = Day_of_Year(year) ;
    int i;

    cout << "Easter:\t\t" << "Month: " << easter_month(year) << "\tDay nr.:" << easter_day(year) << endl ;

    int Carnival_Start = sum - 49 ;
    cout << "Carnival Start:\t"  ;
    Print_Month_Day(year, Carnival_Start);

    int Carnival_End = sum - 47 ;
    cout << "Carnival End:\t" ;
    Print_Month_Day(year, Carnival_End);

    int Good_Friday = sum - 2 ;
    cout << "Good Friday:\t" ;
    Print_Month_Day(year, Good_Friday) ;

    int Ascension_Day = sum + 39 ;
    cout << "Ascension Day:\t" ;
    Print_Month_Day(year, Ascension_Day) ;

    int Whitsuntide = sum + 49 ;
    cout << "Whitsuntide:\t" ;
    Print_Month_Day(year, Whitsuntide) ;
}

//                                                                                              

int main()
{
    int year ;
    int month ;

    cout << "Hello world!" << endl ;
    cout << "Enter a year:" ;
    cin >> year ;
    cout <<"Enter a number for month 1 to 12:" ;
    cin >> month ;
    cout << "Year:" << year << "\tMonth:" << month << "\tDays in month:" << number_of_days_in_month(year, (Month) month) << endl ;

    show_holy_days(year) ;
    return 0;
}

