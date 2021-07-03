#include "command.h"

int main() {
  auto boy = std::make_shared<Barbecuer>();
  auto order_1 = std::make_shared<BakeMutton>(boy);
  auto order_2 = std::make_shared<BakeMutton>(boy);
  auto order_3 = std::make_shared<BakeChickenWing>(boy);
  auto order_4 = std::make_shared<BakeChickenWing>(boy);

  Waiter girl;
  girl.SetOrder(order_1);
  girl.SetOrder(order_2);
  girl.SetOrder(order_3);
  girl.SetOrder(order_4);

  girl.CancelOrder(order_2);

  girl.Notify();
  return 0;
}
