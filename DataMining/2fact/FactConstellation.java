import java.sql.*;
import java.io.*;
import java.util.*;

class FactConstellation
{
	public static void main(String args[]) throws Exception
	{
		try
		{
               
			  Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			
				String conStr ="jdbc:odbc:test1";          
				Connection con = DriverManager.getConnection(conStr);    
			   			
			    Statement s=con.createStatement();
				
ResultSet rs=s.executeQuery("select item_name,sum(dollars_sold) as TotalDollars,sum(units_sold) as TotalUnits from sales_fact s,ship_fact sh,item i,shipper where s.item_key=i.item_key and sh.item_key=i.item_key group by item_name" );
				String itemname;
				int tunits=0;
				double sum=0;
			while(rs.next())
			{
itemname = rs.getString("item_name");
sum = rs.getInt(2);
tunits = rs.getInt(3);

System.out.println(itemname+"  "+sum+"  "+tunits);

			}

			
		  
		}
catch(Exception e)
		{
	System.out.println(e);
	}
				
}
}