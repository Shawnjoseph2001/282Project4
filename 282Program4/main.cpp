#include <iostream>
#include "upDate.h"

int main() {
upDate D1(10,27,2010); 	// overloaded constructor
upDate D2(D1); 	// copy constructor
upDate D3 = D2;
upDate D4;
upDate D5;// also copy constructor – initialize D3 to be copy of D2
D1 = D2;		// assignment operator
D1 += 5;		// add 5 days to D1, result is stored in D1
D1 -= 7;			// subtract 7 days from D1, result is stored in D1
D3 = D2 + 5;  		// add 5 days to D2, assign result to D3
D3 = 5 + D2; 	// add 5 days to D2, assign result to D3
D3 = D2 - 4; 		// subtract 4 days from D2, assign result to D3
int x = D5 - D4; 		// days between D5 and D4. Can be negative or positive
cout << upDate::GetDateCount(); // a static method that returns the number of upDate objects that currently exist
cout << D1; 		// will print “10/27/2010”
D1++;			// increment D1 by one day – postfix style
++D1; 			// also increment D1 by one day – prefix style
D1--; 			// decrement D1 by one day – postfix style
--D1; 			// decrement D1 by one day – prefix style
cout << D1.julian();	// print the Julian integer represented by D1

}
