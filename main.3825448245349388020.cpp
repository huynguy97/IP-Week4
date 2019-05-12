//
//          
//              
//
//                                
//                                                 
//

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
{
    bool check1;
    if (((year % 400) == 0) || ((year % 4 == 0)&&(year % 100 != 0)))
    {
        check1 = true;
    }
    else
    {
        check1 = false;
    }
    return check1;
}

int number_of_days_in_month ( int year, Month month )
{
    int days;
    switch (month)
    {
        case 1: cout << " January";
            days = 31;
            break;
        case 2: cout <<" Febuary";
            if (is_leap_year(year))
        {
            days = 29;
        }
            else
            {
                days = 28;
            }
            break;
        case 3:cout <<" March";
            days = 31;
            break;
        case 4:cout <<" April";
            days = 30;
            break;
        case 5: cout <<" May";
            days = 31;
            break;
        case 6:cout <<" June";
            days = 30;
            break;
        case 7: cout <<" July";
            days = 31;
            break;
        case 8: cout <<" August";
            days = 31;
            break;
        case 9: cout <<" September";
            days = 30;
            break;
        case 10:
            cout <<" October";
            days = 31;
            break;
        case 11: cout <<" November";
            days = 30;
            break;
        case 12: cout <<" December";
            days = 31;
            break;
        default: break;
    }
    return days;
}

/*                                                                   
                                             
                                                                    */
void calculate_date(int number_days, int year)
{
    if (is_leap_year(year))
    {
        switch (number_days)
        {
            case 1 ... 31: cout <<"January-"<< number_days;
                break;
            case 32 ... 60: cout <<"Febuary-"<< number_days - 31;
                break;
            case 61 ... 91: cout << "March-"<< number_days - 60;
                break;
            case 92 ... 121: cout << "April-"<< number_days - 91;
                break;
            case 122 ... 152: cout << "May-"<< number_days - 121;
                break;
            case 153 ... 182: cout << "June-"<< number_days - 152;
                break;
            case 183 ... 213: cout << "July-"<< number_days - 182;
                break;
            case 214 ... 244: cout << "August-"<< number_days - 213;
                break;
            case 245 ... 274: cout << "September-"<< number_days - 244;
                break;
            case 275 ... 305: cout << "October-"<< number_days - 274;
                break;
            case 306 ... 335: cout << "September-"<< number_days - 305;
                break;
            case 336 ... 366: cout << "December-"<< number_days - 306;
                break;
        }
    }
    else
    {
        switch (number_days)
        {
            case 1 ... 31: cout <<"January-"<< number_days;
                break;
            case 32 ... 59: cout <<"Febuary-"<< number_days - 31;
                break;
            case 60 ... 90: cout << "March-"<< number_days - 59;
                break;
            case 91 ... 120: cout << "April-"<< number_days - 90;
                break;
            case 121 ... 151: cout << "May-"<< number_days - 120;
                break;
            case 152 ... 181: cout << "June-"<< number_days - 151;
                break;
            case 182 ... 212: cout << "July-"<< number_days - 181;
                break;
            case 213 ... 243: cout << "August-"<< number_days - 212;
                break;
            case 244 ... 273: cout << "September-"<< number_days - 243;
                break;
            case 274 ... 304: cout << "October-"<< number_days - 273;
                break;
            case 305 ... 334: cout << "September-"<< number_days - 304;
                break;
            case 335 ... 365: cout << "December-"<< number_days - 305;
                break;
        }
    }
    
}

void show_holy_days ( int year)
{
    int number_days;
    int goodfriday, whitsundtide, carnival, ascension;
    
    switch(easter_month(year))
    {
        case 1:
            number_days = 0;
            break;
        case 2:
            number_days = 31;
            break;
        case 3:
            number_days = 59;
            break;
        case 4:
            number_days = 90;
            break;
        case 5:
            number_days = 120;
            break;
        case 6:
            number_days = 151;
            break;
        case 7:
            number_days = 181;
            break;
        case 8:
            number_days = 212;
            break;
        case 9:
            number_days = 243;
            break;
        case 10:
            number_days = 273;
            break;
        case 11:
            number_days = 304;
            break;
        case 12:
            number_days = 334;
            break;
        default: break;
    }
    
    //                       
    number_days = number_days + easter_day(year);
    if (is_leap_year(year) && number_days > 31)
    {
        number_days = number_days +1;
    }
    
    //      
    cout << "Easter is on ";
    calculate_date(number_days, year);
    
    //           
    cout << endl;
    goodfriday = number_days - 2;
    cout << "Good friday is on ";
    calculate_date(goodfriday, year);
    cout << endl;
    
    //            
    whitsundtide = number_days + 49;
    cout << "whitsundtide is on ";
    calculate_date(whitsundtide, year);
     cout << endl;
    //         
    ascension = number_days + 39;
    cout << "Ascension is on ";
    calculate_date(ascension, year);
     cout << endl;
    //        
    carnival = number_days - 47;
    cout << "Carnival is on ";
    calculate_date(carnival, year);
     cout << endl;
}

int main()
{
    //                                              
    //                                        
    int year,days;
    //                            
    Month month;
    int month_test;
    
    //              
    cout << "Please enter the year: ";
    cin >> year;
    
    //               
    if (is_leap_year(year))
    {
        cout << "This is a leap year."<<endl;
    }
    else
    {
        cout << "This is a normal year."<<endl;
    }
    
    //                               
    cout <<"enter your month: ";
    cin >> month_test;
    cout << "The number of days in";
    month = static_cast<Month>(month_test);
    days = number_of_days_in_month(year, month);
    cout << " is "<<days<<endl;
    
    //          
    show_holy_days(year) ;
    return 0;
}

