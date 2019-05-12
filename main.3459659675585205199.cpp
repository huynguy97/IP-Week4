#include <iostream>

using namespace std;
//                             

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
    if(year % 4  == 0)
    {
        if(year % 100 == 0 && year % 400 != 0)
        {
            return false;
        }
        return true;
    }
    return false;
}
//                                                                                                                                                       
int number_of_days_in_month ( int year, Month month )
{
    if(month == 2)
    {
        if(is_leap_year(year))
        {
            return 29;
        }
        return 28;
    }
    if(month == 4 || month == 6 || month == 9 || month == 11 )
    {
        return 30;
    }
    return 31;
}

/*                                                                   
                                                
                                                                   */
//                                                                                                                       
int which_month(int day, int y)
{
    int maand = 1;
    while(day > number_of_days_in_month(y, static_cast<Month> (maand) ))
          {
              day = day - number_of_days_in_month(y, static_cast<Month> (maand));
              maand++;
          }

    return maand;
}
//                                                           
//                                                                                                                                                      
int which_day_in_month(int day, int y)
{
    int maand = 1;
    while(day > number_of_days_in_month(y, static_cast<Month> (maand) ))
          {
              day = day - number_of_days_in_month(y, static_cast<Month> (maand));
              maand++;
          }
    return day;
}
//                                                                                                                      
int easter_day_of_year(int y)

{
    int easter_yearday = 0;
    for(int i = 1 ; i < easter_month(y) ; i++ )
    {
        easter_yearday = easter_yearday + number_of_days_in_month(y, static_cast<Month> (i));
    }
    return easter_yearday + easter_day(y);
}
//                                                                                                          
void show_holy_days()
{
    int y, carnival_day, friday_day, ascension_day, whitsuntide_day;
    cout << "From what year do you want to know the dates of the holy days?" << endl;
    cin >> y;
    int easter_yearday = easter_day_of_year(y);
    cout << "Easter is at : " << easter_month(y) << " - " << easter_day(y) << endl;
    carnival_day = easter_yearday - 49;
    cout << "Carnival is at: " << which_month(carnival_day,y) << " - " << which_day_in_month(carnival_day,y) << " until " << which_month(carnival_day +2, y) << " - " << which_day_in_month(carnival_day + 2 , y) << endl;
    friday_day = easter_yearday - 2;
    cout << "Good Friday is at : " << which_month(friday_day,y) << " - " << which_day_in_month(friday_day, y) << endl;
    whitsuntide_day = easter_yearday + 49;
    cout << "Whitsuntide is at : " << which_month(whitsuntide_day, y) << " - " << which_day_in_month(whitsuntide_day,y) << endl;
    ascension_day = whitsuntide_day - 10;
    cout << "Ascension day is at : " << which_month(ascension_day, y) << " - " << which_day_in_month(ascension_day,y) << endl;
}

int main()
{
    show_holy_days();
    return 0;
}

