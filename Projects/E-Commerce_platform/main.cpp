#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <ctime>

const char comma = ',';     
char switcher;              
bool stop = 0; 
std::string eur = "€";

const int sizemagazzino = 100;
const int sizeutenti = 10;
const int sizecarello = 15;

int countusers = 0, countproducts = 0, carellonumprodotti = 0, quantitacurrent = 0;
std::string currentuser;
bool userlogged = 0;

char front = '/';
char back = '\\';

typedef struct Magazzino{
    std::string nomeprodotto;
    std::string produttore;
    double prezzo;
    int quantita;
    std::string hash;
}Magazzino;

typedef struct Carello{
    
    std::string hashcarello[sizecarello];
    double totaleprezzo;
    int itemscarello[sizecarello];
    std::string carellonomeutente;
    int quantitacurrent[sizecarello];
    
    Magazzino magazzino;
}Carello;

typedef struct User{
    
    std::string nomeutente;
    std::string password;
    int carellonum;
    int userid;
    
    Carello carello;
}User;

void printDivider(){
    std::cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - -"<<std::endl <<std::endl;
};

void printScontrinoDivUp(){

    std::string scontinodiv;
    for(int s = 0; s < 50; s++){
        if(s%2==0)
            std::cout<<front;
        else
            std::cout<<back;
    }
    std::cout<<std::endl;
}

void printScontrinoDivDown(){
    std::string scontinodiv;
    for(int s = 0; s < 50; s++){
        if(s%2==0)
            std::cout<<back;
        else
            std::cout<<front;
    }
    std::cout<<std::endl;
}

void printLogo(){
    std::fstream fileCNTRL;                         
    fileCNTRL.open("logo.txt", std::ios::in); 
    std::string line; 
    if(fileCNTRL.is_open() )                       
        while ( getline (fileCNTRL, line) )       
            std::cout<<line<<std::endl;     
            
    fileCNTRL.close(); 
}

void printScontrinoSpace(int a){
    for(int g = 0; g < a; g++)
        std::cout<<"|                                                |"<<std::endl;
}

void LoginUser(User users_array[]){
    std::string login;
    std::string temppassword;
    
    std::cout<<std::endl;
    std::cout<<"Inserisci il tuo nome utente: ";
    std::cin>>login;
    std::cout<<"Inserisci la tua password: ";
    std::cin>>temppassword;
    for(int i = 0; i < countusers; i++){
        if(login ==  users_array[i].nomeutente && temppassword == users_array[i].password){
            currentuser = login;
            userlogged = 1;
        }
        else
            std::cout<<"Utente non trovato"<<std::endl;
    }
    
}

void printSpaces(int len,int tmpsize){
    for(int g = 0; g < len - tmpsize; g++)
        std::cout<<" ";
    std::cout<<"|";
}


void printProducts(Magazzino magazzino_array[]){        
    
    int tmpsize = 0;
    std::string tmpstring = "";
    std::cout<<std::endl;
    
    if(countproducts > 0){
        std::cout<<"____________________________________________________________________________________."<<std::endl<<std::endl;
        std::cout<<" N. |"<< "        Prodotto        |"<<"        Produttore        |" <<"  pz  |"<<"  Prezzo            |"<<std::endl;
        std::cout<<"____________________________________________________________________________________."<<std::endl;
        printSpaces(84, 0);
        std::cout<<std::endl;
        for(int i = 0 ; i < countproducts; i++){           

        std::cout<<"n."<< i+1  <<" | "<< magazzino_array[i].nomeprodotto;
        tmpsize = magazzino_array[i].nomeprodotto.length();
        printSpaces(23, tmpsize);
        
        std::cout<<" "<< magazzino_array[i].produttore;
        tmpsize = magazzino_array[i].produttore.length();
        printSpaces(25, tmpsize);
        
        std::cout<< magazzino_array[i].quantita;
        tmpstring += std::to_string(magazzino_array[i].quantita);
        tmpsize = tmpstring.length();
        printSpaces(6, tmpsize);
        tmpstring = "";
        
        std::cout<< magazzino_array[i].prezzo   << eur;
        tmpstring += std::to_string(magazzino_array[i].prezzo);
        tmpsize = tmpstring.length() + 1;
        printSpaces(24, tmpsize);
        tmpstring = "";
        
        std::cout<<std::endl;
        }
        std::cout<<"____________________________________________________________________________________."<<std::endl;
    }
    else
        std::cout<<"Nessun prodotto nel magazzino"<<std::endl;
}

