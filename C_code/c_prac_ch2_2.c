#include <stdio.h>
#include <limits.h>
//#include <string.h>

////// Notes
//2-3 --> check
// ++n vs n++
// p48, 2-4, 2-5 --> checked
// p49, 2-6~2-8 -->checked
// oct number: 0####, hex number: 0x### / 0X#### , ex: 0177=0001111111
// p58, 3.1 
// p60, 3.2
// p63, 3.3 (unchecked)
// p64, 3.4-3.6 (unchecked)

///// Declaration
//Function
int htoi(char s[]);
int to_lower(int c);
int power(int base, int pow);
int isint(char c);
int get_strlen(char s[]);
unsigned get_bits(unsigned x, int n, int p);
int bitcount(unsigned x);
int to_lower(int c);
void escape(char s[], char t[]);
//3-5, p62
void shell_sort(int v[], int n);
//3.3, p63
void expand(char s1[], char s2[]);
int ischar(char c);

//2.6
unsigned set_bits(unsigned x, int p, int n, unsigned y);
//2.7
unsigned invert_bits(unsigned x, int p, int n);
//2.8
int right_rot(int x, int n);
//3.1
int binsearch(int x, int v[], int n);

//Variable,constant;
enum mapping {a=10,b,c,d,e,f};// --> problem symbol doesnt equaul to chars



///// Definition:
int to_lower(int c){
   if (c>='A' && c<='Z')
       return c + 'a' -'A';
   else
       return c;
}


int power(int base, int pow){
   int i,n;
   n=1;
   if (pow==0)
       return 1;
   else 
   {for (i=1;i<=pow;++i)
       n= n*base;}
   return n;
}

int isint(char c){
   if (c>='0' && c<='9')
      return 1;
   else
      return 0;
}

int ischar(char c){
   if (c>='a' && c<='z')
      return 1;
   else 
      return 0;
}


int get_strlen(char s[]){
 int i;
 for (i=0;s[i]!='\0';++i);
 return i;
}



int htoi(char s[]){
  int decimal,count,lng, p,hex;
  lng = get_strlen(s);
  
  decimal=0;
  p=0;
  
  if (s[1]=='x' || s[1]=='X'){
      //printf("This is a hexadecimal string!\n");
      //printf("The Length of the  string is (without null): %d\n",lng);
      //printf("The last char of the string (first bit of number) is : %c\n", s[lng-1]);
      //printf("\n");
      for (count=lng-1; s[count]!='\0' && count>1;--count){     
          if (isint(s[count])){
             hex = s[count]-'0';
             decimal = decimal + power(16,p)*hex;
             //printf("Current digit is: %c\n",s[count]);
             //printf("The hex number is: %d\n",hex);
             //printf("The power is: %d\n",p);
             //printf("The decimal is: %d\n",decimal);
             //printf("The decimal in hex is: %x\n",decimal);
             ++p;
             //printf("\n");
          }
          else {
          hex = to_lower(s[count]);
          decimal = decimal + power(16,p)*(hex - 'a' + 10);
          //printf("Current digit is: %c\n",s[count]);
          //printf("The hex number is: %c\n",hex);
          //printf("The value of char is : %d\n", (hex - 'a' + 10));
          //printf("The power is: %d\n",p);
          //printf("The decimal is: %d\n",decimal);
          //printf("The decimal in hex is: %x\n",decimal);
          ++p;
          //printf("\n"); 
          }
      }
      //printf("*******************\n");
      return decimal;
  } 
  else
      //printf("*******************\n");
      return INT_MIN;
}



//p49
unsigned get_bits(unsigned x, int p, int n){
    // Return n bits start from position p to the right
    // x = 01010111
    //     76543210
    // p = 4, n = 3, ---> out: 101 -->shift 4-3+1-->2
    // x>>p-1+n = x>>6 = 00000001
    // ~(~0<<n) = 11111111 --> 11111000 --> 00000111
    // 00000001 & 00000111 = 00000001 
    return (x>>(p+1-n)) & ~(~0<<n);
}

