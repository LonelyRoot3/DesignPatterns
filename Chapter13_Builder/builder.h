/***********************************************************************/
// 建造者模式（生成器模式）
// 将一个复杂对象的构建与表示分离，使得同样的构建过程可以创建不同的表示
// 特点是指挥者持有一份建造者
// 注意其与代理模式和策略模式的区别。这里指挥者与建造者不共基类。
/***********************************************************************/
#include <iostream>
#include <memory>
#include <string>

// 建造者
class PersonBuilder {
 public:
  virtual void BuildHead() = 0;
  virtual void BuildBody() = 0;
  virtual void BuildLegs() = 0;
};

class ThinBuild : public PersonBuilder {
 public:
  void BuildHead() { std::cout << "        O           " << std::endl; }
  void BuildBody() { std::cout << "       口           " << std::endl; }
  void BuildLegs() {
    std::cout << "       ''           " << std::endl;
    std::cout << "       ''           " << std::endl;
    std::cout << "       ''           " << std::endl;
  }
};

class FatBuild : public PersonBuilder {
 public:
  void BuildHead() { std::cout << "        O           " << std::endl; }
  void BuildBody() { std::cout << "      口 口          " << std::endl; }
  void BuildLegs() {
    std::cout << "      '' ''           " << std::endl;
    std::cout << "      '' ''           " << std::endl;
    std::cout << "      '' ''           " << std::endl;
  }
};

// 指挥者
class PersonDirector {
 public:
  explicit PersonDirector(std::shared_ptr<PersonBuilder> pb) : pb_(pb) {}
  void CreatePerson() {
    if (pb_) {
      pb_->BuildHead();
      pb_->BuildBody();
      pb_->BuildLegs();
    }
  }

 private:
  std::shared_ptr<PersonBuilder> pb_;
};