#include <iostream>

using namespace std;

/*
                                                  

                         

                                                  

                                          
                                          

                                                  
*/

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December};

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
bool is_leap_year (int year)
{
    //                                                                                                              
    return ((year % 4) == 0 && !((year % 100) == 0 && (year % 400) != 0));
}

//                                                             
int number_of_days_in_month (int year, Month month)
{
    switch (month)
    {
        case February:
            if (is_leap_year(year))
                return 29;
            else
                return 28;
        case April:
        case June:
        case September:
        case November:
            return 30;
        default:
            return 31;
    }
}

/*                                                                   
                                                
                                                                   */

//                                                                    
int day_number(int year, Month month, int day)
{
    int output = day;
    for (int i=month-1; i>0; i--) //                                              
        output = output + number_of_days_in_month(year, static_cast<Month>(i));
    return output;
}

//                                         
Month month_from_day_number(int year, int day_num)
{
    Month substract = January;
    while (day_num > number_of_days_in_month(year, substract)) //                                                                                      
    {
        day_num = day_num - number_of_days_in_month(year, substract);
        substract = static_cast<Month>(substract + 1);
    }
    return substract;
}

//                                                    
int day_from_day_number(int year, int day_num)
{
    int output = day_num;
    for (int i=month_from_day_number(year, day_num)-1; i>0; i--) //                                        
        output = output - number_of_days_in_month(year, static_cast<Month>(i));
    return output;
}

//                                                                 
void print_date_from_day_number(int year, int day_num)
{
    cout << day_from_day_number(year, day_num) << "-" << month_from_day_number(year, day_num) << "-" << year;
}

void show_holy_days()
{
    //                          
    int year;
    cout << "Enter the year for which you want to see several Christian holy days: ";
    cin >> year;

    //                                   
    int day_number_of_easter = day_number(year, easter_month(year), easter_day(year));

    //                                  
    cout << "\nCarnival is from ";
    print_date_from_day_number(year, day_number_of_easter-49);
    cout << " until ";
    print_date_from_day_number(year, day_number_of_easter-47);

    cout << "\nGood Friday is on ";
    print_date_from_day_number(year, day_number_of_easter-2);

    cout << "\nEaster is on ";
    print_date_from_day_number(year, day_number_of_easter);

    cout << "\nAscension Day is on ";
    print_date_from_day_number(year, day_number_of_easter+39);

    cout << "\nWhitsuntide is on ";
    print_date_from_day_number(year, day_number_of_easter+49);
}

int main()
{
    show_holy_days();

    return 0;
}

