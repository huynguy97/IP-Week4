#include <iostream>
/*
                                                              
                                                               
*/
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
    if ( year % 400 == 0)
        return true;
    else if ( year % 100 == 0 )
        return false;
    else if ( year % 4 == 0 )
        return true;
    else
        return false;
}

int number_of_days_in_month ( int year, Month month )
{
int days;
//                                                                                                    
if (is_leap_year(year))
    switch (month)
    {
        case 1:     days=31; break;
        case 2:     days=29; break;
        case 3:     days=31; break;
        case 4:     days=30; break;
        case 5:     days=31; break;
        case 6:     days=30; break;
        case 7:     days=31; break;
        case 8:     days=31; break;
        case 9:     days=30; break;
        case 10:    days=31; break;
        case 11:    days=30; break;
        case 12:    days=31; break;
    }
else
    switch (month)
    {
        case 1:     days=31; break;
        case 2:     days=28; break;
        case 3:     days=31; break;
        case 4:     days=30; break;
        case 5:     days=31; break;
        case 6:     days=30; break;
        case 7:     days=31; break;
        case 8:     days=31; break;
        case 9:     days=30; break;
        case 10:    days=31; break;
        case 11:    days=30; break;
        case 12:    days=31; break;
    }
return days;
}

/*                                                                   
                                                
                                                                   */
void show_holy_days (int year)
{
    int month_e = easter_month(year);
    int base_e, day_e, base_c, day_c, month_c, base_endc, day_endc, month_endc, base_g, day_g, month_g, base_a, day_a, month_a, base_w, day_w, month_w;
    //                                                                                                            
    //                                                           
    switch (month_e)
    {
        case 3:     base_e=59;    break;
        case 4:     base_e=90;    break;
    }
    day_e = base_e + easter_day(year);
    //                                                                                      
    //                                                                                                   
    //                                                                                                  
    //                                                                   
    base_c = day_e - 49;
    base_g = day_e - 3;
    base_w = day_e + 49;
    base_a = day_e + 39;
    base_endc = base_c + 2;
    //                                                             
    if (!is_leap_year(year))
        {
            //                                                                                                    
            //                                                                                                         
            if (base_c > 59 )
            {
                month_c = 3;
                day_c = base_c - 59;
            }

            else
            {
                month_c = 2;
                day_c = base_c - 31;
            }

            if (base_endc > 59 )
            {
                month_endc = 3;
                day_endc = base_endc - 59;
            }
            else
            {
                month_endc = 2;
                day_endc = base_endc - 31;
            }
            if (base_g > 93)
            {
                month_g = 4;
                day_g = base_g - 90;
            }
            else
            {
                month_g = 3;
                day_g = base_g - 59;
            }

            if (base_w > 120 && base_w <= 151)
            {
                month_w = 5;
                day_w = base_w - 120;
            }
            else if (base_w <= 120)
            {
                month_w = 4;
                day_w = base_w - 90;
            }
            else
            {
                month_w = 6;
                day_w = base_w - 151;
            }

            if (base_a <=120)
            {
                month_a = 4;
                day_a = base_a - 90;
            }
            else if (base_a > 120 && base_a <=151)
            {
                month_a = 5;
                day_a = base_a - 120;
            }
            else
            {
                month_a = 6;
                day_a = base_a - 151;
            }

            cout << "In the year " << year << " is:" << endl;
            cout << "Easter on (" << easter_month(year) << "," << easter_day(year) << ")." << endl;
            cout << "Carnival from (" << month_c << "," << day_c << ") until (" << month_endc << "," << day_endc << ")." << endl;
            cout << "Good friday on (" << month_g << "," << day_g << ")." << endl;
            cout << "Ascencion day on (" << month_a << "," << day_a << ")." << endl;
            cout << "Whitsuntide on (" << month_w << "," << day_w << ")." << endl;
        }
    //                                                                                                                  
    else
        {
            if (base_c > 60 )
            {
                month_c = 3;
                day_c = base_c - 59;
            }

            else
            {
                month_c = 2;
                day_c = base_c - 31;
            }

            if (base_endc > 60 )
            {
                month_endc = 3;
                day_endc = base_endc - 59;
            }
            else
            {
                month_endc = 2;
                day_endc = base_endc - 31;
            }
            if (base_g > 94)
            {
                month_g = 4;
                day_g = base_g - 90;
            }

            else
            {
                month_g = 3;
                day_g = base_g - 59;
            }

            if (base_w <= 152)
            {
                month_w = 5;
                day_w = base_w - 120;
            }
            else
            {
                month_w = 6;
                day_w = base_w - 151;
            }

            if (base_a <=121)
            {
                month_a = 4;
                day_a = base_a - 90;
            }
            else if (base_a > 121 && base_a <=152)
            {
                month_a = 5;
                day_a = base_a - 120;
            }
            else
            {
                month_a = 6;
                day_a = base_a - 151;
            }

            cout << "In the year " << year << " is:" << endl;
            cout << "Easter on (" << easter_month(year) << "," << easter_day(year) << ")." << endl;
            cout << "Carnival from (" << month_c << "," << day_c << ") until (" << month_endc << "," << day_endc << ")." << endl;
            cout << "Good friday on (" << month_g << "," << day_g << ")." << endl;
            cout << "Ascencion day on (" << month_a << "," << day_a << ")." << endl;
            cout << "Whitsuntide on (" << month_w << "," << day_w << ")." << endl;
        }
}

int main()
{
    int Y;
    cout << "Choose a year:" << endl;
    cin >> Y;
    cout << endl;
    show_holy_days(Y);
}

