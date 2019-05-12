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
    if (year % 4 != 0)
        return false;
    else
        if (year % 100 != 0)
            return true;
        else
            if (year % 400 == 0)
                return true;
            else
                return false;
}

int number_of_days_in_month ( int year, Month month )
{
    switch (month)
    {
        case January: return 31;
        case February:
            if (is_leap_year(year))
                return 29;
            else
                return 28;
        case March: return 31;
        case April: return 30;
        case May: return 31;
        case June: return 30;
        case July: return 31;
        case August: return 31;
        case September: return 30;
        case October: return 31;
        case November: return 30;
        case December: return 31;
    }

}

/*                                                                   
                                                
                                                                   */

    //                                                                                                          
    int day_base_to_day_of_month(int year, int day_base)
    {
        int count_days = 0;
        Month my_month = January;
        count_days = number_of_days_in_month(year, my_month);
        while (count_days < day_base)
        {
            my_month = static_cast<Month>(static_cast<int>(my_month)+1);
            count_days += number_of_days_in_month(year, my_month);
        }
        count_days -= number_of_days_in_month(year, my_month);
        return day_base - count_days;

    }
    //                                                                                                           
    int day_base_to_month (int year, int day_base)
    {
        int count_days = 0;
        Month my_month = January;
        count_days = number_of_days_in_month(year, my_month);
        while (count_days < day_base)
        {
            my_month = static_cast<Month>(static_cast<int>(my_month)+1);
            count_days += number_of_days_in_month(year, my_month);
        }
        count_days -= number_of_days_in_month(year, my_month);
        return my_month;

    }

void show_holy_days ()
{
    cout << "Please enter year ";
    int year = 0;
    cin >> year;
    int my_easter_day = easter_day(year);
    Month my_easter_month = easter_month(year);
    cout << "The easter of this year is on month " << my_easter_month << " on day " << my_easter_day << endl;

    //                                                                                              
    int my_easter_base = number_of_days_in_month(year, January); //                                                                                           
    for (int i = 2; i < static_cast<int>(my_easter_month); i++) //                                                                                                
    {
        my_easter_base += number_of_days_in_month(year, static_cast<Month>(i));
    }
    //                                                                  
        my_easter_base += my_easter_day; //                                            

    int my_carnival_base = my_easter_base - 49;
    int my_good_friday_base = my_easter_base - 2;
    int my_ascension_day_base = my_easter_base + 39;
    int my_whitsuntide_base = my_easter_base + 49;

    cout << "The carnival of this year is on month " << day_base_to_month(year, my_carnival_base) << " on day " << day_base_to_day_of_month(year, my_carnival_base) << endl;
    cout << "The good friday of this year is on month " << day_base_to_month(year, my_good_friday_base) << " on day " << day_base_to_day_of_month(year, my_good_friday_base) << endl;
    cout << "The whitsuntide of this year is on month " << day_base_to_month(year, my_whitsuntide_base) << " on day " << day_base_to_day_of_month(year, my_whitsuntide_base) << endl;
    cout << "The ascension day of this year is on month " << day_base_to_month(year, my_ascension_day_base) << " on day " << day_base_to_day_of_month(year, my_ascension_day_base) << endl;
}

int main()
{

    show_holy_days() ;
    return 0;

}