void readMagazzinoFromFile(Magazzino magazzino_array[]){              

    int g=0;                                        
    std::fstream fileCNTRL;                         
    fileCNTRL.open("db_magazzino.txt", std::ios::in);   
    if(fileCNTRL.is_open() ) {                      
        std::string line; 
        while ( getline (fileCNTRL, line) ){       
            
                std::istringstream iss(line);     

                std::string data,tmp;                   
                
                getline(iss, data, comma);          
                magazzino_array[g].nomeprodotto = data;            
                
                getline(iss, data, comma);          
                magazzino_array[g].produttore = data;            
                
                getline(iss, data, comma);         
                magazzino_array[g].quantita = std::stoi(data);               
                
                getline(iss, data, comma);          
                magazzino_array[g].prezzo = std::stod(data);        
                
                getline(iss, data, comma);
                magazzino_array[g].hash = data;
                ++g;                                
        }
    }
    fileCNTRL.close();                          
    std::cout<<std::endl;                           
}

void searchForHash(Magazzino magazzino_array[],Carello &carello, std::string hashtry, int pos){
    int i = 0; 
    hashtry[0] = toupper(hashtry[0]);
    for(i = 0; i <= countproducts; i++)            
        if (magazzino_array[i].hash.find(hashtry) != std::string::npos )   
            carello.itemscarello[pos] = i ;
    
}

void readCarelloFromFile(Magazzino magazzino_array[], Carello &carello, User users_array[]){              

    int g=0, a = 0;                                        
    std::fstream fileCNTRL;
    
    if(userlogged)
        fileCNTRL.open("db_carello_" + currentuser + ".txt", std::ios::in);  
    else
        fileCNTRL.open("db_carello_guest.txt", std::ios::in); 
    
    if( fileCNTRL.is_open() ) {                      
        std::string line;
        
        while ( getline (fileCNTRL,line, comma) ){
                if(g == 0)
                    carello.carellonomeutente = line;
                else if(g == 1)
                    carellonumprodotti = stoi(line);
                if(g > 1 )
                    break;
                    
                g++;
        }
        
    a = 0, g = 0;
    
    fileCNTRL.close();
    
    std::fstream fileCNTRL;
    
    if(userlogged)
        fileCNTRL.open("db_carello_" + currentuser + ".txt", std::ios::in);  
    else
        fileCNTRL.open("db_carello_guest.txt", std::ios::in); 
    
        while ( getline (fileCNTRL,line) ){
            
                if(g > 0){
                    
                    std::istringstream iss(line); 
                    
                    std::string data,tmp;        
                    
                    getline(iss, data, comma);          
                    carello.quantitacurrent[a] = std::stoi(data);
                    
                    getline(iss, data, comma);          
                    carello.hashcarello[a] = data; 
                    
                    searchForHash(magazzino_array , carello, carello.hashcarello[a], a);
                    
                    a++;
                }   
                
                g++;
        }        
    }
        
    fileCNTRL.close(); 
}

