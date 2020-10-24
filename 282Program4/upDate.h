//
// Created by Shawn on 10/21/20.
//
#include <string>


#ifndef INC_282PROGRAM4_UPDATE_H
#define INC_282PROGRAM4_UPDATE_H
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
    upDate operator+=(upDate U);
    upDate operator-=(const upDate& U);
    upDate operator+(upDate U);
    upDate operator-(upDate U);
    int operator-(int U);
    operator int();
    operator string();
    upDate operator+(int U);
    friend ostream& operator<<(ostream &os, upDate &U);
    static int GetDateCount();
    upDate operator++();
    upDate operator++(int);
    upDate operator--();
    upDate operator--(int);
    bool operator==(upDate U);
    bool operator>(upDate U);
    bool operator<(upDate U);
    int julian();



private:
    int * date;
    static int dateCount;
    void setGregorian(int JD);
};


#endif //INC_282PROGRAM4_UPDATE_H
