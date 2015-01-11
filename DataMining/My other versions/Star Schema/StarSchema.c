/* 
 * File:   StarSchema.c
 * Author: Rahul
 *
 * Created on January 26, 2012, 11:45 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
    
    struct item_dim{
        int i_id; //this is prime key
        int stock;
        int ppi; //price per item
        
    }i[4];
    
    struct customer_dim{
        int c_id; //primary
        int quant; //quant purchase
        int price;
        
    }c[4];
    
    struct location_dim{
        int l_id; //primary
        char l_name[20];
        
        
    }l[4];
    
    struct time_dim{
        int t_id; //primary
        char time[20];
        
    }t[4];
    
    struct salesfact{
        int i_id;
        int c_id;
        int l_id;
        int t_id;
        int total_sales;
        
    }sf[4];
    
    //prototypes
    void display();
    void insert(char *tname);
int co=-1;    
int main(int argc, char** argv) {
    
    int ch=-1;
    char tname[20];
    

    printf("Menu: Enter Choice To Enter Table Data\n");
    printf("1.Item Dimension\n");
    printf("2.Customer Dimension\n");
    printf("3.Location Dimension\n");
    printf("4.Time Dimension\n");
    printf("5.Sales Fact Dimension\n");
    printf("6.Display All Tables and Average Sales");
    
    
    do{
        printf("Choice : ");
        scanf("%d",&ch);
    switch (ch)
    {
        case 1: sprintf(tname,"item");insert(tname);
            break;
        
        case 2: sprintf(tname,"customer");insert(tname);
            break;
            
        case 3: sprintf(tname,"location");insert(tname);
            break;
            
        case 4: sprintf(tname,"time");insert(tname);
            break;
            
        case 5:sprintf(tname,"salesfact");insert(tname);
            break;
            
        case 6:display();
            break;
            
        default: printf("Wrong choice:");
        break;
                    
    }
    }while(co==0);
    
            
            

    
    return (EXIT_SUCCESS);
}

void insert(char *tname){
    int j=0,k=0,id=0;
    int total_sales;
    char l_name[20],time[20];
    printf("Enter %s Table Entries\n",tname);
    
    if (!strcmp(tname,"item")){
        for(j=0;j<3;j++)
        {   printf("ID%d (Primary) ",j); scanf("%d",&i[j].i_id);
            for(k=0;k<j;k++)
            {
            if(i[j].i_id ==i[k].i_id)
              {
                printf("No Duplicates/Null Allowed"); j--;
                break;
              }
            
            }
        printf("Stock%d: ",j); scanf("%d",&i[j].stock);
        printf("PPI%d: ",j); scanf("%d",&i[j].ppi);
        }
        
        
    }
    
    if(!strcmp(tname,"customer")){
        for(j=0;j<3;j++)
        {   printf("ID%d (Primary) ",j); scanf("%d",&c[j].c_id);
            for(k=0;k<j;k++)
            {
            if(c[j].c_id ==c[k].c_id)
              {
                printf("No Duplicates/Null Allowed"); j--;
                break;
              }
            
            }
        printf("Quant%d: ",j); scanf("%d",&c[j].quant);
        printf("Price%d: ",j); c[j].price =c[j].quant * i[j].ppi; printf("%d\n",c[j].price);
        }        
        
        
    }
    if(!strcmp(tname,"location")){
         
        for(j=0;j<3;j++)
        {   printf("ID%d (Primary) ",j); scanf("%d",&l[j].l_id);
            for(k=0;k<j;k++)
            {
            if(l[j].l_id ==l[k].l_id)
              {
                printf("No Duplicates/Null Allowed"); j--;
                break;
              }
            
            }
        printf("Location Name%d: ",j); scanf("%s",l_name);
        sprintf(l[j].l_name,"%s",l_name);
        
        }       
        
        
    }
    
    //TIME TABLE
    if(!strcmp(tname,"time")){
        for(j=0;j<3;j++)
        {   printf("ID%d (Primary) ",j); scanf("%d",&t[j].t_id);
            for(k=0;k<j;k++)
            {
            if(t[j].t_id ==t[k].t_id)
              {
                printf("No Duplicates/Null Allowed"); j--;
                break;
              }
            
            }
        printf("Date%d: ",j); scanf("%s",time);
        sprintf(t[j].time,"%s",time);
        
        }           
        
    }
    //SALES FACT TABLE
    if(!strcmp(tname,"salesfact")){
     for(j=0;j<3;j++)
        { 
         //item
         printf("Item ID%d ",j); scanf("%d",&sf[j].i_id);
            for(k=0;k<j;k++)
            {
            if(sf[j].i_id ==i[k].i_id)
              {
                printf("Item Id Must Match With Item Table"); j--;
                break;
              }
            
            }
        
        //customer
        printf("Customer ID%d ",j); scanf("%d",&sf[j].c_id);
            for(k=0;k<j;k++)
            {
            if(sf[j].c_id ==c[k].c_id)
              {
                printf("Customer Id Must Match With Customer Table"); j--;
                break;
              }
            
            }
        //location
        printf("Location ID%d ",j); scanf("%d",&sf[j].l_id);
            for(k=0;k<j;k++)
            {
            if(sf[j].l_id ==l[k].l_id)
              {
                printf("Location Id Must Match With Location Table"); j--;
                break;
              }
            
            }
        
        //time
        printf("Time ID%d ",j); scanf("%d",&sf[j].t_id);
            for(k=0;k<j;k++)
            {
            if(sf[j].t_id ==t[k].t_id)
              {
                printf("Time Id Must Match With Time Table"); j--;
                break;
              }
            
            }
        //total sales
        
         sf[j].total_sales=c[j].quant * i[j].ppi; printf("Sales%d %d\n",j,sf[j].total_sales);
        
        }
   
    }
    //Sales Fact Table End
    printf("Continue? enter 0: ");
    scanf("%d",&co);
}

void display(){
    int j,sum=0,avg=0;
    printf("Item Table:\n");
    printf("ID\tStock\tPPI\n");
    for(j=0;j<3;j++)
    {
        
        printf("%d\t%d\t%d\n",i[j].i_id,i[j].stock,i[j].ppi);
    }
    
    
    printf("Customer Table:\n");
    printf("ID\tQuant\tPrice\n");
    for(j=0;j<3;j++)
    {
        
        printf("%d\t%d\t%d\n",c[j].c_id,c[j].quant,c[j].price);
    }
    
    printf("Location Table:\n");
    printf("ID\tLocation Name\n");
    for(j=0;j<3;j++)
    {
        
        printf("%d\t%s\n",l[j].l_id,l[j].l_name);
    }
    
    printf("Time Table:\n");
    printf("ID\tTime\n");
    for(j=0;j<3;j++)
    {
        
        printf("%d\t%s\n",t[j].t_id,t[j].time);
    }
    
    printf("Sales Fact Table:\n");
    printf("I_ID\tC_ID\tL_ID\tT_ID\tTotal Sales\n");
    for(j=0;j<3;j++)
    {
        
        printf("%d\t%d\t%d\t%d\t%d\n",sf[j].i_id,sf[j].c_id,sf[j].l_id,sf[j].t_id,sf[j].total_sales);
        sum+=sf[j].total_sales;
    }
    
    printf("\n Average Sales = %d",sum/3);
    
    
    printf("Continue? enter 0: ");
    scanf("%d",&co);
}

