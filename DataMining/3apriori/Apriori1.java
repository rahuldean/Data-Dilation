import java.io.*;
import java.sql.*;
class  Apriori1
{
	public static void main(String[] args) 
	{
try
{
Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
Connection con = DriverManager.getConnection("jdbc:odbc:test1");

Statement st_t,st_l1,st_l2,st_l3,st_del;
ResultSet rs_t,rs_l1,rs_l2,rs_l3;

st_t = con.createStatement();
st_l1 = con.createStatement();
st_l2 = con.createStatement();
st_l3 = con.createStatement();
st_del = con.createStatement();

st_del.executeUpdate("delete * from l1");
st_del.executeUpdate("delete * from l2");
st_del.executeUpdate("delete * from l3");

for (int i=1;i<=5 ;i++ )
{
int count1=0,val=0;
rs_t = st_t.executeQuery("select * from trans");

while (rs_t.next())
{
	val = Integer.parseInt(rs_t.getString(""+i+""));
	if (val == 1)
	{
		++count1;
	}

}//while

//write to l1 file
st_l1.executeUpdate("insert into l1(item,support) values('"+i+"','"+count1+"')");


}//for
//----L1 done----

//Construct l2

rs_l1 = st_l1.executeQuery("select * from l1");
int a[] = new int[20];
int i=0;
while (rs_l1.next())
{
a[i]= Integer.parseInt(rs_l1.getString("item"));
++i;
}//while
int len =i;
int fst,snd,val1=0,val2=0;
for (i=0;i<len ;i++ )
for (int j=i+1;j<len ;j++ )
{
fst = a[i];
snd=a[j];
int count2=0;
rs_t = st_t.executeQuery("select * from trans");
while (rs_t.next())
{

val1 = Integer.parseInt(rs_t.getString(""+fst+""));
val2 = Integer.parseInt(rs_t.getString(""+snd+""));

if (val1 == 1 && val2 == 1)
{
	++count2;
}//if
}//while
//write to l2
if (count2 >=2)
{
	st_l2.executeUpdate("insert into l2(item1,item2,support) values('"+fst+"','"+snd+"','"+count2+"')");
}
}//for inner

//create to l3

rs_l2 = st_l2.executeQuery("select item1,item2 from l2");
int b[][] = new int [10][2];
int p=0;
while (rs_l2.next())
{
b[p][0] = Integer.parseInt(rs_l2.getString("item1"));
b[p][1] = Integer.parseInt(rs_l2.getString("item2"));
++p;
}//while

len = p;
int val3=0;
for (int m=0;m<len ;m++)
	for (int n=m+1;n<len ;n++ )
	{

if (b[m][0] == b[n][0])
{
rs_t = st_t.executeQuery("select * from trans");
int count3=0;
while (rs_t.next())
{
val1 = Integer.parseInt(rs_t.getString(""+b[m][0]+""));
val2 = Integer.parseInt(rs_t.getString(""+b[m][1]+""));
val3 = Integer.parseInt(rs_t.getString(""+b[n][1]+""));

if (val1 == 1 && val2 == 1 && val3 ==1)
{
++count3;
}//if
}//while

if (count3>=0)
{
	st_l3.executeUpdate("insert into l3(item1,item2,item3,support) values('"+val1+"','"+val2+"','"+val3+"','"+count3+"')");
}

}//if

	}//for outer



con.close();	
}//try
catch (Exception e1)
{
	System.out.println(e1);
}

	}//main
}//class
