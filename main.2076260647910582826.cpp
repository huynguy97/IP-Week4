#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    bool is_leap_year ( int year )
    {
        if year % 400 == 0;
        return true ;
        if year % 100 == 0;
        return false;
        return year % 4 == 0;
    }

    int number_of_days_in_month ( int year, Month month )
{
   switch ( month )
   {
    case February: if is_leap_year (year) return 29; else return 28  ;
    case April:
    case June:
    case August:
    case November: return 30 ;
    default: return 31 ;
   }
}

}

