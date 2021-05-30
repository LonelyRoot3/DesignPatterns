#include "strategy.h"

CashContext::CashContext(DiscountType type) {
  switch (type) {
    case DiscountType::rebate_100_per_300:
      cash = std::make_shared<CashRebate>(300, 100);
      break;
    case DiscountType::discount_20:
      cash = std::make_shared<CashDiscount>(0.2);
      break;
    default:
      cash = std::make_shared<CashNormal>();
      break;
  }
}

int main() {
  double price = 100;
  double num = 50;

  // CashContext cash_context(DiscountType::normal);
  // CashContext cash_context(DiscountType::discount_20);
  CashContext cash_context(DiscountType::rebate_100_per_300);
  std::cout << "原总价： " << num * price << ", 折后总价： "
            << cash_context.GetResult(num * price) << std::endl;
  return 0;
}