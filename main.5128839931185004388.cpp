#include <iostream>

using namespace std;

//            
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
//                                    
{
    if(year % 4 == 0)
    	{
      if(year % 100 == 0)
      	{
        if(year % 400 == 0)
        	{
        	return true;
        	}
        return false;
        }
      return true;
      }
  	return false;
}

int number_of_days_in_month ( int year, Month month )
{
    //                                                 
    switch (month)
    {   case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December: return 31;
        case April:
        case June:
        case September:
        case November: return 30;
        case February:
            {
                if (is_leap_year(year))
                {   return 29;
                }
                return 28;
            }
    }
}

/*                                                                   
                                                
                                                                   */
int day_number (int day, int month, int year)
//                                           
{
    int day_number = day;

    for (int i = 1;i < month;i++)
    {
        day_number += number_of_days_in_month(year,static_cast<Month>(i));
    }
    return day_number;
}

int day_in_month (int day_number, int year)
//                                                                    
{
    for (int i = 1; day_number > number_of_days_in_month(year,static_cast<Month>(i)); i++)
    {
        day_number -= number_of_days_in_month(year,static_cast<Month>(i));
    }
    return day_number;
}

int month_in_year (int day_number, int year)
//                                                  
{
    int i = 1;

    while (day_number > number_of_days_in_month(year,static_cast<Month>(i)))
    {
        day_number -= number_of_days_in_month(year,static_cast<Month>(i));
        i++;
    }
    return i;
}

void show_date (int day_in_month, int month_in_year)
//                                          
{
    switch (month_in_year)
    {   case 1: cout << "January "; break;
        case 2: cout << "February "; break;
        case 3: cout << "March "; break;
        case 4: cout << "April "; break;
        case 5: cout << "May "; break;
        case 6: cout << "June "; break;
        case 7: cout << "July "; break;
        case 8: cout << "August "; break;
        case 9: cout << "September "; break;
        case 10: cout << "October "; break;
        case 11: cout << "November "; break;
        case 12: cout << "December "; break;
    }
    cout << day_in_month;
}

void show_holy_days ()
//                                       
{
    cout << "Enter a year:\n";
    int year;
    cin >> year;

    int easter_number = day_number(easter_day(year),easter_month(year), year);

    int carnival_start = easter_number - 49;
    int carnival_end = easter_number - 47;
    int good_friday = easter_number - 2;
    int ascension_day = easter_number + 39;
    int whitsuntide = easter_number + 49;

    cout << "The holy days for this year are:\n";

    cout << "Carnival:\tFrom ";
    show_date(day_in_month(carnival_start, year),month_in_year(carnival_start, year));
    cout << " to ";
    show_date(day_in_month(carnival_end, year),month_in_year(carnival_end, year));
    cout << "\n";

    cout << "Good Friday:\t";
    show_date(day_in_month(good_friday, year),month_in_year(good_friday, year));
    cout << "\n";

    cout << "Easter:\t\t";
    show_date(easter_day(year),easter_month(year));
    cout << "\n";

    cout << "Ascension day:\t";
    show_date(day_in_month(ascension_day, year),month_in_year(ascension_day, year));
    cout << "\n";

    cout << "Whitsuntide:\t";
    show_date(day_in_month(whitsuntide, year),month_in_year(whitsuntide, year));
    cout << "\n";

}

int main()
{
    show_holy_days() ;
    return 0;
}

