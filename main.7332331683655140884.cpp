//                     
//                        
#include <iostream>
#include <math.h>
#include <stdlib.h>

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
    if (year%100==0)
    {
        if(year%400==0) return true;
        else return false;
    }
    else
    {
        if (year%4==0) return true;
        else return false;
    }
}

int number_of_days_in_month ( int year, Month month )
{
    //                                                           

    int day [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(is_leap_year(year)) day[1]= 29;

    return day[month-1];
}

int daynumber (int year, Month month, int day)
{
    //                                                                      

    int days=0;

    for (int i=0; i<month-1; i++) days += number_of_days_in_month(year, static_cast<Month>(i+1));

    return days +day;
}

int day_in_month(int year, int day)
{
    //                                                                                                                
    int i = 1;

    while (day > 0 )
    {
        day -= number_of_days_in_month(year, static_cast<Month>(i));
        i++;
    }
    return day += number_of_days_in_month(year, static_cast<Month>(i-1));
}

int month_in_year(int year, int day)
{
    //                                                                                                                        
    int i = 1;
    while (day > 0 )
    {
        day -= number_of_days_in_month(year, static_cast<Month>(i));
        i++;
    }
    return i-2;
}

/*                                                                   
                                                
                                                                   */
void show_holy_days (int year)
{
    //                                

    int easterday = daynumber(year, easter_month(year), easter_day(year));

    int carnivalday = easterday - 49;
    int goodfriday = easterday - 2;
    int whitsuntide = easterday + 49;
    int ascensionday = whitsuntide - 10;

    cout << "Holiday starts on: day - month - year" << endl;
    cout << "Carnavalday starts on: " <<  day_in_month(year, carnivalday) << "-" <<month_in_year(year, carnivalday)+1 <<"-"<<year<< endl;
    cout << "Goodfriday starts on: " <<  day_in_month(year, goodfriday) << "-" <<month_in_year(year, goodfriday)+1 <<"-"<<year<< endl;
    cout << "Whitsuntide starts on: " <<  day_in_month(year, whitsuntide) << "-" <<month_in_year(year, whitsuntide)+1 <<"-"<<year<< endl;
    cout << "Ascensionday starts on: " <<  day_in_month(year, ascensionday) << "-" <<month_in_year(year, ascensionday)+1 <<"-"<<year<< endl;

    }

/*                                                                   
                                      
                                                                   */

void show_month(int year, Month month)
{
    //                                               

    int easterday = easter_day(year);
    Month eastermonth = easter_month(year);
    int easterdaynumber = daynumber(year, eastermonth, easterday);

    int firstdate = daynumber(year, month, 1);
    int difference;

    difference = (easterdaynumber-firstdate)%7; //                                                                                                                                       
    if (difference< 0 ) difference += 7;

    int number_of_tabs = 6 - difference;

    cout << " ma\t di\t wo\t do\t vr\t za\t zo\t" <<  endl;

    int j=number_of_tabs;

    for (int i=1; i<= number_of_days_in_month(year, month); i++) //                                
    {
        while (number_of_tabs>0)
        {
            cout << " \t";
            number_of_tabs--;
        }
        cout << i << "\t";

        if ((i+j)%7==0) cout << endl;

    }
    cout << endl;
    return;

}

int main()
{
    int year;
    int month;

   cout << "Enter a year: " << endl;
   cin >> year;
   cout << "Enter a month: " << endl;
   cin >> month;
    cout << endl;

    show_month(year, static_cast<Month>(month)); //                
    cout << endl;
    show_holy_days(year); //                    

    return 0;
}

