#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char ** parse_args( char * line ){
  char ** args = (char**)calloc(6,sizeof(char*));
  char *stuff = line;
  int x = 0;
  while(stuff){
    args[x] = strsep( &stuff, " ");
    x++;
  }
  return args;
}


int main(){
  char line[150] = "ls -al";
  char ** args = parse_args( line );
  execvp(args[0], args);
  return 0;
}
