/*                                                                    
                                                                      
 */

#include <iostream>
#include <cmath>

using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;

//                                          
bool is_leap_year(int year);

/*                                                                          
                                                                            
                                                           
*/
int easter_base(int year)
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
int easter_day(int year)
{
    return (easter_base(year) % 31) + 1;
}

/*                                                                                   
*/
Month easter_month(int year)
{
    return static_cast<Month>(easter_base (year) / 31);
}

/*                                                                           
                                                                          
                                                                         
                                                                              
                                                                          
                                                                              
                                                                          
                                                                              
                                                                            
                                                                           
                                   
 */
int carnival(int year)
{
    int day = easter_day(year) - 49;
    int month = (int)easter_month(year) - 1;

    if (month == 2) {
        if (is_leap_year(year))
            day += 29;
        else
            day += 28;
    } else if (month == 3) {
        day += 31;
    }

    if (day < 0 && month == 3) {
        if (is_leap_year(year))
            day += 29;
        else
            day += 28;
        month -= 1;
    }

    std::cout << month << "-" << day << "-" << year << '\n';
}

/*                                                                             
                                                                            
                                                                        
                                                                              
                                                                               
                                                                           
                                                                            
                                                                             
                                                                               
 */
int good_friday(int year)
{
    int day;
    int month;

    if (easter_day(year) == 2) {
        day = 31;
        month = (int)easter_month(year) - 1;
    } else if (easter_day(year) == 1) {
        day = 30;
        month = (int)easter_month(year) - 1;
    } else {
        day = easter_day(year) - 2;
        month = (int)easter_month(year);
    }

    std::cout << month << "-" << day << "-" << year << '\n';
}

/*                                                                           
                                                                           
                                                                            
                                                                            
                                                                            
                                                                              
                                                                          
                                     
 */
int whitsuntide(int year)
{
    int day = easter_day(year) + 49;
    int month = (int)easter_month(year) + 1;

    if (month == 4) {
        day -= 31;
    } else if (month == 5) {
        day -= 30;
    }

    if (day > 31 && month == 4) {
        day -= 30;
        month += 1;
    } else if (day > 31 && month == 5) {
        day -= 31;
        month += 1;
    }

    std::cout << month << "-" << day << "-" << year << '\n';
}

/*                                                                         
                                                                             
                                                      
 */
int ascension_day(int year)
{
    int day = easter_day(year) + 39;
    int month = (int)easter_month(year) + 1;

    if (month == 4) {
        day -= 31;
    } else if (month == 5) {
        day -= 30;
    }

    if (day > 31 && month == 4) {
        day -= 30;
        month += 1;
    } else if (day > 31 && month == 5) {
        day -= 31;
        month += 1;
    }

    std::cout << month << "-" << day << "-" << year << '\n';
}

/*                                                                   
                                 
                                                                   */
/*                                                                         
                                                                          
                                                                           
 */
bool is_leap_year(int year)
{
    if (year % 4 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 400 == 0)
        return true;
    else
        return false;
}

/*                                                                        
                                                                            
                                                                 
 */
int number_of_days_in_month(int year, Month month)
{
    switch (month) {
        case 1:
            return 31;
            break;
        case 2:
            if (is_leap_year(year))
                return 29;
            else
                return 28;
            break;
        case 3:
            return 31;
            break;
        case 4:
            return 30;
            break;
        case 5:
            return 31;
            break;
        case 6:
            return 30;
            break;
        case 7:
            return 31;
            break;
        case 8:
            return 31;
            break;
        case 9:
            return 30;
            break;
        case 10:
            return 31;
            break;
        case 11:
            return 30;
            break;
        case 12:
            return 31;
            break;
    }
}

/*                                                                   
                                                
                                                                   */
/*                                                             
                     
 */
void show_holy_days(int year)
{
    std::cout << "               MM-DD-YYYY" << '\n';

    std::cout << "Easter:        ";
    std::cout << easter_month(year) << "-" << easter_day(year) << "-" << year << '\n';

    std::cout << "Carnival:      ";
    carnival(year);

    std::cout << "Good Friday:   ";
    good_friday(year);

    std::cout << "Ascension Day: ";
    ascension_day(year);

    std::cout << "Whitsuntide:   ";
    whitsuntide(year);
}

/*                                                                        
                                                                        
                                                                            
 */
int main()
{
    int year;
    std::cout << "What year would you like to see the holy days of?" << '\n';
    std::cin >> year;
    std::cout << '\n';

    show_holy_days(year);

    //                                                                        

    //                                                               
    //                        
    //                                 
    //     
    //                                  

    return 0;
}

