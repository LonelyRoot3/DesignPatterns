/***********************************************************************/
// 状态模式，实现了状态机
// 特点：多个状态类继承自同一个基类
/***********************************************************************/
#include <iostream>
#include <memory>
#include <string>

// 提前声明
class Work;

// 状态基类
class State {
 public:
  virtual void WriteProgram(Work& work) = 0;
};

// Work类
class Work {
 public:
  void WriteProgram() {
    if (current) {
      current->WriteProgram(*this);
    } else {
      std::cout << "current is nullptr" << std::endl;
    }
  }

 public:
  bool finish = false;
  double hour;
  std::shared_ptr<State> current;
};

class Forenoon : public State {
 public:
  void WriteProgram(Work& work) override;
};

class Noon : public State {
 public:
  void WriteProgram(Work& work) override;
};

class AfterNoon : public State {
 public:
  void WriteProgram(Work& work) override;
};

class Evening : public State {
 public:
  void WriteProgram(Work& work) override;
};
