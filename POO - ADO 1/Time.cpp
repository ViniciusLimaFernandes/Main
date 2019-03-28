// arquivo Time.cpp
#include <iostream>
#include "Time.h"
using namespace std;

const int MAX_HOURS = 23;
const int MAX_MIN_SECS = 59;

void Time::setTime (int newHour, int newMinute, int newSecond)
{
   if (newHour >= 0 && newHour <= MAX_HOURS)
   {
      hour = newHour;
   }
   else
   {
      cout << "Erro: hora deve estar entre 0 e 23" << endl;
      hour = 0;
   }
   if (newMinute >= 0 && newMinute <= MAX_MIN_SECS)
   {
      minute = newMinute;
   }
  else
   {
      cout << "Erro: minuto deve estar entre 0 e 59" << endl;
      minute = 0;
   }
   if (newSecond >= 0 && newSecond <= MAX_MIN_SECS)
   {
      second = newSecond;
   }
   else
   {
      cout << "Erro: segundo deve estar entre 0 e 59" << endl;
      second = 0;
}

}

void Time::getTime (int& currHour, int& currMinute, int& currSecond)
{
   currHour = hour;
   currMinute = minute;
   currSecond = second;
}

void Time::incrementTime (void)
{
  ++second;
  ++hour;
  ++minute;

  //verifica se apos o incremento, o horario nao ultrapassa o limite
  if(second == 60){
    second = 00;
    if(minute == 60){
      minute = 00;
    }
    if(hour == 24){
      hour = 00;
    }
  }

  
}
