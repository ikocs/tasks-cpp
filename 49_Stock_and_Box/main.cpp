#include <iostream>
#include <vector>
#include <algorithm>

class Stock
{
   struct Box
   {
      int m_id;
      int m_weight;
      int m_volume;

      Box(const int id, const int weight, const int volume) :
         m_id(id),
         m_weight(weight),
         m_volume(volume) { }
   };

   std::vector<Box> m_boxes;
   unsigned int m_last_id{0};
public:
   void Add(int w, int v)
   {
      m_boxes.emplace_back(m_last_id++, w, v);
   }

   int GetByW(int min_w)
   {
      std::sort(m_boxes.begin(), m_boxes.end(),
         [](const Box& lhs, const Box& rhs) { return std::tie(rhs.m_weight, lhs.m_id) > std::tie(lhs.m_weight, rhs.m_id); } );

      auto it = std::find_if(m_boxes.begin(),
         m_boxes.end(), [min_w](const Box& box) { return box.m_weight >= min_w; });

      if (it != m_boxes.end())
      {
         const auto id = it->m_id;
         m_boxes.erase(it);
         return id;
      }

      return -1;
   }

   int GetByV(int min_v)
   {
      std::sort(m_boxes.begin(), m_boxes.end(),
   [](const Box& lhs, const Box& rhs) { return std::tie(rhs.m_volume, lhs.m_id) > std::tie(lhs.m_volume, rhs.m_id); } );

      auto it = std::find_if(m_boxes.begin(),
         m_boxes.end(), [min_v](const Box& box) { return box.m_volume >= min_v; });

      if (it != m_boxes.end())
      {
         const auto id = it->m_id;
         m_boxes.erase(it);
         return id;
      }

      return -1;
   }
};

int main() {
   Stock stock;

   // Добавляем коробки
   stock.Add(10, 100);  // серийный номер 0
   stock.Add(20, 200);  // серийный номер 1
   stock.Add(15, 150);  // серийный номер 2
   stock.Add(10, 100);  // серийный номер 3
   stock.Add(5, 50);    // серийный номер 4

   // Получаем коробку по грузоподъемности
   std::cout << stock.GetByW(10) << std::endl;  // ожидаем 0
   std::cout << stock.GetByW(15) << std::endl;  // ожидаем 2
   std::cout << stock.GetByW(25) << std::endl;  // ожидаем -1

   // Получаем коробку по объему
   std::cout << stock.GetByV(50) << std::endl;   // ожидаем 3
   std::cout << stock.GetByV(200) << std::endl;  // ожидаем 1
   std::cout << stock.GetByV(300) << std::endl;  // ожидаем -1

   return 0;
}
