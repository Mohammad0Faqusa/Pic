
//*********************************************************
/*
Student work : Mohammad Faqusa. 
Id : 201014 . 

The GitHub Link : https://github.com/Mohammad0Faqusa/Pic

*/
//*********************************************************


#include <iostream> 
#include <random> 
#include <cmath> 
using namespace std;
        struct position { 
    int x ; 
    int y ;  
}; 
class Game { 

    public : 

    Game () { 
        test = 0 ; 
        initialization() ; 
        play() ; 
    }

    private : 

    int test ; 
    bool stopFlag = false ; 
    char arr [7][7]; 
    char directions[4]   = {'r' , 'l' , 'u' , 'd'} ; 
    position monster ; 
    position picMan ; 
    position *arrBill ;
    int numOfBills ; 
    int indexBill = 0 ; 

    int powerCount ; 

   

    void printDots () { 
        for (int i = 0 ; i < 7 ; i++ ) 
            for (int j = 0 ; j < 7 ; j++ ) { 
                arr[i][j] = '.' ; 
            }

    }

    void printBills() { 
        
        numOfBills = 10 + rand()%20 ; 
        arrBill = new position[numOfBills] ;
    

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
        position r ; 
        r.x = bill.x ; 
        r.y = bill.y ; 

        arrBill[indexBill++] = r ;
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
    void printPowerBills() { 
       for (int i = 0 ; i < 2 ; i++ ) { 
            
            position powerBill  ; 
            powerBill.x = rand()%7 ; 
            powerBill.y =rand()%7 ; 

            while (arr[powerBill.x][powerBill.y] == 'B' || arr[powerBill.x][powerBill.y] == 'P' || arr[powerBill.x][powerBill.y] == 'M'|| arr[powerBill.x][powerBill.y] == 'S' ) { 
                powerBill.x = rand()%7 ; 
                if(arr[powerBill.x][powerBill.y] == 'B' || arr[powerBill.x][powerBill.y] == 'P' || arr[powerBill.x][powerBill.y] == 'M' || arr[powerBill.x][powerBill.y] == 'S')
                powerBill.y = rand()%7 ; 

            }

        arr[powerBill.x][powerBill.y] = 'S' ; 

        powerCount = 0 ; 
            
        }
    }


    void display () { 
        cout << "The herustic value : " << numOfBills + shortestDistance() << endl ; 
        cout << "the number of Bills : "<< numOfBills << endl ; 
        cout << "Power Count :" << powerCount << endl ; 


        for (int i = 0 ; i < 7 ; i++ ) {
            for (int j = 0 ; j < 7 ; j++ ) { 
                cout << arr[j][i] << " "  ; 
                
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
        if (x == 'r' || x == 'l' || x == 'u' || x == 'd' )
        return true ; 
        else 
        return false ; 
    }

    void initialization() { 
        printDots() ; 
        printBills() ; 
        printMonster() ; 
        printPicMan() ; 
        printPowerBills() ; 
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
            
                if ( !validPosition((monster.x + 1) , monster.y ) || arr[monster.x + 1][monster.y] == 'B'  || arr[monster.x + 1][monster.y] == 'S'  )
                    monsterMove() ;
                else{
                arr[monster.x][monster.y] = '.' ; 
                monster.x += 1 ; 
                arr[monster.x][monster.y] = 'M' ; 
                }
                break ; 

                case 'l' : 
                if ( !validPosition((monster.x - 1) , monster.y )  || arr[monster.x - 1][monster.y] == 'B'  || arr[monster.x - 1][monster.y] == 'S' )
                    monsterMove() ;
                else{
                arr[monster.x][monster.y] = '.' ; 
                monster.x -= 1 ; 
                arr[monster.x][monster.y] = 'M' ; 
                }
                break ; 

                case 'u' : 
                if ( !validPosition((monster.x) , (monster.y - 1) ) || arr[monster.x][monster.y - 1] == 'B' || arr[monster.x ][monster.y - 1] == 'S'  )
                    monsterMove() ;
                else{
                arr[monster.x][monster.y] = '.' ; 
                monster.y -= 1 ; 
                arr[monster.x][monster.y] = 'M' ; 
                }
                break ;
                case 'd' : 
                if ( !validPosition((monster.x) , (monster.y +1) ) || (arr[monster.x][monster.y + 1] == 'B') || arr[monster.x ][monster.y + 1] == 'S'  )
                    monsterMove() ;
                else{
                arr[monster.x][monster.y] = '.' ; 
                monster.y += 1 ; 
                arr[monster.x][monster.y] = 'M' ; 
                }
                break ; 
        }



        
    }

    void picManMove (char direction) { 
        
        while (!keyValidation(direction)) { 
            cout << "invalid input, please press valid key" << endl ; 
            hintKeyPress() ; 
            cin >> direction ; 
        }

        switch(direction) { 
            case 'r' : 
                if ( validPosition((picMan.x + 1) , picMan.y )) { 
                    arr[picMan.x][picMan.y] = '.'; 
                    picMan.x += 1 ;}
                break ; 

                case 'l' : 
                if ( validPosition((picMan.x - 1) , picMan.y )) { 
                    arr[picMan.x][picMan.y] = '.'; 
                    picMan.x -= 1 ; }
                    break ; 

                case 'u' : 
                if ( validPosition((picMan.x) , (picMan.y - 1) )) { 
                    arr[picMan.x][picMan.y] = '.' ;
                    picMan.y -= 1 ;}
                    break ; 

                case 'd' :
                if ( validPosition((picMan.x) , (picMan.y +1 ) )) { 
                    arr[picMan.x][picMan.y] = '.' ; 
                    picMan.y += 1 ;}
                    break ; 

        }
  

    if (arr[picMan.x][picMan.y] == 'S') { 
        powerCount = 3 ; 
        arr[picMan.x][picMan.y] = 'P' ;
        return ; 
    }

    if (powerCount > 0 ) { 
        powerCount -- ; 
        if (arr[picMan.x][picMan.y] == 'M') { 
            arr[picMan.x][picMan.y] = 'P' ;
            monster.x = -1 ;  // to leave the monster from the array 
            monster.y = -1 ; 

        } else if (arr[picMan.x][picMan.y] == 'B') { 
            arr[picMan.x][picMan.y] = 'P' ;
            numOfBills = numOfBills - 1   ; 
            
            removeBill(getIndexBill(picMan)) ; 
            
        } else { 
            arr[picMan.x][picMan.y] = 'P' ;
        }

    } else { 
        if (arr[picMan.x][picMan.y] == 'M') { 

            display() ; 
            cout << "You Lost!, the monster has eaten You!" << endl ; 
            stopFlag = true ; 
            return ; 

        } else if (arr[picMan.x][picMan.y] == 'B') { 
            arr[picMan.x][picMan.y] = 'P' ;
            removeBill(getIndexBill(picMan)) ; 
            numOfBills = numOfBills - 1 ; 
        } else { 
            arr[picMan.x][picMan.y] = 'P' ;
        } 

    }

    }

    int getIndexBill(position bill) { 
        for(int i = 0  ; i < indexBill ; i++) { 
            if (bill.x == arrBill[i].x && bill.y == arrBill[i].y )
            return i ; 
        }
        return -1  ; 
    }

    void removeBill (int posBill) { 
        position *newArrBill = new position[--indexBill] ; 

        

        if (indexBill == 0 ) {
            for (int i = 0 ; i < posBill ; i++ ) { 
            newArrBill[i] = arrBill[i + 1] ; 
        }
        }else {

        for (int i = 0 ; i < posBill ; i++ ) { 
            newArrBill[i] = arrBill[i] ; 

        }
        if (posBill < indexBill ) 
        for (int i = posBill ; i < indexBill ; i++ ) { 
             newArrBill[i] = arrBill[i + 1] ; 

        }
        }

        delete [] arrBill ; 

        arrBill = newArrBill ; 


    }

    void displayBill() { 
        for (int i = 0 ; i < indexBill ; i++ ) { 
            cout << "position (x , y) : " << arrBill[i].y << " " << arrBill[i].x << endl ; 
        }
    }

    int distance(position r , position m ) { 

        int deltaX = r.x - m.x ; 
        int deltaY = r.y - m.y ; 

        int distance = sqrt(deltaX * deltaX + deltaY * deltaY) ; 

        return distance ; 
    }

    int shortestDistance () { 
        if (!arrBill)
        return -1 ; 
        int min = distance(arrBill[0] , picMan) ; 

        for (int i = 0 ; i < indexBill ; i ++ ) { 
            if (min > distance(arrBill[i] , picMan ))
                min = distance(arrBill[i] , picMan ) ; 

        }
        if (min < 0 ) 
        return 0 ; 

        return min ; 
    }
    void play() { 
        while (!stopFlag) { 

            if (numOfBills == 0 ) { 

            display() ; 
            cout << "You Win!" << endl ; 
            stopFlag = true ; 
            return ; 
             }
          
            
            display() ; 
            
            cout << "Press a key" << endl ; 
            char x ; 
            cin >> x ;
            while (x == 'b') {
            displayBill() ; 
            cin >> x ;} 

            while (!keyValidation(x)) { 
                cout << "please insert valid input" << endl ; 
                hintKeyPress() ; 
                cin >> x ;
                while (x == 'b') {
                displayBill() ; 
                cin >> x; } 

            }
        
            if(!(monster.x == -1 && monster.y == -1))
            monsterMove() ; 

              
          
            picManMove(x) ; 


        }
    }
 
    


}; 

int main () {
Game *pic = new Game() ; 
}