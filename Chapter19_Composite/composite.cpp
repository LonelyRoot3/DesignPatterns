#include "composite.h"

int main() {
  Composite root("root");
  root.Add(std::make_shared<Leaf>("LeafA"));
  root.Add(std::make_shared<Leaf>("LeafB"));

  auto node_x = std::make_shared<Composite>("X");
  root.Add(node_x);
  node_x->Add(std::make_shared<Leaf>("X_A"));
  node_x->Add(std::make_shared<Leaf>("X_B"));

  auto node_xy = std::make_shared<Composite>("XY");
  node_x->Add(node_xy);
  node_xy->Add(std::make_shared<Leaf>("XY_A"));
  node_xy->Add(std::make_shared<Leaf>("XY_B"));

  auto node_xz = std::make_shared<Composite>("XZ");
  node_x->Add(node_xz);

  root.Display();

  return 0;
}
