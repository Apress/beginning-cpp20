// A C-style interface to a mock database
// (a simplified subset of the MySQL C interface)

#ifndef DB_INCLUDES
#define DB_INCLUDES

using DB_CONNECTION = void;
using DB_QUERY_RESULT = void;
using DB_ROW = const char**;

/*! Make a connection to the database
 * Do not forget to close the database connection (db_disconnect()) once done with it.
 * \return a DB_CONNECTION handle; nullptr upon failure
 */
DB_CONNECTION* db_connect();

/*! Query the database
 * \param[in] connection A database connection handle returned by db_connect()
 * \param[in] query      A SQL query
 * \return A handle to the result of the query (memory to be freed using db_free_result()!)
 */
DB_QUERY_RESULT* db_query(DB_CONNECTION* connection, const char* query);

/*! Retrieve the number of fields per row stored by the given query result
 * \param[in] result A handle returned by db_query 
 * \return The number of fields per row stored by the result; -1 upon failure
 */
int db_num_fields(DB_QUERY_RESULT* result);

/*! Fetch a single row from the result.
 * \param[in] result A handle returned by db_query
 * \return An array of strings. Each field is represented as a string (zero-terminated char array). 
 *    Let row be the result, then the first field is accessed using result[0]. 
 */
DB_ROW db_fetch_row(DB_QUERY_RESULT* result);

/*! Release the memory allocated for the result.
 * \param[in] result A handle returned by db_query()
 */
void db_free_result(DB_QUERY_RESULT* result);

/*! Disconnect from the database
 * \param[in] connection   A connection handle returned by db_connect()
 */
void db_disconnect(DB_CONNECTION* connection);

#endif