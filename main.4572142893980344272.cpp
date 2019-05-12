#include <iostream>
#include <cmath>

using namespace std;
//                          
enum Month {January=1,February=2,March=3,April=4,May=5,June=6,July=7,August=8,September=9,October=10,November=11,December=12} ;

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
    int a=year % 100;
    if (a==0)
    {
        int b=year%400;
        if (b==0)
        {
            cout << "this year is a leapyear" << endl;
        }
        else
        {
            cout << "this year is not a leapyear" << endl;
        }
    }
    else
    {
        int c=year % 4;
        if (c==0)
        {
            cout << "this year is a leapyear" << endl;
        }
        else
        {
            cout << "this year is not a leapyear" << endl;
        }
    }
}

int number_of_days_in_month ()
{
    int year;
    int month;
    cout << "type in the year" << endl;
    cin >> year;
    cout << "January=1,February=2,March=1,April=3,May=1,June=3,July=1,August=1,September=3,October=1,November=3,December=1" << endl;
    int choice;
    cin >> choice;
    if (choice==2)
    {
        int h;
        int d=year%100;
        if (d==0)
        {
            int e=year%400;
            if (e==0)
            {
                h=0;
            }
            else
            {
                h=1;
            }
        }
        else
        {
            int f=year%4;
            if (f==0)
            {
                h=0;
            }
            else
            {
                h=1;
            }
        }
        if (h==0)
        {
            cout << "this month has 29 days" << endl;
            return 0;
        }
        else
        {
            cout << "this month has 28 days" << endl;
            return 0;
        }
    }
    else if (choice==3)
    {
        cout << "this month has 30 days" << endl;
    }
    else
    {
        cout << "this month has 31 days" << endl;
    }
}

/*                                                                   
                                                
                                                                   */
void carnaval()
{
    int year;
    int carnaval_month;
    int carnaval_date;
    if (easter_month(year==4))
    {
        if (easter_day(year)<=18)
        {
            carnaval_month=easter_month(year)-2;
            carnaval_date=easter_day(year)+12;
            cout << "the month of carnaval is;" << endl;
            cout << carnaval_month << endl;
            cout << "the date of carnaval is;" << endl;
            cout << carnaval_date << endl;
        }
        if (easter_day(year)>18)
        {
            carnaval_month=easter_month(year)-1;
            carnaval_date=easter_day(year)+17;
            cout << "the month of carnaval is;" << endl;
            cout << carnaval_month << endl;
            cout << "the date of carnaval is;" << endl;
            cout << carnaval_date << endl;
        }
    }
    else
    {
            carnaval_month=easter_month(year)-1;
            carnaval_date=easter_day(year)+17;
            cout << "the month of carnaval is;" << endl;
            cout << carnaval_month << endl;
            cout << "the date of carnaval is;" << endl;
            cout << carnaval_date << endl;
    }
}

void good_friday()
{
    int year;
    int good_friday_date=easter_day(year)-2;
    if (good_friday_date==0,-1)
    {
        int good_friday_month=easter_month(year)-1;
        cout << "the month of good friday is:" << endl;
        cout << good_friday_month << endl;
        good_friday_date=good_friday_date+31;
        cout << "the date of good friday is:" << endl;
        cout << good_friday_date << endl;
    }
    else
    {
        cout << "the month is:" << endl;
        cout << easter_month(year) << endl;
        cout << "the date is:" << endl;
        cout << good_friday_date << endl;
    }
}

void whitsuntide()
{
    int year;
    int whitsuntide_month;
    int whitsuntide_date;
    if (easter_month(year==4))
    {
        if (easter_day(year)>12)
        {
            whitsuntide_month=easter_month(year)+2;
            whitsuntide_date=easter_day(year)-11;
            cout << "the month of whitsuntide is;" << endl;
            cout << whitsuntide_month << endl;
            cout << "the date of whitsuntide is;" << endl;
            cout << whitsuntide_date << endl;
        }
        if (easter_day(year)<=12)
        {
            whitsuntide_month=easter_month(year)+1;
            whitsuntide_date=easter_day(year)+19;
            cout << "the month of whitsuntide is;" << endl;
            cout << whitsuntide_month << endl;
            cout << "the date of whitsuntide is;" << endl;
            cout << whitsuntide_date << endl;
        }
    }
    else
    {
            whitsuntide_month=easter_month(year)+2;
            whitsuntide_date=easter_day(year)-11;
            cout << "the month of whitsuntide is;" << endl;
            cout << whitsuntide_month << endl;
            cout << "the date of whitsuntide is;" << endl;
            cout << whitsuntide_date << endl;
    }
}

void ascension_day()
{
    int year;
    int ascension_day_month;
    int ascension_day_date;
    if (easter_month(year==4))
    {
        if (easter_day(year)>=23)
        {
            ascension_day_month=easter_month(year)+2;
            ascension_day_date=easter_day(year)-21;
            cout << "the month of ascension day is;" << endl;
            cout << ascension_day_month << endl;
            cout << "the date of ascension day is;" << endl;
            cout << ascension_day_date << endl;
        }
        if (easter_day(year)<23)
        {
            ascension_day_month=easter_month(year)+1;
            ascension_day_date=easter_day(year)+9;
            cout << "the month of ascension day is;" << endl;
            cout << ascension_day_month << endl;
            cout << "the date of ascension day is;" << endl;
            cout << ascension_day_date << endl;
        }
    }
    else
    {
            ascension_day_month=easter_month(year)+2;
            ascension_day_date=easter_day(year)-21;
            cout << "the month of ascension day is;" << endl;
            cout << ascension_day_month << endl;
            cout << "the date of ascension day is;" << endl;
            cout << ascension_day_date << endl;
    }
}

void show_holy_days ()
{
    int year;
    cout << "type in the year" << endl;
    cin >> year;
    easter_base(year);
    easter_month(year);
    easter_day(year);
    cout << "the easter month is:" << endl;
    cout << easter_month(year) << endl;
    cout << "the easter date is:" << endl;
    cout << easter_day(year) << endl;
}

int main()
{
    cout << "is_leapyear=1, number_of_days_in_month=2, dates around easter=3" << endl;
    int choice;
    cin >> choice;
    if (choice==1)
    {
        int year;
        cout << "type in the year" << endl;
        cin >> year;
        is_leap_year(year);
        return 0;
    }
    if (choice==2)
    {
        number_of_days_in_month();
    }
    if (choice==3)
    {
        show_holy_days();
        good_friday();
        carnaval();
        whitsuntide();
        ascension_day();
    }
}

