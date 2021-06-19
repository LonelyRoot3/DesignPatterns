/***********************************************************************/
// 备忘录模式
// 特点：备份数据中的部分成员，并可依次恢复状态
/***********************************************************************/
#include <iostream>
#include <memory>
#include <string>

struct Memento {
  Memento(int v, int a, int d) : vitality(v), attack(a), defense(d) {}
  int vitality = 0;
  int attack = 0;
  int defense = 0;
};

class GameRole {
 public:
  void Init() {
    vitality_ = 100;
    attack_ = 100;
    defense_ = 100;
    play_time_ = 97.5;
    back_ = std::make_shared<Memento>(vitality_, attack_, defense_);
  }

  void Show() {
    std::cout << "当前体力：" << vitality_ << ", 攻击力：" << attack_
              << ", 防御力：" << defense_ << std::endl;
  }

  void Save() {
    if (!back_) {
      back_ = std::make_shared<Memento>(vitality_, attack_, defense_);
    } else {
      back_->vitality = vitality_;
      back_->attack = attack_;
      back_->defense = defense_;
    }
  }

  void Recovery() {
    if (back_) {
      vitality_ = back_->vitality;
      attack_ = back_->attack;
      defense_ = back_->defense;
    }
  }

  void Fight() {
    vitality_ = 0;
    attack_ = 0;
    defense_ = 0;
    play_time_ += 20;
  }

 private:
  // 需要备份的数据
  int vitality_ = 0;
  int attack_ = 0;
  int defense_ = 0;
  // 不需要备份的数据
  double play_time_ = 0;  // 玩游戏的时间长度
  // 备忘录
  std::shared_ptr<Memento> back_;
};
