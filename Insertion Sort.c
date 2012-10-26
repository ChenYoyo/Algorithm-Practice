#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define TOTAL (48)

void Merge( int Array[], int first, int middle, int last){
           
    int index_L,index_M,index_total;
    int element_L, element_M, element_total;
    int sub_array_L[],sub_array_M[];

    element_L = middle - first;
    element_M = last - middle + 1;
    element_total = element_L + element_M;

    for( index_L=0; index_L < element_L; index_L++){
        sub_array_L[index_L] = Array[index_L + first];   
    }
    for( index_M=0; index_M < element_M; index_M++){
        sub_array_M[index_M] = Array[index_M + middle];   
    }

    index_L=0;
    index_M=0;

    for( index_total=first; index_total <= last; index_total++){
        if( (index_L <= element_L) && (index_M <= element_M) ){    
            if(sub_array_L[index_L] <= sub_array_M[index_M]){
               Array[index_total] = sub_array_L[index_L];
               index_L++;
            
            }else{
               Array[index_total] = sub_array_M[index_M];
               index_M++; 
            }
        
        }else if(index_L > element_L){
               Array[index_total] = sub_array_M[index_M];
               index_M++; 
        
        }else if(index_M > element_M){
               Array[index_total] = sub_array_L[index_L];
               index_L++; 
        
        }else{
        
        
        }
          
    }
}

void MergeSort(int Array[], int first, int last){
    int middle = (first+last)/2;
    MergeSort( Array, first, middle);
    MergeSort( Array, middle+1,last);
    Merge( Array, first, middle, last);
     
}


int main(int argc, char *argv[]){

    int card[TOTAL];
    int temp_StartPos;
    int StartPos;
    int ComparedCardPos; 
    int i = 0;
    
    for(i = 0; i < TOTAL; i++){
        card[i] = rand()%100;
        printf("card[%d] = %d\n",i ,card[i] );
    }
    printf("\n");
    
    for(StartPos = 1; StartPos < TOTAL; StartPos++){ 
        ComparedCardPos = StartPos-1;
        temp_StartPos = card[StartPos]; 
       
        while( (card[ComparedCardPos] >= temp_StartPos) && ComparedCardPos >= 0 ){ 
            card[ ComparedCardPos +1 ] = card[ ComparedCardPos ]; 
            ComparedCardPos--;
        };
        if (ComparedCardPos != StartPos-1){
            card[ ComparedCardPos+1 ] = temp_StartPos; 
        } 
        
    }
    
    for(i = 0; i < TOTAL; i++){ 
        printf("card[%d] = %d\n",i ,card[i]);
    }
    // insert code here...
    printf("Hello, World!\n");
    return 0;

}
