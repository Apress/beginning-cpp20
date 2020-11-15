// RAII classes for handles returned by DB.h C interface functions

/*
  In this solution we have the RAII classes accept the resource handle in their constructor.
  Alternatively, you could also acquire the resources inside the constructors of the RAII class.
  For instance: you could call db_connect() from within the DBConnectionRAII() contructor.

  When creating RAII classes, it is typically crucial they cannot be copied
  (otherwise multiple objects would be releasing the same resource, 
   which is typically not allowed). To accomplish this, you delete both copy members.
*/

#ifndef DB_RAII_H
#define DB_RAII_H

#include "DB.h"

/**
 * RAII object that ensures that a given database connection is closed
 * once the RAII object goes out of scope.
 */ 
class DBConnectionRAII
{
public:
  DBConnectionRAII(DB_CONNECTION* connection) noexcept
    : m_connection(connection)
  {
  }  
  ~DBConnectionRAII() // implicitly noexcept
  {
    if (m_connection)
    {
      db_disconnect(m_connection);
    }
  }

  // Prevent copying by deleting both copy members
  DBConnectionRAII(const DBConnectionRAII& other) = delete;
  DBConnectionRAII& operator=(const DBConnectionRAII& other) = delete;

  // Implicit type conversion to the underlying resource handle.
  // Note: many RAII types will use a get() function instead 
  // (unique_ptr / shared_ptr, for instance, do this)
  operator DB_CONNECTION*() const noexcept { return m_connection; }
  
private:
  DB_CONNECTION* m_connection;
};

/* RAII object that takes a DB_QUERY_RESULT and ensures it is freed */
class DBQueryResultRAII
{
public:
  DBQueryResultRAII(DB_QUERY_RESULT* result) noexcept 
    : m_result(result)
  {
  }
  
  ~DBQueryResultRAII() // implicitly noexcept
  {
    if (m_result)
    {
      db_free_result(m_result);
    }
  }

  // Prevent copying by deleting both copy members
  DBQueryResultRAII(const DBQueryResultRAII& other) = delete;
  DBQueryResultRAII& operator=(const DBQueryResultRAII& other) = delete;

  // Implicit type conversion to the underlying resource handle.
  // Note: many RAII types will use a get() function instead 
  // (unique_ptr / shared_ptr, for instance, do this)
  operator DB_QUERY_RESULT* () const noexcept { return m_result; }

private:
  DB_QUERY_RESULT* m_result;
};

#endif