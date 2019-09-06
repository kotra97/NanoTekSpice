#include "chipsets_p.hpp"

C4514::C4514()
{
  for (unsigned i = 0; i != 24; ++i)
  {
    _pins[i] = {NULL, -1, nts::UNDEFINED};
  }
}

C4514::~C4514() x{}

nts::Tristate C4514::compute(size_t num)
{
  if (num < 4 || num > 20)
  {
    std::cerr << "An output can't be linked" << std::endl;
    throw;
  }
}