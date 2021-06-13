#include "adapter.h"

int main() {
  Forwards player_a("LBH");
  Guards player_b("HY");
  player_a.Attack();
  player_b.Defense();

  // 对象适配器模式
  Translator player_c("YM");
  player_c.Attack();
  player_c.Defense();

  // 类适配器模式
  TranslatorClass player_d("FYY");
  player_d.Attack();
  player_d.Defense();
  return 0;
}