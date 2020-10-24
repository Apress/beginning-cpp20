export module words;

import <memory>;
import <string>;
import <vector>;

export namespace words
{
  using Words = std::vector<std::shared_ptr<std::string>>;

  void sort(Words& words);
  void extract_words(Words& words, const std::string& text, const std::string& separators);
  void show_words(const Words& words);
}

export namespace w = words;

/* This does not work:

  namespace wrds
  {
    // A using directive is not a declaration, 
    // and can therefore not be exported from a module.
    // Namespace aliases are therefore preferred over 
    // using directives inside a namespace...
    export using namespace words;
  }
*/
