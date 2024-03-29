// upDate.cpp
// Author: Shawn Joseph
// Program #4 due date: 11/4/2020

#include <string>
#include <iostream>
#include "upDate.h"

upDate::upDate():upDate(5, 11, 1959) {}

upDate::upDate(int M, int D, int Y) {
    date = new int[3];
    setDate(M, D, Y);
    dateCount++;
}

upDate::upDate(int J) {
    date = new int[3];
    setGregorian(J);
    dateCount++;
}
int upDate::dateCount = 0;
upDate::upDate(upDate const &U): upDate(U.date[0], U.date[1], U.date[2]) {}

upDate::~upDate() {
    delete[] date;
    dateCount--;
}

void upDate::setDate(int M, int D, int Y) {
    date[0] = M;
    date[1] = D;
    date[2] = Y;
}

int upDate::getMonth() {
    return date[0];
}

int upDate::getDay() {
    return date[1];
}

int upDate::getYear() {
    return date[2];
}

string upDate::getMonthName() {
    std::string months [] {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[julian() - 1];
}

upDate &upDate::operator=(upDate U) {
    setDate(U.getMonth(), U.getDay(), U.getYear());
    return *this;
}

upDate upDate::operator+=(const upDate& U) {
    return *this = *this + U;
}

upDate upDate::operator-=(const upDate& U) {
    return *this = *this - U;
}

upDate upDate::operator+(upDate U) {
    return upDate(julian() + U.julian());
}

int upDate::operator-(upDate U) {
    return julian() - U.julian();
}

upDate upDate::operator-(int i) {
    return upDate(julian() - i);
}


upDate upDate::operator+(int U) {
    upDate ret;
    ret.setGregorian(julian() + U);
   return ret;
}

 int upDate::GetDateCount() {
    return dateCount;
}

upDate upDate::operator++() {
    return *this += 1;
}

upDate upDate::operator++(int) {
    return *this += 1;
}

upDate upDate::operator--() {
    return *this -= 1;
}

upDate upDate::operator--(int) {
    return *this -= 1;
}

int upDate::julian() {
    int I,J,K;
    J = date[0];
    K = date[1];
    I = date[2];
            int JD= K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
            return JD;
}

void upDate::setGregorian(int JD) {
    int I,J,K;
    int L= JD+68569;
    int N= 4*L/146097;
    L= L-(146097*N+3)/4;
    I= 4000*(L+1)/1461001;
    L= L-1461*I/4+31;
    J= 80*L/2447;
    K= L-2447*J/80;
    L= J/11;
    J= J+2-12*L;
    I= 100*(N-49)+I+L;
    date[2] = I;
    date[0] = J;
    date[1] = K;
}

ostream& operator<<(ostream &os, upDate U) {
    os << string(U) << endl;
    return os;
}

upDate::operator int() {
    return julian();
}

upDate::operator string() {
    return to_string(getMonth()) + "/" + to_string(getDay()) + "/" + to_string(getYear());
}

bool upDate::operator==(upDate U) {
    return julian() == U.julian();
}

bool upDate::operator<(upDate U) {
    return julian() < U.julian();
}

bool upDate::operator>(upDate U) {
    return julian() > U.julian();
}

upDate operator+(int num, upDate U) {
    return upDate(U.julian() + num);
}
