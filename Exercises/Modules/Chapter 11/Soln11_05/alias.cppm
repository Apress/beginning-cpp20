export module words:alias;

import <memory>;
import <string>;
import <vector>;

namespace words
{
  export using Words = std::vector<std::shared_ptr<std::string>>;
}