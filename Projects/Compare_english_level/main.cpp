/******************************************************************************
Olshevskyi Vladyslav 01.04.2022
*******************************************************************************/
#include <iostream>

const int cs = 10;

typedef struct Classe{
    std::string classe;
}Classe;

typedef struct LangLvl{
    std::string studlvl;
    Classe classe;
}LangLvl;

typedef struct Studente{
    std::string nome;
    int studid;
    Classe classe;
    LangLvl lnglvl;
}Studente;

void printStud(Studente stud_arr[], LangLvl lnglvl_arr[], Classe class_arr[]){
    for(int i = 0; i < cs; i++){
        std::cout<< "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n"  <<std::endl;
        std::cout<< "Nome dell studente: "  << stud_arr[i].nome      <<std::endl;
        std::cout<< "Id dell studente: "    << stud_arr[i].studid+1  <<std::endl;
        std::cout<< "Livello Lingustico: "  << lnglvl_arr[i].studlvl <<std::endl;
        std::cout<< "Classe Frequentata: "  << class_arr[i].classe   <<std::endl;
    }
        std::cout<< "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"  <<std::endl;
}

void checkLevel(Studente stud_arr[], LangLvl lnglvl_arr[], Classe class_arr[])
{
    int i = 0, b = 0;
    std::cout<<std::endl;
    for(i = 0; i < cs; i++){
        for(int b=i+1; b < cs; b++){
            if(lnglvl_arr[i].studlvl[0] + lnglvl_arr[i].studlvl[1] > lnglvl_arr[b].studlvl[0] + lnglvl_arr[b].studlvl[1]){
                if(class_arr[i].classe[0] < class_arr[b].classe[0] ){
                    std::cout<<stud_arr[i].nome 
                    <<" dalla classe inferiore (" << class_arr[i].classe <<") ha livello lingustico (" << lnglvl_arr[i].studlvl 
                    << ") superiore a " <<stud_arr[b].nome<< " dalla classe " << class_arr[b].classe << " con livello lingustico " << lnglvl_arr[b].studlvl <<std::endl;
                }
            }
        }
    }
}

int main()
{
        Studente stud_arr[cs];
        LangLvl lnglvl_arr[cs];
        Classe class_arr[cs];
        
        stud_arr[0].nome = "Vladyslav";     stud_arr[0].studid = 0;         lnglvl_arr[0].studlvl = "A1";       class_arr[0].classe = "3I";
        stud_arr[1].nome = "Denys";         stud_arr[1].studid = 1;         lnglvl_arr[1].studlvl = "B2";       class_arr[1].classe = "5F";
        stud_arr[2].nome = "Maria";         stud_arr[2].studid = 2;         lnglvl_arr[2].studlvl = "C2";       class_arr[2].classe = "4C";
        stud_arr[3].nome = "Anna";          stud_arr[3].studid = 3;         lnglvl_arr[3].studlvl = "A2";       class_arr[3].classe = "4I";
        stud_arr[4].nome = "Francesco";     stud_arr[4].studid = 4;         lnglvl_arr[4].studlvl = "C1";       class_arr[4].classe = "5I";
        stud_arr[5].nome = "Antonio";       stud_arr[5].studid = 5;         lnglvl_arr[5].studlvl = "A1";       class_arr[5].classe = "3I";
        stud_arr[6].nome = "Bob";           stud_arr[6].studid = 6;         lnglvl_arr[6].studlvl = "C2";       class_arr[6].classe = "2F";
        stud_arr[7].nome = "George";        stud_arr[7].studid = 7;         lnglvl_arr[7].studlvl = "B1";       class_arr[7].classe = "1C";
        stud_arr[8].nome = "Kristina";      stud_arr[8].studid = 8;         lnglvl_arr[8].studlvl = "A2";       class_arr[8].classe = "4I";
        stud_arr[9].nome = "Roman";         stud_arr[9].studid = 9;         lnglvl_arr[9].studlvl = "A1";       class_arr[9].classe = "5I";

        printStud(stud_arr, lnglvl_arr, class_arr);
        checkLevel(stud_arr, lnglvl_arr, class_arr);
    
    return 0;
}


