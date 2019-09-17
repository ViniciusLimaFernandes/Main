// arquivo Time.h
using namespace std;
class Time
{
  private:
      int hour;    // current hour in military time
      int minute;  // current minute in military time
      int second;  // current second in military time
  
  public:
      Time (){
        hour = 00;
        minute = 00;
        second = 00;        
      }

      // set the time to the time specified by the parameters
      void setTime (int newHour, int newMinute, int newSecond);

      // return the time to the calling method using the provided
      // parameters
      void getTime (int& currHour, int& currMinute, int& currSecond);

      // increment the current time by one second
      void incrementTime (void);
};
