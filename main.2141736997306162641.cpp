/*                         
*/

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
/*                                       
*/
bool is_leap_year ( int year )
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

/*                                                            
*/
int number_of_days_in_month ( int year, Month month )
{
    if(month == 2 && is_leap_year(year))
    {
        return 29;
    }
    else if(month == 2)
    {
        return 28;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else return 31;
}

/*                                                                   
                                                
                                                                   */

/*                                                                                              
*/
Month newMonth(int month, int i)
{
    i += month;
    switch(i)
    {
    case 1 :
        return January;
        break;
    case 2 :
        return February;
        break;
    case 3 :
        return March;
        break;
    case 4 :
        return April;
        break;
    case 5 :
        return May;
        break;
    case 6 :
        return June;
        break;
    case 7 :
        return July;
        break;
    case 8 :
        return August;
        break;
    case 9 :
        return September;
        break;
    case 10 :
        return October;
        break;
    case 11 :
        return November;
        break;
    default :
        return December;
        break;
    }
}

/*                                                            
*/
void carnival(int year, int day, Month month)
{
    month = newMonth(month, -1);
    day -= (49 - number_of_days_in_month(year, month));
    if(day <= 0){
        month = newMonth(month, -1);
        day += number_of_days_in_month(year, month);
    }
    int day2 = day + 2;
    Month month2 = month;
    if(day2 > number_of_days_in_month(year, month)){
        day2 -= number_of_days_in_month(year, month);
        month2 = newMonth(month, 1);
    }
    cout << "Carnival is on " << day <<  "/" << month << " untill " << day2 << "/"<< month2 <<endl;
}

/*                                                              
*/
void goodFriday(int year, int day, Month month)
{
    day = day - 2;
    if(day <= 0)
    {
        month =  newMonth(month, -1);
        day += number_of_days_in_month(year, month);
    }
    cout << "Good Friday is on " << day <<  "/" << month << endl;
}

/*                                                                
*/
void ascensionDay (int year, int day, Month month)
{
    day += (39 - number_of_days_in_month(year, month));
    month = newMonth(month, 1);
    if(day > number_of_days_in_month(year, month)){
        day -= number_of_days_in_month(year, month);
        month = newMonth(month, 1);
    }
    cout << "Ascension Day is on " << day <<  "/" << month << endl;
}

/*                                                              
*/
void Whitsuntide(int year, int day, Month month)
{
    day += (49 - number_of_days_in_month(year, month));
    month = newMonth(month, 1);
    if(day > number_of_days_in_month(year, month)){
        day -= number_of_days_in_month(year, month);
        month = newMonth(month, 1);
    }
    cout << "Whitsuntide is on " << day <<  "/" << month << endl;
}

/*                                                            
*/
void show_holy_days ()
{
    int year;
    cout << "Enter the year of which you want to see the holy days." << endl;
    cin >> year;
    int day = easter_day(year);
    Month month = easter_month(year);
    carnival(year, day, month);
    goodFriday(year, day, month);
    cout << "Easter is on " << day <<  "/" << month << endl;
    ascensionDay(year, day, month);
    Whitsuntide(year, day, month);
}

int main()
{
    show_holy_days() ;
    return 0;
}