void makeScontrino(Magazzino magazzino_array[], Carello &carello, User users_array[]){
    
    int i,tmpsize = 0, b = 0;
    std::string tmpstring;
    double currentprezzo;
    carello.totaleprezzo = 0;
    
    if(carellonumprodotti > 0){
        printScontrinoDivUp();
        printScontrinoSpace(2);
        std::cout<<"|                    Scontrino                   |"<<std::endl;
        printScontrinoSpace(1);
        
        for(i = 0; i < carellonumprodotti; i++){
            
            currentprezzo = 0;
            tmpsize = 0;
            tmpstring = "";
            currentprezzo = magazzino_array[carello.itemscarello[i]].prezzo * carello.quantitacurrent[i];
            carello.totaleprezzo += currentprezzo;
            std::string pricestring = "";
            
            std::stringstream stream1;
            
            stream1 << currentprezzo;
            std::string d = stream1.str();
            pricestring += d;
            
            std::stringstream stream;
            stream << currentprezzo << carello.quantitacurrent[i] << magazzino_array[carello.itemscarello[i]].nomeprodotto;
            std::string s = stream.str();
            
            tmpstring += s;
            
            tmpsize = tmpstring.length() + 4;
            
            std::cout<<"|";
            
            for(int g = 0; g < 14; g++)
                    std::cout<<" ";

            std::cout<<i + 1<< " " << magazzino_array[carello.itemscarello[i]].nomeprodotto << "(x"  << carello.quantitacurrent[i] << ")"<< std::setprecision(4) << pricestring <<""<<eur;
 
            for(int g = 0; g < 32 - tmpsize; g++)
                std::cout<<" ";
            std::cout<<"|"<<std::endl;
        
        }
        
        tmpstring = "";
        printScontrinoSpace(1);
        printLogo();
        printScontrinoSpace(3);
        
        std::stringstream stream;
        stream << carello.totaleprezzo;
        std::string s = stream.str();
        tmpstring+= s;
        
        tmpsize = tmpstring.length() + 1;
        
            std::cout<<"|";
            for(int g = 0; g < 14; g++)
                    std::cout<<" ";

            std::cout<<"Prezzo totale: "<<tmpstring<<eur;

            for(int g = 0; g < 19 - tmpsize; g++)
                std::cout<<" ";
            std::cout<<"|"<<std::endl;

        printScontrinoSpace(1);
        
            std::cout<<"|";
            for(int g = 0; g < 11; g++)
            std::cout<<" ";
            
            time_t now = time(0);
            char* dt = ctime(&now);
            tm *gmtm = gmtime(&now);
            tmpstring = asctime(gmtm);
            
            tmpstring.erase(tmpstring.find('\n', 0), 1);
            
            tmpstring += " UTC";
            
            tmpsize = tmpstring.length();
            
            std::cout << tmpstring;
            
            for(int g = 0; g < 37 - tmpsize; g++)
                std::cout<<" ";
            std::cout<<"|"<<std::endl;

        printScontrinoSpace(1);    
        printScontrinoDivDown();
        tmpstring = "";
    }
    else
    std::cout<<"Nessun prodotto nel carello"<<std::endl;
    
}

void writeMagazzinoInFile(Magazzino magazzino_array[]){   
    std::fstream fileCNTRL;
    
    fileCNTRL.open("db_magazzino.txt", std::ios::out);          
    if(fileCNTRL.is_open() ) {                              
        for(int i=0;i<countproducts;i++){  
   
            fileCNTRL                                       
            << magazzino_array[i].nomeprodotto << comma                     
            << magazzino_array[i].produttore << comma                     
            << magazzino_array[i].quantita << comma                      
            << magazzino_array[i].prezzo << comma 
            << magazzino_array[i].nomeprodotto[0] << ((int)magazzino_array[i].nomeprodotto[0] + 5) + ((int)magazzino_array[i].nomeprodotto[1] * 3 )  % magazzino_array[i].produttore[0] + magazzino_array[i].nomeprodotto[1] << comma; 
            
            if( i+1 !=countproducts )
            fileCNTRL<<"\n";                                         
        }
        fileCNTRL.close();                                  
    }
}

void writeCarelloInFile(Magazzino magazzino_array[], Carello &carello, User users_array[]){   
    
    
    std::fstream fileCNTRL;
    
    if(userlogged)
        fileCNTRL.open("db_carello_" + currentuser + ".txt", std::ios::out);  
    else
        fileCNTRL.open("db_carello_guest.txt", std::ios::out);  
        
    if(fileCNTRL.is_open() ) {                              
        
            if(userlogged){
                    fileCNTRL                                       
                    << currentuser << comma
                    << carellonumprodotti<< comma                     
                    << std::endl;
            }else{
                    fileCNTRL                                       
                    << "guest" << comma
                    << carellonumprodotti<< comma                     
                    << std::endl;

            }

            for(int a = 0; a < carellonumprodotti; a++){
                if(a+1 == carellonumprodotti)
                fileCNTRL << carello.quantitacurrent[a] << comma << magazzino_array[carello.itemscarello[a]].hash << comma;
                else
                fileCNTRL << carello.quantitacurrent[a] << comma << magazzino_array[carello.itemscarello[a]].hash << comma << "\n" ;
            }
            
        fileCNTRL.close();                                  
    }
    
}

