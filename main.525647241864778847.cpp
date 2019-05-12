#include <iostream>
#include <cmath>

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
bool is_leap_year ( int year )
{
    //                        
    if(year % 4 == 0){
        if(year % 100 ==0 && year % 400 != 0)
            return false;
        else
            return true;
    }
    else
        return false;
}

//                                                                                             
int number_of_days_in_month ( int year, Month month )
{
    //                        
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 2:
            if(is_leap_year(year))
                return 29;
            else
                return 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        default:
            return 0;
            break;
    }
}

/*                                                                   
                                                
                                                                   */

//                                                                                                                         
int total_days(int year, Month month, int day)
{
    int total_days = day;
    for(int i = 1; i < static_cast<int>(month); i++)
    {
        total_days = total_days + number_of_days_in_month(year, static_cast<Month>(i));
    }
    return total_days;
}

//                                                                                     
int party_day(int day, int difference)
{
    int days = day  + difference;
    return days ;
}

//                                                                                                                      
Month month_of_year(int year, int days)
{
    int i =1;
    int day = 0;
    while(day < days)
    {

        day = day + number_of_days_in_month(year, static_cast<Month>(i));
        i++;
    }
    return static_cast<Month>(i-1);
}

//                                               
int day_of_month(int year, Month month, int days)
{
    int day = 0;
    for(int i = 1; i < static_cast<int>(month); i++ )
    {
        day = day + number_of_days_in_month(year, static_cast<Month>(i));
    }
    return days-day;
}

//                            
int get_year()
{
    int year = 0;
    cout << "Please enter a year to get the holy dates from."<<endl;
    cin >> year;
    cout << "Year is: "<<year<<endl;
    return year;
}

//                                         
string set_month(Month month)
{
    switch(month){
        case 1:
         return   "January";
            break;
        case 2:
            return   "February";
            break;
        case 3:
            return  "March";
            break;
        case 4:
            return  "April";
            break;
        case 5:
            return   "May";
            break;
        case 6:
            return "June";
            break;
        case 7:
            return "July";
            break;
        case 8:
            return  "August";
            break;
        case 9:
            return   "September";
            break;
        case 10:
            return   "October";
            break;
        case 11:
            return   "November";
            break;
        case 12:
            return  "December";
            break;
        default:
            return    "error";
            break;
    }
}

//                                                 
void show_holy_days ()
{
    //                        
    int year = get_year();
    int day = total_days(year, easter_month(year), easter_day(year));
    cout << "easter(month, day): "<< set_month(easter_month(year)) << ", "<< easter_day(year)<<endl;
    cout << "carnival starts at: " << set_month(month_of_year(year,party_day(day, -49)))<< ", " << day_of_month(year,month_of_year(year, party_day(day, -49)), party_day(day, -49)) <<
    endl;
    cout << "carnival ends at: " << set_month(month_of_year(year, party_day(day, -47)))<< ", " << day_of_month(year,month_of_year(year, party_day(day, -47)), party_day(day, -47)) << endl;
    cout << "Good Friday is on: " << set_month(month_of_year(year, party_day(day, -2)))<< ", "  << day_of_month(year,month_of_year(year, party_day(day, -2)), party_day(day, -2)) <<endl;
    cout << "Ascension Day is on: " << set_month(month_of_year(year, party_day(day, 39)))<< ", " << day_of_month(year,month_of_year(year, party_day(day, 39)), party_day(day, 39)) <<endl;
    cout << "Whitsuntide is on: " << set_month(month_of_year(year, party_day(day, 49)))<< ", " << day_of_month(year,month_of_year(year, party_day(day, 49)), party_day(day, 49)) <<endl;

}

int main()
{
   show_holy_days() ;

    return 0;
}

