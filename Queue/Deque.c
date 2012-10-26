#include<stdio.h>
#include<string.h>

#define MAX_SIZE (11)
#define EMPTY (-99)

#define DEBUG (1)
#define ERROR (1)
#define ERROR_OVERFLOW (2)
#define ERROR_UNDERFLOW (3) 

int front = (MAX_SIZE-1)/2;
int back = (MAX_SIZE-1)/2;
int queue[MAX_SIZE];

void initialize(void){
    int i =0;
    for(i = 0; i < MAX_SIZE; i++){

        queue[i] = EMPTY;
    }
} 

void LOG(void){
    int i = 0;
    printf("front=%d, back=%d\n", front, back);
    for(i = 0; i < MAX_SIZE; i++){
        printf("queue[%d]=%d\n", i, queue[i]);
    }
}
int overflow(void){
  printf("overerflow\n");
  return ERROR_OVERFLOW;
}

int underflow(void){
  printf("underflow\n");
  return ERROR_UNDERFLOW;
}

int push_front(int element);
int push_back(int element);
int pop_front(void);
int pop_back(void);

/*
 *
 index(back and front is in empty position
    ----------
front          back         
    0        MAX_SIZE-1
    ----------
*/

int push_front (int element){
   if( front<0 ){ 
      return overflow();
   }   
   if(front == back){
      back++;
   }
   queue[front--]=element;
#if DEBUG   
   LOG();
#endif
   return 0;
}

int pop_front(void){
   int temp_queue[1] = {EMPTY};

   if(front > MAX_SIZE)
      return underflow();
   else if( front==back){
      ++back;
      temp_queue[1] = queue[++front];
      if(temp_queue[1] == EMPTY){
         --front;
         --back;
         return overflow();
      }   
      queue[front] = EMPTY;
#if DEBUG   
   LOG();
#endif
      return temp_queue[1];
   }
   else{
      temp_queue[1] = queue[++front];
      queue[front] = EMPTY; 
#if DEBUG   
   LOG();
#endif
      return temp_queue[1];
   }
}
int push_back(int element){
   if( back>MAX_SIZE){
      return overflow();
   }
   if(front == back){
      front--;
   }
   queue[back++]=element;
#if DEBUG   
   LOG();
#endif
   return 0;
}

int pop_back(void){
   int temp_queue[1] = {EMPTY};
   if(back<0)
     return underflow();
   else if(front == back){
     --front;
     temp_queue[1] = queue[--back];
     //check deque empty and undo index 
     if(temp_queue[1] == EMPTY){
        ++front;
        ++back;
        return overflow();
     }   
     queue[back] = EMPTY;
#if DEBUG   
   LOG();
#endif
     return temp_queue[1];
   }
   else{
     temp_queue[1] = queue[--back];
     queue[back] = EMPTY;
#if DEBUG   
   LOG();
#endif
     return temp_queue[1];
   }
}

int main(int argc, char *argv[]){

    int input;
    int select = 0;
  
    initialize();
 
    while ( select != 5){
        printf("Choose 1.push_front\n2.pop_front\n3.push_back\n4.pop_back\n5.quit\n"); 
        scanf("%d", &select);
        //getchar();
        printf("select =%d\n",select);
        //putchar(select);

      
        switch (select){
           case 1:
                 printf("please input one number to push_front\n");
                 scanf("%d", &input);
                 getchar();
                 printf("push_front(%d)\n",input);
                 push_front(input);
                 break; 
           case 2: 
                 printf("pop_front%d\n",pop_front() );
                 break; 
           case 3:
                 printf("please input one number to push_back\n");
                 scanf("%d", &input);
                 getchar();
                 printf("push_back(%d)\n",input);
                 push_back(input);
                 break;
           case 4:      
                 printf("pop_back%d\n",pop_back() );
                 break; 
           default:
                printf("Please choose correct one\n"); 
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


