#include<stdio.h>
#include<string.h>
#define MAX_SIZE 5

//initialize Stack A,B  for implementation of a queue using two staks
 int StackA[] = {0};
 int StackB[] = {0};
 int indexStackA = 1;
 int indexStackB = 1;
//initialize two Queues A,B for implementation of a stack using two queues
 int QueueA[] = {0};
 int QueueB[] = {0};
 int headA=1;
 int trailA=1;
 int headB=1;
 int trailB=1;
 
//function prototype for a queue
int dequeue(void);
int enqueue(int);
void pushStackA(int);
int popStackA(void);
void pushStackA(int);
int popStack(void);
//end of unction prototype for a queue
void overflow(void){

  printf("overerflow\n");
}
void underflow(void){
  printf("underflow\n");
}
/*
//function prototype for a stack
 void push(int);
 int  pop(void);
 void enqueueA(int);
 int dequeueA(void);
 void enqueueB(int);
 int dequeueB(void);
//end of function prototype for a stack
*/
int main(int argc, char *argv[])
{

int input;
int select;
int i=0;
//printf("please input one number\n");
 

   //printf("Choose 1.Enque\n2.Deque\n3.quit\n");
   select = 0;

   while ( select != 3){
    printf("Choose 1.Enque\n2.Deque\n3.quit\n");
    //select = getchar();
    scanf("%d", &select);
    //getchar();
    printf("select =%d\n",select);
    //putchar(select);

     switch (select){
       case 1:
             printf("please input one number to enqueue\n");
             scanf( "%d", &input);
             getchar();
             printf("Index %d\n",input);
             enqueque(input);
             break;
       
       case 2:
             //printf("to dequeue\n");
             printf("dequeue %d\n",dequeue());
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
//implementation a queue(enqueue and dequeue)
//using two stacks (pushStackA,pushStackB,popStackA and popStackB)


void pushStackA(int key)
{   
int i;    
    if(indexStackA > MAX_SIZE)
       overflow();
    else{
        //printf("pushStackA[indexStackA=%d],key=%d\n",indexStackA,key);
        
        StackA[indexStackA] = key;

        for (i = 1; i < 6; i++) {
        printf("pushStackA[indexStackA=%d] = %d\n", i, StackA[i]);  
        }
        indexStackA++;
    }

}

int popStackA(void)
{  
   int i;
   if(indexStackA==0)
     underflow();
   else{
      indexStackA--;
      
      for (i = 1; i < 6; i++) {
      printf("StackA[indexStackA=%d] = %d\n", i, StackA[i]);  
      }
      //printf("popStackA[indexStackA=%d] = %d\n", indexStackA, StackA[indexStackA]);  
      return StackA[indexStackA];
   }  
}

void pushStackB(int key)
{   
    
    if(indexStackB > MAX_SIZE)
       overflow();
    else{

       printf("pushStackB[indexStackB = %d]= key =%d\n", indexStackB, key);
       StackB[indexStackB]=key;
       indexStackB++;
    }

}

int popStackB(void)
{
   if(indexStackB == 0)
     underflow();
   else{
        indexStackB--;
        return StackB[indexStackB];
   }
}


void enqueque(int key)
{

    if(indexStackA > MAX_SIZE)
      overflow();
    else
      pushStackA(key);

}

int dequeue(void){
    int temp;
    if(indexStackB == 1)
         if(indexStackA == 0){
            underflow();
         }
         else{
            while(indexStackA > 0){
               //pushStackB(popStackA());
               temp = popStackA();
               printf("temp =%d\n",temp);
               pushStackB(temp);
               //indexStackA--;
            }
            return popStackB();
         }
    else
       return popStackB();
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
if((trail+1)==head)
    underflow();
if(head==S.length)
   head=1h;
   while(head==trail)
      enqueueB=dequeueA();
 return dqueueB();
}
*/


/*
void push(int x)
{
enqueueA(x);
}

int pop(void)
{
while(headA==trailA)
   enqueueB(dequeue());
return dequeueB();
}

void enqueueA(int x);
{}
*/
