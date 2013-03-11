#include<stdio.h>
#include<string.h>
#include<stddef.h>
#include"delta.h"

int main(void){


char *buffer1=" \
An h1 header   \
============\
\
Paragraphs are separated by a blank line.\
\
2nd paragraph. *Italic*, **bold**, `monospace`. Itemized lists\
look like:\
\
  * this one\
  * that one\
  * the other one\
\
Note that --- not considering the asterisk --- the actual text\
content starts at 4-columns in.\
\
> Block quotes are\
> written like so.\
>\
> They can span multiple paragraphs,\
> if you like.\
\
Use 3 dashes for an em-dash. Use 2 dashes for ranges (ex. it's all in\
chapters 12--14). Three dots ... will be converted to an ellipsis.";


char *buffer2=" \
An h1 header   \
============\
\
Paragraphs are separated by a blank line.\
\
2nd paragraph. *Italic*, **bold**, `monospace`. Itemized lists\
look like:\
\
  * this two\
  * that one\
  * the other one\
\
Note that --- not considering the asterisk --- the actual text\
content starts at 4-columns in.\
\
> Block quotes are\
> written like so.\
>\
> They can span multiple paragraphs,\
> if you like.\
\
Use 3 dashes for an em-dash. Use 2 dashes for ranges (ex. it's all in\
chapters 12--14). Three dots ... will be converted to an ellipsis.";


unsigned long size_buffer3;
char *buffer3=diff_delta(buffer1,strlen(buffer1)+1,buffer2,strlen(buffer2)+1,&size_buffer3,4000);

printf("size of diff: %lu\n", size_buffer3);
printf("diff: %s\n", buffer3);

unsigned long size_buffer4;
char *buffer4=patch_delta(buffer1,strlen(buffer1)+1,buffer3,size_buffer3,&size_buffer4);

if(strcmp(buffer4,buffer2)==0){

printf("We have the same buffer\n");

}



}
