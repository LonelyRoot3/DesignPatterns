/***********************************************************************/
// 职责链模式(Chain of Responsibility)
// 特点：请求沿着责任链传递到合适的对象中处理
/***********************************************************************/
#include <iostream>
#include <memory>
#include <string>

struct Request {
  std::string type;
  std::string content;
  unsigned num = 0;
};

// 管理者抽象类
class Manager {
 public:
  explicit Manager(const std::string& name) : name_(name) {}
  void SetSuperior(std::shared_ptr<Manager> superior) { superior_ = superior; }
  virtual void ProcessRequest(const Request& request) = 0;

 protected:
  std::string name_;
  std::shared_ptr<Manager> superior_;  // 上级
};

class CommonManager : public Manager {
 public:
  using Manager::Manager;
  void ProcessRequest(const Request& request) override {
    if (request.type == "请假" && request.num <= 2) {
      std::cout << name_ << ": " << request.content << ", 数量：" << request.num
                << std::endl;
    } else if (superior_ != nullptr) {
      // 关键的一步，传递给上级处理
      superior_->ProcessRequest(request);
    }
  }
};

class Majordomo : public Manager {
 public:
  using Manager::Manager;
  void ProcessRequest(const Request& request) override {
    if (request.type == "请假" && request.num <= 5) {
      std::cout << name_ << ": " << request.content << ", 数量：" << request.num
                << std::endl;
    } else if (superior_ != nullptr) {
      superior_->ProcessRequest(request);
    }
  }
};

class GeneralManager : public Manager {
 public:
  using Manager::Manager;
  void ProcessRequest(const Request& request) override {
    if (request.type == "请假") {
      std::cout << name_ << ": " << request.content << ", 数量：" << request.num
                << std::endl;
    } else if (request.type == "加薪" && request.num <= 500) {
      std::cout << name_ << ": " << request.content << ", 数量：" << request.num
                << std::endl;
    } else if (request.type == "加薪" && request.num > 500) {
      std::cout << name_ << ": " << request.content << ", 数量：" << request.num
                << ", 再说吧" << std::endl;
    } else {
      std::cout << "无效请求" << std::endl;
    }
  }
};
