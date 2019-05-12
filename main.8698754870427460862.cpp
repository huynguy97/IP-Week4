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
    if ( year%4 != 0 || ( year%100 == 0 && year%400 != 0 ))//                                                                                        
        return false;
    return true;
}

int number_of_days_in_month ( int year, Month month )
{
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;//                                                                   
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;//                           
        case 2:
            return 28 + is_leap_year( year );//                                                                                     
    }
}

/*                                                                   
                                                
                                                                   */

//                                                                                                                       
Month  find_month( int eastday,  Month eastmonth, int year, int diff )
{
    int day = eastday + diff;//                                                                  
    Month month = eastmonth;
    while( day<1 || day> number_of_days_in_month(year, month))//                                         
    {
        if (day < 1)//                                      
        {
            month = static_cast<Month>(month-1); //                               
            day = day + number_of_days_in_month( year, month );//                                                                                

        }
        else//                                                
        {
            day = day - number_of_days_in_month( year, month );//                                                                                 
            month = static_cast<Month>(month+1);//                                  
        }
    }
    return month;//                                 

}

//                                                                                                                                                                                               
int find_day( int eastday, Month eastmonth, int year, int diff)
{
    int day = eastday + diff;
    Month month = eastmonth;
    while( day<1 || day> number_of_days_in_month(year, month))
    {
        if (day < 1)
        {
            month = static_cast<Month>(month-1);
            day = day + number_of_days_in_month( year, month );

        }
        else
        {
            day = day - number_of_days_in_month( year, month );
            month = static_cast<Month>(month+1);
        }
    }
    return day;//                               
}

void show_holy_days (int year)
{
    int eastday = easter_day(year);
    Month eastmonth = easter_month(year);
    if( year > 2018)
        cout << "In the year " << year << " the holy days are on the following dates:" << endl;
    else
        cout << "In the year " << year << " the holy days were on the following dates:" << endl;

    cout << "Carnival: " << find_day( eastday, eastmonth, year, -49) << "/" << find_month( eastday, eastmonth, year, -49 );
    cout << " to " << find_day( eastday, eastmonth, year, -47) << "/" << find_month( eastday, eastmonth, year, -47 )<< endl;//                                                                           
    cout << "Good Friday: " << find_day( eastday, eastmonth, year, -2) << "/" << find_month( eastday, eastmonth, year, -2 ) << endl;
    cout << "Easter: " << eastday << "/" << eastmonth << endl;
    cout << "Ascension Day: " << find_day( eastday, eastmonth, year, 39) << "/" << find_month( eastday, eastmonth, year, 39 ) << endl;
    cout << "Whitsuntide: " << find_day( eastday, eastmonth, year, 49) << "/" << find_month( eastday, eastmonth, year, 49 ) << endl;
}

//                                                           
int main()
{
    cout << "You want to know the holy days of which year? ";
    int year;
    cin >> year;
    show_holy_days(year) ;
    return 0;
}

