#include <iostream>

using namespace std;

/*
                        
                         
*/

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;

//                                                  
int year;

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
bool is_leap_year ( int year ) //                                                
{
    if (year % 4 == 0 && year % 400 == 0)
        return true;
    else
        return false;
}

int number_of_days_in_month ( int year, Month month ) //                                                    
{
    int month_length;

    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: month_length = 31; break;
        case 4:
        case 6:
        case 9:
        case 11: month_length = 30; break;
        case 2:
            if (is_leap_year (year))
            {
                month_length = 29; break;
            }
            else
            {
                month_length = 28; break;
            }
    }

    return month_length;
}

/*                                                                   
                                                
                                                                   */
int easter_day_in_year (int year) //                                                 
{
    if (easter_month(year) == 4) //                      
        return easter_day(year) + 62 + number_of_days_in_month(year, February);
    else //                      
        return easter_day(year) + 31 + number_of_days_in_month(year, February);
}

Month return_month (int year, int day_in_year) //                                          
{
    int leftover = day_in_year;

    int month_no = 1;

    Month month = static_cast<Month> (month_no);

    while (leftover > number_of_days_in_month(year, month)) //                                                                                  
    {
        leftover = leftover - number_of_days_in_month(year, month);
        month_no = month_no + 1;
        month = static_cast<Month> (month_no);
    }

    return static_cast<Month> (month_no); //                                          
}

int return_date (int year, int day_in_year) //                                                  
{
    int leftover = day_in_year;

    int month_no = 1;

    Month month = static_cast<Month> (month_no);

    while (leftover > number_of_days_in_month(year, month))
    {
        leftover = leftover - number_of_days_in_month(year, month);
        month_no = month_no + 1;
        month = static_cast<Month> (month_no);
    }

    return leftover; //                             
}

//                              
int carnival_day1, carnival_day3;
Month carnival_month1, carnival_month3;

void find_carnival (int year) //                                           
{
    int carnival_day1_in_year = easter_day_in_year(year) - 49; //                
    int carnival_day3_in_year = easter_day_in_year(year) - 47; //                 

    carnival_month1 = static_cast<Month> (return_month(year, carnival_day1_in_year));
    carnival_month3 = static_cast<Month> (return_month(year, carnival_day3_in_year));

    carnival_day1 = return_date(year, carnival_day1_in_year);
    carnival_day3 = return_date(year, carnival_day3_in_year);
}

//                                 
int goodfriday_day;
Month goodfriday_month;

void find_goodfriday (int year) //                               
{
    int goodfriday_day_in_year = easter_day_in_year(year) - 2;

    goodfriday_month = static_cast<Month> (return_month(year, goodfriday_day_in_year));

    goodfriday_day = return_date(year, goodfriday_day_in_year);
}

//                                   
int ascension_day;
Month ascension_month;

void find_ascension (int year) //                                 
{
    int ascension_day_in_year = easter_day_in_year(year) + 39;

    ascension_month = static_cast<Month> (return_month(year, ascension_day_in_year));

    ascension_day = return_date(year, ascension_day_in_year);
}

//                                 
int whitsuntide_day;
Month whitsuntide_month;

void find_whitsuntide (int year) //                               
{
    int whitsuntide_day_in_year = easter_day_in_year(year) + 49;

    whitsuntide_month = static_cast<Month> (return_month(year, whitsuntide_day_in_year));

    whitsuntide_day = return_date(year, whitsuntide_day_in_year);
}

void find_all_days (int year) //                                    
{
    find_carnival(year);
    find_goodfriday(year);
    find_ascension(year);
    find_whitsuntide(year);
}

void convert_months (Month month) //                                    
{
    switch (month)
    {
        case 1: cout << "January"; break;
        case 2: cout << "February"; break;
        case 3: cout << "March"; break;
        case 4: cout << "April"; break;
        case 5: cout << "May"; break;
        case 6: cout << "June"; break;
        case 7: cout << "July"; break;
        case 8: cout << "August"; break;
        case 9: cout << "September"; break;
        case 10: cout << "October"; break;
        case 11: cout << "November"; break;
        case 12: cout << "December"; break;
    }
}

void output_carnival () //                              
{
    cout << "\n\nThe dates of carnival in " << year << " are ";
    convert_months(carnival_month1);
    cout << " " << carnival_day1 << " until ";
    convert_months(carnival_month3);
    cout << " " << carnival_day3 << "." << endl;
}

void output_good_friday () //                                 
{
    cout << "\nThe date of good Friday in " << year << " is ";
    convert_months(goodfriday_month);
    cout << " " << goodfriday_day << "." << endl;
}

void output_easter () //                            
{
    cout << "\nThe date of Easter in " << year << " is ";
    convert_months(easter_month(year));
    cout << " " << easter_day(year) << "." << endl;
}

void output_ascension_day () //                                   
{
    cout << "\nThe date of Ascension Day in " << year << " is ";
    convert_months(ascension_month);
    cout << " " << ascension_day << "." << endl;
}

void output_whitsuntide () //                                 
{
    cout << "\nThe date of Whitsuntide in " << year << " is ";
    convert_months(whitsuntide_month);
    cout << " " << whitsuntide_day << "." << endl;
}

void all_output() //                             
{
    output_carnival();
    output_good_friday();
    output_easter();
    output_ascension_day();
    output_whitsuntide();
}

void show_holy_days ()
{
    //                                                                    
    cout << "Enter the year of which you want to know the holy dates: ";
    cin >> year;

    //                                                                                                          
    easter_day_in_year(year);
    find_all_days(year);

    //                                   
    all_output();
}

int main()
{
    show_holy_days() ;
    return 0;
}

