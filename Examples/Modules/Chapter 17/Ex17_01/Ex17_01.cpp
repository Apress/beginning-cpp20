// Using a class template
import box;
import array;
import <iostream>;
import <format>;

int main()
{
  try
  {
    const size_t numValues {20};
    Array<double> values {numValues};

    for (unsigned i {}; i < numValues; ++i)
      values[i] = i + 1;

    std::cout << "Sums of pairs of elements:";
    size_t lines {};
    for (size_t i {numValues - 1}; i >= 0; --i)
    {
      std::cout << (lines++ % 5 == 0 ? "\n" : "")
                << std::format("{:5g}", values[i] + values[i-1]);
    }
  }
  catch (const std::out_of_range& ex)
  {
    std::cerr << "\nout_of_range exception object caught! " << ex.what() << std::endl;
  }

  try
  {
    const size_t numBoxes {5};
    Array<Box> boxes {numBoxes};
    for (size_t i {} ; i <= numBoxes ; ++i)
      std::cout << "Box volume is " << boxes[i].volume() << std::endl;
  }
  catch (const std::out_of_range& ex)
  {
    std::cerr << "\nout_of_range exception object caught! " << ex.what() << std::endl;
  }
}
