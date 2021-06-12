#include "observer.h"
int main() {
  auto mm = std::make_shared<Secretary>();
  NBAObserver workmate_1("LBH", mm);
  StockObserver workmate_2("HY", mm);

  // 同事订阅事件
  workmate_1.Subscribe();
  workmate_2.Subscribe();

  // 老板来了
  mm->NotifyBossCome();
  // 老板走了
  mm->NotifyBossLeft();

  // 某同事取消订阅
  workmate_1.UnSubscribe();
  // 老板又来了
  mm->NotifyBossCome();

  return 0;
}
