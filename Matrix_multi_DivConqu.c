#define MATRIX_SIZE (8)

void matrix_multiply_DivConq( int A[][], int B[][]){
     
     if(A_SIZE== 1){ 
       C[0][0] =  A[0][0] * B[0][0];
     
     }else{
       divide_matrix();
       //divide matrix
       //conquer
       C_up_left = matrix_multiply_DivConq( A_up_left, B_up_left)+
                   matrix_multiply_DivConq( A_up_right, B_down_left);

       C_up_right = matrix_multiply_DivConq( A_up_left, B_up_right)+
                   matrix_multiply_DivConq( A_up_right, B_down_right);
       
       C_down_left = matrix_multiply_DivConq( A_down_left, B_up_left)+
                   matrix_multiply_DivConq( A_down_right, B_down_left);

       C_down_right = matrix_multiply_DivConq( A_down_left, B_up_right)+
                   matrix_multiply_DivConq( A_down_right, B_down_right);
            
     
     return C[][];
}

void matrix_multiply_normal( int A[][], int B[][], int C[][]){
     int rowA = 0;
     int columnA = 0;
     int rowB = 0;
     int columnB = 0;
     int value = 0;

     if(MATRIX_SIZE== 1){
    
       C[0][0] =  A[0][0] * B[0][0];
     }
       

     
     }else{
       
       for(int rowA =0; rowA<MATRIX_SIZE; rowA++)
        for(int columnB =0; columnB<MATRIX_SIZE; columnB++)
         for(int index = 0; index < MATRIX_SIZE-1; index++){
            C[rowA][columnB] = 0;
            C[rowA][columnB] = C[rowA][columnB] + A[rowA][index] * B[index][columnB];
     
     
     }

     return C[][];
}

int main(int argc, char *argv[]){

    int A[MATRIX_SIZE][MATRIX_SIZE];
    int B[MATRIX_SIZE][MATRIX_SIZE];
    int C[MATRIX_SIZE][MATRIX_SIZE];
  
 
    

}