void showCarello(Magazzino magazzino_array[], Carello carello){        
    
    printDivider();
    int tmpsize, a = 0;
    double currentprezzo = 0;
    std::string tmpstring;

    if(carellonumprodotti < 1)
    std::cout<<"Nessun prodotto in carello"<<std::endl;
    else{
    std::cout<< "Numero dei prodotti in carello: " << carellonumprodotti<<std::endl<<std::endl;
        
        std::cout<<"_____________________________________________________."<<std::endl<<std::endl;
        std::cout<<" N. |"<< "        Prodotto        |" <<"  pz  |"<<"     Prezzo     |"<<std::endl;
        std::cout<<"_____________________________________________________."<<std::endl;
        
        
        for(a = 0; a < carellonumprodotti; a++){
        tmpsize = 0;
        
        currentprezzo = magazzino_array[carello.itemscarello[a]].prezzo * carello.quantitacurrent[a];
        carello.totaleprezzo += currentprezzo;
        
        std::cout<<"n."<< a+1  <<" | "<< magazzino_array[carello.itemscarello[a]].nomeprodotto;
        tmpsize = magazzino_array[carello.itemscarello[a]].nomeprodotto.length();
        printSpaces(23, tmpsize);
        
        std::cout<< " "<<carello.quantitacurrent[a];
        tmpstring += std::to_string(carello.quantitacurrent[a]);
        tmpsize = tmpstring.length() + 1;
        printSpaces(6, tmpsize);
        tmpstring = "";
        
        double tmpflat = 0;
        tmpflat = magazzino_array[carello.itemscarello[a]].prezzo * carello.quantitacurrent[a];
        
        std::stringstream stream;
        stream << tmpflat;
        std::string s = stream.str();
            
        tmpstring+= s;
            
        tmpsize = tmpstring.length() + 4;
        std::cout<<" "<< tmpstring  << eur;
        tmpsize = tmpstring.length() + 1;
        printSpaces(15, tmpsize);
        tmpstring = "";
        std::cout<<std::endl;
        
        }
        std::cout<<"_____________________________________________________."<<std::endl;
    }
}

void modifyCarello(Magazzino magazzino_array[], Carello &carello){
    
    int g = 0, changeline = 0;
    bool qntflag = 0, sameflag = 0;
    double pricetmp = 0;
    quantitacurrent = 0;
    std::string line, column;
    
    
    showCarello(magazzino_array, carello);
    
    pricetmp =  carello.quantitacurrent[changeline];
    pricetmp *= magazzino_array[carello.itemscarello[changeline]].prezzo;
    
    if(carellonumprodotti > 0){
        std::cout <<std::endl;
        printDivider();
        std::cout << "Se vuoi cambiare la quantita digita la posizione del prodotto in carello: ";
        std::cin >> changeline;
        changeline = changeline - 1;
        
        int carellokey= 0;
        for(int j = 0; j < carellonumprodotti; j++){
            if(magazzino_array[carello.itemscarello[changeline]].hash == carello.hashcarello[j]){
                carellokey = j;
            }
        }
        
        if(changeline < carellonumprodotti && changeline >=0 ){
        printDivider();     
        std::cout<< "Prodotto n.:"                   << changeline +1   << " di " << carellonumprodotti                                         <<std::endl <<std::endl;        
        std::cout<< "Nome prodotto: "                << magazzino_array[carello.itemscarello[changeline]].nomeprodotto                                      <<std::endl;    
        std::cout<< "Produttore: "                   << magazzino_array[carello.itemscarello[changeline]].produttore                                        <<std::endl;   
        std::cout<< "Prezzo(1pz): "                  << magazzino_array[carello.itemscarello[changeline]].prezzo << eur                                     <<std::endl; 
        std::cout<< "Quantita ancora disponibile: "  << magazzino_array[carello.itemscarello[changeline]].quantita - carello.quantitacurrent[changeline]    <<std::endl; 
        std::cout<< "Quantita nel carello: "         << carello.quantitacurrent[changeline]                                                                 <<std::endl; 
        std::cout<< "Prezzo(totale): "               << pricetmp << eur                                                                                     <<std::endl; 
        
        while(qntflag == 0){
            
            std::cout << "Inserisci di nuovo la quantita che vorrei mettere nel carello? ";
            std::cin >> quantitacurrent;
            
            if(quantitacurrent <= magazzino_array[carello.itemscarello[changeline]].quantita){
                    carello.quantitacurrent[carellokey] = quantitacurrent;
                break;
            }
            else
            std::cout<<"Quantita non disponibile, per favore riprova"<<std::endl;
        
        }
        
        
        std::cout<<"Hai aggiunto "<<magazzino_array[carello.itemscarello[changeline]].nomeprodotto <<" in quantita di " << quantitacurrent<<std::endl;
        
        quantitacurrent = 0;
        sameflag = 0;
        }
        else
        std::cout<<"Hai solo " << carellonumprodotti << " oggetto/i nel carello, prodotto n."<< changeline + 1 << " non esiste, per favore riprova";
    }

}

