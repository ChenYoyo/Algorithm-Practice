#define MATRIX_SIZE (8)

#if 0
void matrix_multiply_DivConq( int A[][], int B[][], ){
     if(matrix_size == 1){
       C[0][0] =  A[0][0] * B[0][0];
     }else{
       
     }

}
#endif

void matrix_multiply_DivConq( int A[][], int B[][], int matrix_size){
     int mid_matrix_size = matrix_size/2;
     int C[matrix_size][matrix_size];
     
     int A_up_left[mid_matrix_size], A_up_right[mid_matrix_size],
         A_down_left[mid_matrix_size][mid_matrix_size], A_down_right[mid_matrix_size][mid_matrix_size];

     int B_up_left[mid_matrix_size], B_up_right[mid_matrix_size],\
         B_down_left[mid_matrix_size][mid_matrix_size], B_down_right[mid_matrix_size][mid_matrix_size];

     int C_up_left[mid_matrix_size], C_up_right[mid_matrix_size],\
         C_down_left[mid_matrix_size][mid_matrix_size], C_down_right[mid_matrix_size][mid_matrix_size];
     
     if( matrix_size/2 == 1){ 
       C[0][0] =  A[0][0] * B[0][0];
     
     }else{
       //divide_matrix();
       //divide matrix
       for( row=0; row<matrix_size/2; row++)
        for( col=0; col<matrix_size/2; col++)
           A_up_left[row][col] = A[row][col];
       
       for( row=0; row<matrix_size/2; row++)
        for( col=matrix_size/2; col<matrix_size; col++)
           A_up_right[row][col-matrix_size/2] = A[row][col];

       for( row=matrix_size/2; row<matrix_size; row++)
        for( col=0; col<matrix_size/2; col++)
           A_down_left[row-matrix_size/2][col] = A[row][col];

       for( row=matrix_size/2; row<matrix_size; row++)
        for( col=matrix_size/2; col<matrix_size; col++)
           A_down_right[row-matrix_size/2][col-matrix_size/2] = A[row][col];
       
       //divide  matrix B
       for( row=0; row<matrix_size/2; row++)
        for( col=0; col<matrix_size/2; col++)
           B_up_left[row][col] = B[row][col];
       
       for( row=0; row<matrix_size/2; row++)
        for( col=matrix_size/2; col<matrix_size; col++)
           B_up_right[row][col-matrix_size/2] = B[row][col];

       for( row=matrix_size/2; row<matrix_size; row++)
        for( col=0; col<matrix_size/2; col++)
           B_down_left[row-matrix_size/2][col] = B[row][col];

       for( row=matrix_size/2; row<matrix_size; row++)
        for( col=matrix_size/2; col<matrix_size; col++)
           B_down_right[row-matrix_size/2][col-matrix_size/2] = B[row][col];
       
       //conquer
       C_up_left = matrix_multiply_DivConq( A_up_left, B_up_left, matrix_size/2)+
                   matrix_multiply_DivConq( A_up_right, B_down_left, matrix_size/2);

       C_up_right = matrix_multiply_DivConq( A_up_left, B_up_right, matrix_size/2)+
                   matrix_multiply_DivConq( A_up_right, B_down_right, matrix_size/2);
       
       C_down_left = matrix_multiply_DivConq( A_down_left, B_up_left, matrix_size/2)+
                   matrix_multiply_DivConq( A_down_right, B_down_left, matrix_size/2);

       C_down_right = matrix_multiply_DivConq( A_down_left, B_up_right, matrix_size/2)+
                   matrix_multiply_DivConq( A_down_right, B_down_right, matrix_size/2);
            
       //move to matrix C
       for( row=0; row<matrix_size/2; row++)
        for( col=0; col<matrix_size/2; col++)
           C[row][col] = C_up_left[row][col];
       
       for( row=0; row<matrix_size/2; row++)
        for( col=matrix_size/2; col<matrix_size; col++)
           C[row][col+matrix_size/2] = C_up_right[row][col];

       for( row=matrix_size/2; row<matrix_size; row++)
        for( col=0; col<matrix_size/2; col++)
           C[row+matrix_size/2][col] = C_down_left[row][col];

       for( row=matrix_size/2; row<matrix_size; row++)
        for( col=matrix_size/2; col<matrix_size; col++)
           C[row+matrix_size/2][col+matrix_size/2] = C_down_right[row][col];
     }
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
