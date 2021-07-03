#include "bridge.h"

int main() {
  BrandN phone_n;
  BrandM phone_m;
  phone_n.SetSoft(std::make_shared<HandsetGame>());
  phone_n.Run();

  phone_m.SetSoft(std::make_shared<HandsetMp3>());
  phone_m.Run();
  phone_m.SetSoft(std::make_shared<HandsetGame>());
  phone_m.Run();
  return 0;
}
