
#include <mysql.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	char consulta[80];
	
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn == NULL) {
		printf("Error al crear la conexión: %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	
	// Inicializar la conexión
	MYSQL *conexion = mysql_real_connect(conn, "localhost", "root", "mysql", "BBDD", 0, NULL, 0);
	if (conexion == NULL) {
		printf("Error al inicializar la conexión: %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	
	/* Obtener la cantidad total de puntos de un jugador especÃ­fico */
	SELECT REGISTRO.PUNTOS as 'Total Puntos' 
		FROM REGISTROS
		WHERE REGISTROS.ID_J = '1';
	// Definir la consulta SQL como una cadena de caracteres
	strcpy(consulta, "SELECT REGISTRO.PUNTOS as 'Total Puntos' FROM REGISTROS WHERE REGISTROS.ID_J = '1';");
	
	// Ejecutar la consulta SQL
	if (mysql_query(conexion, consulta)) {
		printf("Error en la consulta: %s\n", mysql_error(conexion));
		exit(1);
	}
	
	// Obtener el resultado de la consulta
	resultado = mysql_store_result(conexion);
	row = mysql_fetch_row(resultado);
	int total_puntos = atoi(row[0]);
	
	// cerrar la conexion con el servidor MYSQL 
	mysql_close(conexion);
	exit(0);
}


