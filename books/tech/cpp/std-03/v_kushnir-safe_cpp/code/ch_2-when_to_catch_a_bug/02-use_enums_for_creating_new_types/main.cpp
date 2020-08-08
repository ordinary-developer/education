typedef enum { SUN, MON, TUE, WED, THU, FRI, SAT } DayOfWeek;
typedef enum 
  { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, SEP, OCT, NOV, DEC } Month;


void FunctionExpectingDayOfWeek(DayOfWeek day_of_week) { }

int main() {
    FunctionExpectingDayOfWeek(SUN);
    // FunctionExpectingDayOfWeek(JAN); // error

    return 0;
}

