#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
  int f;
  int READ = 0;
  int WRITE = 1;
  
  int p1[2];
  int p2[2];
  
  pipe(p1);
  pipe(p2);

  f =fork();
  
  if (f == 0) { //child!!
    close(p1[WRITE]);
    close(p2[READ]);   
    int num;
    read(p1[READ], &num, sizeof(num));

    printf("[child] doing maths on %d\n",num);

    int x = ((num + 77) * 2);  
    printf("[child] sending %d\n",x);
    write( p2[WRITE], &x , sizeof(x) );
  }

  
  else { //parent!!
    close(p1[READ]);
    close(p2[WRITE]); 
    int num2 = 1000;
    write(p1[WRITE], &num2, sizeof(num2));  
    printf("[parent]sending %d\n", num2);
    int receeved;
    read(p2[READ], &receeved, sizeof(receeved)); 
    printf( "[parent] receeved %d\n", receeved);

    
  }

  
}
