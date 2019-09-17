// arquivo main.cpp
#include <iostream>
#include "Time.h"
using namespace std;

int main (void)
{
   Time currTime;  // object that stores the current time
   int hr;         // current hour obtained from currTime
   int min;        // current minute obtained from currTime
   int sec;        // current second obtained from currTime

   currTime.setTime(23, 59, 59);
   currTime.getTime(hr, min, sec);
   cout << "O horário no formato militar está ajustado para: "
        << hr << ":" << min << ":" << sec << endl;

   currTime.incrementTime();
   currTime.getTime(hr, min, sec);
   cout << "Após incrementar o horário, no formato militar tem-se: "
        << hr << ":" << min << ":" << sec << endl;

   return EXIT_SUCCESS;
}
