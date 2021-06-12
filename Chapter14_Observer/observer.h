/***********************************************************************/
// 观察者模式（发布-订阅模式，Publish/Subscribe）
// 让多个观察者对象同时监听某一个主题对象，这个主题对象在状态发生变化时，会通知所有观察者对象。
/***********************************************************************/
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>

enum class BossState : uint16_t {
  UNKNOWN = 0,
  BOSS_IN_OFFICE = 1,
  BOSS_LEFT_OFFICE = 2,
};

// 通知者
class Secretary {
 public:
  // 订阅
  void Subscribe(const std::string& name,
                 std::function<void(BossState)> callback) {
    if (nullptr != callback) {
      if (subs_.count(name) > 0) {
        subs_.erase(name);
      }
      subs_.insert({name, callback});
    }
  }

  // 取消订阅
  void UnSubscribe(const std::string& name) {
    if (subs_.count(name) > 0) {
      subs_.erase(name);
    }
  }

  // 老板来了
  void NotifyBossCome() {
    if (BossState::BOSS_IN_OFFICE != state_) {
      state_ = BossState::BOSS_IN_OFFICE;
      Publish();
    }
  }

  // 老板走了
  void NotifyBossLeft() {
    if (BossState::BOSS_LEFT_OFFICE != state_) {
      state_ = BossState::BOSS_LEFT_OFFICE;
      Publish();
    }
  }

 private:
  // 发布，遍历调用每一个注册进来的回调函数
  void Publish() {
    for (const auto& sub : subs_) {
      sub.second(state_);
    }
    std::cout << "通知结束\n" << std::endl;
  }

 private:
  BossState state_ = BossState::UNKNOWN;
  std::map<std::string, std::function<void(BossState)> > subs_;
};

// 观察者基类
class Observer {
 public:
  Observer(const std::string& name, std::shared_ptr<Secretary> notifier)
      : name_(name), notifier_(notifier) {}
  void Subscribe() {
    if (notifier_ && callback_) {
      notifier_->Subscribe(name_, callback_);
    }
  }

  void UnSubscribe() {
    if (notifier_) {
      notifier_->UnSubscribe(name_);
    }
  }

 protected:
  std::function<void(BossState)> callback_;

 private:
  std::string name_;
  std::shared_ptr<Secretary> notifier_;
};

// 看股票的观察者
class StockObserver : public Observer {
 public:
  StockObserver(const std::string& name, std::shared_ptr<Secretary> notifier)
      : Observer(name, notifier) {
    callback_ = [](BossState state) -> void {
      if (BossState::BOSS_IN_OFFICE == state) {
        std::cout << "老板来了！关掉同花顺，开始工作~" << std::endl;
      } else if (BossState::BOSS_LEFT_OFFICE == state) {
        std::cout << "老板走了！开始愉快地摸鱼吧~" << std::endl;
      }
    };
  }
};

// 看NBA的观察者
class NBAObserver : public Observer {
 public:
  NBAObserver(const std::string& name, std::shared_ptr<Secretary> notifier)
      : Observer(name, notifier) {
    callback_ = [](BossState state) -> void {
      if (BossState::BOSS_IN_OFFICE == state) {
        std::cout << "老板来了！关掉NBA，开始工作~" << std::endl;
      } else if (BossState::BOSS_LEFT_OFFICE == state) {
        std::cout << "老板走了！开始愉快地摸鱼吧~" << std::endl;
      }
    };
  }
};
