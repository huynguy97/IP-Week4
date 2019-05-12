/*

                                                   

                                            
                                              

*/

#include <iostream>
#include <string>

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
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

//                                                        
int number_of_days_in_month ( int year, Month month )
{
    switch (month) {
        //                                        
        case January: case March: case May: case July: case August: case October: case December:
            return 31;
        case February: //                               
            return is_leap_year(year) ? 29 : 28;
        default: //                                 
            return 30;
    }
}
/*                                                                   
                                                

                                                                    */
int day;   //                                                                       
int month;
int endday;
int endmonth;

enum HolyDay { Carnaval= -49, GoodFriday = -2, AscensionDay = 39, Whitsuntide = 49 }; //                                                                                  

void show_holy_days(int year, HolyDay sub) {
    int i = easter_month(year) - 1; //                                                                                             
    day = easter_day(year);

    for (int a = 1; a <= i; ++a) {
        day += number_of_days_in_month(year, static_cast<Month>(a)); //                                                                               
    }
    day = day + sub; //                                                  
    month = 1;
    while (day > number_of_days_in_month(year, static_cast<Month>(month))) {
        day -= number_of_days_in_month(year, static_cast<Month>(month)); //                                                               
        month++; //                                                                                  
    }

    if (sub == Carnaval) { //                                                              
        endday = day + 2;
        endmonth = month;
        if (endday > number_of_days_in_month(year, static_cast<Month>(month))) { //                                                      
            endmonth = month + 1;
            endday -= number_of_days_in_month(year, static_cast<Month>(month));

        }
    }
}

int main()
{
    int year, inputMonth;

    do {
        cout << "Please enter the year to check (> 0):" << endl;
        cin >> year;
    } while (year <= 0); //                       

    cout << "Year " << year << (is_leap_year(year) ? " is" : " is not") << " a leap year." << endl << endl;

    do {
        cout << "Please enter the month to check (1-12):" << endl;
        cin >> inputMonth;
    } while (inputMonth < 1 || inputMonth > 12); //                                

    cout << "Month " << inputMonth << " in year " << year << " has " << number_of_days_in_month(year, static_cast<Month>(inputMonth)) << " days." << endl << endl;

    cout << "Easter is on date " << easter_day(year) << "/" << easter_month(year) << endl;
    show_holy_days(year, Carnaval);
    cout << "Carnaval is on date " << day << "/" << month << " and ends on date "<< endday << "/" << endmonth << endl;
    show_holy_days(year, GoodFriday);
    cout << "Good Friday is on date " << day << "/" << month << endl;
    show_holy_days(year, AscensionDay);
    cout << "Ascension Day is on date " << day << "/" << month << endl;
    show_holy_days(year, Whitsuntide);
    cout << "Whitsuntide is on date " << day << "/" << month << endl;

    //                                                                                     
    return 0;
}

