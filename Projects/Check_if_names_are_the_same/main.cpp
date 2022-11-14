/******************************************************************************
Olshevskyi Vladyslav 3/23/2022
*******************************************************************************/
#include <iostream>
const int qsize = 30;
const int nsize = 15;
char name1[nsize];
char name2[nsize];


void protoCheckNames(){
    bool different = 0;
    for(int a=0; a < nsize; a++){
        if(name1[a] != name2[a]){
            different = 1;
        }
    }
    if(different)
    std::cout<<"I nomi non sono uguali";
    else
    std::cout<<"I nomi sono uguali";

}

int main()
{
    char question1[qsize] = "Come ti chiami? ";
    char question2[qsize] = "Come si chiama il tuo amico? ";
    
    std::cout<<question1;
    std::cin>>name1;
    
    std::cout<<question2;
    std::cin>>name2;
    
    protoCheckNames();

    
    return 0;
}
