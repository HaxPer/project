#include <mysql.h>
#include <iostream>


#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"mysqlclient.lib")
using namespace std;

MYSQL *connection, mysql;
MYSQL_RES *result;
MYSQL_ROW row;
int query;


// ������� ���������� ���������, ������� ����������� ��� �����������
const char *HOST = "localhost";
const char *USER = "root";
const char *PASSWORD = "warcraft4c";
const char *DB_NAME = "test"; 
const string ENCODING = "cp1251";

void main()
{
	// ������ ������� �������� ��������� (��������� cp1251,
	// ������� ��, ������, ������ ���� ������� ��� ��������� ��)
	setlocale(LC_ALL, ENCODING.c_str());

	/* ��������� �� ���������� (����������). �� ����� ��������� ����� ����������,
	� �� ����� ������ ���� ��������������� ����������� ���������� ��� ��������.*/
	MYSQL *link;

	// ������������� ������ �����������. ��� ��� ��������� �������.

	link = mysql_init(0);

	// ����������� � ��

	mysql_real_connect(link, HOST, USER, PASSWORD, DB_NAME, 0, 0, 0);

	MYSQL_RES *result = 0; // ��������� �� ��������� �������
	MYSQL_ROW row; // ����������, �� ������� ����� ������ ���������

	mysql_query(link, ("SET NAMES '" + ENCODING + "'").c_str()); // ������ ��������� ����������

	auto query = "";

	// ������ ������� ������ � ���� �������� mysql_query(���������_����������, ������)

	mysql_query(link, query);

	// ���������� ����������� �������

	result = mysql_store_result(link);

	// ���� � ��� ���� ����� ���� �� ���� ���������� ������...

	if (mysql_num_rows(result) > 0)
	{

		//"��������������" ��������� ������� � row (��� ������ �����, � ������� ������ ������� - ������������� ��������, � ��� �� ������ ����, ��� ��� �� �������� ������ 'Title')

		while (row = mysql_fetch_row(result))
		{
			//������� � ����� � ������� ������ ������ �� ���� �������� ����� (��� ������������, �.�. �� ������� ������ 'Title')
			cout << row[0] << endl;
		}
	}
	else
	{
		cout << "�� ������� �� ����� ������ ����� ������";
	}

	// ����� ������������� ���������� ����������� �������� ������� ����� ��������� ��������!

	mysql_free_result(result);

	// ��������� ����������

	mysql_close(link);

	system("pause");
}