void fillCarello(Magazzino magazzino_array[], Carello &carello, User users_array[]){
    
    int g = 0, changeline = 0;
    bool qntflag = 0, sameflag = 0;
    std::string line;
    int carellokey = 0;
    printProducts(magazzino_array);
    printDivider();
    
    std::cout << "Numero del prodotto in lista che vuoi aggiungere nel carello? ";
    std::cin >> changeline;
    changeline = changeline - 1;
    if(changeline >= 0 && changeline < countproducts){
        
        int j = 0;
        for(j = 0; j < carellonumprodotti; j++){
            if(magazzino_array[changeline].hash == carello.hashcarello[j]){
                sameflag = 1;
                carellokey = j;
                break;
            }
        }
        
        
        printDivider();     
        std::cout<<"Prodotto n.:"           << changeline+1   << " di " << carellonumprodotti           <<std::endl <<std::endl;        
        std::cout<<"Nome prodotto: "        << magazzino_array[changeline].nomeprodotto                 <<std::endl;    
        std::cout<<"Produttore: "           << magazzino_array[changeline].produttore                   <<std::endl;  
        std::cout<<"Prezzo: "               << magazzino_array[changeline].prezzo  << eur               <<std::endl;
        std::cout<<"+ "      <<std::endl; 
        
        if(sameflag){
            std::cout<<"Quantita in magazzino: "<< magazzino_array[changeline].quantita  -  carello.quantitacurrent[carellokey]   <<std::endl;
            std::cout<<"Hai gia "<<carello.quantitacurrent[carellokey]<<".pz nel carello"<<std::endl;
        }
        else
            std::cout<<"Quantita in magazzino: "<< magazzino_array[changeline].quantita  <<std::endl;
        
        while(qntflag == 0){
                if(sameflag == 1 && carello.quantitacurrent[carellokey]  == magazzino_array[changeline].quantita ){
                    std::cout<<"Hai gia messo nel carello la massima quantita disponibile di questo prodotto"<<std::endl;
                    break;
                }
                else{
                quantitacurrent = 0;
                std::cout << "Quantita che vuoi mettere nel carello? ";
                std::cin >> quantitacurrent;
            
                    if(sameflag == 1 && quantitacurrent > 0){
                        if(carello.quantitacurrent[carellokey] + quantitacurrent <= magazzino_array[changeline].quantita && quantitacurrent >= 0){
                        carello.quantitacurrent[carellokey] = carello.quantitacurrent[carellokey] + quantitacurrent;
                        std::cout<<"Hai aggiunto prodotto '"<<magazzino_array[changeline].nomeprodotto <<"' in quantita di " << quantitacurrent<<std::endl;
                        }
                        else
                        std::cout<<"Quantita non disponibile, per favore riprova"<<std::endl;
                        
                    }
        
                    else if(quantitacurrent > 0){
                        if(quantitacurrent <= magazzino_array[changeline].quantita){
                            carello.quantitacurrent[carellonumprodotti] = quantitacurrent;
                            break;
                        }
                        else
                        std::cout<<"Quantita non disponibile, per favore riprova"<<std::endl;
                        
                    }
                    else if(quantitacurrent == 0){
                        std::cout<<"Nessun prodotto aggiunto"<<std::endl;
                        break;
                    }
            }    
        }
        
        if(!sameflag)
        carello.itemscarello[carellonumprodotti] = changeline;
        
        carello.carellonomeutente = currentuser;        
        
        if(!sameflag)
        carellonumprodotti++;
        
        
        sameflag = 0;
        qntflag = 0;
    }
    else{
        printDivider();
        std::cout<<"Ci sono solo " << countproducts <<" prodotti nel magazzino, per favore riprova ";
    }
}

