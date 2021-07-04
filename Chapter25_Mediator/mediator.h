/***********************************************************************/
// 中介者模式(Mediator)
// 特点：请求沿着责任链传递到合适的对象中处理
/***********************************************************************/
#include <iostream>
#include <memory>
#include <string>

class Country;

// 联合国
class UN {
 public:
  virtual void Declare(const std::string& message, const Country& country) = 0;
};

// 国家基类
class Country {
 public:
  explicit Country(std::shared_ptr<UN> un) : mediator_(un) {}
  virtual void Declare(const std::string& message) = 0;
  virtual void GetMessage(const std::string& message) = 0;

 protected:
  std::shared_ptr<UN> mediator_;
};

class USA : public Country {
 public:
  using Country::Country;
  void Declare(const std::string& message) override {
    mediator_->Declare(message, *this);
  }

  void GetMessage(const std::string& message) override {
    std::cout << "美国获得对方的信息:" << message << std::endl;
  }
};

class Iraq : public Country {
 public:
  using Country::Country;
  void Declare(const std::string& message) override {
    mediator_->Declare(message, *this);
  }

  void GetMessage(const std::string& message) override {
    std::cout << "伊拉克获得对方的信息:" << message << std::endl;
  }
};

// 安理会
class SecurityCouncil : public UN {
 public:
  void SetCountry(std::shared_ptr<USA> country_1,
                  std::shared_ptr<Iraq> country_2) {
    country_1_ = country_1;
    country_2_ = country_2;
  }
  void Declare(const std::string& message, const Country& country) override {
    if (country_1_.get() == &country) {
      country_2_->GetMessage(message);
    } else {
      country_1_->GetMessage(message);
    }
  }

 private:
  std::shared_ptr<USA> country_1_;
  std::shared_ptr<Iraq> country_2_;
};