//2.6 ---> checked
unsigned set_bits(unsigned x, int p, int n, unsigned y){
  // x: starts from p , replace n bits for y's n bits
  /*unsigned y_n;
  y_n =   y & ~(~0<<n);   // 0n     //((y>>(p+1-n))& ~(~0<<n))<<(p+1-n); -->this is p-n bits in y, not rightmost n bits
  x_n = x & ~(~0<<(p+1-n)); //  first (p+1-n) bits of x , rest ==0;
  x_p_n = (x>>(p+1-n)) & (~0<<n); // move p-n to the rightmost of x and set to 0;
  x_p_n = ((x_p_n | y_n)<<(p+1-n)) | x_n;*/ // replace x with y
  return (((x>>(p+1-n)) & (~0<<n) | (y & ~(~0<<n)))<<(p+1-n)) | (x & ~(~0<<(p+1-n)));
  // other's idea: 
  // return (x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n))))) | ((y & ~(~0 << n)) << (p + 1 - n))
  // return ((x & ~(~(~0 << n) << p+1-n)) | ((~(~0 << n) & y) << p+1-n));
  // return x & ~(((1U << n) - 1) << p) | (y & ((1U << n) - 1)) << p;
}

//2.7
unsigned invert_bits(unsigned x, int p, int n){
  // invert n bits starts from p:
  // get bits after p : (x&(~0<<(p+1)))
  // get bits before p-n+1 : (x&~(~0<<(p-n+1)))
  // inverting n bits: ((((x&(~0<<(p-n+1)))-1)>>(p-n+1))<<(p-n+1)) & ~(~0<<(p+1))
  // 0110 ^ 1111 = 1001, 1101 ^ 1111 = 0010  --> XOR 1 = invert
  // 0110 ^ 0000 = 0110, 1101 ^ 0000 = 1101  --> XOR 0 = unchange
  // --> x XOR 000111...100 --> ~(~0<<n)<<(p-n+1) 
  //return (x&(~0<<(p+1))) | (x&~(~0<<(p-n+1))) | (((( x&(~0<<(p-n+1)))-1)>>(p-n+1))<<(p-n+1)) & ~(~0<<(p+1));
 return x ^ ((~(~0<<n))<<(p-n+1)) ;
// other solution: set_bits(x,p,n,~x)

}

//2.8---> checked
int right_rot(int x, int n){
// set all others to 0, except right most n bits: x & (~(~0<<n))
// put these n bits to the left and padd others with 0: above << sizeof(x)*8-n
// shift x n bits right:  x>>n  11000011 --> 00001100 (n=4)
// | with above :(x>>n) | ((x& (~(~0<<n)))<<(sizeof(x)*8-n))

// Checked: 1 << sizeof(1)*8-n is correct --> x<<(sizeof(x)*8-n) 
// printf("Size of int is: %d bytes, %d bits \n", sizeof(x),sizeof(x)*8);
// printf("Size to shift right is :%d\n",sizeof(x)*8-n);

// Checked: x & (~(~0<<n)) --> set all others to 0, except right most n bits 
return (x>>n)|(x& (~(~0<<n)))<<(sizeof(x)*8-n) ;  //  x<<(sizeof(x)*8-n) ; 

}

//p50 ---> check
//2.9 ---> check
int bitcount(unsigned x){
  // using:x &= (x-1)
  int b=0;
  /*for (b=0;x!=0;x>>=1){
       if (x & 01) // why use 01? 1 gets the same result
         ++b;  
  }*/
  
  while (x!=0){
    ++b;
    x&=(x-1);
  }
  return b;
}

/*  New to_lower
int to_lower(int c){
 return (c>='A' && c<='Z')?c+'a'-'A':c ;
}*/


//Conditional expression;
/*
if (a>b)
   z=a;
else
   z=b;

is equal to :

z = (a>b)? a:b;
example:

for (i=0;i<n;++i)
   printf("%6d%c",a[i],(i%10==9 || i==n-1)?'\n':' ');
*/
// Beware of "side effect " when using function call, nested assignment, increment and decrement



//3.1, p58
int binsearch(int x, int v[], int n){
}

//3.2, p60
void escape(char s[], char t[]){
 int i=0;
 int j=0;
 while (s[i]!='\0'){
    switch (s[i]){
       case '\n' : 
                 t[j]='\\';
                 printf("t is %s, j is %d\n",t,j);
                 t[++j]='n';
                 printf("t is %s, j is %d\n",t,j);
                 ++i;
                 break;
       case '\t' : 
                 t[j]='\\';
                 printf("t is %s, j is %d\n",t,j);
                 t[++j]='t';
                 printf("t is %s, j is %d\n",t,j);
                 ++i;
                 break;
       default:
                t[j]=s[i];
                ++i;
                ++j;
                printf("t is %s, j is %d\n",t,j);
                break;
   }
 }
 t[j]='\0';
}


