#include "abstract_factory.h"

int main() {
  std::shared_ptr<Factory> factory = std::make_shared<AppleFactory>();
  factory->CreatePhone()->ShowPhone();
  factory->CreateVehicle()->ShowVehicle();

  factory = std::make_shared<HuaweiFactory>();
  factory->CreatePhone()->ShowPhone();
  factory->CreateVehicle()->ShowVehicle();
  return 0;
}
