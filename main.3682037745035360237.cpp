/*
                                  

          
                                                            
                                                                               
                                                                          

                                                                        
                           

*/

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
bool is_leap_year ( int year )
//                                   
{
    if ((year % 4) == 0){
        if ((year % 100) == 0){
            if ((year % 400) == 0){
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
}

int number_of_days_in_month ( int year, Month month )
//                                     
{
    switch(month){
        case 1:
            return 31;
        case 2:
            if (is_leap_year(year)){
                return 29;
            }
            else {
                return 28;
            }
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        //                        
    }
}

string convert_month_nr(int month_number){
//                                                                            
    if (month_number == 1){
        return "January";
    }
    else if (month_number == 2){
        return "February";
    }
    else if (month_number == 3){
        return "March";
    }
    else if (month_number == 4){
        return "April";
    }
    else if (month_number == 5){
        return "May";
    }
    else if (month_number == 6){
        return "June";
    }
    else if (month_number == 7){
        return "July";
    }
    else if (month_number == 8){
        return "August";
    }
    else if (month_number == 9){
        return "September";
    }
    else if (month_number == 10){
        return "October";
    }
    else if (month_number == 11){
        return "November";
    }
    else if (month_number == 12){
        return "December";
    }
}

int input_year(){
    int year = 0;
    //      
    cout << "Please, enter a year: ";
    cin >> year;
    cout << "\n";
    return year;
}

int input_month(){
    int month = 0;
    //      
    cout << "Please, enter a month(1-12): ";
    cin >> month;
    cout << "\n";
    return month;
}

void assignment_0(){
    //                                   
    //              
    int year = input_year();
    if (is_leap_year(year)){
        cout << year << " is a leap year.\n";
    }
    else {
        cout << year << " is not a leap year.\n";
    }
}

void assignment_1(){
    //                             
    int year = input_year();
    int month = input_month();
    int days_in_month = number_of_days_in_month(year, static_cast<Month> (month));
    string month_string = convert_month_nr(month);
    //                                                 
    cout << "The month " << month_string << " in " << year << " had " <<
        days_in_month << " days.\n";
}

/*                                                                   
                                                
                                                                   */
void print_easter(int year, int day, int month){
    //                                                       
    string month_string = convert_month_nr(month);
    cout << "In the year " << year << " easter is in the month " << month_string
        << " on day " << day << ".\n";
}

void print_good_friday(int year, int day, int month){
    //                                                           
    //                                                                         
    if ((day - 2) > 0){
        string month_string = convert_month_nr(month);
        cout << "In the year " << year << " good Friday is in the month " << month_string
            << " on day " << day-2 << ".\n";
    }
    //                                                                        
    else{
        month--;
        day = number_of_days_in_month(year, static_cast<Month> (month)) + (day - 2);
        string month_string = convert_month_nr(month);
        cout << "In the year " << year << " good Friday is in the month " << month_string
            << " on day " << day << ".\n";
    }
}

void print_carnival(int year, int day, int month){
    //                                                         
    int days_to_carnival = 7*7;

    while(days_to_carnival !=0){
        //                                                                
        //                                      
        if ((day - days_to_carnival) < 0){
            days_to_carnival -= day;
            month--;
            day = number_of_days_in_month(year, static_cast<Month> (month));
        }
        //                                                                
        else{
            day -= days_to_carnival;
            days_to_carnival = 0;
        }
    }
string month_string = convert_month_nr(month);
cout << "In the year " << year << " carnival is in the month " <<
            month_string << " on day " << day << " till " << day+2 << ".\n";
}

void print_ascension(int year, int day, int month){
    //                                                                      
    //                                    
    if ((day - 10) > 0){
        string month_string = convert_month_nr(month);
        cout << "In the year " << year << " ascension is in the month " << month_string
        << " on day " << day - 10 << ".\n";
    }
    //                                                                                           
    else{
        int days_left = -(day-10);
        month--;
        day = number_of_days_in_month(year, static_cast<Month> (month)) - days_left;
        string month_string = convert_month_nr(month);
        cout << "In the year " << year << " ascension is in the month " << month_string
        << " on day " << day << ".\n";
    }
}

void print_whitsuntide(int year, int day, int month){
    //                                                         
    int days_to_whitsuntide = 7*7;

    //                                                              

    //                                                                            
    //                                                                          
    //                                                                         
    days_to_whitsuntide -= (number_of_days_in_month(year, static_cast<Month> (month))- day);
    month++;
    day = number_of_days_in_month(year, static_cast<Month> (month));

    //                                                                     
    //                       
    while(day - days_to_whitsuntide < 0){
        //                                                                  
        days_to_whitsuntide -= number_of_days_in_month(year, static_cast<Month> (month));
        //                                                                        
        month++;
        day = number_of_days_in_month(year, static_cast<Month> (month));
    }

    //                                                                    
    //                                                                       
    day = days_to_whitsuntide;

    //                               
    string month_string = convert_month_nr(month);
    cout << "In the year " << year << " whitsuntide is in the month " <<
    month_string << " on day " << day << ".\n";

    //                                                               
    //                      
    print_ascension(year, day, month);
}

void show_holy_days ()
{
    //                
    cout << "Holiday calculator v1\n\n";
    //                                                                    
    int year = input_year();
    int day = easter_day(year);
    int month = easter_month(year);
    //                   
    print_easter(year, day, month);
    print_good_friday(year, day, month);
    print_carnival(year, day, month);
    //                                                        
    //                                                                      
    //                
    print_whitsuntide(year,day,month);
}

int main()
{
    //                                                                        
    //               

    //                                     
    show_holy_days() ;
    return 0;
}

