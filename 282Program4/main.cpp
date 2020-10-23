#include <iostream>
#include "upDate.h"

int main() {
upDate D1(10, 27, 2010);
cout << D1 << endl;
upDate D2(D1);
cout << D2 << endl;
upDate D3 = D2;
cout << D3 << endl;
D2 = upDate(11, 22, 2001);
D1 = D2;
cout << D1 << endl;
D1 += 5;
cout << D1 << endl;// add 5 days to D1, result is stored in D1
D1 -= 7;
cout << D1 << endl;// subtract 7 days from D1, result is stored in D1
D3 = D2 + 5;
cout << D3 << endl;
D3 = upDate();
cout << D3 << endl;// add 5 days to D2, assign result to D3
D3 = 5 + D2;
cout << D3 << endl;
D3 = D2 - 4;
cout << D3 << endl;
upDate D5 = upDate(9, 2, 2029);
upDate D4 = upDate( 7, 29, 2020);// subtract 4 days from D2, assign result to D3
int x = D5 - D4;
cout << x << endl;
cout << upDate::GetDateCount() << endl;
}
