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
    char directions[4]   = {'r' , 'l' , 'u' , 'd'} ; 
    position monster ; 
    position picMan ; 
    int numOfBills ; 

   

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

    void hintKeyPress() { 
        cout << "-----------------------------------------------" << endl; 
        cout << "to move right press (r)" << endl ; 
        cout << "to move left press (l)" << endl ; 
        cout << "to move up press (u)" << endl ; 
        cout << "to move d press (d)" << endl ; 
        cout << "-----------------------------------------------"<< endl ;
    }

    bool keyValidation (char x) { 
        if (x == 'r' ||x == 'l' ||x == 'u' ||x == 'd' )
        return true ; 
        else 
        return false ; 
    }

    void initialization() { 
        printDots() ; 
        printBills() ; 
        printMonster() ; 
        printPicMan() ; 
        hintKeyPress() ; 
        
        
    }

    int min(int x , int y ) { 
        if (x > y) 
        return y ; 
        else 
        return x ; 

    }
    int max (int x , int y ) { 
        if (x > y ) 
        return x ; 
        else 
        return y ; 
    }

    bool validPosition (int x ,int  y ) { 
        if (min(x , y) < 0)
        return false ; 
        if (max(x ,y) > 6) 
        return false ; 

        return true ; 
        
    }
 
    void monsterMove() { 
        char monsterDir = directions[rand()%4] ; 

        switch (monsterDir) { 

            case 'r' : 
            
                if ( !validPosition((monster.x + 1) , monster.y ) && arr[monster.x + 1][monster.y] == 'B'  )
                    monsterMove() ;
                else{
                arr[monster.x][monster.y] = '.' ; 
                monster.x += 1 ; 
                arr[monster.x][monster.y] = 'M' ; 
                }
                break ; 

                case 'l' : 
                if ( !validPosition((monster.x - 1) , monster.y )  && arr[monster.x - 1][monster.y] == 'B'  )
                    monsterMove() ;
                else{
                arr[monster.x][monster.y] = '.' ; 
                monster.x -= 1 ; 
                arr[monster.x][monster.y] = 'M' ; 
                }
                break ; 

                case 'u' : 
                if ( !validPosition((monster.x) , (monster.y +1) ) && arr[monster.x][monster.y + 1] == 'B'  )
                    monsterMove() ;
                else{
                arr[monster.x][monster.y] = '.' ; 
                monster.y += 1 ; 
                arr[monster.x][monster.y] = 'M' ; 
                }
                break ;
                case 'd' : 
                if ( !validPosition((monster.x) , (monster.y -1) ) && (arr[monster.x][monster.y - 1] == 'B')  )
                    monsterMove() ;
                else{
                arr[monster.x][monster.y] = '.' ; 
                monster.y -= 1 ; 
                arr[monster.x][monster.y] = 'M' ; 
                }
                break ; 
        }

        

        
    }
    void play() { 
        while (true) { 
            
            display() ; 
            
            cout << "Press the key" ; 
            char x ; 
            cin >> x ; 
            while (!keyValidation(x)) { 
                cout << "please insert valid input" << endl ; 
                hintKeyPress() ; 
            }


            


        }
    }
 
    Game () { 
        initialization() ; 



    }


}; 

int main () { 
int num [2][2] ; 
cout << num[1][3] ; 
// Game *pic = new Game() ; 
}