void readUsersFromFile(User users_array[]){               

    int g=0;                                    
    std::fstream fileCNTRL;                        
    fileCNTRL.open("db_users.txt", std::ios::in);  
    if(fileCNTRL.is_open() ) {                      
        std::string line; 
        while ( getline (fileCNTRL, line) ){       
            
                std::istringstream iss(line);     
                if(line == "")
                break;
                std::string data;                   
                
                getline(iss, data, comma);          
                users_array[g].nomeutente = data;
                
                getline(iss, data, comma);          
                users_array[g].password = data;           
                
                getline(iss, data, comma);          
                users_array[g].userid = std::stoi(data);   
                
        }
    }
    fileCNTRL.close();
}

void writeUsersInFile(User users_array[]){   
    std::fstream fileCNTRL;
    
    fileCNTRL.open("db_users.txt", std::ios::out);          
    if(fileCNTRL.is_open() ) {                              
        for(int i=0;i<countusers;i++){            
            
            fileCNTRL                                       
            << users_array[i].nomeutente << comma                     
            << users_array[i].password << comma                     
            << users_array[i].userid << comma                      
            <<"\n";                                         
        }
        fileCNTRL.close();                                  
    }
    
}

void askForNewProduct(Magazzino magazzino_array[]){ 
        std::string tmpstring;
        
        std::cout<<"Inserisci i dati del prodotto"<<std::endl;
        
        std::cin.ignore();                                               
        std::cout<<"Inserisci nome del prodotto: ";                               
        std::getline( std::cin, magazzino_array[countproducts].nomeprodotto ); 
        magazzino_array[countproducts].nomeprodotto[0] = toupper(magazzino_array[countproducts].nomeprodotto[0]); 
        
        std::cout<<"Inserisci produttore: ";
        std::getline( std::cin, magazzino_array[countproducts].produttore ); 
        magazzino_array[countproducts].produttore[0] = toupper(magazzino_array[countproducts].produttore[0]); 
        
        std::cout<< "Inserisci quantita disponibile: ";
        std::cin >>  tmpstring;
        magazzino_array[countproducts].quantita = stoi(tmpstring);
        
        tmpstring = "";
        
        std::cout<< "Inserisci prezzo: ";  
        std::cin >>  tmpstring;
        magazzino_array[countproducts].prezzo = stod(tmpstring);         
        
        countproducts++;                               
        
        writeMagazzinoInFile(magazzino_array);                   
}

void askForNewUser(User users_array[], Carello carello){ 
        bool userins = 0, exitbool = 0;
        
        std::string tempnomeutente;
        std::string temppassword;
        
        std::cout<<"Inserisci i dati del user";
        
        std::cin.ignore();  
        
        while(exitbool == 0){
            
            userins = 0;
            std::cout<<std::endl<<"Inserisci nome utente: ";  
            std::getline(std::cin, tempnomeutente); 
                
            for(int a=0; a < countusers; a++)
                if(tempnomeutente == users_array[a].nomeutente)
                     userins = 1;
            if(userins)
                std::cout<<std::endl<<"Username gia registrato";
            else if(userins == 0)
                break;
        }
        
        if(userins == 0){
        users_array[countusers].nomeutente = tempnomeutente;
        
        std::cout<<std::endl<<"Inserisci password utente"<<std::endl;  
        std::getline(std::cin, users_array[countusers].password); 
        
        carello.carellonomeutente = users_array[countusers].nomeutente;
        users_array[countusers].userid = countusers;
        
        }
        
        countusers++;                               
        
        writeUsersInFile(users_array);       
}

