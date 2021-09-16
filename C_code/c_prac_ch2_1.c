#include <stdio.h>
#include <limits.h>
#include <float.h>

#define VTAB '\013'
#define BELL '\007'
// Complete set of escape sequence: p38



///////// Declaration: Function / Variable / constant
int int_power();
int atoi(char s[]);
int to_lower(int c);
int htoi(char s[]);

//2-1, p36
////////// Function code:
int int_power(long base,int power){
 long i,j;
 j=1;
 for (i=1;i<=power;++i){
    j=j*base;    
 }
 return j;
}

//2-2 
int get_line(char line[], int maxline){
   int i,c;
   /*for (i=0; i<maxline-1 && (c=getchar())!=EOF && c != '\n';++i){
       line[i]=c;
   }*/
   i=0;
   while (i<maxline-1){
        c=getchar();
        if (c!=EOF){
            if (c!='\n'){
                line[i]=c;
                ++i;
            }   
       }
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


//2-7
int atoi(char s[]){
   int i,n;
   n=0;
   for (i=0;s[i]>='0' && s[i]<='9';++i)
      n=10*n + (s[i]-'0');
   return n;
}
int to_lower(int c){
   if (c>='A' && c<='Z')
       return c + 'a' - 'A';
   else
       return c;
}

//p46, 2.3
int htoi(char s[]){
// coverting Hexadecimal string to integer:start with 0x or 0X, mapping f-15,e-14,d-13,c-12,b-11,a-10
/* Algorithm: 
1.find sizeof the string 
2.start at the last digit, ex: 0Xff014, the last digit is 4
3.check if the digit is not '\0' 
4.check if the string is a hexadecimal string, 0X or 0x
5.from the last digit, convert it to the decimal value and add up
6. Converting the hex: mapp the value to decimal, multiply the propper base

*/

int count, n, lng;
char not[]="Input is Not a hexadecimal string.";
lng = sizeof(s)/sizeof(s[0])-1;
for (count=lng; s[count]!='\0' && count>1; --count){
   if (s[1]!='x' && s[1]!='X')
       return 0;
   else 
       return 0;


}
}



////////// Main here:
int main(){

//char
char ch1;
signed char ch2;

//int
int int1, base_test=2,power_test;
short int2,base_test2=2;
long int3, base_test3=2;
unsigned int int4, base_test4=2;
signed int int5, base_test5=2;
//long long int6;

//float
float flt1;
double flt2;

printf("Char type:\n");
printf("char :%d\n", sizeof(ch1));
printf("signed char:%d\n", sizeof(ch1));
printf("signed char max:%d\n",SCHAR_MAX);
printf("signed char min:%d\n",SCHAR_MIN);
printf("unsigned char max:%d\n",UCHAR_MAX);
//printf("unsigned char min:%d\n",UCHAR_MIN);



printf("INT type:\n");
printf("int: %d\n", sizeof(int1));
printf("short: %d\n", sizeof(int2));
printf("long: %d\n", sizeof(int3));
//printf("long long: %d\n", sizeof(int6));
printf("unsigned int: %d\n", sizeof(int4));
printf("signed int: %d\n", sizeof(int5));
printf("signed max: %x\n", INT_MAX);
printf("signed min: %x\n", INT_MIN);
printf("Unsigned max: %x\n", UINT_MAX);
printf("long max: %x\n", LONG_MAX);
printf("long min: %x\n", LONG_MIN);


printf("Char type:\n");
printf("float: %d\n", sizeof(flt1));
printf("Double: %d\n", sizeof(flt2));


/*
// int: 0-31 --> 0x0fffffff --> 01111111 --> 10000000: 2**-31 // how c caculate multiplication /// how to assign type when calling functions
for (power_test=1;power_test<=64;++power_test)
    printf("Power: %d,  Value:%d\n",power_test,int_power(base_test,power_test));

for (power_test=1;power_test<=64;++power_test)
    printf("Power: %d,  Value:%d\n",power_test,int_power(base_test2,power_test));

for (power_test=1;power_test<=64;++power_test)
    printf("Power: %d,  Value:%d\n",power_test,int_power(base_test3,power_test));

for (power_test=1;power_test<=64;++power_test)
    printf("Power: %d,  Value:%d\n",power_test,int_power(base_test4,power_test));

for (power_test=1;power_test<=64;++power_test)
    printf("Power: %d,  Value:%d\n",power_test,int_power(base_test5,power_test));*/

printf("%x\n", VTAB);
printf("%x\n", BELL);

//// p38 what is a constant expression?
//// String constant: array---> 'x' != "x"
//// enumeration: like python dictionary --> why the compiler does not need to check the value? 

// char int=0--> '/0':null
char numb[]="0123456789";
char str1[]="ABCabcDeF";
int n = sizeof(numb)/sizeof(numb[0]);
int n1 = sizeof(str1)/sizeof(str1[0]) -1;
int count;
char str2[]="ABCDEFG";
char str3[]="abcdefg";
char *p=str2;

for (count=0;count<n;++count){
    printf("Char value: %d\n", numb[count]);
    printf("Integer representation: %d\n", numb[count]-numb[0]);
}
printf("%d\n",atoi(numb));

for (count=0;count<n && str1[count]!='\0';++count){
    printf(" not Convert : %c,  Converted : %c ", str1[count], to_lower(str1[count]));
    printf("\n");
}
/// Why use printf(%s) get Segmentation fault ---> When you use %s, printf expects you to pass a char*. You are passing a char instead.
printf("%c\n",str1[n1]);
printf("%d\n", n1);
printf("%d\n", n1-1);
printf("%c\n",str1[n1-1]);

printf("%c\n",*p);
printf("%c\n",*p+1);
}
