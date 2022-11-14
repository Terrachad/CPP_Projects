#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

typedef struct Contact{        
    std::string nome;
    std::string cognome;
    std::string cellnum;
    std::string email;
    
}Contact;

typedef struct ContactCount{  
    int contactcount;     
    Contact contact;              
}ContactCount;

const int contactsmax = 128;
const char comma = ',';     
char switcher;              
bool stop = 0;              

void sortContactsBookByName(Contact contacts[], ContactCount ccount){      
        
        int i = 0,j = 0;                                                
        std::cout<<std::endl; 
        for( i = 0; i < ccount.contactcount; i++){                   
            for(j=i+1;j < ccount.contactcount;j++)                      
        	{ 
        		if( (int)contacts[i].nome[0] > (int)contacts[j].nome[0]) 
        		{
        		    Contact tempcontact = contacts[i];                         
        			contacts[i] = contacts[j];                               
        			contacts[j] = tempcontact;                               
        		}
        	}
        }
}

void printContactsList(Contact contacts[], ContactCount ccount){      
    
    for(int i = 0 ; i < ccount.contactcount ; i++){         
    
    std::cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<std::endl <<std::endl;     
    std::cout<<"Contatto n.:"   << i+1   << " di " << ccount.contactcount   <<std::endl <<std::endl;     
    std::cout<<"Nome: "         << contacts[i].nome         <<std::endl;    
    std::cout<<"Cognome: "      << contacts[i].cognome      <<std::endl;   
    std::cout<<"Cellulare: "    << contacts[i].cellnum      <<std::endl;   
    std::cout<<"Email: "        << contacts[i].email        <<std::endl;   
                
    }
}

void protoAskForContact(Contact contacts[], ContactCount ccount){   
        
        std::cout<<"Inserisci i dati del contatto"<<std::endl;
        
        std::cin.ignore();                                               
        std::cout<<"Nome: ";                                
        std::getline( std::cin, contacts[ccount.contactcount].nome ); 
        contacts[ccount.contactcount].nome[0] = toupper(contacts[ccount.contactcount].nome[0]);  
        
        std::cout<<"Cognome: ";
        std::getline( std::cin, contacts[ccount.contactcount].cognome ); 
        contacts[ccount.contactcount].cognome[0] = toupper(contacts[ccount.contactcount].cognome[0]);  
        
        std::cout<<"Cellulare: ";
        std::getline( std::cin, contacts[ccount.contactcount].cellnum );  
        
        std::cout<<"Email: ";
        std::getline( std::cin, contacts[ccount.contactcount].email ); 
        contacts[ccount.contactcount].email[0] = toupper(contacts[ccount.contactcount].email[0]);  
        
        ccount.contactcount++;
        

}

void readBooksFromFile(Contact contacts[], ContactCount ccount){               

    int g=0;                                        
    std::fstream fileCNTRL;                         
    fileCNTRL.open("db_contacts.txt", std::ios::in);  
    if(fileCNTRL.is_open() ) {                      
        std::string line; 
        while ( getline (fileCNTRL, line) ){        
            
                std::istringstream iss(line);       

                std::string data;                  
                
                getline(iss, data, comma);
                if(data != "")
                contacts[g].nome = data;             
                
                getline(iss, data, comma);
                if(data != "")
                contacts[g].cognome = data;            
                
                getline(iss, data, comma);
                if(data != "")
                contacts[g].cellnum = data;               
                
                getline(iss, data, comma);
                if(data != "")
                contacts[g].email = data;             
                          
                
                ++g;                                
                
        }
    }
    fileCNTRL.close();                          
    std::cout<<std::endl;                           
}


void writeContactsInFile(Contact contacts[], ContactCount ccount){  
    std::fstream fileCNTRL;
    
    fileCNTRL.open("db_contacts.txt", std::ios::out);          
    if(fileCNTRL.is_open() ) {                             
        for(int i=0;i<ccount.contactcount;i++){            
            
            fileCNTRL                                      
            << contacts[i].nome << comma                    
            << contacts[i].cognome << comma                   
            << contacts[i].cellnum << comma                       
            << contacts[i].email << comma 
            <<"\n";                                         
        }
        fileCNTRL.close();                                  
    }
    
}

void searchForNameNum(Contact contacts[], ContactCount ccount){
    
    int i;                                                         
    std::string srcstr;                                             
    std::cin.ignore(100, '\n');                                    
    std::cout<<std::endl<<"Inserisci cellulare o nome: ";                  
    std::getline( std::cin, srcstr );  
    srcstr[0] =  toupper(srcstr[0]);
    std::cout<<std::endl;
    for(i = 0; i < ccount.contactcount; i++){                      
        if (contacts[i].nome.find(srcstr) != std::string::npos || contacts[i].cellnum.find(srcstr) != std::string::npos)   
        std::cout << i + 1 << ". "<< contacts[i].nome << " "<< contacts[i].cognome<< " " << contacts[i].cellnum<< " " << contacts[i].email << '\n';
    }
    

}

