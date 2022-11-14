/******************************************************************************
Olshevskyi Vladyslav
*******************************************************************************/
#include <iostream>
#include <string.h>

const int gamesize = 5;
const int playersize = 3;

bool stop = 0;
char switcher;

typedef struct Quiz{        
    std::string question;
    std::string answers[3];
    int rightansw;
}Quiz;

typedef struct Player{  
    std::string name;
    int score = 0;
    Quiz quiz;              
}Player;

void showWinner(Player players[]){
    for(int i = 0; i < playersize; i++){
        for(int j = i+1 ; j < playersize; j++){
            if(players[i].score < players[j].score){
                Player templayer = players[i];
                players[i] = players[j];
                players[j] = templayer;
            }
            
        }
    }
    std::cout<<"Vincitore: "  <<players[0].name<<" ";
    std::cout<<"Punti: "        <<players[0].score;
    std::cout<<std::endl;
}

void askForPlayers(Player players[]){
    std::cout<<std::endl;
    
    for(int i = 0; i < playersize; i++){
        
        std::cout<<"Nome del giocatore n." << i + 1<< " : ";
        std::cin>> players[i].name ;
        players[i].name[0] = toupper(players[i].name[0]);
        
    }

}

void startGame(Quiz quiz[], Player players[]){
    char answer;
    int tempansw;
    
    for(int g = 0; g < playersize; g++){
        std::cout<< "Player N. "<< g + 1 <<std::endl;
        for(int i=0; i < gamesize; i++){
            tempansw = 0;
            std::cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n"  <<std::endl;
            std::cout<< "Domanda n."<< i+1  <<std::endl  << "- - -" <<std::endl;
            std::cout<<   quiz[i].question  <<std::endl  << std::endl;
            std::cout<< "A) "<<  quiz[i].answers[0]      << std::endl;
            std::cout<< "B) "<<  quiz[i].answers[1]      << std::endl;
            std::cout<< "C) "<<  quiz[i].answers[2]      << std::endl;
            std::cout<< "Scegli la risposta giusta (Es. A): ";
            std::cin >> answer;
            
            answer = toupper(answer);
            tempansw = (int)answer - 65;
            
            if(quiz[i].rightansw == tempansw){
                std::cout<<std::endl<<"Risposta corretta!";
                players[g].score = players[g].score + 5;
                std::cout<<std::endl;
                std::cout<< "+ 5 Punti! ("   << players[g].score<< ")";
            }
            else{
                std::cout<<std::endl<<"Risposta sbagliata!";
                players[g].score = players[g].score - 2;
                std::cout<<std::endl;
                std::cout<< "- 2 Punti! (" << players[g].score<< ")";
            }
            std::cout<<std::endl;
        }
        std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n"<<std::endl;
        for(int f = 0; f<playersize; f++){

            std::cout<<"Nome del giocatore: "  <<players[f].name<<" ";
            std::cout<<"Punti: "        <<players[f].score;
            std::cout<<std::endl;
            
        }
        std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n"<<std::endl;
    }   
    showWinner(players);
}

void showLeaderBoard(Player players[]){
        std::cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n"<<std::endl;
        for(int i = 0; i<playersize; i++){
            
            
            if(players[i].name == ""){
                std::cout<< "defaultname";
                std::cout<< players[i].name<<" ";
            }
            else{
                std::cout<<"Giocatore: " << players[i].name<<" ";
            }
            std::cout<<"Punti: "<<players[i].score;
            std::cout<<std::endl;
            
        }
        std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n"<<std::endl;
        showWinner(players);
}

int main()
{
        Quiz quiz[gamesize];
        
        quiz[0].question = "Python è _____ linguaggio di programmazione.";
        quiz[0].answers[0] = "high-level";
        quiz[0].answers[1] = "mid-level";
        quiz[0].answers[2] = "low-level";
        quiz[0].rightansw = 0;
        
        quiz[1].question = "Quale dei seguenti include il motore JavaScript V8 di Chrome?";
        quiz[1].answers[0] = "jQuery";
        quiz[1].answers[1] = "npm";
        quiz[1].answers[2] = "Node.js";
        quiz[1].rightansw = 2;
        
        quiz[2].question = "Quale dei seguenti non è un linguaggio di programmazione??";
        quiz[2].answers[0] = "TypeScript";
        quiz[2].answers[1] = "Python";
        quiz[2].answers[2] = "Anaconda";
        quiz[2].rightansw = 2;
        
        quiz[3].question = "Quale dei seguenti non è un tipo di codice per computer relativo all'esecuzione del programma?";
        quiz[3].answers[0] = "Source code";
        quiz[3].answers[1] = "Bytecode";
        quiz[3].answers[2] = "Hex Code";
        quiz[3].rightansw = 2;
        
        quiz[4].question = "Cosa fa un compilatore?";
        quiz[4].answers[0] = "Traduce il codice del computer dal linguaggio di programmazione di livello inferiore al linguaggio di programmazione di livello superiore.";
        quiz[4].answers[1] = "Traduce il codice del computer dal livello macchina al byte code.";
        quiz[4].answers[2] = "Traduce il codice del computer dal linguaggio di programmazione di livello superiore al codice macchina.";
        quiz[4].rightansw = 2;
        
        Player players[playersize];
        
        while (stop == 0){
            std::cout<<  "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
            std::cout<<std::endl<< "\nScegli la operazione che vuoi farlo\n"<<std::endl;
            std::cout<< "1.Start the game"<<std::endl;
            std::cout<< "2.Print scoreboard"<<std::endl;
            std::cout<< "3.Inserire di nuovo i nomi dei giocatori"<<std::endl
            << "\n0.Esci dal applicazione"  <<std::endl;
            std::cout<<std::endl<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
            std::cout<<std::endl;
            std::cout<<"\nazione n.";
            std::cin>>switcher;
            
            switch(switcher){
                case '1':
                askForPlayers(players);
                startGame(quiz, players);
                break;
                case '2':
                showLeaderBoard(players);
                break;
                case '3':
                askForPlayers(players);
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




