/***********************************************************************/
// 迭代器模式
// 特点：分离了集合对象的遍历行为，抽象出了一个迭代器
/***********************************************************************/
#include <array>
#include <iostream>
#include <memory>
#include <string>

class Aggregate;

class Iterator {
 public:
  Iterator(std::shared_ptr<Aggregate> aggregate) : aggregate_(aggregate) {}
  virtual std::string First() = 0;
  virtual std::string Next() = 0;
  virtual std::string Current() = 0;
  virtual bool IsDone() = 0;

 protected:
  std::size_t current_ = 0;
  std::shared_ptr<Aggregate> aggregate_;
};

class Aggregate {
 public:
  virtual std::string& operator[](std::size_t i) = 0;
  virtual std::size_t Count() = 0;
};

class ConcreteIterator : public Iterator {
 public:
  ConcreteIterator(std::shared_ptr<Aggregate> aggregate)
      : Iterator(aggregate) {}

  std::string First() override;
  std::string Next() override;
  std::string Current() override;
  bool IsDone() override;
};

class ConcreteAggregate : public Aggregate {
 public:
  std::size_t Count() { return items.size(); }
  std::string& operator[](std::size_t i) override;

 public:
  std::array<std::string, 4> items;
};
