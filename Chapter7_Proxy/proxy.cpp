#include "proxy.h"

int main() {
  SchoolGirl lbh = {"LBH"};
  Pursuit jiazuoyi(lbh);
  Proxy daili(jiazuoyi);

  daili.GiveDolls();
  daili.GiveFlowers();
  daili.GiveChocolate();

  return 0;
}