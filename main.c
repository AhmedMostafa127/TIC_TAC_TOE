#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //getch()

char arr[10] = {'0','1','2','3','4','5','6','7','8','9'} ;

void show_board();
int check_for_win();

int main()
{
    int player = 1 ;
    int choice  , i ;
    char mark ; // X or O



    do
    {
        show_board();
        player = (player%2) ? 1 : 2 ;
        printf("Player %d turn : ", player);
        scanf("%i", &choice);
        mark = (player == 1) ? 'X' : 'O' ;

        if ( choice == 1 && arr[1] == '1' )
           arr[1] = mark ;
        else if ( choice == 2 && arr[2] == '2' )
           arr[2] = mark ;
        else if ( choice == 3 && arr[3] == '3' )
           arr[3] = mark ;
        else if ( choice == 4 && arr[4] == '4' )
           arr[4] = mark ;
        else if ( choice == 5 && arr[5] == '5' )
           arr[5] = mark ;
        else if ( choice == 6 && arr[6] == '6' )
           arr[6] = mark ;
        else if ( choice == 7 && arr[7] == '7' )
           arr[7] = mark ;
        else if ( choice == 8 && arr[8] == '8' )
           arr[8] = mark ;
        else if ( choice == 9 && arr[9] == '9' )
           arr[9] = mark ;
        else //player == 1----10
        {
          printf ("Invalid Value !!!! :( , Please Enter again \n") ;
          player--;
          getch();
        }

        i= check_for_win(); //-1,0,1
        player++;

    }while( i == -1 );

    player = (player%2==0) ? 1 : 2 ;

    show_board();
    if (i==1)
    {
        printf("Player %i WON \n" , player);
        i= check_for_win();
    }
    else
    {
        printf("Game Draw \n") ;
    }


    getch();
    return 0;
}

void show_board()
{
    system("cls");
    printf("\t TIC TAC TOE \n") ;
    printf("\t ----------- \n") ;
    printf("         |         |         \n");
    printf("    %c    |    %c    |    %c     \n",arr[1],arr[2],arr[3] );
    printf("         |         |         \n");
    printf("---------|---------|---------\n");

    printf("         |         |         \n");
    printf("    %c    |    %c    |    %c     \n",arr[4],arr[5],arr[6]);
    printf("         |         |         \n");
    printf("---------|---------|---------\n");

    printf("         |         |         \n");
    printf("    %c    |    %c    |    %c     \n",arr[7],arr[8],arr[9]);
    printf("         |         |         \n");
}



int check_for_win()
{
    //WIN
    //ROWS

    if( arr[1] == arr[2] && arr[2] == arr[3] )
        return 1 ;
    else if( arr[4] == arr[5] && arr[5] == arr[6] )
        return 1 ;
    else if( arr[7] == arr[8] && arr[8] == arr[9] )
        return 1 ;

    //COLUMNS

    else if( arr[1] == arr[4] && arr[4] == arr[7] )
        return 1 ;
    else if( arr[2] == arr[5] && arr[5] == arr[8] )
        return 1 ;
    else if( arr[3] == arr[6] && arr[6] == arr[9] )
        return 1 ;

    //DIAGONALS
    else if( arr[1] == arr[5] && arr[5] == arr[9] )
        return 1 ;
    else if( arr[3] == arr[5] && arr[5] == arr[7] )
        return 1 ;

    //DRAW
    else if (arr[1] != '1' && arr[2] != '2' && arr[3] != '3' && arr[4] != '4' && arr[5] != '5' && arr[6] != '6' && arr[7] != '7' && arr[8] != '8' && arr[9] != '9')
        return 0 ;

    //CONTINUE
    else
        return -1 ;

}
