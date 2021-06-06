#include "template.h"

int main() {
  std::shared_ptr<TestPaper> YangGuo = std::make_shared<TestPaperA>();
  YangGuo->Question1();
  YangGuo->Question2();
  YangGuo->Question3();

  std::shared_ptr<TestPaper> LinghuChong = std::make_shared<TestPaperB>();
  LinghuChong->Question1();
  LinghuChong->Question2();
  LinghuChong->Question3();
  return 0;
}