void deleteFromFile(){
    int g = 0, deleteline = 0;
    std::string line;
    
    std::ifstream ifstr;
    ifstr.open("db_contacts.txt");
    std::ofstream temp;
    temp.open("temp.txt");
    std::cout << "Posizione del contatto ? ";
    std::cin >> deleteline;
    deleteline = deleteline - 1;
    while (getline(ifstr,line, '\n'))
    {
        if (g != deleteline)
            temp << line <<'\n';
            
        g++;
    }
    temp.close();
    ifstr.close();
    remove("db_contacts.txt");
    rename("temp.txt","db_contacts.txt");
}


void changeContact(Contact contacts[], ContactCount ccount){
    int g = 0, changeline = 0, helper = 0;
    std::string line, column;
    
    std::cout << "Numero in lista di contatto che vuoi modificare? ";
    std::cin >> changeline;
    changeline = changeline - 1;
    
    std::cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<std::endl <<std::endl;        
    std::cout<<"Contatto n.:"   << changeline+1   << " di " << ccount.contactcount   <<std::endl <<std::endl;        
    std::cout<<"Nome: "         << contacts[changeline].nome         <<std::endl;    
    std::cout<<"Cognome: "      << contacts[changeline].cognome      <<std::endl;   
    std::cout<<"Cellulare: "    << contacts[changeline].cellnum      <<std::endl;   
    std::cout<<"Email: "        << contacts[changeline].email        <<std::endl; 
    std::cout<<std::endl;
    std::cout<< "Cosa vuoi modificare? "<<std::endl;
    std::cout<< "1.Nome " <<"2.Cognome "  <<"3.Cellulare "    <<"4.Email " ; 
    std::cin>>helper;
    std::cout<<std::endl;
    
    std::cout<<"Inserisci nuovo ";
    
    switch(helper){
        case 1:
            std::cout<< "nome: ";
            std::cin>>contacts[changeline].nome;
            contacts[changeline].nome[0] = toupper(contacts[changeline].nome[0]);
        break;
        case 2:
            std::cout<< "cognome: ";
            std::cin>>contacts[changeline].cognome;
            contacts[changeline].cognome[0] = toupper(contacts[changeline].cognome[0]);
        break;
        case 3:
            std::cout<< "cellulare: ";
            std::cin>>contacts[changeline].cellnum;
            contacts[changeline].cellnum[0] = toupper(contacts[changeline].cellnum[0]);
        break;
        case 4:
            std::cout<< "email: ";
            std::cin>>contacts[changeline].email;
            contacts[changeline].email[0] = toupper(contacts[changeline].email[0]);
        break;
        default:
            std::cout<< "nome: ";
            std::cin>>contacts[changeline].nome;
            contacts[changeline].nome[0] = toupper(contacts[changeline].nome[0]);
    }
}

int main()
{
    bool newcontact = 0;
    
    Contact contacts[contactsmax];
    
        while (stop == 0){
        ContactCount ccount;
        
        readBooksFromFile(contacts, ccount);
        ccount.contactcount = 0;
        for(int a=0; a < contactsmax; a++){   
            if(contacts[a].nome != "")       
                ccount.contactcount++;         
            }
        if(newcontact == 1){
            writeContactsInFile(contacts, ccount);
            newcontact = 0;
        }
        sortContactsBookByName(contacts, ccount);
            std::cout<<  "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
            std::cout<<std::endl<< "\nScegli la operazione che vuoi farlo\n"<<std::endl;
            std::cout<< "1.Aggiungi un contatto"<<std::endl
            << "2.Visualliza il numero dei contatti"<<std::endl
            << "3.Elimina il contatto"<<std::endl
            << "4.Visualliza contatti(a-z)" <<std::endl
            << "5.Modifica contatto" <<std::endl
            << "6.Ricerca di contatto per il nome o numero" <<std::endl
            << "\n0.Esci dal applicazione"  <<std::endl;
            std::cout<<std::endl<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
            std::cout<<std::endl;
            std::cout<<"\nazione n.";
            std::cin>>switcher;
            
            switch(switcher){
                case '1':
                protoAskForContact(contacts, ccount);
                newcontact = 1;
                break;
                case '2':
                std::cout<< std::endl<<"Numero dei contatti:" << ccount.contactcount << std::endl;
                break;
                case '3':
                deleteFromFile();
                readBooksFromFile(contacts, ccount);
                break;
                case '4':
                printContactsList(contacts, ccount);
                writeContactsInFile(contacts, ccount);
                break;
                case '5':
                changeContact(contacts, ccount);
                writeContactsInFile(contacts, ccount);
                break;
                case '6':
                searchForNameNum(contacts, ccount);
                break;
                case '0':
                writeContactsInFile(contacts, ccount);
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

