/***********************************************************************/
// 组合模式
// 特点：类似树的数据结构，由派生自同一个基类的不同对象组成一个更大的组织
/***********************************************************************/
#include <iostream>
#include <list>
#include <memory>
#include <string>

class Component {
 public:
  explicit Component(const std::string& name) : name_(name) {}
  virtual void Add(std::shared_ptr<Component> c) = 0;
  virtual void Remove(std::shared_ptr<Component> c) = 0;
  // pre代表前缀，通常就是从根节点到父节点组成的字符串
  virtual void Display(const std::string& pre = "") = 0;

 protected:
  std::string name_;
};

// 叶节点，不再包含任何子节点
class Leaf : public Component {
 public:
  explicit Leaf(const std::string& name) : Component(name) {}

  void Add(std::shared_ptr<Component> c) {
    std::cout << "叶节点不能增加子节点" << std::endl;
  }

  void Remove(std::shared_ptr<Component> c) {
    std::cout << "叶节点不能删除子节点" << std::endl;
  }

  void Display(const std::string& pre = "") {
    std::cout << pre << name_ << std::endl;
  }
};

class Composite : public Component {
 public:
  explicit Composite(const std::string& name) : Component(name) {}

  void Add(std::shared_ptr<Component> c) { children_.push_back(c); }

  void Remove(std::shared_ptr<Component> c) { children_.remove(c); }

  void Display(const std::string& pre = "") {
    std::string new_pre = pre + name_;
    if (children_.size() == 0) {
      // 当前无子节点了，打印
      std::cout << pre << name_ << std::endl;
    } else {
      new_pre += "-->";
      for (auto iter = children_.begin(); iter != children_.end(); iter++) {
        (*iter)->Display(new_pre);
      }
    }
  }

 private:
  std::list<std::shared_ptr<Component>> children_;
};
