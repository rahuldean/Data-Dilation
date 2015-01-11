import java.io.*;
import java.sql.*;

class Star{
public static void main(String[] args){
try{
Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
Connection con = DriverManager.getConnection("jdbc:odbc:test1");

Statement st = con.createStatement();
Statement st1 =con.createStatement();
ResultSet rs = st.executeQuery("select * from salesfact s,item i where s.item_key=i.item_key");
int cost=0,units=0,total=0;
String item_key;
while(rs.next()){
item_key = rs.getString("item_key");
System.out.println("itemkey: "+item_key);

cost = Integer.parseInt(rs.getString("cost"));
System.out.println("Cost "+cost);

units = Integer.parseInt(rs.getString("units_sold"));
System.out.println("units: "+units);

total = cost*units;
System.out.println("Total "+total);
st1.executeUpdate("update salesfact set total= "+total+" where  item_key= '"+item_key+"'");

}//while
con.close();
}
catch(Exception e1)
{
System.out.println(e1);
}
}//main
}//class