#include <stdio.h>

#define IN 1
#define OUT 0

// why need this if the function can be called and used directly with function code(body)
// assume to be contained in one file??
int power(int base, int n);
// return type name (argument type)
int power(int base, int n){
   int i,p;
   p=1;
   for (i=1;i<=n;++i){
       p = p*base;
   }
   return p;
}


float f_to_c(float f){
    /// c = (f-32)*5/9
    float c;
    c = (f-32.)*5/9;
    return c;
}


main(){


//int c,nl,nw,nc,state;
//nl=nw=nc=0;

//int c, state;
//state=OUT;

// print one word per line--> if c=\n or ' ' or '\t'--> seperate a word
//
 
/*while ((c=getchar())!=EOF){
    ++nc;
    if (c=='\n')
        ++nl;
    if (c==' ' || c=='\n' || c=='\t')
        state=OUT;
    else if (state==OUT){
        state=IN;
        ++nw; 
    }
}
printf("%d %d %d \n",nl,nw,nc);
*/


//This is 1-12
/// with out loop, c= a single char
/*c=getchar();
putchar(c);*/
/*while ((c=getchar())!=EOF){
    if (c==' ' || c=='\n' || c=='\t')
        putchar('\n');
    else
        putchar(c);
}*/
/*
while ((c=getchar())!=EOF){
    state=IN;
    if (c==' ' || c=='\n' || c=='\t')
        state=OUT;
    else if (state==OUT){
        //state=IN;
        putchar(c);
        putchar('\n');
    }
}*/


int c,nwhite,nother,i;
nwhite=nother=0;
int narray[10];

printf("Initial count of 0-9: \n");
for (i=0;i<10;++i){
narray[i]=0;
printf("%d:%d  ",i,narray[i]);
}
printf("\n");
printf("Initial count of whitespace: %d \n", nwhite);
printf("Initial count of others: %d \n", nother);



while ((c=getchar())!=EOF){
    // Using '0' char representation, not direct int value
    if (c>='0' && c<='9')
    // why - '0'
       ++narray[c-'0'];
    else if (c==' ' || c=='\t' || c=='\b')
       ++nwhite;
    else
       ++nother;
}

printf("Counting numbers in input:\n");
for (i=0;i<10;++i){
printf("%d:%d  ",i,narray[i]);
}
printf("\n");
printf("Count of whitespace: %d \n", nwhite);
printf("Count of others: %d \n", nother);

/// 1-13 / 1-14 uncheck

/// 1.7 function:

int check_b,check_p;
printf("Check Function: Power of int.\n");

for (check_b=1;check_b <=11;++check_b){
    for (check_p=1;check_p<=5;++check_p)
        printf(" %d %d %d \n",check_b, check_p, power(check_b,check_p));
}

/// 1-15 prac  (p27):
float f=0;
printf("Check 1-15 f_to_c function.\n");
while (f<=100.){
   printf("%.1f  %6.2f\n", f, f_to_c(f));
   f = f + 10.;
}

/// called by value vs called by reference ---> special case: pointer, array

}
