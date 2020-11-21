// A mocked database

#include "DB.h"
#include <cstring>    // For std::strcmp()
import <memory>;
import <vector>;

namespace
{
  struct QueryResult
  {
    std::vector<std::vector<const char*>> data;
    size_t index {};
  };

  class Database
  {
  public:
    Database() = default;
    
    bool hasConnection() const { return m_connected; }
    void connect() { m_connected = true; }
    void disconnect() { m_connected = false; }
    
    QueryResult* query(const char* query);
    
  private:  
    bool m_connected{};
  };
}

DB_CONNECTION* db_connect()
{
  // We only have one single database, which allows only one single connection:
  static Database theDatabase;
  if (theDatabase.hasConnection())
  {
    return nullptr;
  }
  else
  {
    theDatabase.connect();
    return &theDatabase;
  }
}

void db_disconnect(DB_CONNECTION* connection)
{
  // reinterpret_cast<> is used to cast between pointers/references of 
  // unrelated types (such as void* and Database*)
  reinterpret_cast<Database*>(connection)->disconnect();
}

DB_QUERY_RESULT* db_query(DB_CONNECTION* connection, const char* query)
{
  return reinterpret_cast<Database*>(connection)->query(query);
}

QueryResult* Database::query(const char* query)
{
  if (!hasConnection())
  {
    return nullptr;
  }
  
  // Our database only understands one single query!
  if (std::strcmp(query, "SELECT * FROM CUSTOMER_TABEL") != 0)
  {
    return nullptr;
  }
  
  auto result{ std::make_unique<QueryResult>() };
  result->data = std::vector<std::vector<const char*>>{
    { "Sherlock", "Holmes", "Baker Street", "221", "London" },
    { "Joe", "Biden", "Pennsylvania Avenue", "1600", "Washington DC" },
    { "Donald", "Duck", "Webfoot Walk", "1313", "Duckville" },
    { "Sirius", "Black", "Grimmauld Place", "12", "London" },
    { "Nemo", "Clownfish", "Wallaby Way", "42", "Sydney" },
    { "Sam", "Malone", "Beacon Street", "112", "Boston" }
  };
  return result.release();
}

int db_num_fields(DB_QUERY_RESULT* result)
{
  auto* theResult{ reinterpret_cast<QueryResult*>(result) };
  if (!theResult || theResult->data.empty())
  {
    return -1;
  }
  else
  {
    return static_cast<int>(theResult->data.front().size());
  }
}

DB_ROW db_fetch_row(DB_QUERY_RESULT* result)
{
  auto* theResult{ reinterpret_cast<QueryResult*>(result) };
  if (!theResult || theResult->index >= theResult->data.size())
  {
    return nullptr;
  }
  else
  {
     return theResult->data[theResult->index++].data();
  }
}

void db_free_result(DB_QUERY_RESULT* result)
{
  delete reinterpret_cast<QueryResult*>(result);
}
