//                                                               
//                                                       

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

//                                                               
//                                                       

/*                                                                   
                                 
                                                                   */
bool is_leap_year ( int year )
{
    return((year%4==0) && (year%100!=0) || (year%400==0));
}

int number_of_days_in_month ( int year, Month month )
{
    int days;
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: days=31; break;
        case 4: case 6: case 9: case 11: days=30; break;
        case 2:
            {   if(is_leap_year(year))
                    days=29;
                else
                    days=28;
                break;
            }
    }
    return days;

}

/*                                                                   
                                                
                                                                   */
int day_in_year(int day, Month month, int year)
{
    int total = 0;
    for(int i=1; i<month; i++)
    {
        total=number_of_days_in_month(year, static_cast<Month>(i)) + total;
    }
    total= total+day;
    return total;

}

int date_day(int specific_day, int year)
{
    int counter = 1;
   while (specific_day > number_of_days_in_month(year, static_cast<Month>(counter)))
   {
       specific_day= specific_day - number_of_days_in_month(year, static_cast<Month>(counter));
       counter++;
   }
   return specific_day;

}

int date_month(int specific_day, int year)
{
    int counter = 1;
   while (specific_day > number_of_days_in_month(year, static_cast<Month>(counter)))
   {
       specific_day = specific_day - number_of_days_in_month(year, static_cast<Month>(counter));
       counter++;
   }
   return counter;

}

void show_holy_days (int year, Month easter_month , int easter_day)
{
   int specific_day = day_in_year(1, April , year);
   int date_carnaval_start_day = date_day(specific_day-49, year);
   int date_carnaval_end_day = date_day(specific_day-47, year);
   int date_carnaval_start_month = date_month(specific_day-49, year);
   int date_carnaval_end_month=date_month(specific_day-47, year);
   cout<< "carnival starts at " << date_carnaval_start_day << "-" << date_carnaval_start_month << " carnival ends at " << date_carnaval_end_day << "-" << date_carnaval_end_month <<  endl;

    int good_friday_day = date_day(specific_day-2, year);
    int good_friday_month = date_month(specific_day-2, year);
    cout<< "good friday is on " << good_friday_day << "-" << good_friday_month <<  endl;

    int ascension_day_day = date_day(specific_day+39, year);
    int ascension_day_month = date_month(specific_day+39, year);
    cout << "ascension day is on " << ascension_day_day << "-" << ascension_day_month <<  endl;

    int date_whitsuntide_day = date_day(specific_day+49, year);
    int date_whitsuntide_month = date_month(specific_day+49, year);
    cout<< "whitsuntide is on " << date_whitsuntide_day << "-" << date_whitsuntide_month << endl;

}

int main()
{
    int year;
    int day =   easter_day(year);
    Month month = easter_month(year);
    show_holy_days(year, month, day) ;
    return 0;
}

