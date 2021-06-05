/***********************************************************************/
// 代理模式
// 特点是Proxy类和被代理的类（Pursuit）继承同一个基类，并且Proxy类持有一份Pursuit
/***********************************************************************/

#include <assert.h>
#include <math.h>

#include <iostream>
#include <memory>
#include <string>

// 被追的妹子
struct SchoolGirl {
  std::string name;
};

// 追妹子的方法
class GiveGift {
 public:
  virtual void GiveDolls() = 0;
  virtual void GiveFlowers() = 0;
  virtual void GiveChocolate() = 0;
};

// 追求者
class Pursuit : public GiveGift {
 public:
  explicit Pursuit(const SchoolGirl& mm) : mm_(mm) {}
  void GiveDolls() {
    std::cout << mm_.name << ", 这是送你的洋娃娃！" << std::endl;
  }
  void GiveFlowers() {
    std::cout << mm_.name << ", 这是送你的花！" << std::endl;
  }
  void GiveChocolate() {
    std::cout << mm_.name << ", 这是送你的巧克力！" << std::endl;
  }

 private:
  SchoolGirl mm_;
};

// 代理
class Proxy : public GiveGift {
 public:
  explicit Proxy(const Pursuit& gg) : gg_(gg) {}
  void GiveDolls() { gg_.GiveDolls(); }
  void GiveFlowers() { gg_.GiveFlowers(); }
  void GiveChocolate() { gg_.GiveChocolate(); }

 private:
  Pursuit gg_;
};