//creat a new database named rooll6
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<mysql.h>
using namespace std;
 int main()
 {
	 const char user[] ="root";	
	 const char pswd[] ="1234";
	 const char host[] ="localhost";
	 const char table[] = "roll6";
	 unsigned int port = 3306;
	 MYSQL myCont,*sock;
	 mysql_init(&myCont);
	 if(sock=mysql_real_connect(&myCont,host,user,pswd,NULL,3306,NULL,0)){
			 char CreateDbCmd[]="CREATE DATEBASE IF NOT EXISTS `roll6`";
			 mysql_query(sock,CreateDbCmd);
			 mysql_query(sock,"use roll6");
			char CreateTableCmd[] = "CREATE TABLE IF NOT EXISTS `featureResult_45d` ("
							"`id` INT(11) NOT NULL AUTO_INCREMENT,"
							"`f1` float  NULL DEFAULT NULL,"
							"`f2` float  NULL DEFAULT NULL,"
							"`f3` float  NULL DEFAULT NULL,"
							"`f4` float  NULL DEFAULT NULL,"
							"`f5` float  NULL DEFAULT NULL,"
							"`degree` int(11) NULL  DEFAULT '0',"
							"PRIMARY KEY (`id`))"
							"ENGINE = InnoDB "
							"DEFAULT CHARACTER SET = utf8 "
							"COLLATE = utf8_general_ci;" 
							;
		if(mysql_query(sock , CreateTableCmd))
		{
			cout<<mysql_error(sock);
		}
		else cout<<"ok";
		mysql_close(sock);}
	system("pause");
	return 0;
 }
