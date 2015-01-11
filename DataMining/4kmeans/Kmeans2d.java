import java.io.*;
import java.util.*;
class Kmeans2d{
public static void main(String[] args){
Random rm = new Random();
int a[][] = new int[10][2];

int cnt1=0,cnt2=0,cnt3=0;
int cluster1[][] = new int[10][2];
int cluster2[][] = new int[10][2];
int cluster3[][] = new int[10][2];

//Fill input array
for(int i=0;i<8;i++)
for(int j=0;j<2;j++)
a[i][j] = 1+rm.nextInt(15);

//show input array
for(int i=0;i<8;i++){
for(int j=0;j<2;j++)
System.out.print(a[i][j]+"  ");
System.out.println();
}
float mean1[][] = new float[10][2];
float mean2[][] = new float[10][2];
float mean3[][] = new float[10][2];

//set initial centers
for(int i=0;i<2;i++)
{
mean1[0][i] = a[0][i]; 
mean2[0][i] = a[1][i];
mean3[0][i] = a[2][i];
}
String str1;
int sum10=0,sum11=0,sum20=0,sum21=0,sum30=0,sum31=0;
for(int iter=1;iter<5;iter++){
float k1=0,k2=0,k3=0;

for(int i=0;i<8;i++){
k1 = ((mean1[0][0]-a[i][0]) * (mean1[0][0]-a[i][0])) + ((mean1[0][1]-a[i][1])*(mean1[0][1]-a[i][1]));
k2 = ((mean2[0][0]-a[i][0]) * (mean2[0][0]-a[i][0])) + ((mean2[0][1]-a[i][1])*(mean2[0][1]-a[i][1]));
k3 = ((mean3[0][0]-a[i][0]) * (mean3[0][0]-a[i][0])) + ((mean3[0][1]-a[i][1])*(mean3[0][1]-a[i][1]));

if (k1<k2){
if(k1<k3) str1 ="c1";
else str1 ="c3";
}//if

else{
if(k2<k3) str1="c2";
else str1="c3";
}//else

if(str1 == "c1"){
for(int j=0;j<2;j++){
cluster1[cnt1][j] = a[i][j];
}//for c1
++cnt1;
}

if(str1 == "c2"){
for(int j=0;j<2;j++){
cluster2[cnt2][j] = a[i][j];
}//for c2
++cnt2;
}

if(str1 == "c3"){
for(int j=0;j<2;j++){
cluster3[cnt3][j] = a[i][j];
}//for c3
++cnt3;
}

}//for inner

//calculate mean for each cluster and keep this mean as next center
sum10=0;sum11=0;sum20=0;sum21=0;sum30=0;sum31=0;
for(int i=0;i<cnt1;i++)
{
sum10 += cluster1[i][0];
sum11 += cluster1[i][0];
}
mean1[0][0] = (float) sum10/cnt1;
mean1[0][1] = (float) sum11/cnt1;

for(int i=0;i<cnt2;i++)
{
sum20 += cluster2[i][0];
sum21 += cluster2[i][0];
}
mean2[0][0] = (float) sum20/cnt2;
mean2[0][1] = (float) sum21/cnt2;

for(int i=0;i<cnt3;i++)
{
sum30 += cluster3[i][0];
sum31 += cluster3[i][0];
}
mean3[0][0] = (float) sum30/cnt3;
mean3[0][1] = (float) sum31/cnt3;

System.out.println("----Iteration: "+iter+" ----");
System.out.println("Cluster1");
for(int i=0;i<cnt1;i++)
System.out.println("["+cluster1[i][0]+", "+cluster1[i][1]+"]");
System.out.println("Mean: "+mean1[0][0]+","+mean1[0][1]);

System.out.println("Cluster2");
for(int i=0;i<cnt2;i++)
System.out.println("["+cluster2[i][0]+", "+cluster2[i][1]+"]");
System.out.println("Mean: "+mean2[0][0]+","+mean2[0][1]);

System.out.println("Cluster3");
for(int i=0;i<cnt3;i++)
System.out.println("["+cluster3[i][0]+", "+cluster3[i][1]+"]");
System.out.println("Mean: "+mean3[0][0]+","+mean3[0][1]);

System.out.println("--------\n");

cnt1=0;cnt2=0;cnt3=0;

}//for iter
}//main
}//class