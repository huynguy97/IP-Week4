#include <iostream>

using namespace std;

int year;

int x=0;

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

/*                                                                   
                                 
                                                                   */
bool is_leap_year ( int year )
{
    if (year%4==0)
    {
        if(year%100==0)
            {
                if (year%400==0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        else
        {
             return true;
        }
    }
    else
    {
        return false;
    }

}

int number_of_days_in_month ( int year, Month month )
{
    if(month==2)
    {
        if (is_leap_year(year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    if (month<8)
    {
        if (month%2==0)
        {
            return 30;
        }
        else
        {
            return 31;
        }
    }
    else
    {
        if (month%2==0)
        {
            return 31;
        }
        else
        {
            return 30;
        }
    }

}

/*                                                                   
                                                
                                                                   */
void minusdays(int year, int day, int month, int min, string name)
{

    if (day>min)
    {
        day = day-min;
    }
    else
    {
        month--;
        day=number_of_days_in_month(year, (Month(month)))-(min-day);
    }
    cout << "the date of "<< name <<" of the year " << year << " is: " <<day<< "-"<< Month(month) <<"-"<< year << endl;

}

void show_holy_days (int year)
{
    int carnival_day=easter_day(year);
    int carnival_month;
    int weeks=7;

    if(easter_month(year)==(Month(3)))
    {
        carnival_month = 3;
    }
    else
    {
        carnival_month = 4;
    }
    while(weeks>0)
    {
        if (carnival_day>7)
        {
            carnival_day= carnival_day-7;
        }
        else
        {
            carnival_month--;
            carnival_day=number_of_days_in_month(year, (Month(carnival_month)))-(7-carnival_day);
        }
        weeks--;
    }

    cout << "the date of Carnival of the year " << year << " is: " <<carnival_day<<"-" << Month(carnival_month)<<"-"<< year << endl;

    int goodfriday_day=easter_day(year);
    int goodfriday_month = easter_month(year);

    minusdays(year, goodfriday_day, goodfriday_month, 2, "Good friday");

    int whitsuntide_month;
    int whitsuntide_day= easter_day(year);
    weeks=7;

    if(easter_month(year)==(Month(3)))
    {
        whitsuntide_month = 3;
    }
    else
    {
        whitsuntide_month = 4;
    }
    while(weeks>0)
    {
        if (whitsuntide_day<(number_of_days_in_month(year, (Month(whitsuntide_month)))-7))
        {
            whitsuntide_day= whitsuntide_day+7;
        }
        else
        {

            whitsuntide_day=1+(6-(number_of_days_in_month(year, Month(whitsuntide_month))-whitsuntide_day));
            whitsuntide_month++;
        }
        weeks--;
    }

    cout << "the date of Whitsuntide of the year " << year << " is: " <<whitsuntide_day<< "-"<< Month(whitsuntide_month) <<"-"<< year<< endl;

    int ascensionday_day=whitsuntide_day;
    int ascensionday_month=whitsuntide_month;

    minusdays(year, ascensionday_day, ascensionday_month, 10, "Ascensionday");

}

int main()
{
    while(x<1)
    {
        cout << "welcome, enter a year" << endl;
        cin >> year;
        show_holy_days(year);

    }
}