//Shell sort:
void shell_sort(int v[], int n){
   // n: length of the int array
   int gap, i, j,temp;
   for (gap=n/2;gap>0;gap/=2) // gap=n/2 --> 1
      for (i=gap;i<n;++i) // from gap to n
          for (j=i-gap; j>=0 && v[j]>v[j+gap];j-=gap){
               temp = v[j];
               v[j] = v[j+gap];
               v[j+gap]=temp;  
          }
}


//expand:
void expand(char s1[], char s2[]){
   // expand short hand: 'a-z' to complete series: abcd..xyz
   // Handel both digits and letters, and take leading or trailing - literally
   /* If any '-', complete the series: ex: -c--> abc, -a-z-->abcd...xyz, z-a: zxy..cba  
      Algorithm: 
      1. find '-' between chars
      2. left char: starting point, right char ending-->complete the series  
      3. leading and trailing ('-' not between chars): omitted
      --> find the index of '-' and letter/digits
      --> according to the index, complete the series
  */
   int i,j,k;
   int start, end; 
   int index_s2, char_start;
    
   printf("The lenght of orignal string is: %d\n", get_strlen(s1));
   for (i=0;s1[i]!='\0';++i){
       j=i+1;
       if (s1[i]=='-' && (i==0))
          s2[i]='-';
       printf("Current index = %d, next index is %d\n", i, j);
       if (s1[i]=='-' && i!=0 && s1[j]!='\0'){
          k=i-1;
          if (ischar(to_lower(s1[j])) && ischar(to_lower(s1[k]))){
              printf("Found - between chars\n");
              if (to_lower(s1[j])>to_lower(s1[k])){
                  printf("Start is greater\n");
                  for (index_s2=0,char_start=to_lower(s1[j]);char_start <= to_lower(s1[k]); ++index_s2, ++char_start)
                       s2[index_s2]=char_start;
              }
              if (to_lower(s1[j]) < to_lower(s1[k])){
                  printf("Start is lesser\n");
                  for (index_s2=0,char_start=to_lower(s1[j]);char_start >= to_lower(s1[k]); ++index_s2, --char_start)
                       s2[index_s2]=char_start;
              } 
          }
          else if (isint(s1[j]) && isint(s1[k])){
              printf("Found - between digits\n");
              if (s1[j] > s1[k]){
                  printf("Start is greater\n");
                  for (index_s2=0,char_start=s1[j];char_start <= s1[k]; ++index_s2, ++char_start)
                       s2[index_s2]=char_start;
              }
              if (s1[j] < s1[k]){
                  printf("Start is lesser\n");
                  for (index_s2=0,char_start=s1[j];char_start >= s1[k]; ++index_s2, --char_start)
                       s2[index_s2]=char_start;
              } 
          }
       }
           
           


   }
}


