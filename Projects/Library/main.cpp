/******************************************************************************

Olshesvkyi Vladyslav Lybrary App

*******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

typedef struct Book{        // una struct per ogni libro 
    std::string titolo;
    std::string autore;
    std::string anno;
    std::string editor;
    std::string price;
    
}Book;

typedef struct Books_List{  // numero dei libri in libreria
    int bookscount;     
    Book book;              // porta Book struct a lista dei libri
}Books_List;

const int libsize = 100;    // la grandeza di libreria
const char comma = ',';     // const comma per comodita in getline
char switcher;              // char di controllo della applicazione
bool stop = 0;              // boolean per la uscita dal applicazione

void printBooksList(Book books[], Books_List bookslist){        // stampa la lista dei libri con tutta la informazione // import Book struct come books[] // import Books_List struct come bookslist
    
    for(int i = 0 ; i < bookslist.bookscount ; i++){            // for loop di controllo per ogni libro // i = posizione = libro in lista
    
    std::cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<std::endl <<std::endl;        //divisore
    std::cout<<"Libro n.:"<< i+1        << " di " << bookslist.bookscount   <<std::endl <<std::endl;        //i+1 per visuallizare numero del Libro partendo dal 1 invece che di 0
    std::cout<<"Titolo: " << books[i].titolo    <<std::endl;    // visualliza il titolo  // i = posizione = libro in lista
    std::cout<<"Autore: " << books[i].autore    <<std::endl;    // visualliza il autore 
    std::cout<<"Anno: "   << books[i].anno      <<std::endl;    // visualliza il anno 
    std::cout<<"Editor: " << books[i].editor    <<std::endl;    // ...
    std::cout<<"Price: "  << books[i].price     <<std::endl;
    }
}

void printBooksAuthorList(Book books[], Books_List bookslist){      // Stampare l’elenco dei libri raggruppati per autore // import Book struct come books[] // import Books_List struct come bookslist
        
        int i = 0,j = 0;                                                // controllo di posizione // i = libro attuale, j = i+1 = prossimo libro 
        std::cout<<std::endl; 
        for( i = 0; i < bookslist.bookscount; i++){                     // esegui il loop per il numero dei libri 
            for(j=i+1;j<bookslist.bookscount;j++)                       // i = libro attuale, j = i+1 = prossimo libro 
        	{ 
        		if( (int)books[i].autore[0] > (int)books[j].autore[0])  // se le prima lettera del nome di autore del libro attuale e superiore a quello di libro prossimo
        		{
        		    Book tempbook = books[i];                           // import Book come tempbook - libro attuale 
        			books[i] = books[j];                                // la posizione del libro in posizione i diventa + 1
        			books[j] = tempbook;                                // la posizione del libro in posizione j diventa - 1
        		}
        	}
        	std::cout<<books[i].autore<< " - " <<books[i].titolo<<std::endl;
        }
}

void searchBooksForName(Book book_arr[], Books_List bookslist){     // Stampare i libri che contengono nel titolo una stringa // import Book struct come book_arr[] //import Books_List struct come bookslist
    
    int i;                                                          // posizione
    std::string title;                                              // stringa temporanea per input di titolo che vorrei trovare
    std::cin.ignore(100, '\n');                                     // cin.ignore per non avere problemi con getline
    std::cout<<std::endl<<"Quale titolo cerchi? ";                  // promt per ricerca per la stringa
    std::getline( std::cin, title );                                // salva in stringa temporanea "title"
    title[0] = toupper(title[0]);
    
    for(i = 0; i < bookslist.bookscount; i++){                      // per ogni libro in libreria
        if (book_arr[i].titolo.find(title) != std::string::npos)    // trova per la stringa fino il raggiungimento della fine della righa
        std::cout << book_arr[i].titolo << '\n';  
       
    }
    
}

void readBooksFromFile(Book books[]){               // Leggi i libri dalla database // import Book struct come books[]

    int g=0;                                        // posizione in lista
    std::fstream fileCNTRL;                         // stream file to fileCNTRL
    fileCNTRL.open("db_books.txt", std::ios::in);   // leggi dal file db_books.txt 
    if(fileCNTRL.is_open() ) {                      // se il file e aperto
        std::string line; 
        while ( getline (fileCNTRL, line) ){        // leggi la linea e metti in stringa "line"
            
                std::istringstream iss(line);       // std::istringstream è un oggetto di classe stringa che viene utilizzato per trasmettere la stringa in diverse variabili e allo stesso modo i file possono essere trasmessi in stringa

                std::string data;                   // stringa temporanea per la righa
                
                getline(iss, data, comma);          // metti la prima colonna nel data       // -titolo
                books[g].titolo = data;             // titolo = prima colonna
                
                getline(iss, data, comma);          // metti la seconda colonna nel data     // -autore
                books[g].autore = data;             // titolo = seconda colonna
                
                getline(iss, data, comma);          // metti la terza colonna nel data       // -anno
                books[g].anno = data;               // titolo = terza colonna
                
                getline(iss, data, comma);          // metti la quarta colonna nel data      // -editor
                books[g].editor = data;             // titolo = quarta colonna
                
                getline(iss, data, comma);          // metti la quinta colonna nel data      // -prezzo
                books[g].price = data;              // titolo = quinta colonna
                
                ++g;                                // g = posizione in lista
                
        }
    }
    fileCNTRL.close();                              // chiudi fstream
    std::cout<<std::endl;                           // visualliza nuova righa
}

void writeBookInFile(Book books[], Books_List bookslist){   // Aggiungere un libro alla collezione // Salva i libri nella database // import Book struct come books[] //import Books_List struct come bookslist
    std::fstream fileCNTRL;
    
    fileCNTRL.open("db_books.txt", std::ios::out);          // scrivi nel file db_books.txt
    if(fileCNTRL.is_open() ) {                              // se file dal fstream e aperto
        for(int i=0;i<bookslist.bookscount;i++){            // per ogni libro in libreria
            
            fileCNTRL                                       // scrivi nel fileCNTRL file stream (db_books.txt)
            << books[i].titolo << comma                     // scrivi il titolo in db_books.txt seguito dal virgola
            << books[i].autore << comma                     // scrivi l'autore in db_books.txt seguito dal virgola
            << books[i].anno << comma                       // ...
            << books[i].editor << comma                     
            << books[i].price << comma                      
            <<"\n";                                         //aggiungi nuova linea alla fine del loop
        }
        fileCNTRL.close();                                  //chiudi fstream
    }
    
}

void protoAskBookInfo(Book book_arr[], Books_List bookslist){   // import Book struct come book_arr[] // import Books_List struct come bookslist
        
        std::cout<<"Inserisci i dati del libro"<<std::endl;
        
        std::cin.ignore();                                               // cin.ignore per non avere i problemi con getline
        std::cout<<"Inserisci titolo: ";                                 // chiedi a Inserire titolo
        std::getline( std::cin, book_arr[bookslist.bookscount].titolo ); // salva il titolo
        book_arr[bookslist.bookscount].titolo[0] = toupper(book_arr[bookslist.bookscount].titolo[0]);   // porta la prima lettera del titolo a maiuscolo
        
        std::cout<<"Inserisci autore: ";
        std::getline( std::cin, book_arr[bookslist.bookscount].autore ); // salva il autore
        book_arr[bookslist.bookscount].autore[0] = toupper(book_arr[bookslist.bookscount].autore[0]);   // porta la prima lettera del autore a maiuscolo
        
        std::cout<<"Inserisci anno: ";
        std::getline( std::cin, book_arr[bookslist.bookscount].anno );   // salva il anno
        
        std::cout<<"Inserisci editore: ";
        std::getline( std::cin, book_arr[bookslist.bookscount].editor ); // salva il editor
        book_arr[bookslist.bookscount].editor[0] = toupper(book_arr[bookslist.bookscount].editor[0]);   // porta la prima lettera del editor a maiuscolo
        
        std::cout<<"Inserisci prezzo: ";                                
        std::cin>>book_arr[bookslist.bookscount].price;         // salva il prezzo
        
        bookslist.bookscount++;                                 // conta libri +1
        
        writeBookInFile(book_arr, bookslist);                   // salva il libro nel file
}

int main()
{
    
    Book book_arr[libsize];             // import Book come book_arr di grandezza libsize
    
    while (stop == 0){ 
        Books_List bookslist;           // import Books_List come booklist
        readBooksFromFile(book_arr);    // leggi i libri dal file
        bookslist.bookscount = 0;       // reimposta contatore dei libri come 0
        for(int a=0; a < libsize; a++){     //  per la grandezza di libreria
        if(book_arr[a].titolo != "")        //  se titolo non uguale a stringa vuota
            bookslist.bookscount++;         //  conta i libri
            }
        
            std::cout<<  "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
            std::cout<<std::endl<< "\nScegli la operazione che vuoi farlo\n"<<std::endl;
            std::cout<< "1.Aggiungere un libro alla collezione."            <<std::endl
             << "2.Mostrare il numero di libri nella collezione"            <<std::endl
             << "3.Stampare l’elenco dei libri"                             <<std::endl
             << "4.Stampare l’elenco dei libri raggruppati per autore"      <<std::endl
             << "5.Stampare i libri che contengono nel titolo una stringa"  <<std::endl
             << "\n9.Debugger" << "\n0.Esci dal applicazione"  <<std::endl;
            std::cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
            std::cout<<std::endl;
            std::cout<<"\nazione n."; 
            std::cin>>switcher; // salva carattere di controllo 
            
            switch(switcher){
                case '1': // Aggiungere un libro alla collezione
                protoAskBookInfo(book_arr, bookslist); 
                break;
                case '2': // Mostrare il numero di libri nella collezione
                std::cout<< std::endl<<"Numero dei libri in lista:" << bookslist.bookscount << std::endl;
                break;
                case '3': // Stampare l’elenco dei libri
                printBooksList(book_arr, bookslist);
                break;
                case '4': // Stampare l’elenco dei libri raggruppati per autore
                printBooksAuthorList(book_arr, bookslist);
                break;
                case '5': // Stampare i libri che contengono nel titolo una stringa
                searchBooksForName(book_arr, bookslist);
                break;
                case '9': // Debugger
                std::cout << "W.Salva i libri in database ('db_books.txt')"    
                <<std::endl<< "R.Leggi i libri dalla database ('db_books.txt')" ;
                break;
                case 'W': // Salva i libri nella database ('db_books.txt')
                writeBookInFile(book_arr, bookslist);
                std::cout<<"Hai scritto i dati in file!"<<std::endl;
                break;
                case 'R': // Leggi i libri dalla database ('db_books.txt')
                readBooksFromFile(book_arr);
                std::cout<<"Hai letto i dati dal file!"<<std::endl;
                break;
                case 0:
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






