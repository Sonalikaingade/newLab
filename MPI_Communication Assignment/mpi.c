#include<stdio.h>
#include<mpi.h>
int main(int argc, char** argv)
{
 int my_rank;
 int array[10] = {1,1,1,1};
 int rate[4] = {7,3,3,1};
 MPI_Status status;
 MPI_Init(&argc, &argv);
 MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
 if (my_rank==0){
  MPI_Recv( &array, 4, MPI_INT, 1, 10, MPI_COMM_WORLD, &status);
  printf("The data received  from department 1 is\n");
  for(int i = 0;i<4;i++)
  printf("%d ",array[i]);
  printf("\n");
  array[0] = array[0]*rate[0];
          array[1] = array[1]*rate[1];
          array[2] = array[2]*rate[2];
          array[3] = array[3]*rate[3];
          MPI_Send( &array, 4, MPI_INT, 1, 10, MPI_COMM_WORLD);
  MPI_Recv( &array, 4, MPI_INT, 2, 20, MPI_COMM_WORLD, &status);
  printf("The data received from department 2 is\n");
  for(int i = 0;i<4;i++)
   printf("%d ",array[i]);
  printf("\n");
  array[0] = array[0]*rate[0];
          array[1] = array[1]*rate[1];
          array[2] = array[2]*rate[2];
          array[3] = array[3]*rate[3];
          MPI_Send( &array, 4, MPI_INT, 2, 20, MPI_COMM_WORLD);
  MPI_Recv( &array, 4, MPI_INT, 3, 30, MPI_COMM_WORLD, &status);
  printf("The data received from department 3 is\n");
  for(int i = 0;i<4;i++)
   printf("%d ",array[i]);
  printf("\n");
  array[0] = array[0]*rate[0];
          array[1] = array[1]*rate[1];
          array[2] = array[2]*rate[2];
          array[3] = array[3]*rate[3];
          MPI_Send( &array, 4, MPI_INT, 3, 30, MPI_COMM_WORLD);
  
 }
 else if(my_rank == 1)
 {
  if (!array) // error checking
          {
            MPI_Abort (MPI_COMM_WORLD,1);
          }
          array[0] = 100;
          array[1] = 205;
          array[2] = 346;
          array[3] = 570;
          printf("item cost of department 1\n");
          for(int i = 0;i<4;i++)
                printf("%d ",array[i]); 
  printf("\n");
  MPI_Send( &array, 4, MPI_INT, 0, 10, MPI_COMM_WORLD);
  printf("The data is sent from the server number %d\n",my_rank);
  MPI_Recv( &array, 4, MPI_INT, 0, 10, MPI_COMM_WORLD, &status);
  printf("Successfully Received the data at department number 1\n");
  for(int i = 0;i<4;i++)
   printf("%d ",array[i]);
  printf("\n");
  
 }
 else if(my_rank == 2)
 {
  if (!array) // error checking
          {
            MPI_Abort (MPI_COMM_WORLD,1);
          }
          array[0] = 89;
          array[1] = 167;
          array[2] = 270;
          array[3] = 205;
          printf("The item cost of department 2\n");
          for(int i = 0;i<4;i++)
                printf("%d ",array[i]); 
  printf("\n");
  MPI_Send( &array, 4, MPI_INT, 0, 20, MPI_COMM_WORLD);
  printf("The data sent from the server number %d\n",my_rank);
  MPI_Recv( &array, 4, MPI_INT, 0, 20, MPI_COMM_WORLD, &status);
  printf("Successfully Received the data at department number 2 \n");
  for(int i = 0;i<4;i++)
   printf("%d ",array[i]);
  printf("\n");
 }
 else if(my_rank == 3)
 {
  if (!array) // error checking
          {
            MPI_Abort (MPI_COMM_WORLD,1);
          }
          array[0] = 56;
          array[1] = 478;
          array[2] = 6;
          array[3] = 889;
          printf("The item cost of department 3\n");
          for(int i = 0;i<4;i++)
   printf("%d ",array[i]); 
  printf("\n");
  MPI_Send( &array, 4, MPI_INT, 0, 30, MPI_COMM_WORLD);
  printf("The data sent from the server number %d\n",my_rank);
  MPI_Recv( &array, 4, MPI_INT, 0, 30, MPI_COMM_WORLD, &status);
  printf("Successfully Received the data at department number 3 \n");
  for(int i = 0;i<4;i++)
   printf("%d ",array[i]);
  printf("\n");
 }
 MPI_Finalize();
 return 0;
}
