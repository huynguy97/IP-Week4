#include <iostream>

using namespace std;

enum Month {
  January = 1,
  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November,
  December
};

/*                                                                          
                                                                            
                                                           
*/

int easter_base(int year) {
  const int A = year % 19;
  const int B = year / 100;
  const int C = year % 100;
  const int D = B / 4;
  const int E = B % 4;
  const int F = (B + 8) / 25;
  const int G = (B - F + 1) / 3;
  const int H = (19 * A + B - D - G + 15) % 30;
  const int I = C / 4;
  const int K = C % 4;
  const int L = (32 + 2 * E + 2 * I - H - K) % 7;
  const int M = (A + 11 * H + 22 * L) / 451;
  return H + L - 7 * M + 114;
}

/*                                                                          
                            
*/
int easter_day(int year) {
  return (easter_base(year) % 31) + 1;
}

/*                                                                             
        
 */
Month easter_month(int year) {
  return static_cast<Month>(easter_base(year) / 31);
}

/*                                                                   
                                 
                                                                   */

//                                   
//                                   
//                                   
//                                   
//                                   
//                                   
//                                   

bool is_leap_year(int year) {
	//                                                                                                                          
  return year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0);
}

int number_of_days_in_month(int year, Month month) {
	//                                                                
  switch (month) {
    case January:
      return 31;
    case February:
			//                                                                        
      if (is_leap_year(year)) {
        return 29;
      } else {
        return 28;
      }
    case March:
      return 31;
    case April:
      return 30;
    case May:
      return 31;
    case June:
      return 30;
    case July:
      return 31;
    case August:
      return 31;
    case September:
      return 30;
    case October:
      return 31;
    case November:
      return 30;
    case December:
      return 31;
  }
  return -1;
}

/*                                                                   
                                                
                                                                   */

int corrected_easter_base(int year){                                                //                                                                       
    return easter_base(year) - 32;                                                  //                                                  
}

void print_base_day_as_date(int year, int day, string holy_day){                    //                                                                               
    int month_number = 1;                                                           //                                 

    while(day > number_of_days_in_month(year, static_cast<Month>(month_number++))){ //                                                                         
        day-=number_of_days_in_month(year, static_cast<Month>(month_number));       //                                                               
        month_number++;                                                             //                                    
    }                                                                               //                                                                                                   

    cout << holy_day << ":\t("<< month_number << ", " << day << ")" << endl;        //                         

}

void print_carnival(int year){                                                      //                              
   print_base_day_as_date(year, corrected_easter_base(year) - 49, "Start Carnival");
   print_base_day_as_date(year, corrected_easter_base(year) - 47, "End Carnival");
}

void print_friday(int year){                                                        //                                 
    print_base_day_as_date(year, corrected_easter_base(year) - 2, "Good Friday");
}

void print_ascension_day(int year){                                                 //                                   
    print_base_day_as_date(year, corrected_easter_base(year) + 39, "Ascension Day");
}

print_whitsuntide(int year){                                                        //                                 
    print_base_day_as_date(year, corrected_easter_base(year) + 49, "Whitsuntide");
}

void show_holy_days() {
    cout << "Enter a positive integer for the year for which you want to calculate its holy days: " << endl;
    int year;                           //                                                                                                                     
    cin >> year;                        //                                     
    if(year >= 0){
        cout << "The dates (month, day) of the holy days of " << year << " are:" << endl;
        print_carnival(year);
        cout << "Easter:\t\t(" << easter_month(year) << ", " << easter_day(year) << ")" << endl;
        print_friday(year);
        print_ascension_day(year);
        print_whitsuntide(year);
    } else {                            //                                             
        cout << "Please enter a valid year next time";
    }

  return;
}

int main() {
  show_holy_days();
  return 0;
}

