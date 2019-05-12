#include <iostream>
#include <math.h>

//                                                   
//         

using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;
int result;

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
    double yeardivided4 = year/4.0;
    double yeardivided400 = year/400.0;
    double yeardivided100 = year/100.0;

    if (floor(yeardivided4) ==  yeardivided4)
    {
        if (floor(yeardivided100) == yeardivided100)
        {
            if (floor(yeardivided400) == yeardivided400)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }

}

int number_of_days_in_month ( int inputyear, Month month)
{

    if ((month == 2) && is_leap_year(inputyear))
    {
        result = 29;

    }
    else
    {
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
        {
            result = 31;
        }
        if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
        {
            result = 30;
        }
        if ((month == 2))
        {
            result = 28;
        }
    }
    return result;
}
int dayeaster (int inputyear)
{
    int resultday;
    int daysFebruary;

    if (is_leap_year(inputyear))
    {
        daysFebruary = 29;
    }
    else
    {
        daysFebruary = 28;
    }
    int daysJanuary = 31;
    int daysMarch = 31;

    if (easter_month(inputyear) == 3)
    {
        resultday = (daysJanuary + daysFebruary + easter_day(inputyear));
    }
    else
    {
        resultday = (daysJanuary + daysFebruary + daysMarch + easter_day(inputyear));
    }

    return resultday;
}

void textmonth (int inputmonth)
{
    switch(inputmonth)
    {
    case 1:
        cout << "January";
        break;
    case 2:
        cout << "February";
        break;
    case 3:
        cout << "March";
        break;
    case 4:
        cout << "April";
        break;
    case 5:
        cout << "May";
        break;
    case 6:
        cout << "June";
        break;
    case 7:
        cout << "July";
        break;
    case 8:
        cout << "August";
        break;
    case 9:
        cout << "September";
        break;
    case 10:
        cout << "October";
        break;
    case 11:
        cout << "November";
        break;
    case 12:
        cout << "December";
        break;

    }
}

/*                                                                   
                                                
                                                                   */
int daytoday(int inputyear, int holidayday)
{
    int i = 1;

    while (holidayday > number_of_days_in_month(inputyear, static_cast<Month>(i)))
    {
        holidayday = holidayday - number_of_days_in_month(inputyear, static_cast<Month>(i));
        i++;
    }
    return holidayday;
}
int daytomonth(int inputyear, int holidayday)
{
    int i = 1;
    while (holidayday > number_of_days_in_month(inputyear, static_cast<Month>(i)))
    {
        holidayday = holidayday - number_of_days_in_month(inputyear, static_cast<Month>(i));
        i++;
    }
    return i;
}

int daycarnavalcalc ( int inputyear)
{
    int daycarnaval = dayeaster(inputyear) - 49;
    return daycarnaval;
}

int daycarnavalendcalc ( int inputyear)
{
    int daycarnavalend = dayeaster(inputyear) - 47;
    return daycarnavalend;
}

int daygoodfridaycalc ( int inputyear)
{
    int goodfriday = dayeaster(inputyear) - 2;
    return goodfriday;
}

int daywhitesuntidecalc ( int inputyear)
{
    int whitesuntide = dayeaster(inputyear) + 49;
    return whitesuntide;
}

int dayascensiondaycalc ( int inputyear)
{
    int ascensionday = daywhitesuntidecalc(inputyear) - 10;
    return ascensionday;
}

void show_holy_days (int inputyear)
{

    int carnaval = daycarnavalcalc(inputyear);
    int carnavalend = daycarnavalendcalc(inputyear);
    int goodfriday = daygoodfridaycalc(inputyear);
    int whitesuntide = daywhitesuntidecalc(inputyear);
    int ascensionday = dayascensiondaycalc(inputyear);

    cout << "Carnaval begins on " << daytoday(inputyear, carnaval) << "-" << daytomonth(inputyear, carnaval) << " and ends on " << daytoday(inputyear, carnavalend) << "-" << daytomonth(inputyear, carnavalend) << endl;
    cout << "Good friday is on " << daytoday(inputyear, goodfriday) << "-" << daytomonth(inputyear, goodfriday) << endl;
    cout << "Ascensionday is on " << daytoday(inputyear, ascensionday) << "-" << daytomonth(inputyear, ascensionday) << endl;
    cout << "White suntide is on " << daytoday(inputyear, whitesuntide) << "-" << daytomonth(inputyear, whitesuntide) << endl;

}

int main()
{
    int inputyear;
    Month month;
    int inputmonth;

    cout << "---------- Part 1. Leap years ----------" << endl;
    cout << "Please insert a year: " ;
    cin >> inputyear ;

    if(inputyear < 1)
    {
        cout << "Please pick a year bigger than 0" << endl;
        cout << "" << endl;
        cout << "" << endl;
        return main();

    }
    else
    {
        if (is_leap_year(inputyear))
        {
            cout << "This year is a leap year." << endl;
        }
        else
        {
            cout << "This year is not a leap year." << endl;
        }

        cout << "Please pick a month (January = 1, February = 2 ...): ";
        cin >> inputmonth ;

        if ((inputmonth > 12) || (inputmonth <= 0))
        {
            cout << "there are only 12 months" << endl;
            cout << "" << endl;
            cout << "" << endl;
            return main();

        }
        else
        {
            Month month = static_cast<Month>(inputmonth);
            number_of_days_in_month (inputyear, month);
            cout << "The month ";
            textmonth(inputmonth);
            cout << " has " << result << " days." << endl;
            cout << "" << endl;
            cout << "---------- Part 2: Holy days based on Easter ----------" << endl;
            cout << "Easter in the year " << inputyear << " is on " << easter_day(inputyear) << "-"<< easter_month(inputyear) << ". Which is day " << dayeaster(inputyear) << " of the year."<< endl;
            show_holy_days(inputyear);
            cout << "" << endl;
            cout << "" << endl;

        }
    }
    return main();
}

