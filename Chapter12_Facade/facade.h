/***********************************************************************/
// 外观模式
// 为子系统中的一组接口提供一个一致的界面
/***********************************************************************/
#include <iostream>
#include <memory>
#include <string>

// 股票
class Stock {
 public:
  explicit Stock(const std::string& name) : name_(name) {}
  void Buy(uint32_t num) {
    num_ += num;
    std::cout << "买入 " << num << " 股 " << name_ << ", 现存总计 " << num_
              << "股" << std::endl;
  }

  void Sell(uint32_t num) {
    if (num > num_) {
      std::cout << "卖出 " << name_ << " 失败, 股票不足" << std::endl;
    } else {
      num_ -= num;
      std::cout << "卖出 " << num << " 股 " << name_ << ", 现存总计 " << num_
                << "股" << std::endl;
    }
  }
  std::string name_;
  uint32_t num_ = 0;  // 现存多少股
};

class NationalDebt {
 public:
  explicit NationalDebt(const std::string& name) : name_(name) {}
  void Buy(uint32_t num) {
    num_ += num;
    std::cout << "买入 " << num << " 份 " << name_ << ", 现存总计 " << num_
              << "份" << std::endl;
  }

  void Sell(uint32_t num) {
    if (num > num_) {
      std::cout << "卖出 " << name_ << " 失败, 国债不足" << std::endl;
    } else {
      num_ -= num;
      std::cout << "卖出 " << num << " 份 " << name_ << ", 现存总计 " << num_
                << "份" << std::endl;
    }
  }
  std::string name_;
  uint32_t num_ = 0;  // 现存多少份
};

class Fund {
 public:
  Fund() : stock_1("小米集团"), stock_2("腾讯股份"), nd_1("未名国债") {}
  void Buy(uint32_t num) {
    stock_1.Buy(num);
    stock_2.Buy(2 * num);
    nd_1.Buy(3 * num);
    std::cout << "本次买入结束！\n" << std::endl;
  }

  void Sell(uint32_t num) {
    stock_1.Sell(num);
    stock_2.Sell(2 * num);
    nd_1.Sell(3 * num);
    std::cout << "本次卖出结束！\n" << std::endl;
  }

 private:
  Stock stock_1;
  Stock stock_2;
  NationalDebt nd_1;
};
