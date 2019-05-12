#include <iostream>

using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;

/*                                                                          
                                                                            
                                                           
*/

//                                    
//                        

string return_month(Month month);

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
bool is_leap_year ( int year ) //                                                                                                 
{
    if (year % 4 == 0 && year % 100 == 0 && year % 400 != 0) {
        return false;
    }
    if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }

}

int number_of_days_in_month ( int year, Month month ) //                                                               
{                                                     //                                                     
    switch (month) {
        case 1:
            cout << "January has 31 days" << endl;
            return 31;
            break;
        case 2:
            if (is_leap_year(year)) {
                cout << "February has 29 days."<< endl;
                return 29;
            } else {
                cout << "February has 28 days."<< endl;
                return 28;
            }
            break;
        case 3:
            cout << "March has 31 days." << endl;
            return 31;
            break;
        case 4:
            cout << "April has 30 days." << endl;
            return 30;
            break;
        case 5:
            cout << "May has 31 days." << endl;
            return 31;
            break;
        case 6:
            cout << "June has 30 days." << endl;
            return 30;
            break;
        case 7:
            cout << "July has 31 days." << endl;
            return 31;
            break;
        case 8:
            cout << "August has 31 days." << endl;
            return 31;
            break;
        case 9:
            cout << "September has 30 days" << endl;
            return 30;
            break;
        case 10:
            cout << "October has 31 days." << endl;
            return 31;
            break;
        case 11:
            cout << "November has 30 days." << endl;
            return 30;
            break;
        case 12:
            cout << "December has 31 days." << endl;
            return 31;
            break;
        default: cout << "Error calculating number of days." << endl;
            return 100;
    }
}

/*                                                                   
                                                
                                                                   */

void show_holy_days (int year) //                                               
{
    Month cast_month_carnival; //                                                                    
    Month cast_month_goodf;
    Month cast_month_ascday;
    Month cast_month_wst;
    string output_month = " ";
    int day_goodf;
    day_goodf = (int) easter_day (year);
    int month_goodf;
    month_goodf = (int) easter_month (year);
    for (int i = 0; i < 2; i++) //                                     
    {
        if (day_goodf == 1 && month_goodf == 4)
        {
            day_goodf = 31;
            month_goodf = month_goodf - 1;
        } else if (day_goodf == 1 && month_goodf == 3 && !is_leap_year(year))
        {
            day_goodf = 29;
            month_goodf = month_goodf - 1;
        } else if (day_goodf == 1 && month_goodf == 3 && is_leap_year(year))
        {
            day_goodf = 28;
            month_goodf = month_goodf - 1;
         } else if (day_goodf != 1)
        {
            day_goodf = day_goodf - 1;
        }
    }
    int day_ascday;
    day_ascday = (int) easter_day(year);
    int month_ascday;
    month_ascday = (int) easter_month(year);
    for (int i = 0; i < 39; i++) //                                       
    {
        if (day_ascday == 31 && (month_ascday == 3 || month_ascday == 5))
        {
            day_ascday = 1;
            month_ascday = month_ascday + 1;
        } else if (day_ascday == 30 && (month_ascday == 4 || month_ascday == 6))
        {
            day_ascday = 1;
            month_ascday = month_ascday + 1;
        } else if (day_ascday != 30 || day_ascday != 31)
        {
            day_ascday = day_ascday + 1;
        }
    }
    int day_wst;
    day_wst = (int) easter_day(year);
    int month_wst;
    month_wst = (int) easter_month(year);
    for (int i = 0; i < 49; i++) //                                     
    {
        if (day_wst == 31 && (month_wst == 3 || month_wst == 5))
        {
            day_wst = 1;
            month_wst = month_wst + 1;
        } else if (day_wst == 30 && (month_wst == 4 || month_wst == 6))
        {
            day_wst = 1;
            month_wst = month_wst + 1;
        } else if (day_wst != 30 || day_wst != 31)
        {
            day_wst = day_wst + 1;
        }
    }
    int day_carnival;
    day_carnival = (int) easter_day(year);
    int month_carnival;
    month_carnival = (int) easter_month(year);
    for (int i = 0; i < 49; i++) { //                                      

          if (day_carnival == 1 && month_carnival == 4)
        {
            day_carnival = 31;
            month_carnival = month_carnival - 1;
        } else if (day_carnival == 1 && month_carnival == 3 && is_leap_year(year))
        {
            day_carnival = 29;
            month_carnival = month_carnival - 1;
        } else if (day_carnival == 1 && month_carnival == 3 && !is_leap_year(year))
        {
            day_carnival = 28;
            month_carnival = month_carnival - 1;
        } else if (day_carnival != 1) {
           day_carnival = day_carnival - 1;
        }
    }
    cast_month_carnival = static_cast<Month> (month_carnival);
    cast_month_goodf = static_cast<Month> (month_goodf);
    cast_month_ascday = static_cast<Month> (month_ascday);
    cast_month_wst = static_cast<Month> (month_wst);

    cout << "Easter is on the " << easter_day(year) << "th of " << return_month(easter_month(year)) << "." << endl;
    cout << endl;
    cout << "Carnival is on the " << day_carnival << "th of " << return_month(cast_month_carnival) << "." << endl;
    cout << endl;
    cout << "Good Friday is on the " << day_goodf << "th of " << return_month(cast_month_goodf) << "." << endl;
    cout << endl;
    cout << "Ascension Day is on the " << day_ascday << "th of " << return_month(cast_month_ascday) << "." << endl;
    cout << endl;
    cout << "Whitsuntide is on the " << day_wst << "th of " << return_month(cast_month_wst) << "." << endl;
}
void welcome_message () { //                                               
    cout << "Welcome!" << endl;
    cout << endl;
    cout << "To find out if a year is a leap year, press 1." << endl;
    cout << endl;
    cout << "To get the number of days in a month, press 2." << endl;
    cout << endl;
    cout << "To get the holy days for a specific year, press 3." << endl;
    cout << endl;
}