void changeProduct(Magazzino magazzino_array[]){
    int g = 0, changeline = 0, helper = 0;
    std::string line, tmpstring;
    
    printProducts(magazzino_array);
    

    std::cout << std::endl << "Numero in lista del prodotto che vuoi modificare? ";
    std::cin >> changeline;
    changeline = changeline - 1;
    
    if(changeline < countproducts && changeline >= 0){
        printDivider();     
        std::cout<<"Prodotto n.:"           << changeline+1   << " di " << countproducts                <<std::endl <<std::endl;        
        std::cout<<"Nome prodotto: "        << magazzino_array[changeline].nomeprodotto                 <<std::endl;    
        std::cout<<"Produttore: "           << magazzino_array[changeline].produttore                   <<std::endl;   
        std::cout<<"Quantita: "             << magazzino_array[changeline].quantita                     <<std::endl;   
        std::cout<<"Prezzo: "               << magazzino_array[changeline].prezzo  << eur               <<std::endl; 
        std::cout<<std::endl<< "Cosa vuoi modificare? "<<std::endl;
        std::cout<<"1.Nome prodotto " <<"2.Produttore " <<"3.Quantita " <<"4.Prezzo " ; 
        
        std::cin>>helper;
        std::cout<<std::endl;
        
        std::cout<<"Inserisci nuovo ";
        std::cin.ignore();  
        
        switch(helper){
            case 1:
                std::cout<< "nome prodotto: ";
                std::getline( std::cin, magazzino_array[changeline].nomeprodotto); 
                magazzino_array[changeline].nomeprodotto[0] = toupper(magazzino_array[changeline].nomeprodotto[0]); 
            break;
            case 2:
                std::cout<< "produttore: ";
                std::getline( std::cin, magazzino_array[changeline].produttore ); 
                magazzino_array[changeline].produttore[0] = toupper(magazzino_array[changeline].produttore[0]);
            break;
            case 3:
                std::cout << "quantita: ";
                std::cin >>  tmpstring;
                magazzino_array[changeline].quantita = stoi(tmpstring);
            break;
            case 4:
                std::cout<< "prezzo: ";
                std::cin >>  tmpstring;
                magazzino_array[changeline].prezzo = stod(tmpstring);
            break;
            default:
                std::cout<< "Nome prodotto: ";
                std::getline( std::cin, magazzino_array[changeline].nomeprodotto); 
                magazzino_array[changeline].nomeprodotto[0] = toupper(magazzino_array[changeline].nomeprodotto[0]); 
        }
        
        writeMagazzinoInFile(magazzino_array);
    }
    else if(changeline >= 0){
        printDivider();
        std::cout<<"Ci sono solo " << countproducts <<" prodotti nel magazzino, per favore riprova ";
    }
    else
    std::cout<<"prodotto n."<< changeline + 1 << " non esiste, per favore riprova";
}

void deleteProductFromCarello(){
    
    
    
    int g = 0, deleteline = 0;
    std::string line;
    std::string tempfilename = "db_carello_" + currentuser + ".txt";
    
    std::ifstream ifstr;
    
    std::cout<<std::endl;
    
    if(userlogged)
        ifstr.open(tempfilename);  
    else
        ifstr.open("db_carello_guest.txt");  
        
    std::ofstream temp;
    temp.open("temp.txt");
    
    if(carellonumprodotti > 0){
        std::cout << "Numero del prodotto nel carello: ";
        std::cin >> deleteline;
        deleteline = deleteline - 1;
        if(deleteline  < carellonumprodotti && deleteline >= 0){
        while (getline(ifstr,line, '\n'))
        {
            if (g != deleteline)
                temp << line <<'\n';
                
            g++;
        }
        
        temp.close();
        ifstr.close();
        
        if(userlogged){
                remove(tempfilename.c_str());
                rename("temp.txt",tempfilename.c_str()); 
            }
        else{
                remove("db_carello_guest.txt");
                rename("temp.txt","db_carello_guest.txt"); 
        }
        
        if(carellonumprodotti != 0)
        carellonumprodotti--;
        
        std::cout<<"Prodotto n." << deleteline+1 << " eliminato con sucesso";
        }
        else
            std::cout<<"Hai solo " << carellonumprodotti <<" prodotti nel carello, per favore riprova ";
        
        temp.close();
        ifstr.close();
    }
}

void deleteProductFromFile(Magazzino magazzino_array[]){
    int g = 0, deleteline = 0;
    std::string line;
    
    std::cout<<std::endl;
    
    std::ifstream ifstr;
    ifstr.open("db_magazzino.txt");
    std::ofstream temp;
    
    temp.open("temp2.txt");
    
    std::cout << "Inserisci il numero del prodotto che vorrei eliminare : ";
    std::cin >> deleteline;
    deleteline = deleteline - 1;
    
    std::cin.ignore();
    
    if(deleteline < countproducts && deleteline >= 0){
        while (getline(ifstr,line, '\n'))
        {
            if (g != deleteline)
                temp << line  <<'\n';
                
            g++;
        }
        temp.close();
        ifstr.close();
        remove("db_magazzino.txt");
        rename("temp2.txt","db_magazzino.txt");
        
        std::cout<<"Prodotto n." << deleteline + 1 << " eliminato con sucesso";
    }
    else{
        printDivider();
        std::cout<<"Prodotto n." << deleteline + 1 << " non esiste. Ci sono solo "<< countproducts << " prodotti nel magazzino"<<std::endl;
    }
    temp.close();
    ifstr.close();
}


