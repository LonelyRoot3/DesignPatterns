/***********************************************************************/
// 抽象工厂模式
// 多个具体工厂继承自一个抽象工厂，而每个工厂又能生产多类产品。
/***********************************************************************/
#include <iostream>
#include <memory>
#include <string>

// 两种抽象产品，车与手机
class Vehicle {
 public:
  virtual void ShowVehicle() = 0;
};

class Phone {
 public:
  virtual void ShowPhone() = 0;
};

// 四种具体产品
class VehicleApple : public Vehicle {
 public:
  void ShowVehicle() { std::cout << "这是苹果汽车" << std::endl; }
};

class VehicleHuawei : public Vehicle {
 public:
  void ShowVehicle() { std::cout << "这是华为汽车" << std::endl; }
};

class PhoneApple : public Phone {
 public:
  void ShowPhone() { std::cout << "这是苹果手机" << std::endl; }
};

class PhoneHuawei : public Phone {
 public:
  void ShowPhone() { std::cout << "这是华为手机" << std::endl; }
};

// 抽象工厂
class Factory {
 public:
  virtual std::shared_ptr<Vehicle> CreateVehicle() = 0;
  virtual std::shared_ptr<Phone> CreatePhone() = 0;
};

// 苹果的工厂
class AppleFactory : public Factory {
 public:
  std::shared_ptr<Vehicle> CreateVehicle() {
    return std::make_shared<VehicleApple>();
  }

  std::shared_ptr<Phone> CreatePhone() {
    return std::make_shared<PhoneApple>();
  }
};

// 华为的工厂
class HuaweiFactory : public Factory {
 public:
  std::shared_ptr<Vehicle> CreateVehicle() {
    return std::make_shared<VehicleHuawei>();
  }

  std::shared_ptr<Phone> CreatePhone() {
    return std::make_shared<PhoneHuawei>();
  }
};
