#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define MAXLINE 1000


/*Notes:
--> p71, 4.1 : checked
--> p73, 4.2
--> p79, 4.3-4.10
--> p83, 4.11
--> p88, 4.12-13
--> p91, 4.14
--> p91, conditional inclution
--> p97, 5.1-5.2
--> p107, 5.3-5.6
--> p110, 5.7
--> p112, 5.8
--> p114, 5.9
--> p118, 5.10-5.13
--> p121, 5.14-5.17
--> p126, 5.18-5.20

Function are always external: C does not allow function to be defined inside another function
Reverse Polish notation--> using stack

%f -->Display the floating point number using decimal representation, ex:3.1415
%e -->Display the floating point number using scientific notation with e, ex:1.86e6 (same as 1,860,000)
%g ->Use shorter of the two representations: f or e


the order of function call in an(some?) expression is not defined: ex: pop()-pop()


Definition / Declaration --> definition cause the storage to be set
Header: gather definition / declaration of shared (external varaibles)

register variable----> advise to put in register, but can be ignored by the compiler, can only be used as function parameters / internal(automatic) variables
some properties are related to machine

Block structure: declaration inside function


Array initialization: int month[]={1,2,3,4,5,6,7,8,9,10,11,12} --> size can be omitted


Using Macro: need to check whether () is needed. EX:
#define square(x) x*x
square(x+3) = x+3*x+3 =x+3 +3x

Ch5:

&: only apply to variables and arrays---> can't apply to constant, expression, register 
*: indirection or dereferencing

associative: when two operators have the same precedence, use associative: ex 100/10*10 (left to right)= (100/10)*10 

pa=&a[0] == pa=a

C guarantees that 0 is never a valid address for data

Pointer to array address scaling according to type(?)--> p+n, if an int is 41 bytes, then it will be scaled by 4

C does not provide any operators for processing an entire string of characters as a unit
declaration: p* and p[] is equal

*t++ : the character t points to before it is increment

int (*ptrarry)[13] is not equal to int *ptrarry[13]    


int *f() ---> f: function  return a pointer to integer
int (*pf)() ---> pf:  pointer to function return integer

typedef --- complicated declaration: p122

char **argv;
int (*daytab)[13];
int *daytab[13];
void *comp();
void (*comp)();
char (*(*x())[])();
char (*(*x[3])())[5];


69*15 = 4.6

accessing structure member: . , , this is higher than *, ex: (*pp).x  != *pp.x (*(pp.x)) 

*/



//Declaration: function, label, constant
int get_line(char line[], int max);
int strindex(char s[], char t[]);
int strrindex(char s[], char t[]); // p71, 4.1
double a_to_f(char s[]); // p71,  42


// Function code
int get_line(char line[], int max){
   // Get line of input char, return linenumber, fixed array (string)
   int i,c;
   i =0; 
   while (--max>0 && (c=getchar()) != EOF && c!='\n')
        line[i++]=c;
   if (c=='\n')
        line[i++]='\n';
   line[i++]='\0';
   return i;
}


int strindex(char s[], char t[]){
  // Find index of t in s, if no t in s, return -1
  int i,j,k;
  for (i=0;s[i]!='\0';++i){
     for (j=i, k=0;t[k]!='\0' && (t[k]==s[j]) ;++k,++j)
          ;
     if (k>0 && t[k]=='\0') // make sure the t in s and complete the searching
        return j;
 }
  return -1;   
}


int strrindex(char s[], char t[]){
  // Find the right most index of matching t in s
  int i,j,k, rightmost;
  rightmost=-1;
  for (i=0;s[i]!='\0';++i){
      for (j=i, k=0; t[k] != '\0'&& (t[k]==s[j]);++j,++k)
           ;
      if (k>0 && t[k]=='\0' && i>=rightmost){
          rightmost = i;
      }
  }
  //(rightmost > 0) ? return rightmost:return -1;
  if (rightmost != -1)
     return rightmost;
  else
     return -1;
}

// atoi at p61
double a_to_f(char s[]){
  // input: string of float numbers--> ex: 4.12,0.457,  -0.1245, output: double 
  /* algorithm:
     1. skip whitespace (at the begining of the string)
     2. find sign
     3. skip + / -
     4. find value before .
     5. find value after . and the power
     6. combine value and powerm return
  */

   double val, power;
   int i, sign;
   
   for (i=0;isspace(s[i]);++i) // skipping whitespace
   ;
   sign = (s[i]=='-')? -1:1;   // find sign
   if (s[i]=='+' || s[i]=='-') // skipping + / -  --> why there are + / - after sign??
       ++i;
   for (val =0 ; isdigit(s[i]); ++i)
       val = 10*val + (s[i]-'0');
   if (s[i]=='.')
       ++i;
   for (power = 0; isdigit(s[i]); ++i){
       val = 10*val + (s[i] - '0');
       power *= 10;
   }
   return sign*val/power;

}


//////// Main

/* This is main in 4.1
main(){
  char line[MAXLINE];
  int found=0;
  
  while (get_line(line,MAXLINE)>0){
      if (strindex(line, pattern)>=0){
          printf("%s\n",line);
          found++;
      } 
  }
  return found;
}*/


/*typedef struct TEST
{
  char *data;
  char testchar;
  int expected;
} TEST;


int main(void)
{
  TEST test[] =
  {
    {"Hello world", 'o', 7},
    {"This string is littered with iiiis", 'i', 32},
    {"No 'see' letters in here", 'c', -1}
  };

  size_t numtests = sizeof test / sizeof test[0];
  size_t i;

  char ch = 'o';
  int pos;

  for(i = 0; i < numtests; i++)
  {
    pos = strrindex(test[i].data, test[i].testchar);

    printf("Searching %s for last occurrence of %c.\n",
           test[i].data,
           test[i].testchar);

    printf("Expected result: %d\n", test[i].expected);
    printf("%sorrect (%d).\n", pos == test[i].expected ? "C" : "Inc", pos);
    if(pos != -1)
    {
      printf("Character found was %c\n", test[i].data[pos]);
    }
  }

  return 0;
}*/


int main()
{
    /*char s[] = "cqa bcdef cqa efff cdbbef";
    char t[] = "ef";
    char u[] = "cd";
    char v[] = "cqa";
    char z[] = "gh";
    int i;
    i = strrindex(s, t);
    if (i >=0)printf("'%s' matches '%s' at index %d\n",t,s,i);
    else printf("'%s' doesn't match '%s' at all\n",t,s);

    i = strrindex(s, u);
    if (i >=0)printf("'%s' matches '%s' at index %d\n",u,s,i);
    else printf("'%s' doesn't match '%s' at all\n",u,s);

    i = strrindex(s, v);
    if (i >=0)printf("'%s' matches '%s' at index %d\n",v,s,i);
    else printf("'%s' doesn't match '%s' at all\n",v,s);

    i = strrindex(s, z);
    if (i >=0)printf("'%s' matches '%s' at index %d\n",z,s,i);
    else printf("'%s' doesn't match '%s' at all\n",z,s);


    return 0;*/

  char line[MAXLINE];
  //double sum=0;
  
  while (get_line(line, MAXLINE) > 0){
      printf("\t%g\n", atof(line));  
  }
  return 0;

  

}

