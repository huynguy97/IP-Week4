//                                 
//                                                 
//                                                   

//                                                                            
//                                                                           
//                                                                         
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

/*                                                                   
                                 
                                                                   */

//                                                        
bool is_leap_year ( int year )
{
//               
//                                     

//                
//                                                             
    if (year % 4 == 0)
    {
        if (year % 100 == 0 && year % 400 != 0)
        {
            return false;
        }
        return true;
    }
    return false;
}

//                                                           
int number_of_days_in_month ( int year, Month month)
{
//               
//                                     

//                
//                                                                        
//                                                   
    switch (month)
    {
        case January:   return 31; break;
        case February:
                        if (is_leap_year(year))
                        {
                            return 29;
                        }
                        return 28; break;
        case March:     return 31; break;
        case April:     return 30; break;
        case May:       return 31; break;
        case June:      return 30; break;
        case July:      return 31; break;
        case August:    return 31; break;
        case September: return 30; break;
        case October:   return 31; break;
        case November:  return 30; break;
        case December:  return 31; break;
    }
}

/*                                                                   
                                                
                                                                   */

//                                                   
string month_name (int month)
{

//               
//                                               

//                
//                                                                  

    switch(month)
    {
        case 1: return "January" ; break;
        case 2: return "February" ; break;
        case 3: return "March" ; break;
        case 4: return "April" ; break;
        case 5: return "May" ; break;
        case 6: return "June" ; break;
        case 7: return "July" ; break;
        case 8: return "August" ; break;
        case 9: return "September" ; break;
        case 10: return "October" ; break;
        case 11: return "November" ; break;
        case 12: return "December" ; break;
    }
}

//                                           
void easter (int year)
{
//               
//                                     

//                
//                                                                               
    cout << "Easter falls on day\t\t" << easter_day(year) << " of " << month_name (static_cast<int>(easter_month(year))) << endl;
}

//                                                
void good_friday (int year)
{
//               
//                                     

//                
//                                                            
    int month = easter_month(year)-1;

    switch (easter_day(year))
    {
        case 1: cout << "Good Friday in on day\t" << number_of_days_in_month(year,static_cast<Month>(month))-1 << " of " << month_name (month) << endl; break;
        case 2: cout << "Good Friday in on day\t" << number_of_days_in_month(year,static_cast<Month>(month)) << " of " << month_name (month) << endl; break;
        default: cout << "Good Friday falls on day\t" << easter_day(year)-2 << " of " << month_name (month + 1) << endl; break;
    }
}

//                                                
void whitsuntide (int year)
{
//               
//                                     

//                
//                                                            
    int day = easter_day(year);
    int month = easter_month(year);

    for (int days_passed = 1; days_passed <= 49; days_passed++)
    {
        if (day < number_of_days_in_month(year, static_cast<Month>(month)))
        {
            day++;
        }
        else
        {
            day = 1;
            month+=1;
        }
    }
    cout << "Whitsuntide falls on day\t" << day << " of " << month_name (month) << endl;
}

//                                                  
void ascension_day (int year)
{
//               
//                                     

//                
//                                                              
    int day = easter_day(year);
    int month = easter_month(year);

    for (int days_passed = 1; days_passed <= 39; days_passed++)
    {
        if (day < number_of_days_in_month(year, static_cast<Month>(month)))
        {
            day++;
        }
        else
        {
            day = 1;
            month += 1;
        }
    }
    cout << "Ascension Day falls on day\t" << day << " of " << month_name (month) << endl;
}

//                                             
void carnival (int year)
{
//               
//                                     

//                
//                                                               
    int day = easter_day(year);
    int month = easter_month(year);

    for (int i = 1; i <= 49; i++)
    {
        if (day > 1)
        {
            day--;
        }
        else
        {
            month--;
            day = number_of_days_in_month(year, static_cast<Month>(month));
        }
    }
    cout << "Carnival begins on day\t\t" << day << " of " << month_name (month) << endl;

    if (day == number_of_days_in_month(year, static_cast<Month>(month)))
    {
        cout << "Carnival ends on day\t\t" << 2 << " of " << month_name (month + 1) << endl;
    }
    else if (day == number_of_days_in_month(year, static_cast<Month>(month))-1)
    {
        cout << "Carnival ends on day\t\t" << 1 << " of " << month_name (month + 1) << endl;
    }
    else
    {
        cout << "Carnival ends on day\t\t" << day+2 << " of " << month_name (month) << endl;
    }
}

//                                                                               
//                  
void show_holy_days ()
{
//               
//  

//                
//                                                                                
//                  
    int year;

    cout << "Of which year do you want to know the holy days?" << endl;
    cin >> year;

    easter(year);
    good_friday(year);
    whitsuntide(year);
    ascension_day(year);
    carnival(year);
}

int main()
{
    show_holy_days() ;
    return 0;
}