int main(){
/*
printf("This is the value of a: %d\n",a);
printf("This is the value of 'a': %d\n",'a');
printf("Testing char arithmetic: a to 10= %d\n",'a'-'a'+10);
printf("Testing char arithmetic: b to 11= %d\n",'b'-'a'+10);
printf("Testing char arithmetic: c to 12= %d\n",'c'-'a'+10);
printf("Testing char arithmetic: d to 13= %d\n",'d'-'a'+10);
printf("Testing char arithmetic: e to 14= %d\n",'e'-'a'+10);
printf("Testing char arithmetic: f to 15= %d\n",'f'-'a'+10);

printf("Checking power function: 16**0: %d\n", power(16,0));
printf("Checking power function: 16**1: %d\n", power(16,1));
printf("Checking power function: 16**2: %d\n", power(16,2));
printf("Checking power function: 16**3: %d\n", power(16,3));
printf("Checking power function: 16**4: %d\n", power(16,4));
printf("Checking power function: 16**5: %d\n", power(16,5));
printf("Checking power function: 16**6: %d\n", power(16,6));
printf("Checking power function: 16**7: %d\n", power(16,7));
printf("Checking power function: 16**8: %d\n", power(16,8));*/


char test1[]="0xFf"; //signed :-1, unsigned: 16*15+15=255
char test2[]="0X111"; //signed: -16**2 + 16 +1= -240 , unsigned: 273 = 512-240+1=2**9 -240 +1(0x111=000100010001)
char test3[]="abc";
char test4[]="122";
char test5[]="ab1";
char test6[]="0xFF1023"; // 1023= -16**3 + 16*2 + 3 = -4061, unsigned: 15*16**5 + 15*16**4 +1*16**3 +0 +2*16**1 +3 = 16745811
char test7[]="0x0aB3"; //10*16**2+11*16**1+3*16*0 = 2560 + 176 +3 = 2739 

//int test_6=htoi(test6);
printf("Testing HtoI: uncoverted: %s , converted: %d\n", test1, htoi(test1));
printf("*******************\n");
printf("Testing HtoI: uncoverted: %s , converted: %d\n", test2, htoi(test2));
printf("*******************\n");
printf("Testing HtoI: uncoverted: %s , converted: %d\n", test3, htoi(test3));
printf("*******************\n");
printf("Testing HtoI: uncoverted: %s , converted: %d\n", test4, htoi(test4));
printf("*******************\n");
printf("Testing HtoI: uncoverted: %s , converted: %d\n", test5, htoi(test5));
printf("*******************\n");
printf("Testing HtoI: uncoverted: %s , converted: %d\n", test6, htoi(test6));
printf("*******************\n");
printf("Testing HtoI: uncoverted: %s , converted: %d\n", test7, htoi(test7));
printf("*******************\n");


// Checking get_bits()

/*
unsigned utest = 18; 
unsigned utest2 = 215;

printf("%x\n", get_bits(utest, 4,3));
printf("%x\n", get_bits(utest2, 4,3));*/

/*2.6
unsigned i;
unsigned j;
unsigned k;
int p;
int n;
  
  for(i = 0; i < 30000; i += 511)
  {
    for(j = 0; j < 1000; j += 37)
    {
      for(p = 0; p < 16; p++)
      {
        for(n = 1; n <= p + 1; n++)
        {
          k = set_bits(i, p, n, j);
          printf("setbits(%u, %d, %d, %u) = %u\n", i, p, n, j, k);
        }
      }
    }
  }*/

/* 2.7
unsigned x;
int p, n;

  for(x = 0; x < 700; x += 49)
    for(n = 0; n < 8; n++)
      for(p = 0; p < 8; p++)
        printf("%x, %d, %d: %x\n", x, p, n, invert_bits(x, p, n));
  return 0;
*/

  //unsigned x;
  //int n;

  /*for(x = 0; x < 700; x += 49)
    for(n = 1; n < 8; n++)
      printf("%u, %d: %u\n", x, n, right_rot(x, n));*/

  /*x = 2;
  for (n =1; n<8; ++n)
      printf("%d, %d, %d \n",x, n,right_rot(x,n ));*/
      // 0x00000001
      // 0x00000002-3

  //printf("signed max: %d\n", INT_MAX);
  //printf("signed min: %d\n", INT_MIN);
  //printf("Unsigned max: %d\n", UINT_MAX);

  /*for (x=0;x<=50;++x){
     printf("x is %d, Number of 1 in x is: %d\n",x,bitcount(x));
  }*/

    /* These hasnt checked yet
    char text1[50] = "\aHello,\n\tWorld! Mistakee\b was \"Extra 'e'\"!\n";
    char text2[51];
    
    printf("Original string:\n%s\n", text1);
    
    escape(text1, text2);
    printf("Escaped string:\n%s\n", text2);
    
    unescape(text1, text2);
    printf("Unescaped string:\n%s\n", text1);*/
    

  // Can use the result of a function as an input to the other function
  //printf("Test function calls: %d\n", ischar(to_lower('A')));

    char *s[] = { "a-z-", "z-a-", "-1-6-",
                  "a-ee-a", "a-R-L", "1-9-1",
                  "5-5", NULL };
    char result[100];
    int i = 0;

    while ( s[i] ) {

        /*  Expand and print the next string in our array s[]  */

        expand(s[i],result);
        printf("Unexpanded: %s\n", s[i]);
        printf("Expanded  : %s\n", result);
        ++i;
    }

  int testing1 = 10, testing2 = 10;
  // ++ -- suffix/positfix > prefix > (>,=>,<,<=, relational operator) > = (assignment)
  while (--testing1 > 0) // testing1 = testing1 -1, then check testing1 > 0, so the last print is: 1 (t=1-1=0, 0 !> 0)
        printf("testing --t is %d\n",testing1);
  while (testing2-- > 0) // check testing2 > 0 then testing2 = testing2 -1, so the last print is :0 (1>0, t=1-1=0)
        printf("testing t-- is %d\n",testing2);

  return 0;


}
