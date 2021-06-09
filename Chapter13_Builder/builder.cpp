#include "builder.h"

int main() {
  auto ptb = std::make_shared<ThinBuild>();
  auto pdThin = std::make_shared<PersonDirector>(ptb);
  pdThin->CreatePerson();

  auto pfb = std::make_shared<FatBuild>();
  auto pdFat = std::make_shared<PersonDirector>(pfb);
  pdFat->CreatePerson();
}