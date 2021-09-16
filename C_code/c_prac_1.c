#include <stdio.h>


#define THIS 300
#define THAT 1000

#define IN 1
#define OUT 0


main(){
//printf("This is test");
//printf("THis ");
//printf("is test");
//printf("\n");
//printf("\c");

int fahr, cel;
int upper, lower, step;

float ff, cc;
/// c = (f-32)*5/9

upper = 200;
lower = 0;
step = 20;

fahr = lower;
ff = lower;

printf("Head\n");
while (fahr <= upper){
// the datatype doesnt change (or not?)
// int divide is truncate: testing (f-32)*(5/9)---> result will be all 0 (check)
cel = (fahr - 32)*5/9;
// the format can be used to print more than 1 values
// format long: %6d --> 6 digits wide
printf("%d\t%d\n",fahr,cel);
//printf("%d\n",cel);
fahr += step;
}

//printf format: %d decimal integer / %6d decimal integer at least 6 digit wide / %f float / %o octal / %x hex / %c char / %s string / %% %
//what is it mean 6 digit wide?
printf("%10s\n","Head!");
while (ff <= upper){
    cc = (5.0/9.0)*(ff-32.0);
    printf("%3.0f\t%6.1f\n",ff,cc);
    ff += step;

}

// testing printf digit wide:
printf("%d\n", upper);
printf("%1d\n", upper);
printf("%2d\n", upper);
printf("%3d\n", upper);
printf("%4d\n", upper);
printf("%5d\n", upper);
printf("%6d\n", upper);


cc = lower;
printf("%s\n","C to F");
while (cc <= upper){
    ff = (9.0/5.0)*cc + 32;
    printf("%3.0f\t%6.1f\n",cc,ff);
    cc += step;
}

int fahr_int;

printf("Using FOR loop\n");
for (fahr_int = 0; fahr_int <= 300; fahr_int +=10){
    printf("%3d\t%6.1f\n", fahr_int, (fahr_int-32)*(5.0/9.0));
}
for (fahr_int = 300; fahr_int >= 0; fahr_int -=10){
    printf("%3d\t%6.1f\n", fahr_int, (fahr_int-32)*(5.0/9.0));
}

printf("This is THIS:%d\t%o\t%x\n",THIS,THIS,THIS);
printf("This is THAT:%d\t%o\t%x\n",THAT,THAT,THAT);

int c;
long nc;

//int d=EOF;
printf("This is EOF: %x\n",EOF);
printf("%d\n",getchar()!=EOF);
//printf("%d\n",d!=EOF);

/*c=getchar();

while (c != EOF){
    putchar(c);
    c=getchar();
}*/
// Can be rewritten as:
//while ((c=getchar())!=EOF){putchar(c);}

printf("%x\t%x\n", sizeof(int),sizeof(long));
nc = 0;
// In linux, to input EOF: ctrl + D
// The counting below counts nearly everything: including enter
while (getchar()!=EOF)
    ++nc;
printf("The count is: %1d\n",nc);

/*
double nc;
for (nc=0;nc!+EOF;++nc)
    ;  <--- this is null statment
printf("The count is: %1d\n",nc);
*/

printf("Char inter value: %d\n",'A');
printf("%d\n",'A'<10);

// Counting blank:
long bl=0,tb=0, nl=0;
nc = 0;

while ((c=getchar())!=EOF){
    if (c==' ')
        ++nc;
    if (c=='\t')
        ++tb;
    if (c=='\n')
        ++nl;
}
printf("The number of blanks is: %d\n", nc);
printf("The number of tabs is: %d\n", tb);
printf("The number of newlines is: %d\n", nl);

//////  1-9 counting ' '
//c=getchar();
// 1.  c= getchar() <--- a single char
// 2. if c==' ' ---> check next: c= getchar()
// 3. if c==' ' ---> continue to next char (loop back) ---> if not, putchar()=' ' 
/*while ((c=getchar())!=EOF){
    //putchar(c);    
    if (c==' '){
        c=getchar();
        while (c==' ')    
            c=getchar();
        putchar(' ');
        //putchar('\n');
        //printf("\n");
        }
    else
    putchar(c);
}*/

////// 1-10 replacing tab:\t, backspace:\b, backslash:\\  ---> uncheck
what is the backspace symbol??
/*while ((c=getchar())!=EOF){
    //putchar(c);    
    if (c=='\t'){
        c=getchar();
        while (c=='\t')    
            c=getchar();
        putchar('\\');
        putchar('t');
        //putchar('\n');
        //printf("\n");
        }
    if (c=='\b'){
        c=getchar();
        while (c=='\b')    
            c=getchar();
        putchar('\\');
        putchar('b');
        //putchar('\n');
        //printf("\n");
        }
    if (c=='\\'){
        c=getchar();
        while (c=='\\')    
            c=getchar();
        putchar('\\');
        //putchar('t');
        //putchar('\n');
        //printf("\n");
        }
   
   
    else
    putchar(c);
}*/

// 1-11 uncheck
// 1-12 uncheck


}
