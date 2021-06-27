/***********************************************************************/
// 线程安全的单例模式
// 分为懒汉模式和饿汉模式 https://www.cnblogs.com/xiaolincoding/p/11437231.html
/***********************************************************************/
#include <array>
#include <iostream>
#include <memory>
#include <string>

// 懒汉模式，在调用GetInstance时才创建，使用函数静态局部变量
class LazySingleton {
 public:
  static LazySingleton& GetInstance() {
    // C++11，内部静态变量是线程安全的
    static LazySingleton instance;
    return instance;
  }

  void Show() { std::cout << "这是单例模式" << std::endl; }

 private:
  // 将构造函数设为私有
  ~LazySingleton() = default;
  LazySingleton() = default;
  LazySingleton(const LazySingleton&) = default;
  const LazySingleton& operator=(const LazySingleton& temp) {
    if (this == &temp) {
      return *this;
    } else {
      return temp;
    }
  }
};
