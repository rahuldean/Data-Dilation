import java.io.*;
class Kmedoids 
{
	static int input[] = {3,4,6,9,2,1,5,7,10,22};
	public static void main(String[] args) throws Exception
	{

int c1[] = new int[3]; //centers
int c2[] = new int[3];

int cluster1[] = new int[10];
int cluster2[] = new int[10];
int cluster3[] = new int[10];
int n;
int count1=0,count2=0,count3=0,total1=0;
int total2=0;
int k1,k2,k3;
String str1,str2;

BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
System.out.println("Enter 3 Centers For Iter1");
for(int i=0;i<3;i++)
	c1[i]=Integer.parseInt(br.readLine());

System.out.println("Enter 3 Centers For Iter2");
for(int i=0;i<3;i++)
	c2[i]=Integer.parseInt(br.readLine());
int inc1=0,inc2=0,inc3=0;

for (int i=0;i<10 ;i++ )
{
k1 = Math.abs(c1[0]-input[i]);
k2 = Math.abs(c1[1]-input[i]);
k3 = Math.abs(c1[2]-input[i]);

if (k1<k2)
{
	if (k1<k3)
		{str1 = "c1";	cluster1[inc1] = input[i];++inc1;}
	else 
		{str1="c3";	cluster3[inc3] = input[i];++inc3;}

}
else
	{
		if (k2<k3)
			{str1 ="c2";	cluster2[inc2] = input[i];++inc2;}
		else
			{str1 = "c3";	cluster3[inc3] = input[i];++inc3;}
	}//else

if(str1 == "c1")
	count1+=k1;
if(str1 == "c2")
	count2+= k2;
if(str1 == "c3")
	count3+= k3;
	
}//for
total1 = count1+count2 +count3;

//Display cluster after 1st iter
System.out.println("Clusters 1,2,3 are: After Iter1:");
for (int i=0;i<inc1;i++)
System.out.print(cluster1[i]+"\t");
System.out.println("");
for (int i=0;i<inc2;i++)
System.out.print(cluster2[i]+"\t");
System.out.println("");
for (int i=0;i<inc3;i++)
System.out.print(cluster3[i]+"\t");


//Displayed!!!!

count1 =0;count2=0;count3=0;
inc1=0;inc2=0;inc3=0;
cluster1 = new int[10];
cluster2 = new int[10];
cluster3 = new int[10];
for (int i =0;i<10 ;i++ )
{
k1 = Math.abs(c2[0]-input[i]);
k2 = Math.abs(c2[1]-input[i]);
k3 = Math.abs(c2[2]-input[i]);

if (k1<k2)
{
	if(k1<k3)
		{str2 = "c1";cluster1[inc1] = input[i];++inc1;}
	else
		{str2="c3";cluster3[inc3] = input[i];++inc3;}
}
else
{
	if(k2<k3)
		{str2 = "c2";cluster2[inc2] = input[i];++inc2;}
	else
		{str2 = "c3";cluster3[inc3] = input[i];++inc3;}
}

if(str2 == "c1")
	count1 += k1;
if(str2 == "c2")
	count2+=k2;
if(str2 == "c3")
	count3 +=k2;
	
}//for
total2 = count1 + count2 +count3 ;

System.out.println("");

System.out.println("Clusters 1,2,3 After iter 2 are:");
for (int i=0;i<inc1;i++)
System.out.print(cluster1[i]+"\t");
System.out.println("");
for (int i=0;i<inc2;i++)
System.out.print(cluster2[i]+"\t");
System.out.println("");
for (int i=0;i<inc3;i++)
System.out.print(cluster3[i]+"\t");
System.out.println("");

//summary
System.out.println("Cluster1 Cost: "+total1);
System.out.println("Cluster2 Cost: "+total2);

if(total1<total2)
	System.out.println("Cluster1 has minimum cost");
if(total1 == total2)
	System.out.println("Botha have same cost");
if (total2<total1)
	System.out.println("Cluster2 has minimum cost");

	}//main
}//class
