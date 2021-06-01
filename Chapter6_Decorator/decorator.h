#include <assert.h>
#include <math.h>

#include <iostream>
#include <memory>
#include <string>

// 人
class Person {
 public:
  Person() = default;
  Person(const std::string& new_name) : name(new_name) {}
  virtual void Show() { std::cout << "装扮的 " << name << std::endl; }

 private:
  std::string name;
};

// 服饰基类，继承自人
class Finery : public Person {
 public:
  void Decorate(std::shared_ptr<Person> p) { component = p; }
  void Show() override {
    if (component) {
      component->Show();
    }
  }

 protected:
  std::shared_ptr<Person> component;
};

class TShirt : public Finery {
 public:
  void Show() override {
    Finery::Show();
    std::cout << "大T恤" << std::endl;
  }
};

class BigTrouser : public Finery {
 public:
  void Show() override {
    Finery::Show();
    std::cout << "大裤子" << std::endl;
  }
};

class Slipper : public Finery {
  void Show() override {
    Finery::Show();
    std::cout << "拖鞋" << std::endl;
  }
};