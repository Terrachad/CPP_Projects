/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>


using namespace std;


int main()
{
    
    int i = -8;
    char c= '4';
    float f= 4.3;
    double d = 44254.3434;
    //cout<<time(0)<< endl;
    cout<<"valore di int " << i << "" << " | Numero Byte int: "<<sizeof(i)<<endl;
    cout<<"valore di char " << c << "" <<" | Numero Byte char: "<<sizeof(c)<<endl;
    cout<<"valore di float " << f << "" << " | Numero Byte float: "<<sizeof(f)<<endl;
    cout<<"valore di double " << d << "" << " | Numero Byte double: "<<sizeof(d)<<endl;
    cout<<"somma di tutti byte "<<sizeof(i)+sizeof(c)+sizeof(f)+sizeof(d);
    
    
    //cout<<rand()%10;
    

    return 0;
}
