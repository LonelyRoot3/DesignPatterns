/***********************************************************************/
// 工厂方法模式
// 既有产品基类，也有工厂基类。每一种产品都有对应的工厂类。
/***********************************************************************/
#include <iostream>
#include <memory>
#include <string>

// 雷锋基类
class LeiFeng {
 public:
  void Sweep() {
    std::cout << "扫地" << std::endl;
    return;
  }

  void Wash() {
    std::cout << "洗衣" << std::endl;
    return;
  }

  void BuyRice() {
    std::cout << "买米" << std::endl;
    return;
  }
};

// 大学生
class Undergraduate : public LeiFeng {};

// 志愿者
class Volunteer : public LeiFeng {};

// 工厂基类
class IFactory {
 public:
  virtual std::shared_ptr<LeiFeng> CreateLeiFeng() = 0;
};

class UndergraduateFactory : public IFactory {
 public:
  std::shared_ptr<LeiFeng> CreateLeiFeng() {
    return std::make_shared<Undergraduate>();
  }
};

class VolunteerFactory : public IFactory {
 public:
  std::shared_ptr<LeiFeng> CreateLeiFeng() {
    return std::make_shared<Volunteer>();
  }
};