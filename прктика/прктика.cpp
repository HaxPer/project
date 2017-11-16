#include <mysql.h>
#include <iostream>


#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"mysqlclient.lib")
using namespace std;

MYSQL *connection, mysql;
MYSQL_RES *result;
MYSQL_ROW row;
int query;


// Зададим глобальные константы, которые понадобятся при подключении
const char *HOST = "localhost";
const char *USER = "root";
const char *PASSWORD = "warcraft4c";
const char *DB_NAME = "test"; 
const string ENCODING = "cp1251";

void main()
{
	// Научим консоль понимать кириллицу (кодировка cp1251,
	// которую мы, кстати, должны были указать при установки БД)
	setlocale(LC_ALL, ENCODING.c_str());

	/* Указатель на соединение (дескриптор). Мы можем открывать много соединений,
	а он будет своего рода идентификатором конкретного соединения для операции.*/
	MYSQL *link;

	// Инициализация нового подключения. Учи как китайскую грамоту.

	link = mysql_init(0);

	// Подключение к БД

	mysql_real_connect(link, HOST, USER, PASSWORD, DB_NAME, 0, 0, 0);

	MYSQL_RES *result = 0; // Указатель на результат запроса
	MYSQL_ROW row; // Переменная, из которой будем читать результат

	mysql_query(link, ("SET NAMES '" + ENCODING + "'").c_str()); // Задаем кодировку соединения

	auto query = "";

	// Теперь сделаем запрос к базе функцией mysql_query(указатель_соединения, запрос)

	mysql_query(link, query);

	// Извлечение результатов запроса

	result = mysql_store_result(link);

	// Если у нас база нашла хотя бы одну подходящую запись...

	if (mysql_num_rows(result) > 0)
	{

		//"Расшифровываем" результат запроса в row (это массив строк, в которых каждый элемент - запрашиваемый параметр, у нас он только один, так как мы выбирали только 'Title')

		while (row = mysql_fetch_row(result))
		{
			//Выведем в цикле в консоль первую запись из всех найденых строк (она единственная, т.к. мы выбрали только 'Title')
			cout << row[0] << endl;
		}
	}
	else
	{
		cout << "Не найдено ни одной статьи этого автора";
	}

	// После использования результата обязательно освободи ресурсы перед следующим запросом!

	mysql_free_result(result);

	// Закрываем соединение

	mysql_close(link);

	system("pause");
}