//            
//                                       

#include <iostream>

using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;

enum HolyDays {Carnival, Carnival_End, Good_Friday, Ascension, Witsuntide};

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
    bool leap_year = year%4==0;
    if ( year%100==0 && year%400!=0 ) //                                                                    
        leap_year = false;
    return leap_year;
}

int number_of_days_in_month ( int year, Month month )
{
    int days;
    int feb_days = 28;
    if(is_leap_year(year)) //                              
        feb_days = 29;

    switch(month) //                                                          
    {
        case January: days = 31; break;
        case February: days = feb_days; break;
        case March: days = 31; break;
        case April: days = 30; break;
        case May: days = 31; break;
        case June: days = 30; break;
        case July: days = 31; break;
        case August: days = 31; break;
        case September: days = 30; break;
        case October: days = 31; break;
        case November: days = 30; break;
        case December: days = 31; break;
    }
    return days;
}
/*                                                                   
                                                
                                                                   */
string get_month_name (Month month) //                         
{
    string name;
    switch(month)
    {
        case January: name = "January"; break;
        case February: name = "February"; break;
        case March: name = "March"; break;
        case April: name = "April"; break;
        case May: name = "May"; break;
        case June: name = "June"; break;
        case July: name = "Juli"; break;
        case August: name = "August"; break;
        case September: name = "September"; break;
        case October: name = "October"; break;
        case November: name = "November"; break;
        case December: name = "December"; break;
    }
    return name;
}

int get_total_days (int year, int day, Month month) //                                                                     
{
    int days = day;

    for(int i = 1; i < month; i++)
    {
        days += number_of_days_in_month(year, static_cast<Month>(i) );
    }
    return days;
}

Month get_month (int year, int days) //                                        
{
    int i = 1;
    while(days>0)
    {
        days  = days - number_of_days_in_month(year, static_cast<Month>(i));
        i ++;
    }
    return static_cast<Month>(i - 1);
}

int get_day (int year, int days) //                                      
{
    return ( days - get_total_days(year, 0 , get_month(year,days)) ); //                                                                                                                
}
int holy_day_get_days (int easterdate, HolyDays holyday) //                                          
{
    int delta_days = 0;
    switch(holyday)
    {
        case Carnival: delta_days = -49 ; break;
        case Carnival_End: delta_days = -46 ; break;
        case Good_Friday: delta_days = -2 ; break;
        case Ascension: delta_days = 39 ; break;
        case Witsuntide: delta_days = 49 ; break;
    }
    return (easterdate+delta_days);
}

void show_holy_days ()
{
    int year;

    cout << "Enter the year you want to know the Holy Days dates of..."<<endl;
    cin >> year;

    int easter_days = get_total_days(year, easter_day(year), easter_month(year) );

    //                         
    cout << "Carnival begins on " << get_day(year, holy_day_get_days(easter_days, Carnival))<< " " << get_month_name( get_month(year, holy_day_get_days(easter_days, Carnival)))<< " and ends on " << get_day(year, holy_day_get_days(easter_days, Carnival_End))<< " " << get_month_name( get_month(year, holy_day_get_days(easter_days, Carnival_End))) << endl;
    cout << "Good Friday is on " << get_day(year, holy_day_get_days(easter_days, Good_Friday))<< " " << get_month_name( get_month(year, holy_day_get_days(easter_days, Good_Friday)))<<endl;
    cout << "Easter is on " << easter_day(year)<< " " << get_month_name(easter_month(year))<<endl;
    cout << "Ascension is on " << get_day(year, holy_day_get_days(easter_days, Ascension))<< " " << get_month_name( get_month(year, holy_day_get_days(easter_days, Ascension)))<<endl;
    cout << "Witsuntide is on " << get_day(year, holy_day_get_days(easter_days, Witsuntide))<< " " << get_month_name( get_month(year, holy_day_get_days(easter_days, Witsuntide)))<<endl;

}

int main()
{
    show_holy_days();
    return 0;
}

