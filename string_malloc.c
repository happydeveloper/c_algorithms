#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * strcat_safe(char *dest, size_t dest_size, const char *src) { 
    int dest_len = strlen(dest); 
    if(dest_len >= dest_size) { 
      return dest; 
    } snprintf(
        dest + dest_len, dest_size - dest_len, "%s", src); 
    return dest; 
}


int main(){
  char temp[8];
  char *p_str = NULL;
  int total_size = 0, size = 0;
  int cnt;
  while(1){
    fgets(temp, 8, stdin);
    size = strlen(temp);
    total_size += size;

    if(p_str == NULL){
      p_str = (char *)malloc(total_size+1);
      //strcpy_s(p_str, total_size + 1, temp);
      memcpy(p_str, temp, total_size + 1);
    } else {
      p_str = (char *)realloc(p_str, total_size+1);
      strcat_safe(p_str, total_size + 1, temp);
    }

    if(temp[size -1 ] == '\n'){
      *(p_str + total_size -1) = 0;
      break;
    }
    cnt++;
  }

  printf("--> %s \n몇번 사이클이 도는지 체크 : %d\n", p_str, cnt);
  free(p_str);
  return 0;
}
