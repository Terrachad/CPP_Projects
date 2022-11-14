/******************************************************************************
Olshevskyi Vladyslav
*******************************************************************************/
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

char switcher;
bool stop = 0;
bool filebool = 0;
const char space = ' ';

void writeTo(){
    std::fstream fileCNTRL;
    
    fileCNTRL.open("testo1.txt", std::ios::out); //mode to write to text file 
    if(fileCNTRL.is_open() ) {
        fileCNTRL << "Hello i'm a good text what needs to be copied\n";
        fileCNTRL << "Hello i'm a second good text what needs to be copied\n";
        fileCNTRL << "Hello i'm a third good text andhereistheerror2\n";
        fileCNTRL << "Error1 and i'm a bad text which need to stay in file1\n";
        fileCNTRL << "Proof what i've stopped\n";
        fileCNTRL.close();
    }
    
    fileCNTRL.open("testo2.txt", std::ios::out); //mode to write to text file 
    if(fileCNTRL.is_open() ) {
        fileCNTRL << "Hello i'm a good text what needs to be copied\n";
        fileCNTRL << "Hello i'm a second good text what needs to be copied\n";
        fileCNTRL << "Hello i'm a third good text andhereistheerror2\n";
        fileCNTRL << "Error2 and i'm a bad text which need to stay in file2\n";
        fileCNTRL << "Proof what i've stopped\n";
        fileCNTRL.close();
    }
}


void readLine(){
        std::ifstream inTesto1("testo1.txt");
        std::ifstream inTesto2("testo2.txt");  
        std::fstream fileCNTRL;

        fileCNTRL.open("db.txt", std::ios::app);
            if(fileCNTRL.is_open() ) {
                fileCNTRL << std::endl;
                fileCNTRL.close();
            }

        while( (!inTesto1.eof() & !inTesto2.eof())  ){

                std::string strOne, strTwo,line;
                
                std::getline(inTesto1,strOne,space); 
                std::getline(inTesto2,strTwo,space);
                
                if( (strOne == strTwo)){
                fileCNTRL.open("db.txt", std::ios::app); //mode to write to text file 
                    if(fileCNTRL.is_open() ) {
                    fileCNTRL << strOne << space;
                    }       
                }
                else if(strOne != strTwo)
                break;

            fileCNTRL.close();

        }
}


int main()
{
        while (stop == 0){

            std::cout<<  "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
            std::cout<<std::endl<< "\nScegli la operazione che vuoi farlo\n"<<std::endl;
            std::cout<< "1.Creare due file con testo preimpostato"<<std::endl;
            std::cout<< "2.Copia in file texto3.txt solo la parte iniziale di testo1 e testo2 se sono uguali"<<std::endl
            << "\n0.Esci dal applicazione"  <<std::endl;
            std::cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
            std::cout<<std::endl;
            std::cout<<"\nazione n.";
            std::cin>>switcher;
            std::cout<<std::endl;
            
            switch(switcher){
                case '1':
                writeTo();
                break;
                case '2':
                readLine();
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