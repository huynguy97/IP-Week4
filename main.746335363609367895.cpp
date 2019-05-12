#include <iostream>
#include <cmath>

//                    
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
    if(year%4 == 0)//                                                
    {
        if(year%100 == 0)//                                            
        {
            if(year%400 == 0)
            {
                return true;//                                                         
            }
            else
            {
                return false;//                                                       
            }
        }
        return true;//                                                  
    }
    else
    {
        return false;//                                       
    }
}

int number_of_days_in_month ( int year, Month month )
{
    switch(month)
    {
        //                         
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December: return 31; break; //                                                                   
        //                         
        case April:
        case June:
        case September:
        case November: return 30; break;
        //                                                       
        case February: if(is_leap_year(year))
                    return 29;
                else
                    return 28;
                break;

    }
}

/*                                                                   
                                                
                                                                   */

//                                              
//                                                      
void calculate_date(int days_away, int year)
{
//                                     
    int daynumber = 0;//                                            
    int n = 1;//                          
    int new_daynumber = 0;//                                             
    while(n!=Month(easter_month(year)))//                                            
    {
        daynumber += number_of_days_in_month(year, Month(n));//                                                                          
        n++;//                        
    }
    daynumber += easter_day(year);//                                                            
//                              
    new_daynumber = daynumber + days_away;
//                                     
    n = 1;//                           
    while(new_daynumber>number_of_days_in_month(year,Month(n)))//                                             
    {
        new_daynumber -= number_of_days_in_month(year,Month(n));//                                                            
        n++;//                        
    }
    cout << Month(n)<< "." << new_daynumber;//                                                                                                             
}

//                                                               
//                                                                           
void show_holy_days ()
{
    int year;
    do
    {
        cout << "Please type in the year you want to know the holidays of." << endl;
        cin >> year;
    }while(year<1);//                                                       
    cout << "The day of the holidays is given in form of month.day."<< endl;
    cout << "Easter is on        "; cout << easter_month(year); cout << "."; cout << easter_day(year) <<endl;
    cout << "Carnival is from    "; calculate_date(-49, year);
    cout << " to "; calculate_date(-47, year); cout << endl;
    cout << "Good Friday is on   "; calculate_date(-2, year); cout << endl;
    cout << "Ascension Day is on "; calculate_date(39, year); cout << endl;
    cout << "Whitsuntide is on   "; calculate_date(49, year); cout << endl;
}

int main()
{
    show_holy_days() ;
    return 0;
}

