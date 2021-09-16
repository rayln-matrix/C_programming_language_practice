#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

///// Function
int get_line(char *line, int max);


///// Function code


int get_line(char *line, int max){
	int i,c;
	while (--max > 0 && (c=getchar())!=EOF && c!='\n'){
              *line++=c;
		++i;        
	}
        if (c=='\n'){
              *line++=c;
		++i;
	}
        line[i]='\0';

        return i;

}





/*int main(){
int i;
for (i=0;i<100;++i)
    printf("i is %d, i%4 is %d\n",i, i%4);
}*/


///// Echo function
// char *argv[] --> pointer to an array of pointers
/*main(int argc, char *argv[]){
	int i;
	for (i=1;i<argc;i++) // starts from 1 --> 0 is for the main name
		printf("%s%s",argv[i],(i < argc-1)?" ":"")); // why not *argv[i]?
	printf("\n");
	return;
}*/

// Version 2
/// It is invoke when running the binary file
/*
main(int argc, char *argv[]){
	while (--argc>0) // index: 0~argc-1
        	printf((argc>1)?"%s ":"%s",*++argv); // ++argv-->escape argv[0]
	printf("\n");
	return;
}*/





///// Grep function
/*  Unclear behavior:
main(int argc, char *argv[]){

char line[MAXLINE];
int found = 0;

if (argc != 2)
	printf("Usage: find pattern.\n");
else
	while (get_line(line,MAXLINE) > 0)
		if (strstr(line, argv[1]) != NULL){
			printf("%s",line);
			found ++;	
		}	
//lenth = get_line(line,MAXLINE);
//printf("Length of the input is %d\n",lenth);
//printf("%s",line);
//printf("%d\n",lenth);

return found;
}*/


///// Find flag
main(int argc, char *argv[]){
// command: find -x -n pattern
// argc > 1 , *argv[0]= find, *argv[1] = -x, *argv[2] = -n, *argv[3] = pattern
/* check argc and if there are flag
    if no flag: normal finding
    if with flag, change flag variables: number, except
              run the flag function 
   (*++argv)[0] == **++argv
   *++argv[0] == *++(argv[0]) --> walk along string pointed by argv[0](*argv[0])
  
*/

char line[MAXLINE];
int c, number=0, except=0,found=0;
long lineno = 0;

while (--argc > 0 && (*++argv)[0]=='-')
	while (c = *++argv[0]){
	switch (c){
		case 'x':
			except = 1;
			break;
		case 'n':
			number = 1;
			break;
		default:
			printf("Find: illegal option %c\n",c);
			argc = 0;
			found = -1;
			break;
	}
	}
if (argc != 1)
	printf("Usage: find -x -n pattern.\n");
else
	while (get_line(line,MAXLINE)>0){
		lineno++;
		if ((strstr(line,*argv) != NULL) != except){
			if (number)
				printf("%1d:",lineno);
		printf("%s",line);
		found++;
		}	
	} 
return found;
} 



