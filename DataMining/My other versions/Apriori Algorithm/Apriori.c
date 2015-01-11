/* 
 * File:   Apriori.c
 * Author: Rahul
 *
 * Created on January 27, 2012, 11:10 PM
 */

/*TF is the Input File
 * i0 in the file indicates no item for that transaction
 */
#include <stdio.h>
#include <stdlib.h>


#define INP "TF" //Input File Location
//prototypes
void inp_open(char* ,int ,int*);//file to open , line to extract , array to store that line(formatted)
void compute_l3(int ,int ,int);
void l1();
void l2();
void l3();

//globals
char inp[]=INP;
static int linescount; // used as a ref to the number of lines in l1 to generate l2..



int main(int argc, char** argv) {  

    l1(); //l0 item-count will be written to l0 file
    l2();
    l3();
    
    
    return (EXIT_SUCCESS);
}

void l1()
{
    int i;
    static int count[5]; //counts of items 1- 5 in order
    int lc[20]={0x0}; //line content lc[0]-transaction number ; lc[1] to lc[5] -item numbers
    FILE *l1 = fopen("l1","w");
    if(l1== NULL) ferror(l1);
    
    for (i=1;i<=5;i++)
        {
        inp_open(inp,i,lc);
        if (lc[1])  ++count[0];
        if (lc[2])  ++count[1];
        if (lc[3])  ++count[2];
        if (lc[4])  ++count[3];
        if (lc[5])  ++count[4];
        
         }
    //write to l0 File
    fprintf(l1,"ItemNo\tOccurences\n"); 
    for(i=1;i<=5;i++)
    {
    fprintf(l1,"i%d\t%d\n",i,count[i-1]);
    }
    fclose(l1);
    printf("l1 Written \n");
    
    
    
}

void l2()
{
    
/*i will copy each line content to lc array using inp_open() - to go through each line i use 'k'
 * i will then do a forward combination search like {i1,i2}{i1,i3} ..., {i4,i5} and not {i2,i1} ....
 * 
*/
    int i,j,k,t;
    int count[1][5][5]={0x0}; //using 1st index i can use it to store the sum of particular occurence combination for all transactions
    int lc[20]={0x0}; //line content lc[0]-transaction number ; lc[1] to lc[5] -item numbers
    FILE *l2 =fopen("l2","w");
    if(l2==NULL) ferror(l2);
    
    for(k=1;k<=5;k++) //iterate through lines of TF file
    {
        inp_open(inp,k,lc);
        for(i=0;i<=5;i++)
        {
         for(j=0;j<=5;j++)
           {
            if(i==j || i>j || i==0) continue; //since lc[0] is transaction number
            if(lc[i]!=0 && lc[j]!=0){
              ++count[0][i][j] ;
           }
         }
        
        }
    }
 
    //print it to the l2 file
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
        {
            if(i==j || i>j || i==0) continue;
            fprintf(l2,"i{%d,%d}\t%d\n",i,j,count[0][i][j]);
            linescount++;
        }
    printf("l2 Written\n");
    fclose(l2);
    
}



void l3()
{
    
/* Open l2 file and go through each line (total lines in l2 is determined using linescount variable) 
 * use only those rows that have frequency !=0 
 * now proceed as : i{1,3} find only i{1,3,4} i{1,3,5} ie: use the last number(b) in  i{a,b} and expand 
*/
    int j=0,k=0,a=0,b=0,freq=0; //a is dummy , b,freq are the variables see above comment
    
    FILE *l2 =fopen("l2","r");
    if(l2==NULL) ferror(l2);
    
    for(k=1;k<=linescount;k++) //Browse through lines of TF File
    {
        fscanf(l2,"i{%d,%d}\t%d\n",&a,&b,&freq);
        
         j=b+1; // we need i{a,b,b+1} since is forward search i.e i{3,4,5}... and{1,5,6} not computable so add j<=5
             
            
                if(freq>0 && j<=5)
                 {
                    compute_l3(a,b,j);  //this will process the current line and find all combination ocuurences same as i{a,b,j}
                    
                 }
              
        
       }
    
    printf("l3 Written");
 
}

void inp_open(char* fname ,int line ,int* lc){
      int l=0;
      
      FILE *fp = fopen(fname,"r");
      if(fp ==NULL) ferror(fp);
      
      for (l=1;l<=line;l++)
        {
          fscanf(fp,"t%d\ti%d\ti%d\ti%d\ti%d\ti%d\n",&lc[0],&lc[1],&lc[2],&lc[3],&lc[4],&lc[5]);
          
          
        }
      fclose(fp);
}


void compute_l3(int a,int b,int j) //starts by computing i{3,4,4} and then i{3,4,5} occurences in all lines of TF
{
   int i,k;
   int w,x,y,z; //dummy to hold the l3 file values
   int lc[20]={0x0},count1[5][5]={0x0};
   FILE *l3 =fopen("l3","w");
   if(l3==NULL) ferror(l3);
   
   for(i=0;i<5;i++){
    for(j=0;j<5;j++)
    {count1[i][j]=0;}   
   }
       
   
    for(i=1;i<=5;i++) //read  the line(s) of TF
    {
     inp_open(inp,i,lc);
     k=j; // reset so that when next line is read it dsnt hold the previous value (incremented) in for loop
       for(k=j;k<=5;k++) //read the jth value stored in lc i.e jth value of the current line
        {

            if(lc[a]!=0 && lc[b]!=0 && lc[k]!=0) //check if a,b values are non zero on current line *Necessary Condition*
                    {
                      count1[b][k]=count1[b][k]+1;
                      w=count1[b][k];
                      printf("Line:%d i{%d,%d,%d}\t",i,a,b,k);
                      printf("count[%d][%d] %d\n",b,k,count1[b][k]);
                      
                    }             
        }


    }
   
   return 0;
fclose(l3);
}