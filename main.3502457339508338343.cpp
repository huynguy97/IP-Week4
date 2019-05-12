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
    if (!(year%100) && (year%400)) //                                  
        return false;
    return !(year%4); //               
}

int number_of_days_in_month ( int year, Month month )
{
    switch (month)
    {
        case 2: //         
            if (is_leap_year(year))
                return 29;
            return 28;
        case 4: //      
        case 6: //     
        case 9: //       
        case 11: //         
            return 30;
        default: //                             
            return 31;
    }
}
/*                                                                   
                                                
                                                                   */
//                                                                                    
void print_date_from_day_change(int year, Month month, int day, int day_change)
{
    day += day_change;
    while (day < 1) //                                       
    {
        day += number_of_days_in_month(year, Month(int(month)-1));
        month = Month(int(month)-1);
    }
    while (day > number_of_days_in_month(year, month)) //                                
    {
        day -= number_of_days_in_month(year, month);
        month = Month(int(month)+1);
    }
    cout << day << "/" << month << "/" << year << endl;
    //                                                                        
    //                                                                           
}
void show_holy_days (int Y)
{
    cout << "Carnival starts on ";
    print_date_from_day_change(Y, easter_month(Y), easter_day(Y), -49); //                      
    cout << "Carnival ends on ";
    print_date_from_day_change(Y, easter_month(Y), easter_day(Y), -47); //             
    cout << "Good Friday is on ";
    print_date_from_day_change(Y, easter_month(Y), easter_day(Y), -2); //                     
    cout << "Easter is on " << easter_day(Y) << "/" << easter_month(Y) << "/" << Y << endl;
    cout << "Ascension Day is on ";
    print_date_from_day_change(Y, easter_month(Y), easter_day(Y), 39); //                           
    cout << "Whitsuntide is on ";
    print_date_from_day_change(Y, easter_month(Y), easter_day(Y), 49); //                    
}
int main()
{
    int Y; //     
    cout << "This program outputs the dates of the holy days Easter, Carnival," << endl;
    cout << "Good Friday, Ascension Day and Whitsuntide for a specified year." << endl;
    cout << "Of which year would you like to see the holy days?" << endl;
    cin >> Y;
    cout << endl << "Dates are given in the format day / month / year." << endl;
    show_holy_days(Y);
    return 0;
}

