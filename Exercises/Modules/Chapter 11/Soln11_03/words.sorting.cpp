module words.sorting;

/* Additional helpers for word::sort(Words&) */
void swap(words::Words& words, size_t first, size_t second)
{
  auto temp{ words[first] };
  words[first] = words[second];
  words[second] = temp;
}

void sort(words::Words& words, size_t start, size_t end);

// Sort strings in ascending sequence
void words::sorting::sort(Words& words)
{
  if (!words.empty())
    ::sort(words, 0, words.size() - 1);
}

void sort(words::Words& words, size_t start, size_t end)
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