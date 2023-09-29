#include <iostream> 
#include <random> 
using namespace std;
        struct position { 
    int x ; 
    int y ;  
}; 
class Game { 

    public : 
    
    char arr [7][7]; 
   position monster ; 
   position picMan ; 
   int numberOfBills ; 

   

    void printDots () { 
        for (int i = 0 ; i < 7 ; i++ ) 
            for (int j = 0 ; j < 7 ; j++ ) { 
                arr[i][j] = '.' ; 
            }

    }

    void printBills() { 
        numOfBills = 10 + rand()%20 ; 
        cout << "number of bills are " << numOfBills << endl ;  
        for (int i = 0 ; i < numOfBills ; i++ ) { 
            
            position bill ; 
            bill.x = rand()%7 ; 
            bill.y =rand()%7 ; 

            while (arr[bill.x][bill.y] == 'B') { 
                bill.x = rand()%7 ; 
                if(arr[bill.x][bill.y] == 'B')
                bill.y = rand()%7 ; 

            }

      arr[bill.x][bill.y] = 'B' ; 
            
        }
    }
   
   void printMonster() { 
     
    monster.x  = rand()%7 ; 
    monster.y  = rand()%7 ; 

    while (arr[monster.x][monster.y] == 'B'){
        monster.x  = rand()%7 ; 
        monster.y  = rand()%7 ; 
    }

    arr[monster.x][monster.y] = 'M' ; 
   }

    void printPicMan () { 
        picMan.x  = rand()%7 ; 
        picMan.y  = rand()%7 ; 

        while (arr[picMan.x][picMan.y] == 'B' ||arr[picMan.x][picMan.y] == 'M' ){
        monster.x  = rand()%7 ; 
        monster.y  = rand()%7 ; 
    }

        arr[picMan.x][picMan.y] = 'P' ; 
    }


    void display () { 
        for (int i = 0 ; i < 7 ; i++ ) {
            for (int j = 0 ; j < 7 ; j++ ) { 
                cout << arr[i][j] << " "  ; 
                
            }
            cout << endl ;}

    }

    void initialization() { 
printDots() ; 
        printBills() ; 
        printMonster() ; 
        printPicMan() ; 
        display() ; 
    }
 
 
    Game () { 
        

    }


}; 

int main () { 

Game *pic = new Game() ; 
}