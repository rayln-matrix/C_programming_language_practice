#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>

int adding(int a, int b){
int c=a+b;
return c;
};

const int constant_1 = 1024;
const float constant_2 = 3.1415;

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len){
    int i;
    for (i = 0; i<len ; i++)
        printf("%.2x",start[i]);
    printf("\n");
}


void show_int(int x){
    show_bytes((byte_pointer) &x, sizeof(int));
}
void show_float(float x){
    show_bytes((byte_pointer) &x, sizeof(float));
}
void show_pointer(void *x){
    show_bytes((byte_pointer) &x, sizeof(void *));
}


int32_t abs(int32_t x){
    int32_t mask = (x>>31);
    return (x+mask)^mask;

}

int shift_bits(int x){
  int shifted = (x<<31);
  return shifted;
}

int check_sign(int x, int y){
return ((x^y)<0);
}

void out_hex(){
  int i;
  for (i =0 ; i<=INT_MAX ; i++)
    printf("%x\n",i);
  //printf("%x\n",i);
   printf("\n");
}

// a = ~a + 1  1001 --> 0110 + 0001 = 0111 
//             0111 --> 1000 + 0001 = 1001
// if a >= 0 -> mask = 0x00000000
// if a , 0  -> mask = 0xFFFFFFFF
// abs (a) = ~a + 1 (for a <0 ) --> abs(a) -1 = ~a
// 1101 - 0011 ---> 1101 + 1111 = (1)1100
// -a + a = (1)0000
int32_t abs_1(int32_t a){
int mask = (a>>31);
return (a+mask)^mask;
}

int32_t abs_2(int32_t b){
int mask = (b>>31);
return (b^mask)-mask;
}

// Get the sign of an integer:
int get_sign(int x){
int v;
return -(x>>(sizeof(int)*CHAR_BIT - 1));
}

// de-branching: if(a>b) x+=c ---> x+=((b-a)>>31)&c
//The register storage  class  is  used  to  define  local  variables  that  should  be  stored  in  a register  instead  of  RAM. 


int main(){
//Size of int:
printf("Storage size of int is %x\n", sizeof(int));
printf("Storage size of unsigned int is %x\n", sizeof(unsigned));
printf("Storage size of short is %x\n", sizeof(short));
printf("Storage size of unsigned short is %x\n", sizeof(unsigned short));
printf("Storage size of long is %x\n", sizeof(long));
printf("Storage size of unsigned long is %x\n", sizeof(unsigned long));
printf("Storage size of char is %x\n", sizeof(char));
//Size of float:
printf("Storage size of float is %x\n", sizeof(float));
printf("Maximum of float is %f\n", FLT_MAX );
printf("Minimum of float is %f\n", FLT_MIN );
printf("Storage size of double is %x\n", sizeof(double));
printf("Storage size of long double is %x\n", sizeof(long double));
printf("Precision Value: %d\n", FLT_DIG);

int x=127, y=245;
int x_plus_y;
x_plus_y = adding(x,y);
printf("Result of testing function is : %d\n", x_plus_y);
/// test function call result: works

printf("Testing constant: %d\n", constant_1);
printf("Testing constant: %f\n", constant_2);
printf("Testing constant: %d\n", constant_1+constant_1);

int int_val;
float flt_val = int_val;
int *p_val = &int_val;
//float *f_p = &flt_val;

show_int(int_val);
show_float(flt_val);
//show_pointer(p_val);

printf("X in 10  is :%d\n",x);
printf("X in hex is :0x%x\n",x);
printf("Y in 10  is :%d\n",y);
printf("Y in hex is :0x%x\n",y);



x = (y << 8);
printf("Unshifted y: %d\n", y);
printf("Shift y: %d\n",x);

//out_hex();


return 0;
}
