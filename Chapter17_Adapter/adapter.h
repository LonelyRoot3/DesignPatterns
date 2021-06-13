/***********************************************************************/
// 适配器模式
// 特点：适配器中持有一份被适配的对象，他们并不继承同一个基类，接口也不一致
// 注意适配器模式(adaptor)与代理模式(proxy)的区别。
/***********************************************************************/
#include <iostream>
#include <memory>
#include <string>

// 球员基类
class Player {
 public:
  explicit Player(const std::string& name) : name_(name) {}
  virtual void Attack() = 0;   // 进攻
  virtual void Defense() = 0;  // 防守

 protected:
  std::string name_;
};

// 前锋
class Forwards : public Player {
 public:
  explicit Forwards(const std::string& name) : Player(name) {}
  void Attack() { std::cout << "前锋 " << name_ << " 进攻!" << std::endl; }
  void Defense() { std::cout << "前锋 " << name_ << " 防守!" << std::endl; }
};

// 中锋
class Center : public Player {
 public:
  explicit Center(const std::string& name) : Player(name) {}
  void Attack() { std::cout << "中锋 " << name_ << " 进攻!" << std::endl; }
  void Defense() { std::cout << "中锋 " << name_ << " 防守!" << std::endl; }
};

// 后卫
class Guards : public Player {
 public:
  explicit Guards(const std::string& name) : Player(name) {}
  void Attack() { std::cout << "后卫 " << name_ << " 进攻!" << std::endl; }
  void Defense() { std::cout << "后卫 " << name_ << " 防守!" << std::endl; }
};

// 外国中锋，并不继承Player
class ForeignCentre {
 public:
  explicit ForeignCentre(const std::string& name) : name_(name) {}
  void Jingong() { std::cout << "中锋 " << name_ << " 开整啊！" << std::endl; }
  void Fangshou() { std::cout << "中锋 " << name_ << " 瞅啥呢！" << std::endl; }

 private:
  std::string name_;
};

// 翻译，adaptor，它要继承Player
// 对象适配器模式，持有一份要适配的对象
class Translator : public Player {
 public:
  Translator(const std::string& name) : Player(name) {
    foreigner_ = std::make_shared<ForeignCentre>(name);
  }

  void Attack() { foreigner_->Jingong(); }
  void Defense() { foreigner_->Fangshou(); }

 private:
  std::shared_ptr<ForeignCentre> foreigner_;
};

// 类适配器模式，多重继承
class TranslatorClass : public Player, ForeignCentre {
 public:
  explicit TranslatorClass(const std::string& name)
      : Player(name), ForeignCentre(name) {}

  void Attack() { Jingong(); }
  void Defense() { Fangshou(); }
};
