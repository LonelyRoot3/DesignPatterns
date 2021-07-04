#include "mediator.h"

int main() {
  auto unsc = std::make_shared<SecurityCouncil>();
  auto c1 = std::make_shared<USA>(unsc);
  auto c2 = std::make_shared<Iraq>(unsc);

  unsc->SetCountry(c1, c2);
  c1->Declare("不准研发核武器，否则要发动战争!");
  c2->Declare("我们没有核武器，但也不怕侵略.");
  return 0;
}
