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
string make_month_string(int month)
{
    switch(month)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        return "no month";
    }
}

//                              
int get_year ()
{
    int year;
    cout << "Please, give a year" << endl;
    cin >> year;
    return year;
}

//                                                                                       
//                                               
//                                                                                                                                                    
//                                                                      
bool is_leap_year ( int year )
{
    if (!(year%4 == 0))
    {
        return false;
    }
    else if (year%400==0)
    {
        return true;
    }
    else if (year%100 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//                                               
int number_of_days_in_month ( int year, Month month )
{
    switch(month)
    {
    case January:
    case March:
    case May:
    case July:
    case August:
    case October:
    case December:
        return 31;
        break;
    case February:
        if (is_leap_year(year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
        break;
    default:
        return 30;
    }
}

/*                                                                   
                                                
                                                                   */

//                                                                                                                                                      
//                                                     
int get_easter_day (int year)
{
    int eday = easter_day(year);
    int emonth = easter_month(year);
    int day = 0;
    for (int month = 1; month < emonth; month++)
    {
        day = day + number_of_days_in_month(year, static_cast<Month>(month));
    }
    day = day + eday;
    return day;
}

//                                                                                   
//                                                                                         
//                             

int get_month(int day, int year)
{
    int month = 0;
    while (day > 0)
    {
        day = day - number_of_days_in_month(year, static_cast<Month>(month));
        month++;
    }
    return month;
}

//                                                                                                                                 
//                                                                                                                            
//                           
int get_day(int day, int year)
{
    int month = get_month(day, year);
    int total_days = 1;
    for (int i = 1; i < month; i++)
    {
        total_days = total_days + number_of_days_in_month(year, static_cast<Month>(i));
    }
    day = day - total_days + 1;
    return day;
}

//                                                                                                  
void write (int day, int year, string holiday)
{
    int month = get_month(day,year);
    int hday = get_day(day, year);

    cout << holiday << " falls in the year " << year << " on " << make_month_string(month) <<" "<< hday << '\n';
}

//                                                                    
void show_holy_days ()
{
    cout << "This is a program to see all the dates of the holy days (Carnival, Good Friday, Easter, Ascension Day, Whitsuntide) in a given year"<< '\n';
    int year = get_year();
    //                                      
    write(get_easter_day(year) - 49, year, "Carnival");
    write(get_easter_day(year) - 2, year, "Good Friday");
    write(get_easter_day(year), year, "Easter");
    write(get_easter_day(year) + 39, year, "Ascension Day");
    write(get_easter_day(year) + 49, year, "Whitsuntide Day");

}

int main()
{
    show_holy_days();
    return 0;
}

