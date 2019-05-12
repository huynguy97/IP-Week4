#include <iostream>

//                                 
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
bool is_leap_year ( int year )
{
    if ((year%4 == 0 && year%100 != 0) || (year%100 == 0 && year%400 == 0 )) //                                                                             
    {
        return (true);
    }
    return(false);
}

int number_of_days_in_month ( int year, Month month )
{
    switch(month) //                                                             
    {
        case January: return 31;
        case February:
            {
                if (is_leap_year(year))     //                                      
                {
                    return (29);
                }
                return (28);
            }
        case March: return(31);
        case April: return(30);
        case May: return(31);
        case June: return(30);
        case July: return(31);
        case August: return(31);
        case September: return(30);
        case October: return(31);
        case November: return(30);
        case December: return(31);
    }

}

/*                       
                                                
                       */

int numday_to_month(int nday, int year)
{
    int month = 1, i = 1;                                                       //                                                                 
    while (nday > number_of_days_in_month (year, static_cast<Month>(i)))
    {
        month++;
        nday -= number_of_days_in_month (year, static_cast<Month>(i));
        i++;
    }
    return (month);
}
int numday_to_day(int nday, int year)                                           //                                                                                      
{
    int i = 1;
    while (nday > number_of_days_in_month (year, static_cast<Month>(i)))
    {
        nday -= number_of_days_in_month (year, static_cast<Month>(i));
        i++;
    }
    return (nday);
}

void show_holy_days ()
{
    int year,e_day_num,e_month;
    int c_month, gf_month, w_month, ad_month;
    int c_day, gf_day, w_day, ad_day;

    cout << "Choose a year" << endl;
    cin >> year;                                    //           

    e_day_num = easter_day(year);                           //                         
    e_month = static_cast<int>(easter_month(year));         //            
    for (int i=0 ; i<e_month; i++)                              //                                                                   
    {
        e_day_num += number_of_days_in_month(year,static_cast<Month>(i));
    }
    int c_day_num = e_day_num - 49;                 //                                  
    int gf_day_num = e_day_num - 2;
    int w_day_num = e_day_num + 49;
    int ad_day_num = w_day_num - 10;

    c_month = numday_to_month(c_day_num, year);             //                  
    gf_month = numday_to_month(gf_day_num, year);
    w_month = numday_to_month(w_day_num, year);
    ad_month = numday_to_month(ad_day_num, year);

    c_day = numday_to_day(c_day_num, year);                 //                
    gf_day = numday_to_day(gf_day_num, year);
    w_day = numday_to_day(w_day_num, year);
    ad_day = numday_to_day(ad_day_num, year);

    cout<< "Easter date: " << easter_day(year) << "-" << e_month << "-" << year << endl;                                                    //             
    cout<< "Carnaval date: " << c_day << "-" << c_month << "-" << year << " -- " << c_day+2 << "-" << c_month << "-" << year <<  endl;
    cout<< "Good Friday date: " << gf_day << "-" << gf_month << "-" << year << endl;
    cout<< "Whitsuntide date: " << w_day << "-"  << w_month << "-" << year << endl;
    cout<< "Ascension day date: " << ad_day << "-" << ad_month << "-" << year << endl;

}

int main()
{
    show_holy_days() ;
    return 0;
}

