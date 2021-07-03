/***********************************************************************/
// 命令模式
// 特点：把一个类的成员函数封装成一个对象，这个对象需要持有一份原对象
/***********************************************************************/
#include <iostream>
#include <list>
#include <memory>
#include <string>

// 烧烤大厨
class Barbecuer {
 public:
  void BakeMutton() { std::cout << "烤羊肉串" << std::endl; }
  void BakeChickenWing() { std::cout << "烤鸡翅" << std::endl; }
};

// 抽象命令类
class Command {
 public:
  explicit Command(std::shared_ptr<Barbecuer> receiver) : receiver_(receiver) {}
  virtual void ExecCommand() = 0;
  virtual std::string GetName() = 0;

 protected:
  std::shared_ptr<Barbecuer> receiver_;
};

class BakeMutton : public Command {
 public:
  using Command::Command;
  void ExecCommand() override { receiver_->BakeMutton(); }
  std::string GetName() { return std::move("Command.BakeMutton"); }
};

class BakeChickenWing : public Command {
 public:
  using Command::Command;
  void ExecCommand() override { receiver_->BakeChickenWing(); }
  std::string GetName() { return std::move("Command.BakeChickenWing"); }
};

// 服务员类，其接收命令
class Waiter {
 public:
  // 下单
  void SetOrder(std::shared_ptr<Command> order) {
    orders.push_back(order);
    std::cout << "下单: " << order->GetName() << std::endl;
  }

  // 取消订单
  void CancelOrder(std::shared_ptr<Command> order) {
    orders.remove(order);
    std::cout << "取消订单: " << order->GetName() << std::endl;
  }

  // 通知厨师
  void Notify() {
    for (const auto& order : orders) {
      order->ExecCommand();
    }
  }

 private:
  std::list<std::shared_ptr<Command>> orders;
};