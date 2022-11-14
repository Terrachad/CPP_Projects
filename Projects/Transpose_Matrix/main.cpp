/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

int val;

const int wide = 3;
const int tall = 3;

int horizontal[tall][wide];
int vertical[wide][tall];


void protoInputFill(int w, int t){
    int a=0, b=0;
    for(a=0; a < w; a++){
        std::cout<<"\nInserisci valori della righa n."<<a+1<<std::endl;
        std::cout<<"___________________________________\n"<<std::endl;
        for(b=0; b < t; b++){
            val = 0;
            std::cout<<"valore n." << b << "|";
            std::cin>>val;
            horizontal[a][b] = val;
            
        }
    }
    
}

void protoReadVertical(int w, int t){
    for(int a=0; a < w; a++){
        std::cout<<std::endl;
        for(int b=0; b < t; b++){
            if(vertical[a][b]< 10)
            std::cout<<vertical[a][b]<<" |";
            else
            std::cout<<vertical[a][b]<<"|";
            
        }
    }
}

void protoReadHorizontal(int w, int t){
    for(int a=0; a < w; a++){
        std::cout<<std::endl;
        for(int b=0; b < t; b++){
            if(horizontal[a][b]< 10)
            std::cout<<horizontal[a][b]<<" |";
            else
            std::cout<<horizontal[a][b]<<"|";
        }
    }
}

void protoTransfer(int w, int t){
    for(int a=0; a < w; a++){
        std::cout<<std::endl;
        for(int b=0; b < t; b++){
            vertical[b][a] = horizontal[a][b];
            
        }
    }
}

void protoChecker(int w, int t){
    bool symmetric=1;
    for(int a=0; a < w; a++){
        std::cout<<std::endl;
        for(int b=0; b < t; b++){
            if(vertical[a][b] != horizontal[a][b]){
                symmetric = 0;
            }
        }
    }
    if(symmetric == 1){
        std::cout<<"La matrice data è simmetrica";
    }
    else
    std::cout<<"La matrice data è antisimmetrica";
}


int main()
{

    std::cout << std::endl << "\nMatice horizontale 2*3"<< std::endl ;

    protoInputFill(tall, wide);
    
    protoReadHorizontal(tall, wide);
    
    protoTransfer(tall, wide);
    
    std::cout << "Matice traspostata (da horizontale 2*3 a verticale 3*2)"<< std::endl;
    
    protoReadVertical(wide, tall);
    
    protoChecker(tall,wide);
    
    
    
    return 0;
}






