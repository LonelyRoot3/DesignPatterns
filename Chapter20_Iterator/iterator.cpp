#include "iterator.h"

std::string& ConcreteAggregate::operator[](std::size_t i) { return items[i]; }
std::string ConcreteIterator::First() { return (*aggregate_)[0]; }
std::string ConcreteIterator::Next() {
  current_++;
  if (current_ < aggregate_->Count()) {
    return (*aggregate_)[current_];
  } else {
    return "";
  }
}

bool ConcreteIterator::IsDone() {
  return current_ >= aggregate_->Count() ? true : false;
}

std::string ConcreteIterator::Current() { return (*aggregate_)[current_]; }

int main() {
  auto ca = std::make_shared<ConcreteAggregate>();
  ca->items[0] = "HY";
  ca->items[1] = "FYY";
  ca->items[2] = "LBH";
  ca->items[3] = "HYM";

  std::cout << ca->Count() << std::endl;

  ConcreteIterator iter(ca);

  while (!iter.IsDone()) {
    std::cout << iter.Current() << ", 请买车票!" << std::endl;
    iter.Next();
  }

  return 0;
}
