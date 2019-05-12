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

//                                                  
bool is_leap_year ( int year )
{
    double y;

//                                                   
    int x = year/100.00;
    if( (year/100.00 == x) && (year >= 1000))
    {
        y = year/400.00;
    }
    else
    {
        y = year/4.00;
    }

//                                                                                         
    if(y == (int)y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//                                                          
int number_of_days_in_month (int year, int m)
{
    int D;
    switch (static_cast<Month> (m))
    {
        case 1  : D = 31; break;
        case 2  : D = 28; break;
        case 3  : D = 31; break;
        case 4  : D = 30; break;
        case 5  : D = 31; break;
        case 6  : D = 30; break;
        case 7  : D = 31; break;
        case 8  : D = 31; break;
        case 9  : D = 30; break;
        case 10 : D = 31; break;
        case 11 : D = 30; break;
        case 12 : D = 31; break;
    }

//                                               
    if(is_leap_year(year) && (m == 2))
    {

        D = 29;
    }

    return D;
}

//                                    
void days()
{
    int year;
    int m;
    cout << "Choose a year: ";
    cin >> year;
    cout << "Choose a month(1 up to 12): ";
    cin >> m;

    cout << "This month has " << number_of_days_in_month(year, m) << " Days!\n \n";
}

/*                                                                   
                                                
                                                                   */

//                                                            
int month_of_year(int base, int year)
{
    int m;
    if(is_leap_year(year))
    {
        if(base <= 366) m = 12;
        if(base <= 336) m = 11;
        if(base <= 306) m = 10;
        if(base <= 275) m = 9;
        if(base <= 245) m = 8;
        if(base <= 214) m = 7;
        if(base <= 183) m = 6;
        if(base <= 153) m = 5;
        if(base <= 122) m = 4;
        if(base <= 92)  m = 3;
        if(base <= 61)  m = 2;
        if(base <= 31)  m = 1;
    }
    else
    {
        if(base < 365) m = 12;
        if(base < 335) m = 11;
        if(base < 305) m = 10;
        if(base < 274) m = 9;
        if(base < 244) m = 8;
        if(base < 213) m = 7;
        if(base < 182) m = 6;
        if(base < 152) m = 5;
        if(base < 121) m = 4;
        if(base < 91) m = 3;
        if(base < 60) m = 2;
        if(base < 31) m = 1;
    }

    return m;

}

//                                                                       
int day(int base, int year)
{

    int m = month_of_year(base, year);
    int day;
    if(is_leap_year(year))
    {
        switch(m)
        {
            case 1  : day = base; break;
            case 2  : day = base - 31; break;
            case 3  : day = base - 60; break;
            case 4  : day = base - 91; break;
            case 5  : day = base - 122; break;
            case 6  : day = base - 152; break;
            case 7  : day = base - 182; break;
            case 8  : day = base - 213; break;
            case 9  : day = base - 244; break;
            case 10 : day = base - 274; break;
            case 11 : day = base - 305; break;
            case 12 : day = base - 335; break;
        }
    }
    else
    {
        switch(m)
        {
            case 1  : day = base; break;
            case 2  : day = base - 31; break;
            case 3  : day = base - 59; break;
            case 4  : day = base - 90; break;
            case 5  : day = base - 120; break;
            case 6  : day = base - 151; break;
            case 7  : day = base - 181; break;
            case 8  : day = base - 212; break;
            case 9  : day = base - 243; break;
            case 10 : day = base - 273; break;
            case 11 : day = base - 304; break;
            case 12 : day = base - 334; break;
        }
    }
    return day;
}

//                                                                     
int easter (int day, int month, int year)
{
    int d;
    if(is_leap_year(year))
    {
          switch(month)
        {
            case 1  : d = day; break;
            case 2  : d = day + 31; break;
            case 3  : d = day + 60; break;
            case 4  : d = day + 91; break;
            case 5  : d = day + 121; break;
            case 6  : d = day + 152; break;
            case 7  : d = day + 182; break;
            case 8  : d = day + 213; break;
            case 9  : d = day + 244; break;
            case 10 : d = day + 274; break;
            case 11 : d = day + 305; break;
            case 12 : d = day + 335; break;
        }
    }
    else
    {
        switch(month)
        {
            case 1  : d = day; break;
            case 2  : d = day + 31; break;
            case 3  : d = day + 59; break;
            case 4  : d = day + 90; break;
            case 5  : d = day + 120; break;
            case 6  : d = day + 151; break;
            case 7  : d = day + 181; break;
            case 8  : d = day + 212; break;
            case 9  : d = day + 243; break;
            case 10 : d = day + 273; break;
            case 11 : d = day + 304; break;
            case 12 : d = day + 334; break;
        }
    }
    return d;
}

//                                     
void show_holy_days ()
{
    int y;
    cout << "Choose a year: ";
    cin >> y;
    int dayy = easter_day(y);
    int month = easter_month(y);
    int D = easter(dayy, month, y);

    int carnaval    = D - 49;
    int good_friday = D - 2;
    int ascension   = D + 39;
    int whitsuntide = D + 49;

    cout << "In " << y << "\n";
    cout << "Carnaval is on day " << day(carnaval, y) << " of month " << month_of_year(carnaval, y) << "\n";
    cout << "Good friday is on day " << day(good_friday, y) << " of month "  << month_of_year(good_friday, y) << "\n";
    cout << "Ascension day is on day " << day(ascension, y) << " of month " << month_of_year(ascension, y) << "\n";
    cout << "Whitsuntide is on day " << day(whitsuntide, y) << " of month " << month_of_year(whitsuntide, y) <<"\n";

}

int main()
{

    days();
    show_holy_days ();
    return 0;
}

