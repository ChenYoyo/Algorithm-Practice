//
//  main.c
//  InsertionSort
//
//  Created by Yoyo_Chen on 1/6/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define TOTAL (48)
int main (int argc, const char * argv[])
{
    int card[TOTAL];
    int temp_card;
    int StartPos;
    int ComparedCardPos;
    //   int OffStartPos = 0;
    int i = 0;
    
    for(i = 0; i < TOTAL; i++){
        card[i] = rand()%100;
        printf("card[%d] = %d\n",i ,card[i] );
    }
    printf("\n");
    
    for(StartPos = 1; StartPos < TOTAL; StartPos++){
        
        ComparedCardPos = StartPos-1;
        temp_card = card[StartPos];
        printf("card[StarPos]\n");
        printf("card[%d] = %d\n",StartPos ,card[StartPos] );
        while( (card[ComparedCardPos] >= card[StartPos]) && ComparedCardPos >= 0 ){ 
            card[ ComparedCardPos +1 ] = card[ ComparedCardPos ];
            printf("card[%d] = %d\n",ComparedCardPos+1 ,card[ComparedCardPos+1] );
            ComparedCardPos--;
        };
        if (ComparedCardPos != StartPos-1) {
            card[ ComparedCardPos+1 ] = temp_card;
            printf("card[%d] = %d ",ComparedCardPos+1 ,card[ComparedCardPos+1] );
        }
 
        
        /*  
         OffStartPos = StartPos - ComparedCardPos -1;
         if( OffStartPos != StartPos - 1 ){
         while( OffStartPos > 0 ){
         OffStartPos--;
         }
         }*/ 
    }
    
    for(i = 0; i < TOTAL; i++){ 
        printf("card[%d] = %d\n",i ,card[i]);
    }
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

