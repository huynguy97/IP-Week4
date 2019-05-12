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

bool is_leap_year ( int year )
{
     if (year%100 == 0)
    {
        if (year%400==0)        //                                                                 
            return true;
        else
            return false;
    }
    else
    {
        if (year%4==0)          //                                                                         
            return true;
        else
            return false;
    }
}

int number_of_days_in_month ( int year, Month month )
{
    if (month == 2)
    {
        if (is_leap_year(year))         //                                                                 
            return 29;
        else
            return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) //                      
        return 30;
    else
        return 31;      //                        
}

/*                                                                   
                                                
                                                                   */
void show_holy_days (int year)
{
    int e=easter_day(year);
    int m=easter_month(year);
    int nfebruary= number_of_days_in_month (year, February); //                                                                               
    if (m==3)           //         
    {
        int Carnaval_day = e+nfebruary-49;
        int Carnaval_month = 2;
        cout << "Carnival \t(" << Carnaval_month << ", " << Carnaval_day << ")" << endl;
    }
    else if (m==4 && e>18)
    {
        int Carnaval_day = e-18;
        int Carnaval_month = 3;
        cout << "Carnival \t(" << Carnaval_month << ", " << Carnaval_day << ")" << endl;
    }
    else
    {
        int Carnaval_month = 2;
        int Carnaval_day = e+nfebruary-18;
        cout << "Carnival \t(" << Carnaval_month << ", " << Carnaval_day << ")" << endl;
    }                                                                                       //                                                                                      
    if (2<e)                                                                                //                                                                                               
    {
        int Good_friday_day = e-2;
        int Good_friday_month = m;
        cout << "Good Friday \t(" << Good_friday_month << ", " << Good_friday_day << ")" << endl;
    }
    else
    {
        int Good_friday_month = m-1;
        int Good_friday_day = 31+e-2;
        cout << "Good Friday \t(" << Good_friday_month << ", " << Good_friday_day << ")" << endl;
    }                                                                                       //                              
    cout << "Easter \t\t(" << m << ", " << e << ")" << endl;
    if (m==3)
    {
        int Ascention_month = 5;
        int Ascention_day = e-22;
        cout << "Ascension Day \t(" << Ascention_month << ", " << Ascention_day << ")" << endl;
    }
    else if (m==4 && e<23)
    {
        int Ascention_month = 5;
        int Ascention_day = e+9;
        cout << "Ascension Day \t(" << Ascention_month << ", " << Ascention_day << ")" << endl;
    }
    else
    {
        int Ascention_month = 6;
        int Ascention_day = e-22;
        cout << "Ascension Day \t(" << Ascention_month << ", " << Ascention_day << ")" << endl;
    }                                                                                          //                                
    if (m==3)
    {
        int Whitsuntide_month = 5;
        int Whitsuntide_day = e-12;
        cout << "Whitsuntide \t(" << Whitsuntide_month << ", " << Whitsuntide_day << ")" << endl;
    }
    else if (m==4 && e<13)
    {
        int Whitsuntide_month = 5;
        int Whitsuntide_day = e+19;
        cout << "Whitsuntide \t(" << Whitsuntide_month << ", " << Whitsuntide_day << ")" << endl;
    }
    else
    {
        int Whitsuntide_month = 6;
        int Whitsuntide_day = e-12;
        cout << "Whitsuntide \t(" << Whitsuntide_month << ", " << Whitsuntide_day << ")" << endl;
    }                                                                                            //                              
}

int main()
{
    cout << "What year do you want the holidays of?" << endl;
    int year;
    cin >> year;
    cout << "\t\t(Month,Day)" << endl;
    show_holy_days(year);
    return 0;
}

