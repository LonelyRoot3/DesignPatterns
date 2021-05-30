#include <assert.h>
#include <math.h>

#include <cfloat>
#include <iostream>
#include <memory>

// 结账类型
enum class DiscountType : uint8_t {
  // 正常结账
  normal = 0,
  // 返现结账 1 ~ 100
  rebate_100_per_300 = 1,  // 满300返100
  // 折扣结账 101 ~ max
  discount_20 = 101,  // 八折
};

// 算账的基类
class Cash {
 public:
  virtual double AcceptCash(double raw_money) = 0;
};

// 正常结算
class CashNormal : public Cash {
 public:
  double AcceptCash(double raw_money) override { return raw_money; }
};

// 满XX返XX
class CashRebate : public Cash {
 public:
  CashRebate(double money_condition, double money_rebate)
      : money_condition_(money_condition), money_rebate_(money_rebate) {}
  double AcceptCash(double raw_money) override {
    if (fabs(money_condition_) <= DBL_EPSILON ||
        fabs(money_rebate_) <= DBL_EPSILON || raw_money < money_condition_) {
      return raw_money;
    } else {
      return raw_money -
             std::floor(raw_money / money_condition_) * money_rebate_;
    }
  }

 private:
  double money_condition_ = 0;
  double money_rebate_ = 0;
};

// 打折
class CashDiscount : public Cash {
 public:
  CashDiscount(double discount) : discount_(discount) {}
  double AcceptCash(double raw_money) override {
    if (discount_ > 1 || discount_ < 0) {
      return raw_money;
    } else {
      // 8折的discount为20%.
      return raw_money * (1 - discount_);
    }
  }

 private:
  double discount_ = 0;
};

class CashContext {
 public:
  explicit CashContext(DiscountType type);
  double GetResult(double raw_money) {
    assert(cash);
    return cash->AcceptCash(raw_money);
  }

 private:
  std::shared_ptr<Cash> cash;
};