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
bool is_leap_year ( int year )
{
    return !(year % 4) && ((year % 100) || !(year % 400));
}

//                                                                           
//                              
int number_of_days_in_month ( Month month, int year )
{
    switch(month){
        case January:
            return 31;
        case February:
            if(is_leap_year(year)){
                return 29;
            } else{
                return 28;
            }
        case March:
            return 31;
        case April:
            return 30;
        case May:
            return 31;
        case June:
            return 30;
        case July:
            return 31;
        case August:
            return 31;
        case September:
            return 30;
        case October:
            return 31;
        case November:
            return 30;
        case December:
            return 31;
        default:
            return -1;
    }
}

/*                                                                   
                                                
                                                                   */

//                                                                      
string string_month( Month month )
{
    switch(month){
        case January:
            return "January";
        case February:
            return "February";
        case March:
            return "March";
        case April:
            return "April";
        case May:
            return "May";
        case June:
            return "June";
        case July:
            return "July";
        case August:
            return "August";
        case September:
            return "September";
        case October:
            return "October";
        case November:
            return "November";
        case December:
            return "December";
        default:
            return "No month found";
    }
}

//                                                        
//                                                       
void print_carnival_date( int easter_day, Month easter_month, int year)
{
    //                                  
    int days_remaining = 49;
    //                      
    days_remaining -= easter_day;
    //                                                                                                            
    if (number_of_days_in_month( static_cast<Month>(easter_month - 1), year) < days_remaining){
        //                                                                               
        days_remaining -= number_of_days_in_month( static_cast<Month>(easter_month - 1), year);
        cout << "Carnival is on " << string_month( static_cast<Month>(easter_month - 2) ) << ' '
            << number_of_days_in_month( static_cast<Month>(easter_month - 2), year) - days_remaining << endl;
    } else{
        //                                 
        cout << "Carnival is on " << string_month( static_cast<Month>(easter_month - 1) ) << ' '
            << number_of_days_in_month( static_cast<Month>(easter_month - 1), year) - days_remaining << endl;
    }
}

//                                                           
//                                                       
void print_good_friday_date( int easter_day, Month easter_month, int year)
{
    //                                    
    int days_remaining = 2;
    //                                                              
    if (easter_day < days_remaining){
        //                                      
        days_remaining -= easter_day;
        cout << "Good Friday is on " << string_month( static_cast<Month>(easter_month - 1) ) << ' '
            <<  number_of_days_in_month( static_cast<Month>(easter_month - 1), year) - days_remaining << endl;
    } else{
        //                                          
        cout << "Good Friday is on " << string_month(easter_month) << ' ' << easter_day - days_remaining << endl;
    }
}

//                                                      
//                                              
void print_easter_date( int easter_day, Month easter_month)
{
    cout << "Easter " << string_month(easter_month) << ' ' << easter_day << endl;
}

//                                                             
//                                                       
void print_ascension_day_date( int easter_day, Month easter_month, int year)
{
    //                                      
    int days_remaining = 39;
    //                     
    days_remaining -= number_of_days_in_month(easter_month, year) - easter_day;
    //                                                                
    if (number_of_days_in_month( static_cast<Month>(easter_month + 1), year) < days_remaining){
        //                                      
        days_remaining -= number_of_days_in_month( static_cast<Month>(easter_month + 1), year);
        cout << "Ascension Day is on " << string_month( static_cast<Month>(easter_month + 2) ) << ' ' << days_remaining << endl;
    } else{
        //                                       
        cout << "Ascension Day is on " << string_month( static_cast<Month>(easter_month + 1) ) << ' ' << days_remaining << endl;
    }
}

//                                                           
//                                                       
void print_whitsuntide_date( int easter_day, Month easter_month, int year)
{
    //                                      
    int days_remaining = 49;
    //                     
    days_remaining -= number_of_days_in_month( easter_month, year) - easter_day;
    //                                                            
    if (number_of_days_in_month( static_cast<Month>(easter_month + 1), year) < days_remaining){
        //                                    
        days_remaining -= number_of_days_in_month( static_cast<Month>(easter_month + 1), year);
        cout << "Whitsuntide is on " << string_month( static_cast<Month>(easter_month + 2) ) << ' ' << days_remaining << endl;
    } else{
        //                                     
        cout << "Whitsuntide is on " << string_month( static_cast<Month>(easter_month + 1) ) << ' ' << days_remaining << endl;
    }
}

//                                                                                               
//                                                                                                         
//                                                                                                                   
//                                                                                                                       
//                                                                                                  
void show_holy_days ()
{
    int year;
    cout << "Please enter the year for which you want to know the holy days (YYYY)" << endl;
    cin >> year;

    int int_easter_day = easter_day(year);
    Month int_easter_month = easter_month(year);

    print_carnival_date(int_easter_day, int_easter_month, year);
    print_good_friday_date(int_easter_day, int_easter_month, year);
    print_easter_date(int_easter_day, int_easter_month);
    print_ascension_day_date(int_easter_day, int_easter_month, year);
    print_whitsuntide_date(int_easter_day, int_easter_month, year);
}

//                         

//                                                                
int main()
{
    show_holy_days() ;
    return 0;
}

