/******************************************************************************

*******************************************************************************/
#include <iostream>
#include <string.h>



typedef struct Person{
    std::string nome;
    int countvocs = 0;
    int countcons = 0;
}Person;

typedef struct Grouplist{
    int countgroup = 0;
    Person people;
}Grouplist;


char consonanti[21] = {'B','C', 'D', 'F', 'G', 'H', 'L', 'M', 'N', 'P', 'Q', 'R','S', 'T', 'V', 'Z', 'K', 'J', 'W', 'X', 'Y'};
char vocali[6] = {'A','E', 'I', 'O', 'U'};

int listpos;
char switcher;
bool stop = 0;

void countConsVoc(Person people[], int listpos)
{
    int size;
    bool flag = 0;
    
    size = people[listpos].nome.length();
    
    for(int j = 0; j < size;j++){
        for(int k = 0; k < 21; k++){
            
            if( (people[listpos].nome[j] == consonanti[k] || (int)people[listpos].nome[j] == (int)consonanti[k] + 32)){
                if( people[listpos].nome[j+1] == people[listpos].nome[j] || (int)people[listpos].nome[j+1] == (int)people[listpos].nome[j]+32){
                    std::cout<<people[listpos].nome<<" - doppia consonante in posizione " <<j+1<<"("<< people[listpos].nome[j]<<") e "<<j+2 <<"("<<people[listpos].nome[j+1]<<")";
                    flag = 1;
                }
                people[listpos].countcons++;
            }
        }
    }
    
    for(int j = 0; j < size;j++){
        for(int k = 0; k < 6; k++){
            
            if( (people[listpos].nome[j] == vocali[k] || (int)people[listpos].nome[j] == (int)vocali[k] + 32)){
                if( people[listpos].nome[j+1] == people[listpos].nome[j] || (int)people[listpos].nome[j+1] == (int)people[listpos].nome[j]+32){
                     std::cout<<people[listpos].nome<<" - doppia vocale in posizione " <<j+1<<"("<< people[listpos].nome[j]<<") e "<<j+2 <<"("<<people[listpos].nome[j+1]<<")";
                     flag = 1;
                }
                people[listpos].countvocs++;
            }
        }
    }
    
    if(flag)
    std::cout<<" ha "<< people[listpos].countvocs << " vocali e " << people[listpos].countcons<< " consonanti" << std::endl;
    else
    std::cout<<people[listpos].nome<< " - ha "<< people[listpos].countvocs << " vocali e " << people[listpos].countcons<< " consonanti" << std::endl;
    
}

void checkGroup(Person people[],Grouplist grouplist, int listpos){
    for(listpos = 0; listpos < grouplist.countgroup; listpos++){
        countConsVoc(people, listpos);
    }
}


int main()
{
    int groupsize = 10;
    
    Person people_arr[groupsize];
    
    people_arr[0].nome = "Bob";
    people_arr[1].nome = "Alessandra";
    people_arr[2].nome = "Francesco";
    people_arr[3].nome = "Aang";
    people_arr[4].nome = "Denys";
    people_arr[5].nome = "Anna";
    people_arr[6].nome = "George";
    people_arr[7].nome = "Vladyslav";
    
    Grouplist grouplist;
    
    while (stop == 0){
        for(int a=0; a < groupsize; a++){
            if(people_arr[a].nome != "")
                grouplist.countgroup++;
        }

            std::cout<<  "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
            std::cout<<std::endl<< "\nScegli la operazione che vuoi farlo\n"<<std::endl;
            std::cout<< "1.RICERCA DOPPIE, VOCALI E CONSONANTI"            <<std::endl
            << "\n0.Esci dal applicazione"  <<std::endl;
            std::cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
            std::cout<<std::endl;
            std::cout<<"\nazione n.";
            std::cin>>switcher;
            std::cout<<std::endl;
            
            switch(switcher){
                case '1':
                checkGroup(people_arr, grouplist, grouplist.countgroup);
                break;
                case '0':
                stop = 1;
                break;
                default:
                std::cout<<std::endl<<"Hai sbagliato a scegliere la operazione, per favore riprova";
            }
        if(stop)
        break;
    }
    
    return 0;
}