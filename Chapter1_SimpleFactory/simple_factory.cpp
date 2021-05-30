#include "simple_factory.h"

#include <memory>
shared_ptr<Operation> OperationFactory::CreateOperate(const string& operate) {
  if (operate == "+") {
    return make_shared<OperationAdd>();
  } else if (operate == "-") {
    return make_shared<OperationSub>();
  } else if (operate == "*") {
    return make_shared<OperationMul>();
  } else if (operate == "/") {
    return make_shared<OperationDiv>();
  } else {
    cout << "unknown operate: " << operate << endl;
    return nullptr;
  }
}

int main() {
  shared_ptr<Operation> oper = nullptr;

  // 加法
  oper = OperationFactory::CreateOperate("+");
  if (nullptr != oper) {
    oper->SetPar(1, 2);
    cout << "1 + 2 = " << oper->GetResult() << endl;
  }

  // 乘法
  oper = OperationFactory::CreateOperate("*");
  if (nullptr != oper) {
    oper->SetPar(3, 4);
    cout << "3 * 4 = " << oper->GetResult() << endl;
  }

  // 除法
  oper = OperationFactory::CreateOperate("/");
  if (nullptr != oper) {
    oper->SetPar(3, 4);
    cout << "3 / 4 = " << oper->GetResult() << endl;
  }

  return 0;
}