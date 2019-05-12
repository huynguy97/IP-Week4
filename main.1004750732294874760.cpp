#include <iostream>
#include <stdio.h>
#include <string.h>
#include <tuple>

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
const int days_month [2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
                                {0,31,29,31,30,31,30,31,31,30,31,30,31}}    ;

bool is_leap_year ( int year )
{
    int a,b,c; //             
    a=year/4; //                                                                                
    b=year/400;
    c=year/100;
    if (b*400 == year) //                                                                                 
    {
        return true;
    }
    else
    {
        if (((c*100) == year) || ((a*4) != year))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

int number_of_days_in_month ( int year, Month month )
{
    bool leap_y;
    leap_y=is_leap_year(year);//                                         
    if (leap_y==true) //                                                                                                 
    {
        return days_month[1][month];
    }
    else //                                 
    {
        return days_month[0][month];
    }
}

/*                                                                   
                                                
                                                                   */

std::tuple<int,int>totaldays_to_m_d (int days,int year) //                                                                                                                
{
    int i, maand;
    if (is_leap_year(year)==true) //                                                                                         
    {
        for (i=1; days> days_month[1][i];i=i+1) //                                                                                                           
        {
            days=days-days_month[1][i]; //                                                         
            maand=i+1;
        }
        return make_tuple(maand,days); //                              
    }
    else
    {
        for (i=1; days> days_month[0][i];i=i+1) //                                      
        {
            days=days-days_month[0][i];
            maand=i+1;
        }
        return make_tuple(maand,days);
    }
}

int m_d_to_totaldays (int year) //                                                                                 
{
    int easterday,i,eday,emonth;
    eday=easter_day(year);
    emonth=easter_month(year);
    if (is_leap_year(year)==true) //                                                           
    {
        easterday=eday;
        for (i=1; i<emonth ;i=i+1)
        {
            easterday=easterday+days_month[1][i];
        }
    }
    else //                                   
    {
        easterday=eday;
        for (i=1; i<emonth ;i=i+1)
        {
            easterday=easterday+days_month[0][i];
        }
    }
    return easterday;
}

//                                                                                                       
void display_dates (int CS_M, int CS_D, int CF_M, int CF_D, int GF_M, int GF_D, int WST_M, int WST_D, int ACD_M, int ACD_D, int ED1_M, int ED1_D, int ED2_M, int ED2_D, int year)
{
    cout << "Carnival" << "\t" <<  CS_D << "-" << CS_M << " until " << CF_D << "-" << CF_M << "\t" << " in " << year << endl;
    cout << "Good Friday" << "\t" << GF_D << "-" << GF_M << "\t\t" << " in " << year << endl;
    cout << "Easter days" << "\t" <<  ED1_D << "-" << ED1_M << " and " << ED2_D << "-" << ED2_M << "\t" << " in " << year << endl;
    cout << "Ascensionday" << "\t" << ACD_D << "-" << ACD_M << "\t\t" << " in " << year << endl;
    cout << "Whitsuntide" << "\t" << WST_D << "-" << WST_M << "\t\t" << " in " << year << endl;
}
void show_holy_days (int year)
{
    int eday,emonth,totaldays,easterday,i,carnival_start,carnival_finish,good_friday,whitsuntide,ascensionday,easter_day1,easter_day2;
    easterday=m_d_to_totaldays(year);
    int CS_M, CS_D, CF_M, CF_D, GF_M, GF_D, WST_M, WST_D, ACD_M, ACD_D, ED1_M, ED1_D, ED2_M, ED2_D; //                     
    //                                                                
    easter_day1= easterday;
    easter_day2= easterday+1;
    carnival_start= easterday-49;
    carnival_finish= easterday-47;
    good_friday= easterday-2;
    whitsuntide= easterday+49;
    ascensionday= whitsuntide-10;
    //                                                 
    tie (CS_M,CS_D)= totaldays_to_m_d(carnival_start, year);
    tie (CF_M,CF_D)= totaldays_to_m_d(carnival_finish, year);
    tie (GF_M,GF_D)= totaldays_to_m_d(good_friday, year);
    tie (WST_M,WST_D)= totaldays_to_m_d(whitsuntide, year);
    tie (ACD_M,ACD_D)= totaldays_to_m_d(ascensionday, year);
    tie (ED1_M,ED1_D)= totaldays_to_m_d(easter_day1, year);
    tie (ED2_M,ED2_D)= totaldays_to_m_d(easter_day2, year);
    //                                     
    display_dates(CS_M, CS_D, CF_M, CF_D, GF_M, GF_D, WST_M, WST_D, ACD_M, ACD_D, ED1_M, ED1_D, ED2_M, ED2_D, year);
}

int main()
{
    int year, days, number;
    bool leap_year;
    cout << "Enter a year: " << endl;
    cin >> year;
    while (number<1 || number>12) //             
    {
        cout << "Enter a month: (1-12)" << endl;
        cin >> number;
    }
    Month M = static_cast<Month>(number); //                        
    leap_year = is_leap_year(year);
    days = number_of_days_in_month(year, M);
    //                                                                                 
    if (leap_year == true)
    {
        cout << year << " is a leap year, so month " << M << " has " << days << " days" << endl;
    }
    else
    {
        cout << year << " is not a leap year, so month " << M << " has " << days << " days" << endl;
    }
    show_holy_days(year);
    return 0;
}

