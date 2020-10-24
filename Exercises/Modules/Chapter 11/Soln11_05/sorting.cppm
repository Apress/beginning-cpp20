// A module interface partition containing words::sort()
export module words:sorting;

import :alias;   // For the use of words::Words
import :internals;

export namespace words
{
  void sort(Words& words);
}

/* Recursive helper for word::sort(Words&) */
namespace words
{
  void sort(Words& words, size_t start, size_t end);
}

// Sort strings in ascending sequence
void words::sort(Words& words)
{
  if (!words.empty())
    sort(words, 0, words.size() - 1);
}

void words::sort(Words& words, size_t start, size_t end)
{
  // start index must be less than end index for 2 or more elements
  if (!(start < end))
    return;

  // Choose middle address to partition set
  swap(words, start, (start + end) / 2);     // Swap middle address with start

  // Check words against chosen word
  size_t current {start};
  for (size_t i {start + 1}; i <= end; i++)
  {
    if (*words[i] < *words[start])           // Is word less than chosen word?
      swap(words, ++current, i);             // Yes, so swap to the left
  }

  swap(words, start, current);               // Swap chosen and last swapped words

  if (current > start) sort(words, start, current - 1); // Sort left subset if exists
  if (end > current + 1) sort(words, current + 1, end); // Sort right subset if exists
}
