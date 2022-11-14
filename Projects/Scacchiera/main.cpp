#include <iostream>

const int size = 8;
bool alter=1;
int board[size][size];

void protoFillBoard(){
    for(int a=0;a<size;a++){
        for(int b=0;b<size;b++){
            std::cout<<"Inserisci il valore di cell |"<< a <<"|"<< b <<"| ";
            std::cin>>board[a][b];
        }
    }
}

void protoCheckBoard(){
    for(int a=0;a<size;a++){
        for(int b=0;b<size;b++){
            if(board[a][b]!=(a+b)%2)
            alter=0;
        }
    }
}

int main()
{
    
    std::cout<<"Verifica se una matrice 8×8 di interi è una “scacchiera”\n"<<std::endl;
    
    protoFillBoard();
    
    protoCheckBoard();
    
    if(alter)
    std::cout<<"La matrice 8x8 data è una “scacchiera”\n";
    else
    std::cout<<"La matrice 8x8 data non è una “scacchiera”\n";
    
    return 0;
}