/*
 * const.cpp
 *
 *  Created on: Apr 21, 2015
 *      Author: will
 */

#include <iostream>
using namespace std;
class X{};
class Y: public virtual X{};
class Z: public virtual X{};
class A: public Y,public Z{};


int main()
{
    cout << "X="<<sizeof(X)<<endl;
    cout << "Y="<<sizeof(Y)<<endl;
    cout << "Z="<<sizeof(Z)<<endl;
    cout << "A="<<sizeof(A)<<endl;
   return 0;
}


