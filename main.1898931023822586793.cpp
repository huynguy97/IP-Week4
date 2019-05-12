#include <iostream>
//                                                     
using namespace std;
int inputyear;

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
/*                                                                   
                                 
                                                                   */
bool is_leap_year ( int year )
{
    if (year % 4 == 0 ) {
        if(year % 100 == 0 && year % 400 != 0 ){
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int number_of_days_in_month ( int year, Month month )
{
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;

    case 4: case 6: case 9: case 11:
        return 30;

    case 2: if (is_leap_year(year)) {
        return 29;
    } else {
        return 28;
    }
    default: std::cout << "Invalid month" ;
    }
}
//                                                     
/*                                                                   
                                                
                                                                   */
void calculate_holy_days (int year, int days, string event) {

   for (int i = 1; i < 12; i++) {
       if (days > number_of_days_in_month(year, Month(i))) {
            days = days - number_of_days_in_month(year, Month(i));
       } else {
            cout << "The month in which"  << event << " falls is: "<< i << " and the day is: " << days<< "\n";
            break;
       }
   }
}
void show_holy_days (int year)
{
    int daynumber_easter = easter_day(year);
    for(int i = easter_month(year) - 1; i != 0; i = i - 1) {
        daynumber_easter = daynumber_easter + number_of_days_in_month(year, Month(i));
    }

    int daynumber_carnaval = daynumber_easter - 49;
    int daynumber_gfriday = daynumber_easter - 2;
    int daynumber_whitsuntide = daynumber_easter + 49;
    int daynumber_ascensionday = daynumber_easter + 39;

    calculate_holy_days(year, daynumber_easter, " Easter");
    calculate_holy_days(year, daynumber_carnaval, " Carnaval");
    calculate_holy_days(year, daynumber_gfriday, " Good Friday");
    calculate_holy_days(year, daynumber_whitsuntide, " Whitsuntide");
    calculate_holy_days(year, daynumber_ascensionday, " Ascension Day");

}

int main()
{
    std::cout << "Enter year:";
    std::cin >> inputyear;
    show_holy_days(inputyear) ;

}

