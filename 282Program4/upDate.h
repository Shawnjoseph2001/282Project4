// upDate.h
// Author: Shawn Joseph
// Program #4 due date: 11/4/2020

#ifndef INC_282PROGRAM4_UPDATE_H
#define INC_282PROGRAM4_UPDATE_H
#include <string>
using namespace std;
class upDate {
public:
    upDate();
    upDate(int M, int D, int Y);
    upDate(int J);
    upDate(upDate const &U);
    ~upDate();
    void setDate(int M, int D, int Y);
    int getMonth();
    int getDay();
    int getYear();
    string getMonthName();
    upDate& operator= (upDate U);
    upDate operator+=(const upDate& U);
    upDate operator-=(const upDate& U);
    upDate operator+(upDate U);
    int operator-(upDate U);
    upDate operator-(int U);
    explicit operator int();
    explicit operator string();
    upDate operator+(int U);
    friend ostream& operator<<(ostream &os, upDate U);
    static int GetDateCount();
    upDate operator++();
    upDate operator++(int);
    upDate operator--();
    upDate operator--(int);
    bool operator==(upDate U);
    bool operator>(upDate U);
    bool operator<(upDate U);
    int julian();
    friend upDate operator+(int num, upDate U);

private:
    int * date;
    static int dateCount;
    void setGregorian(int JD);
};

#endif //INC_282PROGRAM4_UPDATE_H
