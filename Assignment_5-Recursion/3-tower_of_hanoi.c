/*
 * Problem-3: Implement the tower of hanoi function but instead of
   implementing the actual move function, just print the movement
   along with count of movements.
 * Ayush Singh 1910990059 01/08/21
 * Assignment_5 -> Recursion
*/

#include <stdio.h>

int move(int n, char from_rod, char to_rod){
  printf("move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
  return 1;
}

int tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod){

  //we can directly move 1 disk to desired rod
  if(n == 1){
    return move(n, from_rod, to_rod);
  }

  //we have to call the fn to first move top (n-1) disks to a temp rod
  //then  move the bottom disk to the desired rod and then again
  //use fn to move the other (n-1) disks above it
  return tower_of_hanoi(n-1, from_rod, aux_rod, to_rod) +
         move(n, from_rod, to_rod) +
         tower_of_hanoi(n-1, aux_rod, to_rod, from_rod);
}

int main(){
    int n, moves_req;
    n=3;

    printf("\e[1;1H\e[2J");
    moves_req = tower_of_hanoi(n, 'A', 'C', 'B');
    printf("Total Moves Required = %d", moves_req);

    return 0;
}
