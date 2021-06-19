#include "memento.h"

int main() {
  GameRole LiXiaoyao;
  LiXiaoyao.Init();
  LiXiaoyao.Show();
  LiXiaoyao.Save();

  LiXiaoyao.Fight();
  LiXiaoyao.Show();

  LiXiaoyao.Recovery();
  LiXiaoyao.Show();

  return 0;
}