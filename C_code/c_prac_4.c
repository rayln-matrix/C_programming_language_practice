#include <stdio.h>
#define MAXLEN 1000
#define TAB 7

// Sec 1.9--> check

////////// Variables and Functions declare
int get_line(char line[], int maxline);
void copy(char to[], char from[]);
// P31
//1.16: print length of line and line for any long line
int get_text(char s[]);
//1.17-->check
//1.18-->check
int de_blanking(char s[]);
//1.19-->check
int reverse(char orig[], char revrsd[]);

// P34
// 1.20-1.24
// 1.20
void print_tab(char s[]);


////////// Functions
// Return length of the line
// local variable: automatic variable
// External variable: gloable access---> shared memory location?
// External declartion can be ommited in the same file
// Definintion vs Declaration
int get_line(char line[], int maxline){
   int i,c;
   for (i=0; i<maxline-1 && (c=getchar())!=EOF && c != '\n';++i){
       line[i]=c;
   }
   /*if (c=='\n'){
       line[i]=c;
       ++i;
   }*/
   // '\0': null character, end of the array
   line[i]='\0';
   //printf(line);
   return i;
}

void copy(char to[], char from[]){
    // copy every char from from[] to to[]
    int i=0;
    while ((to[i]=from[i])!='\0')
        ++i;
}


int get_text(char s[]){
    int i,c;
    for (i=0;(c=getchar())!=EOF && c!='\n';++i){
        s[i]=c;
    }
    if (c=='\n'){
        s[i]=c;
        ++i;
    }
    s[i]='\0';
    //printf("%d\n",i);
    return i;
}


///1-18 -->check
int de_blanking(char s[]){
   // for c = getchar --> if c != \n --> puting c in array --> if c == \n--> end collecting, then removing the blank
   int c,i;
   i=0;
   while ((c=getchar())!=EOF && c != '\n'){
       if (c!='\t' && c!=' '){
           s[i]=c;
           ++i;}
   }
       if (c=='\n'){
           s[i]=c;
           ++i;
       }
   s[i]='\0';
   return i;
}

///1-19  -->check
//-->Segmentation fault (core dumped)
void reverse_line(char orig[], char revrsd[],int lng){
   int i,j,k;
   j=0;
   i=lng-1;//orig[lng]==null, will make the whole array empty(why?)
   k=i;
   //printf("%s",orig[lng]); --> this is null;
   while (j<=k){
       revrsd[j]=orig[i];
       ++j;
       --i;
       //printf("%s",revrsd[j]);
       //printf("%s",orig[i]);
   }
   //printf("%s\n",orig);
   printf("%s\n",revrsd);
}

//1-20
void print_de_tab(char s[], int max, int tab_len){
    int c,i,j;
    i=0;
    while (i<max-1 && (c=getchar())!=EOF && c != '\n'){
        if (c!='\t'){
            s[i]=c;
            ++i;
        }
        if (c=='\t'){
            for (j=tab_len;j>=0;--j){
                s[i]=' ';
                ++i; 
            }
        }
    }
    printf("%s\n",s);

}



////////// Main here:
main(){
   // while (line is not longer than limmit){ if (line is longer){copy to long}} printout longest length
   // array can be modified by called function
   //char current[MAXLEN];
   //char longest[MAXLEN];
   char text[MAXLEN];
   char text2[MAXLEN];
   //char test[10];
   int lng;
   //int max;
   //max = 0;
   
   /*while ((lng =get_line(current,MAXLEN))>0){
       //printf("Lng is %d\n",lng-1);
       if (lng > max){
           copy(longest,current);
           max = lng;
       }
       if (max>10){
       printf("%s", longest);
       }
   }*/

   
   /*if (max>0){
       printf("%s", longest);
   }*/

    
   //1-17
   /*while ((lng = get_text(text))>0){
       printf("%d\n",lng);
       printf("Length of the line is %d\n",lng);
       if (lng>0){
           //copy(longest,current);
           printf("%s",text);
       }
   
   }*/

   /* 1-18
   while ((lng=de_blanking(text))>0){
         printf("The lng of de_blanked string is %d\n", lng);
         printf("%s\n",text);
   
   }*/
   // Testing: if value asignment not start from begining or not sequential: failed to asigned (if start at 0 but not sequential: break at where the sequence stopped)
   // ex:
   /*test[0]='1';
   test[1]='1';
   test[2]='1';
   test[3]='1';
   test[4]='0';
   test[5]='0';
   test[6]='0';
   test[7]='1';
   test[8]='1';
   test[9]='\0';// ending with '\0' won't cause problems.
   printf("%s\n",test);*/
   
   //1.19
   /*while ((lng=get_line(text,MAXLEN))>0){
       //printf("The original line:%s\n",text);
       reverse_line(text, text2, lng);
       //printf("The reversed line:%s\n",text2);
   }*/

   //1.20
   //print_de_tab(text,MAXLEN,5);
   // R's Answer:
   int c,i;

   i = 0;

   while ((c = getchar()) != EOF) {
     i++;
     if (c == '\n')
       i = 0; /* reset column counter */
     if (c == '\t') {
       while ((i % TAB) != 0) {
        putchar(' ');
        i++;
      }
    } else {
      putchar(c);
     }
    }
 
   


   return 0;
}
