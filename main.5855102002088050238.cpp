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
    //                                               
    if(year % 4 != 0)
        return false;

    //                                                                    
    if(year % 100 == 0 && year % 400 != 0)
        return false;

    //                      
    return true;
}

int number_of_days_in_month ( int year, Month month )
{
    //                         
    bool leap = is_leap_year(year);

    //                                                                
    if(month == February)
        return (leap) ? 29 : 28;

    //                                                                    
    if(month < 7){
        return (month % 2 == 0) ? 30 : 31;
    }
    else{
        return (month % 2 == 0) ? 31 : 30;
    }
}

/*                                                                   
                                                
                                                                   */

//                                             
void print_day(int title, int dayChange, int year){
    //             
    switch(title){
        case 1: cout << "GOOD FRIDAY" << endl; break;
        case 2: cout << "ASCENSION DAY" << endl; break;
        case 3: cout << "WHITSUNTIDE" << endl; break;
    }

    //                                                           
    int day = easter_base(year) + dayChange;

    //                                                    
    int month = day/31;
    int extraDay = ((title == 0 || title == 2) ? 1 : 2);
    int dayInMonth = (day % 31) + extraDay;

    //                      
    cout << "Month = " << month << " | Day = " << dayInMonth << endl;

    //                                       
    if(title != 0)
        cout << "\n" << endl;
}

//                                            
void show_carnaval(int year){
    //                       
    cout << "CARNAVAL" << endl;

    //                                    
    for(int i = 0; i < 3; i++){
        int day = - (7 * 7) + i;

        print_day(0, day, year);
    }
}

//                        
void show_holy_days (int year)
{
    show_carnaval(year);
    cout << "\n" << endl;
    print_day(1, -2, year);
    print_day(2, (7 * 7) - 9, year);
    print_day(3, (7 * 7), year);
}

int main()
{
    //              
    int year = -1;

    //                       
    do{
        cout << "ENTER A YEAR" << endl;
        cin >> year;
    }
    while(year < 0);

    //                                    
    show_holy_days(year);

    return 0;
}

