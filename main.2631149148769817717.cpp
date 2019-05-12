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

bool is_leap_year (int year)
{
    int c =    year%4;

    int a =  year%100;
if (a == 0)
{
      int b =  year%400;
      if (b == 0 && c ==0)
        return true;
      else return false;
}
if (c==0)
    return true;
else return false;
}

int number_of_days_in_month ( int year, Month month )
{
    switch (month)
    {
        case January : return 31 ; break;

        case February :
            if (is_leap_year(year)) return 29;
                else return 28; break;

        case March: return  31 ;
        case April : return  30 ;
        case May : return  31 ;
        case June : return  30 ;
        case July : return  31 ; break;
        case August : return  31 ;
        case September : return  30 ;
        case October : return  31 ;
        case November : return  30 ;
        case December : return  31 ;

    }

}

/*                                                                   
                                                
                                                                   */
int whitsuntide(int year)
{
int month = easter_month(year);
int day = easter_day(year);
int aantal_dagen = 0;

  int e =         number_of_days_in_month(year, January);
  int f =         number_of_days_in_month(year, February);
  int g =          number_of_days_in_month(year, March);
  int h =          number_of_days_in_month(year, April);
  int i =          number_of_days_in_month(year, May);
  int j =          number_of_days_in_month(year, June);
  int k =          number_of_days_in_month(year, July);
  int l =          number_of_days_in_month(year, August);
  int m =          number_of_days_in_month(year, September);
  int n =          number_of_days_in_month(year, October);
  int o =          number_of_days_in_month(year, November);
  int p =          number_of_days_in_month(year, December);

  if (month = 2)
    aantal_dagen = day + e;
if (month = 3)
    aantal_dagen = day + e + f;
if (month = 4)
    aantal_dagen = day + e + f + g;
if (month = 5)
    aantal_dagen = day + e + f + g + h;
if (month = 6)
    aantal_dagen = day + e + f + g + h + i;
//                                      
int the_date_of_whitsuntide = aantal_dagen + 49; //                                          

return the_date_of_whitsuntide;
}
void show_holy_days ()
{

int whitsuntide(int year);
}
/*
           
 
                             
              
                

                                  
                               

                                                    
                      
             
 
*/

int main()
{

    cout << "enter a year:" ;
    int year ;
    cin >> year;

    int month = easter_month(year);
    int day = easter_day(year);

    show_holy_days() ;

    if (is_leap_year(year))
    {
         cout << "year is a leap year" << endl;
            }else
            {
                 cout << "year is not a leap year" << endl;
            }
            int banaan();
{
    for(int d = 1; d <= 12; d = d+ 1)
    {
    cout << "Month: " << d << '\t' << "number of days in this month: " << number_of_days_in_month ( year, static_cast<Month> (d) ) << endl;
    }
    cout << "eastern date:" << month << '\t' << day << endl;

    return 0;
}

}

