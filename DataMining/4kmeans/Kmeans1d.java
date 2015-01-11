import java.io.*;
class Kmeans1d{
public static void main(String args[]){
int input[] ={3,4,6,9,2,1,5,7,10,22};
int cluster1[]=new int[10];
int cluster2[]=new int[10];
int cluster3[]=new int[10];
int cnt1=0,cnt2=0,cnt3=0;
int sum1=0,sum2=0,sum3=0;
float mean1=input[0],mean2=input[1],mean3=input[2];
String str1=null,str2=null;
float k1=0,k2=0,k3=0;
for(int iter=1;iter<=5;iter++)
{
for(int i=0;i<10;i++){
k1 = Math.abs(mean1-input[i]);
k2 = Math.abs(mean2-input[i]);
k3 = Math.abs(mean3-input[i]);

if(k1<k2){
if(k1<k3)
{str1 ="c1";}
else
str1 ="c3";
}//if
else{
if(k2<k3)
str1 = "c2";
else
str1 = "c3";
}//else

if(str1 == "c1")
{cluster1[cnt1]=input[i];++cnt1;}

if(str1 == "c2")
{cluster2[cnt2]=input[i];++cnt2;}

if(str1 == "c3")
{cluster3[cnt3]=input[i];++cnt3;}
}//for inner


//calculate means and change center to this mean
for(int i=0;i<cnt1;i++)
{sum1+=cluster1[i];}
mean1= (float)sum1/cnt1;

for(int i=0;i<cnt2;i++)
sum2 +=cluster2[i];
mean2=(float)sum2/cnt2;

for(int i=0;i<cnt3;i++)
sum3+=cluster3[i];
mean3=(float)sum3/cnt3;

System.out.println("----Iteration "+iter+" ----");
for(int j=0;j<cnt1;j++)
System.out.print(cluster1[j]+"  ");
System.out.println("\nMean:"+mean1);

for(int j=0;j<cnt2;j++)
System.out.print(cluster2[j]+"  ");
System.out.println("\nMean:"+mean2);

for(int j=0;j<cnt3;j++)
System.out.print(cluster3[j]+"  ");
System.out.println("\nMean:"+mean3);
System.out.println("----------------");

cnt1=0;cnt2=0;cnt3=0;
sum1=0;sum2=0;sum3=0;

}//iterator for
}//main
}//class