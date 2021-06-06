/***********************************************************************/
// 模板方法模式
// 定义一个操作中的算法的骨架，而将一些步骤延迟到子类中
/***********************************************************************/
#include <iostream>
#include <memory>
#include <string>

class TestPaper {
 public:
  void Question1() {
    std::cout << "问题1： 你是谁？" << std::endl;
    std::cout << "答案是： " << Answer1() << std::endl;
  }

  void Question2() {
    std::cout << "问题2： 你是老婆谁？" << std::endl;
    std::cout << "答案是： " << Answer2() << std::endl;
  }

  void Question3() {
    std::cout << "问题3： 你最厉害的武功是什么？" << std::endl;
    std::cout << "答案是： " << Answer3() << std::endl;
  }

  virtual std::string Answer1() = 0;
  virtual std::string Answer2() = 0;
  virtual std::string Answer3() = 0;
};

class TestPaperA : public TestPaper {
 public:
  std::string Answer1() { return "杨过\n"; }
  std::string Answer2() { return "小龙女\n"; }
  std::string Answer3() { return "黯然销魂掌\n"; }
};

class TestPaperB : public TestPaper {
 public:
  std::string Answer1() { return "令狐冲\n"; }
  std::string Answer2() { return "任盈盈\n"; }
  std::string Answer3() { return "独孤九剑\n"; }
};
