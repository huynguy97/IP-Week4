#include <iostream>

using namespace std;

//              
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
bool is_leap_year ( int year )
{
    if (year%4==0)
        return true ;
    else
        return false ;
}

int number_of_days_in_month ( int year, Month month )
{
    if (is_leap_year(year))
    {
        switch (month)
        {
            case January :
                return 31;
            case February :
                return 29;
            case March :
                return 31;
            case April :
                return 30;
            case May :
                return 31;
            case June :
                return 30;
            case July :
                return 31;
            case August :
                return 31;
            case September :
                return 30;
            case October :
                return 31;
            case November :
                return 30;
            case December :
                return 31;
        }
    }
    else
        switch (month)
        {
            case January :
                return 31;
            case February :
                return 28;
            case March :
                return 31;
            case April :
                return 30;
            case May :
                return 31;
            case June :
                return 30;
            case July :
                return 31;
            case August :
                return 31;
            case September :
                return 30;
            case October :
                return 31;
            case November :
                return 30;
            case December :
                return 31;
        }

}

/*                                                                   
                                                
                                                                   */
void date_easter(int year)
{
    int y = easter_day (year) ;
    int z = easter_month (year) ;
    cout << "The date for Easter is " << y << "/" << z << "/" << year <<endl ;
}

void date_carnival (int year)
{
    int ya = ((easter_base (year)-49) % 31) + 1 ;
    int za = static_cast<Month> ((easter_base (year)-49) / 31) ;
    if (!is_leap_year(year))
        cout << "The date for Carnival is " << ya-3 << "/" << za << "/" << year << endl ;
    else
        cout << "The date for Carnival is " << ya-2 << "/" << za << "/" << year << endl ;
}

void date_good_friday (int year)
{
    int yb = ((easter_base (year)-3) % 31) + 1 ;
    int zb = static_cast<Month> ((easter_base (year)-3) / 31) ;
    if (!is_leap_year(year))
        cout << "The date for Good friday is " << yb+1 << "/" << zb << "/" << year << endl ;
    else
        cout << "The date for Good friday is " << yb+1 << "/" << zb << "/" << year << endl ;
}

void date_ascension_day (int year)
{
    int yc = ((easter_base (year)+39) % 31) + 1 ;
    int zc = static_cast<Month> ((easter_base (year)+39) / 31) ;
    if (!is_leap_year(year))
        cout << "The date for Ascension day is " << yc+1 << "/" << zc << "/" << year << endl ;
    else
        cout << "The date for Ascension day is " << yc+1 << "/" << zc << "/" << year << endl ;
}

void date_whitsuntide (int year)
{
    int yd = ((easter_base (year)+49) % 31) + 1 ;
    int zd = static_cast<Month> ((easter_base (year)+49) / 31) ;
    if (!is_leap_year(year))
        cout << "The date for Whitsuntide is " << yd+1 << "/" << zd << "/" << year << endl ;
    else
        cout << "The date for Whitsuntide is " << yd+1 << "/" << zd << "/" << year << endl ;
}

void show_holy_days ()
{
    int year ;
    cin >> year ;
    date_carnival(year);
    date_good_friday(year) ;
    date_easter(year) ;
    date_ascension_day(year) ;
    date_whitsuntide(year) ;
}

int main()
{
    cout << "Input a year to see all holy cristian days." << endl ;
    show_holy_days() ;
    return 0;
}
