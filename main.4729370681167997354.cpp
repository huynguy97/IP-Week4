#include <iostream>

using namespace std;

//                             

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;
int carnamonth;             //                                                                                                                             
int goodmonth;              //                                                                                                                                                                                
int whitmonth;
int ascenmonth;             //                                                                

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

bool is_leap_year ( int year )                          //                                                                                                                                   
{
    if ((year % 4 == 0) && (year / 100 % 4 == 0))
        return true;
    else
        return false;
}

int number_of_days_in_month ( int year, Month month )   //                                                                                                                                                                                                                             
{
    switch (month){
        case January: return 31;
        case February:
            {
            if (is_leap_year(year))
                return 29;
            else
                return 28;
                }
        case March: return 31;
        case April: return 30;
        case May: return 31;
        case June: return 30;
        case July: return 31;
        case August: return 31;
        case September: return 30;
        case October: return 31;
        case November: return 30;
        case December: return 31;
    }
}
string month_name (int number)              //                                                                                   
{
    switch (number){
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
    }
}

int month_number (string month)             //                                                                                                                                  
{                                           //                                                                                                                                                                          
    if (month == "January")
        return 1;
    else if (month == "February")
        return 2;
    else if (month == "March")
        return 3;
    else if (month == "April")
        return 4;
    else if (month == "May")
        return 5;
    else if (month == "June")
        return 6;
    else if (month == "July")
        return 7;
    else if (month == "August")
        return 8;
    else if (month == "September")
        return 9;
    else if (month == "October")
        return 10;
    else if (month == "November")
        return 11;
    else if (month == "December")
        return 12;
    else
        return 0;
}

void user_input()                           //                                                                            
{
    int year;
    cout << "Year to test for leap-year: ";
    cin >> year;

    if (is_leap_year(year))
        cout << year << " is a leap year." << endl;
    else
        cout << year << " is not a leap year." << endl;

    string month;
    cout << "\nMonth you want to know the amount of days of: " << endl;
    cin >> month;

    if (month_number(month) == 0){
        cout << "Please input month-name in format: 'January'" << endl;
    }
    else if(month_number(month) == 2){
        cout << "\nYear to test: " << endl;                                         //                                                                      
        cin >> year;
        cout << "Number of days in " << month << " in " << year << " is: " << number_of_days_in_month(year, static_cast<Month>(month_number(month))) << " days." << endl;
    }
    else
        cout << "Number of days in " << month << " every year is: " << number_of_days_in_month(year, static_cast<Month>(month_number(month))) << " days." << endl;
}

/*                                                                   
                                                
                                                                   */

int carnaval (int year, bool firstday)              //                                                                                   
{
    int deltadays;
    carnamonth = 0;

    if (firstday)                                       //                                                                                            
        deltadays = 49;
    else
        deltadays = 47;                                 //                                                                                                             

    int carnaday = easter_day(year) - deltadays;        //                                                                                            

    if ((carnaday < 0) && (easter_month(year) == 3)){   //                                                                                               
        carnaday = carnaday + 29;                       //                                                                                                                                                        
        carnamonth++;                                   //                                                                                                                

        if (carnaday < 0){                              //                                                                             
            carnaday = carnaday + 27;
            carnamonth++;
        }
    }

    else if ((carnaday < 0) && (easter_month(year) == 4)){  //                                                           
        carnaday = carnaday + 31;
        carnamonth++;

        if ((carnaday < 0) && (is_leap_year(year))){
            carnaday = carnaday + 29;
            carnamonth++;
        }
        else if ((carnaday < 0) && !(is_leap_year(year))){
            carnaday = carnaday + 28;
            carnamonth++;
        }
    }
    return carnaday;
}

int good_friday (int year)                      //                                                                       
{
    goodmonth = 0;
    int goodday = easter_day(year) - 2;         //                                                                                  

    if (goodday < 0){                           //                                                                  
        goodmonth++;                            //                                                                                                   
        return goodday + 31;
    }
    else
        return goodday;
}

int whitsunday (int year)                       //                                                                      
{
    whitmonth = 0;
    int whitday = easter_day(year) + 49;                //                                                                           

    if ((whitday > 31) && (easter_month(year) == 3)){   //                                                                                                  
        whitday = whitday - 31;
        whitmonth++;                                    //                                                                                

        if (whitday > 30){
            whitday = whitday - 30;
            whitmonth++;
        }
    }

    else if ((whitday > 30) && (easter_month(year) == 4)){
        whitday = whitday - 30;
        whitmonth++;

        if (whitday > 31){
            whitday = whitday - 31;
            whitmonth++;
        }
    }
    return whitday;
}

int ascension_day (int year)            //                                                                        
{
    ascenmonth = 0;                         //                                                                                                  
    int ascenday = whitsunday(year) - 10;   //                                                        

    if (ascenday < 0){
        ascenmonth++;                       //                                                                                                               
        return ascenday + 31;
    }
    else
        return ascenday;
}

void show_holy_days ()              //                                                                   
{
    int Y;
    cout << "\n\nShow holy-days of year: ";
    cin >> Y;

    //                                                                                                                                                           
    //                                                                                                                                    

    cout << "\nEaster is on " << month_name(easter_month(Y)) << " " << easter_day(Y) << endl;
    cout << "Carnival is from " << month_name(easter_month(Y)-carnamonth) << " " << carnaval(Y, true) << " until " << month_name(easter_month(Y)-carnamonth) << " " << carnaval(Y, false) << endl;
    cout << "Good Friday is on " << month_name(easter_month(Y)-goodmonth) << " " << good_friday(Y) << endl;
    cout << "Whitsunday is on " << month_name(easter_month(Y)+whitmonth) << " " << whitsunday(Y) << endl;
    cout << "Ascension Day is on " << month_name(easter_month(Y)+whitmonth-ascenmonth) << " " << ascension_day(Y) << endl;
}

int main()
{
    user_input();
    show_holy_days();
    return 0;
}

