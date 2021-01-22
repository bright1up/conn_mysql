#include<iostream>
#include<string>
// #include<mysql-cppconn-8/jdbc/cppconn/driver.h>
// #include<mysql-cppconn-8/jdbc/cppconn/resultset.h>
// #include<mysql-cppconn-8/jdbc/cppconn/statement.h>
// #include<mysql-cppconn-8/jdbc/cppconn/exception.h>
// #include<mysql/mysql.h>
// #include<mysql-cppconn-8/mysqlx/xdevapi.h>
#include<cppconn/driver.h>
#include<cppconn/resultset.h>
#include<cppconn/statement.h>
#include<cppconn/exception.h>
#include<mysql/mysql.h>
// #include<mysql_driver.h>
//#include "jdbc\mysql_connection.h"
//
//#include"jdbc\cppconn\driver.h"
//#include"jdbc\cppconn\exception.h"
//#include"jdbc\cppconn\resultset.h"
//#include"jdbc\cppconn\statement.h"



int main() {
	//浏览表lib_test中的lib_table
	std::string title = "浏览表lib_test中的lib_table";
	std::cout << title << std::endl;
	try {
		sql::Driver *driver = nullptr;
		// sql::mysql::MySQL_Driver *driver=nullptr;
		sql::Connection *conn = nullptr;
		sql::Statement *stmt = nullptr;
		sql::ResultSet *res = nullptr;

		std::string hostname = "tcp://127.0.0.1:3306";
		std::string username = "root";
		std::string password = "passwd";

		//创建连接
		driver = get_driver_instance();
		try{
			conn = driver->connect(hostname, username, password);
			conn->setSchema("test_db");

			stmt = conn->createStatement();
			std::string sql = "select * from test_table";
			res = stmt->executeQuery(sql);
			while (res->next()){
				std::cout << res->getString(1) << "\t" << res->getString(2) << std::endl;
			}
			delete res;
			delete stmt;
			delete conn;
		}
		catch (std::bad_alloc &e) {
			std::cout << e.what() << std::endl;
		}
	}
	catch (sql::SQLException &e) {
		std::cout << e.what() << std::endl;
		//std::cout << e.getErrorCode() << std::endl;
		//std::cout << e.getSQLState() << std::endl;
		//std::cout << e.getSQLStateCStr() << std::endl;
	}
	return 0;

}
