/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

typedef struct Automobiles{
    std::string marca;
    int cilindrata;
    int annoimm;
}Automobiles;


typedef struct Person{
    std::string nome;
    std::string cognome;
    Automobiles car;
}Person;

void printAutomobiles(Automobiles car){
    std::cout<<std::endl;
    std::cout<<"Marca del auto: "<< car.marca<<std::endl;
    std::cout<<"Cilindrata del auto: "<< car.cilindrata<< "cc"<<std::endl;
    std::cout<<"Anno di immatricolazione del auto: "<<car.annoimm<<std::endl;
}

void printPerson(Person person){
    std::cout<<std::endl;

    printAutomobiles(person.car);
    std::cout<<std::endl<<"Nome e Cognome di proprietario: "<<person.nome << " "<<person.cognome<<std::endl;
    
    std::cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
}

void printPersonInfo(Person pers_arr[]){
    for(int i = 0; i < 5; i++)
        printPerson(pers_arr[i]);
}

void checkCarCC(Automobiles car_arr[], Person pers_arr[]){
    std::cout<< std::endl<< std::endl << "Auto con cilindrata superiore a 1800cc" << std::endl << std::endl;
    for(int i = 0; i < 5; i++){
        if(car_arr[i].cilindrata > 1800){
            std::cout <<"• "<<pers_arr[i].cognome << " ( "<< car_arr[i].cilindrata<< "cc  " << car_arr[i].marca << " )"<<std::endl;
        };
    }
}

void checkAnnoImma(Automobiles car_arr[], Person pers_arr[]){
    int anno = 0;
    int count = 0;
    std::cout<< std::endl<< std::endl << "Inserisci l'anno di immatricolazione che vuoi trovare ";
    std::cin>>anno;
    std::cout<< std::endl << std::endl;
    for(int i = 0; i < 5; i++){
        if(car_arr[i].annoimm == anno){
            std::cout <<"• "<<pers_arr[i].cognome << " ( "<< car_arr[i].marca << " immatricolata in " <<car_arr[i].annoimm<< " )"<<std::endl;
            count++;
        };
    }
    std::cout<<std::endl<<"Il numero delle macchine immatricolate in "<< anno << " : "<< count<< std::endl<< std::endl;
}

void printMarceList(Automobiles car_arr[], Person pers_arr[]){
    std::string marca;
    std::cout<< std::endl<<std::endl<< "Stampa la lista delle marce delle auto disponibili in autosalone e fai ricerca: " << std::endl;
    for(int i = 0; i < 5; i++){
        std::cout <<"• "<< car_arr[i].marca << " |" ;
    }
    std::cout<<std::endl;
    std::cout<<"Quale marca cerchi? ";
    std::cin>>marca;
    
    
    for(int i = 0; i < 5; i++){
        if(car_arr[i].marca == marca)
        std::cout <<"• "<<pers_arr[i].cognome << " ( "<< car_arr[i].marca << " immatricolata in " <<car_arr[i].annoimm<< " )"<<std::endl;
        
    }
}

void mainApp(Automobiles car_arr[], Person pers_arr[]){
    int switcher;
    bool stop = 0;
    
    while(stop == 0){
    std::cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
    std::cout<<std::endl<< "\nScegli la operazione che vuoi farlo\n"<<std::endl;
    std::cout<< "1.Stampa le macchine e i proprietari"<<std::endl
             << "2.Verificare quale macchine hanno la cilindrata superiore a 1800cc"<<std::endl
             << "3.Stampa le marce disponibili o cercha per merca"<<std::endl
             << "4.Trova proprietario per l'anno di immatricolazione"<<std::endl
             << "0.Esci dal applicazione"<<std::endl;
             std::cout<<std::endl;
    
    std::cin>>switcher;
    
        switch(switcher){
            case 1:
            printPersonInfo(pers_arr);
            break;
            case 2:
            checkCarCC(car_arr, pers_arr);
            break;
            case 3:
            printMarceList(car_arr, pers_arr);
            break;
            case 4:
            checkAnnoImma(car_arr, pers_arr);
            break;
            case 0:
            stop = 1;
            break;
            default:
            printPersonInfo(pers_arr);//print person info
        
            checkCarCC(car_arr, pers_arr);//check car con cilindrata superiore a 1800cc
        
            printMarceList(car_arr, pers_arr); //print list of avalible cars
        
            checkAnnoImma(car_arr, pers_arr);//check anno di immatricolazione
        }
        
    if(stop)
    break;
    }
}

int main()
{
    
    
    
        Automobiles car_arr[5];
        
    car_arr[0].marca = "Ford";
    car_arr[0].cilindrata = 1600;
    car_arr[0].annoimm = 2005;

    car_arr[1].marca = "Bentley";
    car_arr[1].cilindrata = 2500;
    car_arr[1].annoimm = 2018;

    car_arr[2].marca = "Mazda";
    car_arr[2].cilindrata = 1850;
    car_arr[2].annoimm = 2008;
    
    car_arr[3].marca = "Toyota";
    car_arr[3].cilindrata = 2000;
    car_arr[3].annoimm = 2005;
    
    car_arr[4].marca = "Mercedes";
    car_arr[4].cilindrata = 2200;
    car_arr[4].annoimm = 2015;
    
        Person pers_arr[5];
    pers_arr[0].nome = "Vladyslav";
    pers_arr[0].cognome = "Olshevskyi";
    pers_arr[0].car = car_arr[0];
    
    pers_arr[1].nome = "Satoshi";
    pers_arr[1].cognome = "Nakamoto";
    pers_arr[1].car = car_arr[1];
    
    pers_arr[2].nome = "Denys";
    pers_arr[2].cognome = "Karpenko";
    pers_arr[2].car = car_arr[2];
    
    pers_arr[3].nome = "Mari";
    pers_arr[3].cognome = "Laykina";
    pers_arr[3].car = car_arr[3];
    
    pers_arr[4].nome = "Anna";
    pers_arr[4].cognome = "Karenina";
    pers_arr[4].car = car_arr[4];
    
    mainApp(car_arr, pers_arr);
    
    return 0;
}




