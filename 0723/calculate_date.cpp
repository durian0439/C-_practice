#include <iostream>

using namespace std;

class Date {
	int year_;
	int month_;
	int day_;

public:
	void SetDate(int year, int month, int date) {

		year_ = year;
		month_ = month;
		day_ = date;

		cout << year_ <<"년" << month_ << "월" << day_ << "일" << endl;

	}
	void AddDay(int inc) {
		while (true) {
			if (month_ == 1 | 3 | 5 | 7 | 8 | 10 | 12) {
				if (day_ + inc > 31) {
					day_ = day_ + inc - 31;
					month_++;
				}
				else 
					day_ = day_ + inc;
					
				break;
			}

			else if (month_ == 4 | 6 | 9 | 11) {
				if (day_ + inc > 30) {
					day_ = day_ + inc - 30;
					month_++;
				}
				else 
					day_ = day_ + inc;
				
				break;
			}
			else if (month_ == 2) {
				if (day_ + inc > 28) {
					day_ = day_ + inc - 28;
					month_++;
				}
				else 
					day_ = day_ + inc;
					
				break;
			}
		}
	}
	void AddMonth(int inc) {
		while (true) {
			if (month_ + inc > 12) {
				 - 12;
				year_++;
			}
			else 
				month_ = month_ + inc;
			

			break;

		}
	}
	void AddYear(int inc) {
		year_ = year_ + inc;
	}

	void ShowDate() {
		cout << year_ << "년 " << month_ << "월 " << day_ << "일" << endl;
	}
};
int main() {
	Date date;
	int year, month, day, plus_date, plus_month, plus_year;

	cout << "연/월/일을 입력하세요" << endl;
	cin >> year >> month >> day;
	date.SetDate(year, month, day);
	
	cout << "추가하실 년도를 입력하세요 (없을경우 0)" << endl;
	cin >> plus_year;

	cout << "추가하실 월을 입력하세요 (없을경우 0)" << endl;
	cin >> plus_month;

	cout << "추가하실 일자를 입력하세요 (없을경우 0)" << endl;
	cin >> plus_date;

	date.AddDay(plus_date);
	date.AddMonth(plus_month);
	date.AddYear(plus_year);
	date.ShowDate();



	return 0;
}