string return_month (Month month) { //                                                       
    switch (month) {
        case 1:
            return "January";
            break;
        case 2:
            return "February";
            break;
        case 3:
            return "March";
            break;
        case 4:
            return "April";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "June";
            break;
        case 7:
            return "July";
            break;
        case 8:
            return "August";
            break;
        case 9:
            return "September";
            break;
        case 10:
            return "October";
            break;
        case 11:
            return "November";
            break;
        case 12:
            return "December";
            break;
        default: cout << "Error calculating month name." << endl;
    }
}

int main()
{
    string year_type = " A.D.";
    int month_choice = 0;
    int year_choice = 0;
    int option_choice = 0;
    Month month_cast ;
    welcome_message();
    cin >> option_choice;
    cout << endl;
    while (option_choice < 1 || option_choice > 3) {
        cout << "Your option choice is not 1, 2 or 3. Please try again" << endl;
        cin >> option_choice;
        cout << endl;
    }
    switch (option_choice) { //                                  
        case 1:
            cout << "Enter the year (for B.C use negative value):" << endl;
            cin >> year_choice;
            cout << endl;
            while (year_choice == 0) {
                cout << "0 is not a year. Please input a valid year." << endl;
                cin >> year_choice;
            }
            if (year_choice < 0)
                year_type = " B.C.";
            cout << "Please wait..." << endl;
            cout << endl;
            if (year_choice < 0)
                year_choice = -year_choice;
            if (is_leap_year(year_choice)) {
                cout << "The year " << year_choice << year_type << " is a leap year." << endl;
                cout << endl;
            } else {
                cout << "The year " << year_choice << year_type << " is not a leap year." << endl;
                cout << endl;
            }
            break;
        case 2:
            cout << "Enter the year of your month (for B.C use negative value):" << endl;
            cin >> year_choice;
            cout << endl;
            while (year_choice == 0) {
                cout << "0 is not a year. Please input a valid year." << endl;
                cout << endl;
                cin >> year_choice;
                cout << endl;
            }
            cout << "Choose your month number according to this format:" << endl;
            cout << endl;
            cout << "1 - January" << endl << "2 - February" << endl << "3 - March" << endl << "4 - April"
            << endl << "5 - May" << endl << "6 - June" << endl << "7 - July" << endl << "8 - August" << endl
            << "9 - September" << endl << "10 - October" << endl << "11 - November" << endl << "12 - December" << endl;
            cout << endl;
            cout << "Input month:" << endl;
            cin >> month_choice;
            cout << endl;
            cout << "Please wait..." << endl;
            cout << endl;
            month_cast = static_cast<Month> (month_choice);
            number_of_days_in_month (year_choice, month_cast);
            break;
        case 3:
            cout << "Enter the year (for B.C use negative value):" << endl;
            cin >> year_choice;
            cout << endl;
            while (year_choice == 0) {
                cout << "0 is not a year. Please input a valid year." << endl;
                cout << endl;
                cin >> year_choice;
                cout << endl;
            }
            cout << "Please wait..." << endl;
            cout << endl;
            show_holy_days (year_choice);
            break;
    }
    return 0;
}

