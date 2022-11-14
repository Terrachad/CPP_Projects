/******************************************************************************

Codice Fiscale - Vladyslav Olshevskyi 27/04/2022

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>
#include <cctype>

char cf[16], cognomecf[3];
char consonanti[21] = {'B','C', 'D', 'F', 'G', 'H', 'L', 'M', 'N', 'P', 'Q', 'R','S', 'T', 'V', 'Z', 'K', 'J', 'W', 'X', 'Y'};
char vocali[6] = {'A','E', 'I', 'O', 'U'};
std::string matrix[12][2];
int size,sizelet,tmp,tmp2;
bool sesso; // 0 - maschile ; 1 - feminile
const char comma = ',';
std::string comune;


void fillCFcomune(std::string comune)
{
    
    std::fstream fileCNTRL;
    
    int i = 0;
    bool flag = 0;
    bool eq = 0;

    fileCNTRL.open("comuni-pt1.txt", std::ios::in);//read from file 
    if(fileCNTRL.is_open() ) {
        std::string line;
        while ( getline (fileCNTRL, line, comma) ){
                i++;
                if (line.find(comune) != std::string::npos) {
                    for(int j=0; j < line.size();j++){
                        if(line[j+1] == comune[j] && line.size() - 1 == comune.size())
                        flag = 1;
                        else
                        flag = 0;
                        
                        
                    }
                }
                if(flag ==1 && i%2==0){
                        cf[11] = line[0];
                        cf[12] = line[1];
                        cf[13] = line[2];
                        cf[14] = line[3];
                        break;
                }
        }
    }
    fileCNTRL.close();
    
    flag = 0;
    eq = 0;
    i = 0;

    fileCNTRL.open("comuni-pt2.txt", std::ios::in);//read from file 
    if(fileCNTRL.is_open() ) {
        std::string line;
        while ( getline (fileCNTRL, line, comma) ){
                i++;
                if (line.find(comune) != std::string::npos) {
                    for(int j=0; j < line.size();j++){
                        if(line[j+1] == comune[j] && line.size() - 1 == comune.size())
                        flag = 1;
                        else
                        flag = 0;
                    }
                }
                if(flag ==1 && i%2==0){
                        cf[11] = line[0];
                        cf[12] = line[1];
                        cf[13] = line[2];
                        cf[14] = line[3];
                        break;
                }
        }
    }
    fileCNTRL.close();
    
    flag = 0;
    eq = 0;
    i = 0;

    fileCNTRL.open("STATIESTERI.txt", std::ios::in);//read from file 
    if(fileCNTRL.is_open() ) {
        std::string line;
        while ( getline (fileCNTRL, line, comma) ){
                i++;
                if (line.find(comune) != std::string::npos) {
                    for(int j=0; j < line.size();j++){
                        if(line[j+1] == comune[j] && line.size() - 1 == comune.size())
                        flag = 1;
                        else
                        flag = 0;
                        
                        
                    }
                }
                if(flag ==1 && i%2==0){
                        cf[11] = line[0];
                        cf[12] = line[1];
                        cf[13] = line[2];
                        cf[14] = line[3];
                        break;
                }
        }
    }
    fileCNTRL.close();
    
}


void fillCFcognome(char* cognome){
    int i = 0, j = 0, k = 0, p = 0;
    int countcons = 0, countvoc = 0;
    
    size = strlen(cognome);
    
        for(j = 0; j < size;j++){
            for(k = 0; k < 21; k++){
                if( (cognome[j] == consonanti[k] || (int)cognome[j] == (int)consonanti[k] + 32) && i<3 && countcons < 3){
                    cf[i] = cognome[j];
                    i++;
                    countcons++;
                    }
                }
            tmp = j;
        }
        
        for(j = 0; j < size;j++){
            for(k = 0; k < 7; k++){
                if( (cognome[j] == vocali[k] || (int)cognome[j] == (int)vocali[k] + 32) && i<3 && countvoc < 1){
                    cf[i] = cognome[j];
                    i++;
                    countvoc++;
                    }
                }
            tmp = j;
        }
        
        if(tmp == size-1 && i < 3 && countvoc < 2){
            do{
                cf[i] = 'X';
                i++;
                
            }while(i<3);   
        }
        

    
    //std::cout<<cf;  - debug
}

void fillCFnome(char* nome){
    int i = 0, j = 0, k = 0;
    int countcons = 0, countvoc = 0, position = 0, key = 0;
    
    size = strlen(nome);

    for(j = 0; j < size;j++){
        for(k = 0; k < 21; k++){
        if( (nome[j] == consonanti[k] || (int)nome[j] == (int)consonanti[k] + 32)){
            countcons++;
            }
        }
        
    }

    for(j = 0; j < size;j++){
        for(k = 0; k < 21; k++){
            if( (nome[j] == consonanti[k] || (int)nome[j] == (int)consonanti[k] + 32) && i <= 3){
                if( position == 1 && countcons > 3)
                    ++position;
                else if( position == 1 && countcons < 3){
                    cf[key + 3] = nome[j];
                    position++;
                    key++;
                    i++;
                }
                else{
                cf[key + 3] = nome[j];
                position++;
                i++;
                key++;
                }
            }
        }
    }
        
    for(j = 0; j < size;j++){
            for(k = 0; k < 7; k++){
                if( (nome[j] == vocali[k] || (int)nome[j] == (int)vocali[k] + 32))
                    countvoc++;
        }
    }
    
    
    for(j = 0; j < size;j++){
        for(k = 0; k < 7; k++){
            if( (nome[j] == vocali[k] || (int)nome[j] == (int)vocali[k] + 32) && countcons <3 && i <= 3){
                countvoc++;
                cf[key + 3] = nome[j];
                key++;
                i++;
                }
            }
    }
    
    while(i < 3 ){
            cf[key + 3] = 'X';
            key++;
            i++;
    } 
    //std::cout<<cf[3]<<cf[4]<<cf[5]; - debug
}

void fillCFanno(char* anno){
    cf[6] = anno[2];
    cf[7] = anno[3];
    //std::cout<<cf[6]<<cf[7]; - debug
}

void fillCFgiorno(char* giorno){
    if(sesso == 1){
        //std::cout<<giorno; - debug
        cf[9] = giorno[0] + 4;
        cf[10] = giorno[1];
    }
    else if(sesso == 0){
        //std::cout<<giorno; - debug
        cf[9] = giorno[0];
        cf[10] = giorno[1];
    }
}

void fillCFmese(char* mese){
    
    int c=0;
    int meselen; 
    meselen = strlen(mese);
    
    for(c=0; c < 12;c++){
        if(mese == matrix[c][0]){
            //std::cout<<matrix[c][1];-debug
            cf[8] = matrix[c][1][0];
        }
        
    }
}

void makeBIG(){
    for(int b=0; b < 16; b++){
        cf[b] = (char)toupper(cf[b]);
    }
}


void fillCDC()
{
    char pari[9];
    char dispari[9];
    bool flag = 0;
    char cntrlletter;
    int i = 0,g = 0,resto;
    int dis = 0, par = 0, sum = 0;
    
    int p = 0,d = 0;
    for(int i=0;i < 17; i++){
        if(i%2 == 0){
            dispari[p] = cf[i];
            p++;
        }
        else if(i%2 == 1){
            pari[d] = cf[i];
            d++;
        }
    }
    std::fstream fileCNTRL;
    
    
    for(int a = 0; a<7; a++){
    fileCNTRL.open("PARI.txt", std::ios::in);//read from file 
    if(fileCNTRL.is_open() ) {
        std::string line;
        i=0;
            while ( getline (fileCNTRL, line, comma) ){
                    if(i%2==0){
                        if((char)line[1] == (char)pari[a]){
                        //std::cout<<line[1]<<" ";
                        flag = 1;
                        g++;
                        }
                    //std::cout<<line[1]<<std::endl;
                    //std::cout<<tmp;
                    }
                    if(i%2==1 && flag == 1){
                        //std::cout<<line<<" "<<std::endl;
                        flag=0;
                        //std::cout<<std::stoi(line)<< ' ';
                        par += std::stoi(line);
                    }
                    i++;
                }
            }
           
    fileCNTRL.close();
    }
    //std::cout<<" = "<< par;
    flag = 0;
    i = 0;
    g = 0;
    
    for(int a = 0; a<8; a++){
    fileCNTRL.open("DISPARI.txt", std::ios::in);//read from file 
    if(fileCNTRL.is_open() ) {
        std::string line;
        std::string tmp;
        i=0;
        
            while ( getline (fileCNTRL, line, comma) ){
                    if(i%2==0){
                        if((char)line[1] == (char)dispari[a]){
                        //std::cout<<line[1]<<" ";
                        flag = 1;
                        g++;
                        }
                    //std::cout<<line[1]<<std::endl;
                    //std::cout<<tmp;
    
                    }
                    if(i%2==1 && flag == 1){
                        //std::cout<<line<<" "<<std::endl;
                        flag=0;
                        //std::cout<<std::stoi(line)<< ' ';
                        dis += std::stoi(line);
                    }
                    i++;
                }
            }
           
    fileCNTRL.close();
    }
    //std::cout<<" = "<< dis<<std::endl;
    sum = dis + par;
    resto = sum%26;
    
    flag = 0;

    i = 0;
    int tmp0;

    fileCNTRL.open("RESTO.txt", std::ios::in);//read from file 
    if(fileCNTRL.is_open() ) {
        std::string line;
        i=0;
            while ( getline (fileCNTRL, line, comma) ){
                
                if(i%2==0 )
                    tmp0 = std::stoi(line);
                    //std::cout<<tmp0;//debug
                if(i%2==1 && resto  == tmp0 )
                    flag = 1;
                    //std::cout<<std::endl<<"flag== 1 "<<tmp0<<std::endl<<std::endl; //debug
                    
                if(i%2==1 && flag){
                    //std::cout<<line[0]<<std::endl;  //
                    cntrlletter = line[0];
                    cf[16] = cntrlletter;
                    
                }
                
                flag = 0;
                i++;
                }
            }
           
    fileCNTRL.close();
    
    //std::cout<<" = "<< dis;
    sum = dis + par;
    flag = 0;
    i = 0;
    
    for(int u = 0; u < 17; u++)
        std::cout<<cf[u];
}

int main()
{   
    
    char nome[20];
    char cognome[20];
    char giorno[3];
    char mese[20];
    char anno[5];
    char letsesso;
    
    std::cout<<"Nome? ";
    std::cin>>nome;
    
    std::cout<<"Cognome? ";
    std::cin>>cognome;
    
    std::cout<<"Giorno di nascita? (Es. 02) ";
    std::cin>>giorno;
    
    std::cout<<"Mese di nascita? (Es. Aprile) ";
    std::cin>>mese;
    
    std::cout<<"Anno di nascita? (Es. 1970) ";
    std::cin>>anno; 
    
    std::cin.ignore();
    std::cout<<"Comune o stato estero? (Es. Milano Es.Ucraina) ";
    getline(std::cin, comune);
    
    std::cout<<"Sesso? (M/F)";
    std::cin>>letsesso;
    
    if(letsesso == 'M' || letsesso == 'm')
        sesso = 0;
    else if(letsesso == 'F' || letsesso == 'f')
        sesso = 1;
    
    
    //sesso = 0; // 1 - feminile 

    matrix[0][0] = "Gennaio";
    matrix[0][1] = "A";
    
    matrix[1][0] = "Febbraio";
    matrix[1][1] = "B";
    
    matrix[2][0] = "Marzo";
    matrix[2][1] = "C";
    
    matrix[3][0] = "Aprile";
    matrix[3][1] = "D";
    
    matrix[4][0] = "Maggio";
    matrix[4][1] = "E";
        
    matrix[5][0] = "Giugno";
    matrix[5][1] = "H";
        
    matrix[6][0] = "Luglio";
    matrix[6][1] = "L";
        
    matrix[7][0] = "Agosto";
    matrix[7][1] = "M";
        
    matrix[8][0] = "Settembre";
    matrix[8][1] = "P";
    
    matrix[9][0] = "Ottobre";
    matrix[9][1] = "R";
    
    matrix[10][0] = "Novembre";
    matrix[10][1] = "S";
    
    matrix[11][0] = "Dicembre";
    matrix[11][1] = "T";
    
    fillCFcognome(cognome);
    fillCFnome(nome);
    fillCFanno(anno);
    fillCFmese(mese);
    fillCFgiorno(giorno);
    fillCFcomune(comune);
    makeBIG();
    fillCDC();
    
    return 0;
}











