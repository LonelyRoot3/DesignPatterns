#include "responsibility.h"

int main() {
  auto jinli = std::make_shared<CommonManager>("金理");
  auto zongjian = std::make_shared<Majordomo>("宗剑");
  auto zongjinli = std::make_shared<GeneralManager>("宗精励");

  jinli->SetSuperior(zongjian);
  zongjian->SetSuperior(zongjinli);

  Request request;
  request.type = "请假";
  request.content = "小蔡请假";
  request.num = 1;
  jinli->ProcessRequest(request);

  Request request_2;
  request_2.type = "加薪";
  request_2.content = "小蔡请求加薪";
  request_2.num = 1000;
  jinli->ProcessRequest(request_2);

  return 0;
}
