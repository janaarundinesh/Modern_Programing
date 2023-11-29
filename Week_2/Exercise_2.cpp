#include<iostream>
#include<string>

//Time_to_Seconds 
//2227229

using namespace std;

int time_to_Sec_converter(int hour, int min, int sec, string meridiem);

int main()
{
	int hour, min, sec, time_to_sec;
	string  meridiem;
	cout << "Enter a Time (Format : hh mm ss am/pm) : ";
	cin >> hour >> min >> sec >> meridiem;

	if((hour >= 0 && hour <=12) && (min >= 0 && min <= 60) && (sec >= 0 && sec <= 60) && (meridiem == "am" || "pm"))
	{
		time_to_sec = time_to_Sec_converter(hour, min, sec, meridiem);
		cout << "Since 0:00 " << time_to_sec << " seconds have elapsed." << endl;
	}
	else
	{
		cout << "Enter a valid time!" << endl;
	}

	return 0;
};

int time_to_Sec_converter(int hour, int min, int sec, string meridiem)
{
	if(meridiem == "am")
	{
		if(hour == 12)
		{
			hour = 0;
			return (hour*3600)+(min*60)+sec;
		}
		else
		{
			return (hour*3600)+(min*60)+sec;
		}
	}
	else
	{
		if(hour == 12)
		{
			return (hour*3600)+(min*60)+sec;
		}else{
			return ((12+hour)*3600)+(min*60)+sec;
		}
	}
};
