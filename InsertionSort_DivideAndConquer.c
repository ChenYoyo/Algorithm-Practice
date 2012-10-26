#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define TOTAL (128)

void Merge( int Array[], int first, int middle, int last){
           
    int index_L,index_M,index_total;
    int element_L, element_M, element_total;
    
    element_L = middle - first + 1;
    element_M = last - middle;
    element_total = element_L + element_M;
    int sub_array_L[element_L],sub_array_M[element_M];


    for( index_L=0; index_L < element_L; index_L++){
        sub_array_L[index_L] = Array[index_L + first];   
        //printf("Array[index_L:%d+first:%d]\n", index_L, first);
    }
    for( index_M=0; index_M < element_M; index_M++){
        sub_array_M[index_M] = Array[index_M + middle+1];   
       //printf("Array[index_M:%d+(middle+1)%d]\n", index_M, middle+1);
    }

    index_L=0;
    index_M=0;

    for( index_total=first; index_total <= last; index_total++){
        if( (index_L < element_L) && (index_M < element_M) ){    
            if(sub_array_L[index_L] <= sub_array_M[index_M]){
               Array[index_total] = sub_array_L[index_L];
               index_L++;
            
            }else{
               Array[index_total] = sub_array_M[index_M];
               index_M++; 
            }
        
        }else if(index_L >= element_L){
               Array[index_total] = sub_array_M[index_M];
               index_M++; 
        
        }else if(index_M >= element_M){
               Array[index_total] = sub_array_L[index_L];
               index_L++; 
        
        }else{
        
        
        }
          
    }
}

void MergeSort(int Array[], int first, int last){
    if(first<last){    
        int middle = floor( (first+last)/2 );
        printf("first is %d middle:%d last:%d\n",first,middle,last);
        MergeSort( Array, first, middle);
        printf(" MergeSort first is %d middle:%d last:%d\n",first,middle,last);
        MergeSort( Array, middle+1,last);
        printf("Before Merge first is %d middle:%d last:%d\n",first,middle,last);
        Merge( Array, first, middle, last);
    }
     
}

int main(int argc, char *argv[]){

    int x/*aa*/y;
    int card[TOTAL];
    int temp_StartPos;
    int StartPos;
    int ComparedCardPos; 
    int i = 0;
    
    for(i = 0; i < TOTAL; i++){
        card[i] = rand()%TOTAL;
        printf("card[%d] = %d\n",i ,card[i] );
    }
    
   
    MergeSort(card,0,TOTAL-1);
    
    for(i = 0; i < TOTAL; i++){ 
        printf("card[%d] = %d\n",i ,card[i]);
    }
    // insert code here...
    printf("\"blunder??!??\"Hello, World!\40\x40\100\x100\0123\x0123\n");
    return 0;

}
