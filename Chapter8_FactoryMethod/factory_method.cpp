#include "factory_method.h"

int main() {
  std::shared_ptr<IFactory> factory = std::make_shared<UndergraduateFactory>();
  std::shared_ptr<LeiFeng> studentA = factory->CreateLeiFeng();
  studentA->Sweep();
  studentA->Wash();
  studentA->BuyRice();
  return 0;
}
