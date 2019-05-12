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
//                                  
//                          
//                      

//                                                                                              
bool is_leap_year ( int year )
{
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            return true ;
        }
        else
        {
            return false ;
        }
    }
    else if (year % 4 == 0 )
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

//                                                                                                         
int number_of_days_in_month ( int year, Month month ) {
    if ((is_leap_year(year)) && (month == February))
    {
        return 29 ;
    }
    else
    {
        switch (month)
        {
        case February:
            return 28;
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December:
            return 31;
            break;
        default:
            return 30;
        }
    }
}
//                                                                                              

/*                                                                   
                                                
                                                                   */
//                                                                                                               
//                                                                               
int paasdag ( int year)
{
//                                                                               
    Month month;
    int t=0;
    int month_no = easter_month(year);
    month_no--;
    while(month_no >= 1)
        {
        month = static_cast<Month> (month_no);
        t= number_of_days_in_month(year, month) + t;
        month_no--;
        }
    t = t + easter_day(year);
    return t;
}

//                                                                                                               
//                                                                                 
int carnaval ( int year)
{
    int c_t = paasdag(year) - 49;
    return c_t;
}

int good_friday( int year )
{
    int gf_t =  paasdag(year) - 2;
    return gf_t;
}
int ascension ( int year )
{
    int a_t = paasdag(year) + 39;
    return a_t;
}
int Whitsuntide (int year)
{
    int w_t = paasdag(year) + 49;
    return w_t;
}

//                                                                                                                    
//                                                                                                                             
//                                                                                                                                   

int calculation(int h, bool q, int year)
{
    int month_no = 1;
    int d = h;
    Month month = January;
    while (d - number_of_days_in_month(year, month) > 0) {
        d = d - number_of_days_in_month(year, month);
        month_no++;
        month = static_cast<Month> (month_no);
    }
    if (d == 0)
    {
        d = number_of_days_in_month(year, month);
    }
    else if (q == true)
    {
        return d;
    }
    else
    {
        return month_no;
    }
}

//                                                                                                                 
//                                                                                                             
//                                   
void show_holy_days (int year)
{

    int c_d = calculation(carnaval(year), true, year); //                                                                      
    int c_m = calculation(carnaval(year), false, year);//                                                

    int gf_d = calculation(good_friday(year), true, year);
    int gf_m = calculation(good_friday(year), false, year);

    int a_d = calculation(ascension(year), true, year);
    int a_m = calculation(ascension(year), false, year);

    int w_d = calculation(Whitsuntide(year), true, year);
    int w_m = calculation(Whitsuntide(year), false, year);

    cout <<"Carnaval will be at: ("<< c_m << ", " << c_d << ")\n";
    cout <<"Good friday will be at: ("<< gf_m << ", " << gf_d << ")\n";
    cout << "Easter will be at: ("<< easter_month(year)<< ", " << easter_day(year) << ")\n";
    cout << "Ascension will be at: ("<< a_m << ", " << a_d << ")\n";
    cout << "Whitsuntide will be at: ("<< w_m << ", " << w_d << ")\n";
}

//                                                                                                                        
//                                                                                            
int main()
{
    cout << "Please insert the year for which you would like to check the dates of holy holidays: \n";
    int year = 0 ;
    cin >> year ;
    cout << "The year you chose is: "<< year<< "\nThe dates will follow. They will be shown in the form (month, day) \n";
    show_holy_days(year);
    return 0;

}

