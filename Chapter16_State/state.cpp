#include "state.h"

// 在.cpp文件中实现成员函数，可以避免类之间循环引用的问题
void Forenoon::WriteProgram(Work& work) {
  if (work.hour < 12) {
    std::cout << "当前时间：" << work.hour << "点。 上午工作，精神百倍"
              << std::endl;
  } else {
    work.current = std::make_shared<Noon>();
    work.WriteProgram();
  }
}

void Noon::WriteProgram(Work& work) {
  if (work.hour < 13) {
    std::cout << "当前时间：" << work.hour << "点。 饿了，午饭；犯困，午睡。"
              << std::endl;
  } else {
    work.current = std::make_shared<AfterNoon>();
    work.WriteProgram();
  }
}

void AfterNoon::WriteProgram(Work& work) {
  if (work.hour < 17.5) {
    std::cout << "当前时间：" << work.hour << "点。 下午状态还不错，继续努力。"
              << std::endl;
  } else {
    work.current = std::make_shared<Evening>();
    work.WriteProgram();
  }
}

void Evening::WriteProgram(Work& work) {
  if (work.hour < 12) {
    work.current = std::make_shared<Forenoon>();
    work.WriteProgram();
  } else {
    if (work.finish) {
      std::cout << "当前时间：" << work.hour
                << "点。 工作已完成，睡觉了，明天继续。" << std::endl;
    } else {
      if (work.hour < 22) {
        std::cout << "当前时间：" << work.hour << "点。 活没干完继续上班。"
                  << std::endl;
      } else {
        std::cout << "当前时间：" << work.hour << "点。 时间到了，必须睡觉了"
                  << std::endl;
      }
    }
  }
}

int main() {
  Work work;
  work.current = std::make_shared<Forenoon>();
  work.hour = 9;
  work.WriteProgram();

  work.hour = 12;
  work.WriteProgram();

  work.hour = 13;
  work.WriteProgram();

  work.hour = 17;
  work.WriteProgram();

  work.hour = 20;
  work.WriteProgram();

  work.hour = 23;
  work.WriteProgram();

  work.hour = 9;
  work.WriteProgram();

  return 0;
}