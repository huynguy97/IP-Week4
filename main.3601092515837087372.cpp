//                                                    
#include <iostream>

using namespace std;

const string MONTHS[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;
const int NUMDAYS[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

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
	if ((year % 4) != 0){
		return false;
	}
	if ((year % 100) != 0){
		return true;
	}
	if ((year % 400) != 0){
		return false;
	}
	return true;
}

int number_of_days_in_month ( int year, Month month )
{
	if (month == February){
		if (is_leap_year(year)){
			return 29;
		}
		else{
			return 28;
		}
	}
	return NUMDAYS[(int)month-1]; //                                  
}

/*                                                                   
                                                
                                                                   */

void print(Month month, int day){
	cout << MONTHS[month-1] << " " << day << endl;
}

//                                          
//                                                                       
//                                                                   
void subtractDaysAndPrint(Month startmonth, int startday, int year, int ndays){
	int currentDay = startday;
	Month currentmonth = startmonth;
	for(int x=0; x<ndays; x++){
		currentDay--;
		if(currentDay==0){
			int monthNumber = currentmonth;
			monthNumber--;
			currentmonth = static_cast<Month>(monthNumber);
			currentDay = number_of_days_in_month(year, currentmonth);
		}
	}
	print(currentmonth, currentDay);
}

void addDaysAndPrint(Month startmonth, int startday, int year, int ndays){
	
	int currentDay = startday;
	Month currentmonth = startmonth;
	for(int x=0; x<ndays; x++){
		currentDay++;
		if(currentDay>number_of_days_in_month(year, currentmonth)){
			int monthNumber = currentmonth;
			monthNumber++;
			currentmonth = static_cast<Month>(monthNumber);
			currentDay = 1;
		}
	}
	print(currentmonth, currentDay);
}

void printCarnival(Month eastermonth, int easterday, int year){
	//                                               
	subtractDaysAndPrint(eastermonth, easterday, year, 49);
}

void printGood_Friday(Month eastermonth, int easterday, int year){
	//                                                                                        
	subtractDaysAndPrint(eastermonth, easterday, year, 2);
}

void printEaster(Month eastermonth, int easterday, int year){
	//                                     
	print(eastermonth, easterday);
}

void printAscensionDay(Month eastermonth, int easterday, int year){
	//                            
	addDaysAndPrint(eastermonth, easterday, year, 39);
}

void printWhitsuntide(Month eastermonth, int easterday, int year){
	//                         
	addDaysAndPrint(eastermonth, easterday, year, 49);
}

void show_holy_days ()
{
	cout << "Enter the year for which you want to see the holidays: " << endl;
	int year; cin>>year;
	Month easterMonth = easter_month(year);
	int easterDay = easter_day(year);
	cout << "Carnival: "; printCarnival(easterMonth, easterDay, year);
	cout << "Good Friday: "; printGood_Friday(easterMonth, easterDay, year);
	cout << "Easter: "; printEaster(easterMonth, easterDay, year);
	cout << "Ascension day: "; printAscensionDay(easterMonth, easterDay, year);
	cout << "Whitsuntide: "; printWhitsuntide(easterMonth, easterDay, year);
}

int main()
{
    show_holy_days() ;
    return 0;
}

