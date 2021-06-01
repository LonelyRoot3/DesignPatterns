#include "decorator.h"

int main() {
  auto me = std::make_shared<Person>("LonelyRoot3");
  auto shoes = std::make_shared<Slipper>();
  auto trouser = std::make_shared<BigTrouser>();
  auto shirt = std::make_shared<TShirt>();

  shoes->Decorate(me);
  trouser->Decorate(shoes);
  shirt->Decorate(trouser);

  shirt->Show();

  return 0;
}
