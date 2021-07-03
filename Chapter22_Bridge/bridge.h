/***********************************************************************/
// 桥接模式
// 特点：一个抽象类中含有另一个抽象类
/***********************************************************************/
#include <iostream>
#include <memory>
#include <string>

// 软件抽象类
class HandsetSoft {
 public:
  virtual void Run() = 0;
};

// 手机品牌抽象类
class HandsetBrand {
 public:
  void SetSoft(std::shared_ptr<HandsetSoft> soft) { soft_ = soft; }
  virtual void Run() = 0;

 protected:
  std::shared_ptr<HandsetSoft> soft_;
};

class HandsetGame : public HandsetSoft {
 public:
  void Run() override { std::cout << "运行手机游戏" << std::endl; }
};

class HandsetMp3 : public HandsetSoft {
 public:
  void Run() override { std::cout << "开始播放音乐" << std::endl; }
};

class BrandN : public HandsetBrand {
 public:
  void Run() override {
    std::cout << "N 品牌手机：";
    soft_->Run();
  }
};

class BrandM : public HandsetBrand {
 public:
  void Run() override {
    std::cout << "M 品牌手机：";
    soft_->Run();
  }
};
