#include <iostream>

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
    int leap_year;
    int i;
    int y;

    cout << "Give year:" ;
    cin >> y;

    for (int i = 1; i <= y; ++i)
    {
        int leap_year = year / 400;
        leap_year = year / 4;
    }
    return year;
}

int number_of_days_in_month ( int year, Month month )
{
    int days;
    int x = 0;
    int m = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);

    if(m = 1, 3, 5, 7, 8, 10, 12)
    {
        x = 31;
    }

    int days_in_month(int year);

    if(m = 4, 6, 9, 11)
    {
        x = 30;
    }

    if(m ==2)
    {
        if(is_leap_year)
        {
            x = 29;
        }
        else
        {
            x = 28;
        }
    }

    return 0;
}

/*                                                                   
                                                
                                                                   */
void show_holy_days ()
{
    if(is_leap_year(int year))
    {
        int easter_day(int year);
        int easter_month(int year);
    }
    else
    {
        int easter_day(int year);
        int easter_month(int year);
    }

}

int main()
{
    show_holy_days() ;
    return 0;
}

