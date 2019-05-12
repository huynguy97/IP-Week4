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
//                       
//                        

/*                                                                   
                                 
                                                                   */
bool is_leap_year ( int year )
{
cout << "Input year " ;
cin >> year ;
if ((year % 400) == 0) { return true ;}
else if ((year % 100) == 0) { return false ;}
else if  ((year % 4) == 0) { return true ;}
else { return false;}

}

int number_of_days_in_month ( int year, Month month)
{

switch (month)

{
    case January    : return 31;
    case February   : if (is_leap_year(year)== 0) {return 28;} else {return 29;}
    case March      : return 31;
    case April      : return 30;
    case May        : return 31;
    case June       : return 30;
    case July       : return 31;
    case August     : return 31;
    case September  : return 30;
    case November   : return 30;
    case December   : return 31;

}
}

/*                                                                   
                                                
                                                                   */
void show_holy_days ()
{
    int year ;
      int daynumber ;
   Month easter_month;
   int easter_day;
      if (is_leap_year(year)== 0) {
            if (easter_month == 3){
                daynumber = (easter_day + 28 + 31)
                ;}
            if (easter_month == 4) {
                daynumber = (easter_day + 31 + 31 + 28)
                ;}

            }
        if (is_leap_year(year)== 1) {
            if (easter_month == 3){
            daynumber = (easter_day + 29 + 31)
            ;}
            if (easter_month == 4) {
            daynumber = (easter_day + 31 + 31 + 29)  ;}

        }

int n_carnival_day = daynumber - 49 ;

        int target_month;
        int hday ;
        if (is_leap_year(year)==0) {
 if (daynumber <= 59) {target_month = 2;}
 if (daynumber <= 90) {target_month = 3;}
 if (daynumber <= 120) {target_month = 4;}
 if (daynumber <= 151) {target_month = 5;}
 if (daynumber <= 181) {target_month = 6;}

 if (target_month==2) {hday=daynumber-31;}
 if (target_month==3) {hday=daynumber-59;}
 if (target_month==4) {hday=daynumber-90;}
 if (target_month==5) {hday=daynumber-120;}
 if (target_month==6) {hday=daynumber-151;}
        }
        if (is_leap_year(year)==1) {
 if (daynumber <= 60) {target_month = 2;}
 if (daynumber <= 91) {target_month = 3;}
 if (daynumber <= 121) {target_month = 4;}
 if (daynumber <= 152) {target_month = 5;}
 if (daynumber <= 182) {target_month = 6;}

 if (target_month==2) {hday=daynumber-31;}
 if (target_month==3) {hday=daynumber-60;}
 if (target_month==4) {hday=daynumber-91;}
 if (target_month==5) {hday=daynumber-121;}
 if (target_month==6) {hday=daynumber-152;}
        }

int n_gfriday_day = daynumber - 2 ;
int n_ascension_day = daynumber + 39 ;
int n_whitsuntide = daynumber + 49 ;

cout << "carnival is on" << hday << "/" << '\t' << target_month ;
//                                                                                                                  
   }

int main()
{
int month_int;
int year;
cout << "input month ";
cin >> month_int;
Month month = static_cast<Month> (month_int) ;
cout << '\n' << "input year ";
cin >> year ;

int numberdays;
numberdays = number_of_days_in_month( year, month);
cout << numberdays << '\n' ;

//                                                                                                                                                           
//                                                                                                                                                   

    show_holy_days() ;
    return 0;
}

