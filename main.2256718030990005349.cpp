#include <iostream>
/*                         */
using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;

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
    return            (H + L - 7 * M + 114);
}

int easter_day ( int year )
{
    return (easter_base (year) % 31) + 1 ;
}

Month easter_month ( int year )
{
    return static_cast <Month> (easter_base (year) / 31) ;
}
/*                                                                   
                                 
                                                                   */
bool is_leap_year ( int year )
{
    if (year % 4 == 0 || year % 400 == 0 ){
        return true;
    }

    else
        return false;
}

int number_of_days_in_month ( int year, Month month )
{
    switch(month)
    {
        case February: if(is_leap_year(year))
                        {
                            return 29;
                        }

                        else
                            return 28;

        case April:
        case June:
        case September:
        case November:
                        return 30;

        default:        return 31;
    }
}
/*                                                                   
                                                
                                                                   */
int day_number (int year, int day, Month month)
{
    int total_days;
    int day_number;

    if(is_leap_year(year))
    {
        total_days = 366;
    }
    else
        total_days = 365;

    int i = 12;
    while(i >= month && total_days > 0)
    {
        total_days = total_days - number_of_days_in_month(year, (Month) i);
        i--;
    }

    day_number = total_days + day;
    return day_number;
}

int month_number (int year, int day_number)
{
    int totaldays;
    Month month = (Month)1;

    if(is_leap_year(year))
    {
        totaldays = 366;
    }
    else
    {
        totaldays = 365;
    }

    int x;
    x = totaldays - day_number;

    int i = 12;

    while(i >= month && x > 0)
    {
        x = x - number_of_days_in_month(year, (Month) i);
        i--;
    }

    return (Month)(i + 1);
}

void show_holy_days ( int year )
{
    int bunny_day = easter_day(year);
    Month bunny_month = (Month) easter_month(year);
    int dagnummer = day_number(year, bunny_day, bunny_month);
    int maandnummer = month_number(year, (dagnummer));

    cout << "Pasen is dit jaar op " << bunny_day << " / " << bunny_month << endl;
    cout << "Carnaval valt op dag " << dagnummer - 49 << endl;
    cout << "Carnaval valt in de maand " << month_number(year, (dagnummer - 49)) << endl;
    cout << "En op dag " << (dagnummer - 49) - number_of_days_in_month(year, (Month) (maandnummer - 49)) << endl;

    cout << "Pinksteren valt op dag " << dagnummer + 49 << endl;
    cout << "Pinksteren valt in de maand " << month_number(year, (dagnummer + 49)) << endl;
    cout << "En op dag " << (dagnummer + 49) - number_of_days_in_month(year, (Month) (maandnummer + 49)) << endl;

    cout << "Goede Vrijdag valt op dag " << dagnummer - 2 << endl;
    cout << "Goede Vrijdag valt in de maand " << month_number(year, (dagnummer - 2)) << endl;
    cout << "En op dag " << (dagnummer - 2) - number_of_days_in_month(year, (Month) (maandnummer - 2)) << endl;

    cout << "Hemelvaart valt op dag " << dagnummer + 39 << endl;
    cout << "Hemelaart valt in de maand " << month_number(year, (dagnummer + 39)) << endl;
    cout << "En op dag " << (dagnummer + 39) - number_of_days_in_month(year, (Month) (maandnummer + 39)) << endl;

}

int main()
{
    int year;
    int month;
    cout << "Welk jaar wil je weten \n" ;
    cin >> year;
    cout << is_leap_year(year) << endl;
    cout << "Welke maand? \n";
    cin >> month;
    cout << number_of_days_in_month(year, (Month) month) << endl << "Wil je ook de feestdagen weten? Zo ja, vul het jaar opnieuw in! \n";
    cin >> year;
    show_holy_days(year);
    return 0;
}

