#include<stdio.h>
#include<string.h>

#define MAX_SIZE 5
#define EMPTY -99
#define DEBUG 1

//initialize two Queues A,B for implementation of a stack using two queues
char queueA = 'A';
char queueB = 'B';

int QueueA[MAX_SIZE] = {EMPTY};
int QueueB[MAX_SIZE] = {EMPTY};

int headA = 1;
int tailA = 1;
int headB = 1;
int tailB = 1;

typedef enum { FALSE, TRUE} BOOL;
BOOL is_A_empty = FALSE;
BOOL is_B_empty = FALSE;
 

void overflow(void){
  printf("overerflow\n");
}

void underflow(void){
  printf("underflow\n");
}


void check_empty(void){
     
     if(headA == tailA && (QueueA[headA-1] == EMPTY) ){
        
          is_A_empty = TRUE; 
     }
     else is_A_empty = FALSE;
     
     if(headB == tailB && (QueueB[headB-1] == EMPTY) ){
        
          is_B_empty = TRUE;
     }
     else is_B_empty = FALSE;
     
    

}

int dequeue(char queue){
    int tmp;
//revise switch case 'A' and 'B' to
//       if else (queue == QueueA)
    switch(queue){
       case 'A':
          if(headA == MAX_SIZE){
              headA = 1;
              return QueueA[MAX_SIZE-1];  
          }
          else{
#if DEBUG               
              printf("dequeue headA=%d tailA=%d \n", headA, tailA); 
              printf(" dequeue function\n");
#endif
              tmp = QueueA[headA-1];
              QueueA[headA-1] = EMPTY; 
              headA++;
              return tmp;
          }
       case 'B':
          if(headB == MAX_SIZE){
              headB = 1;
              return QueueB[MAX_SIZE-1];
          }
          else{
              tmp = QueueB[headB-1];
              QueueB[headB-1] = EMPTY;
              headB++;
              return tmp;
          }
       default:
             printf("debug on dequeue function\n");
          return 1;   
         
    }
}

void enqueue( char queue, int input){
     
//revise switch case 'A' and 'B' to
//       if else (queue == QueueA)
     switch(queue){
        
        case 'A': 
           if(tailA == MAX_SIZE){
              tailA = 1;
              QueueA[MAX_SIZE-1] = input;
           }
           else{ 
              printf("enque input=%d ++",input);
              printf("headA=%d ++",headA);
              printf("tailA=%d \n",tailA);
              printf("headB=%d ++",headB);
              printf("tailB=%d \n",tailB);
              QueueA[tailA-1] = input;
              tailA++;
           }
           break;

        case 'B':
           if(tailB == MAX_SIZE){
              tailB = 1;
              QueueB[MAX_SIZE-1] = input;
           }
           else{
            QueueB[tailB-1] = input;
            tailB++;
           }
           break;

           default:
             printf("debug on enqueue function\n");
           
           break;
     }
}
void push(int x){

     check_empty();

     if(is_A_empty && is_B_empty){
              printf("push A and B empty headA=%d ++",headA);
              printf("tailA=%d \n",tailA);

        enqueue( queueA, x);
     }
     
     else if(is_A_empty && !is_B_empty){
              printf("push A and B non empty headA=%d ++",headA);
              printf("tailA=%d \n",tailA);
              enqueue( queueB, x);
     }

     else if(!is_A_empty && is_B_empty){
              printf("push A not and B empty headA=%d ++",headA);
              printf("tailA=%d \n",tailA);
        enqueue( queueA, x);
     }
     
     else{
        printf("debug on push function\n");
     }

  
}

int pop(void){

    int tmp_pop;
    
    check_empty();
    
    if( !is_A_empty){
       if(tailA != 1){     
          while( headA != (tailA-1) ){
             enqueue( queueB, dequeue(queueA));
          }
       }
       else{
          while( headA != MAX_SIZE){
             enqueue( queueB, dequeue(queueA));
          }
       }   
          
          tmp_pop = dequeue(queueA);
          //reinitialization 
          headA = 1;
          tailA = 1;

          return tmp_pop;
    }   
       
    else if(!is_B_empty){
       while( headB != (tailB-1) ){
          enqueue( queueA, dequeue(queueB));
       }  
          tmp_pop = dequeue(queueB);
          //reinitialization
          headB = 1;
          tailB = 1;

          return tmp_pop;
    }

    printf("debug on pop function\n");
}


int main(int argc, char *argv[])
{

    int input;
    int select = 0;
    int i = 0;

 
    while ( select != 3){
    printf("Choose 1.Push\n2.Pop\n3.quit\n");
    
    scanf("%d", &select);
    //getchar();
    printf("select =%d\n",select);
    //putchar(select);

    for (i = 0; i < 5; i++) { 
       printf("QueueA[%d]=%d QueueB[%d]=%d\n", i, QueueA[i], i, QueueB[i]);
    }
     switch (select){
       case 1:
             printf("please input one number to Push   \n");
             scanf("%d", &input);
             getchar();
             printf("Push(%d)\n",input);
             push(input);
             break;
       
       case 2: 
             printf("Pop %d\n",pop());
             break;
       
       case 3:
             printf("quit\n");
             break;
       
       default:
            printf("default case\n"); 
            break;
              
          

       }

  };
  
   return 0;

}







   

/* method (1)
 * Queue  1:  enqueue queue 1 when the number of queue 1 is greater than 1 ,dequeue 1 to queue 2
 * Queue 2: dequeue
 *
 * methode (2):
 * Queue 1: enqueue 2 ,then dequeue items in queue 1 to queue 2
 *          switch q1 and q2
 * Queue 2 : dequeue
 * implement a stack using two queues
 push(x) =enqueue()
 {

   if (trail==head)
        overflow();
   if(trail==S.length)  
        trail=1;
   else
      S[trail]=x;
      trail++;
     
 }
  pop()
{
if((tail+1)==head)
    underflow();
if(head==S.length)
   head=1h;
   while(head==tail)
      enqueueB=dequeueA();
 return dqueueB();
}
*/