int main()
{
    User users_array[sizeutenti];
    
    Carello carello;

    while (stop == 0){
            Magazzino magazzino_array[sizemagazzino];
            readUsersFromFile(users_array);
            
            countusers = 0, countproducts = 0;
            
            readMagazzinoFromFile(magazzino_array);
            
            for(int a=0; a < sizeutenti; a++)    
                if(users_array[a].nomeutente != "")       
                    countusers++;     
                    
            for(int a=0; a < sizemagazzino; a++)   
                if(magazzino_array[a].nomeprodotto != "")     
                    countproducts++;
                
            printDivider();
            
            if(userlogged == 1)
                std::cout<<"Ciao, "<< currentuser<<std::endl<<std::endl;
                
            std::cout<< "Scegli la operazione che vuoi farlo\n"<<std::endl;
            if(userlogged)
                std::cout<< "1.Logout"<<std::endl;
            else if(userlogged == 0){
                std::cout<< "1.Login"<<std::endl;
                
            }
            
            
            std::cout                                       <<std::endl
            << "2.Vedi il magazzino"                        <<std::endl
            << "3.Aggiungi un prodotto nel magazzino"        <<std::endl
            << "4.Modifica un prodotto nel magazzino"        <<std::endl
            << "5.Elimina il prodotto dal magazzino"        <<std::endl
                                                            <<std::endl
            << "6.Vedi il tuo carello"                      <<std::endl
            << "7.Elimina un prodotto dal carello"          <<std::endl
            << "8.Aggiungi un prodotto nel carello"          <<std::endl
            << "9.Cambia la qnt. di un prodotto nel carello" <<std::endl
            << "S.Stampa lo scontrino"                      <<std::endl;
            
            if(!userlogged)
            std::cout<< "R.Registrati/Aggiungi nuovo user"  <<std::endl;
            
            std::cout
            << "\n0.Esci dal applicazione"                  <<std::endl;
            printDivider();
            
            std::cout<<"\nazione n.";
            std::cin>>switcher;
            
            switcher = toupper(switcher);
            
            switch(switcher){
                case '1':
                    writeCarelloInFile(magazzino_array,carello, users_array);
                    if(userlogged){
                        userlogged = 0;
                        currentuser = "";
                    }
                    else if(userlogged == 0)
                        LoginUser(users_array);
                    readCarelloFromFile(magazzino_array,carello, users_array);
                break;
                case '2':
                printProducts(magazzino_array);
                break;
                case '3':
                askForNewProduct(magazzino_array);
                break;
                case '4':
                changeProduct(magazzino_array);
                break;
                case '5':
                readMagazzinoFromFile(magazzino_array);
                printProducts(magazzino_array);
                deleteProductFromFile(magazzino_array);
                break;
                case '6':
                readCarelloFromFile(magazzino_array,carello, users_array);
                showCarello(magazzino_array, carello);
                break;
                case '7':
                readCarelloFromFile(magazzino_array,carello, users_array);
                showCarello(magazzino_array, carello);
                deleteProductFromCarello();
                writeCarelloInFile(magazzino_array,carello, users_array);
                readCarelloFromFile(magazzino_array,carello, users_array);
                break;
                case '8':
                readCarelloFromFile(magazzino_array,carello, users_array);
                fillCarello(magazzino_array,carello, users_array);
                writeCarelloInFile(magazzino_array,carello, users_array);
                break;
                case '9':
                readCarelloFromFile(magazzino_array,carello, users_array);
                modifyCarello(magazzino_array, carello);
                writeCarelloInFile(magazzino_array,carello, users_array);
                readCarelloFromFile(magazzino_array,carello, users_array);
                break;
                case 'R':
                askForNewUser(users_array, carello);
                break;
                case 'S':
                readCarelloFromFile(magazzino_array,carello, users_array);
                makeScontrino(magazzino_array,carello, users_array);
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