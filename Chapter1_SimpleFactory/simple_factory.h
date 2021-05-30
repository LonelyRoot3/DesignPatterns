#include <math.h>

#include <cfloat>
#include <iostream>
#include <memory>
using namespace std;

// 算术操作基类
class Operation {
 public:
  virtual double GetResult() = 0;
  void SetPar(double a, double b) {
    a_ = a;
    b_ = b;
  }

 protected:
  // 算术运算的两个操作数
  double a_ = 0;
  double b_ = 0;
};

// 加减乘除运算类
class OperationAdd : public Operation {
 public:
  double GetResult() override { return a_ + b_; }
};

class OperationSub : public Operation {
 public:
  double GetResult() override { return a_ - b_; }
};

class OperationMul : public Operation {
 public:
  double GetResult() override { return a_ * b_; }
};

class OperationDiv : public Operation {
 public:
  double GetResult() override {
    if (fabs(b_) <= DBL_EPSILON) {
      throw("分母不可为0");
    }
    return a_ / b_;
  }
};

class OperationFactory {
 public:
  static shared_ptr<Operation> CreateOperate(const string& operate);
};