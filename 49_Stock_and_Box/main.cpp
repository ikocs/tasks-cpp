#include <iostream>
#include <set>
#include <vector>

class Stock
{
   struct WightNum
   {
      int m_weight;
      size_t m_id;

      bool operator< (const WightNum &rhs) const
      {
         return std::tie(m_weight, rhs.m_id) < std::tie(rhs.m_weight, m_id);
      }
   };

   struct VolumeNum
   {
      int m_volume;
      size_t m_id;

      bool operator<(const VolumeNum&rhs) const
      {
         return std::tie(m_volume, rhs.m_id) < std::tie(rhs.m_volume, m_id);
      }
   };

   struct Iter
   {
      std::set<WightNum>::iterator byW;
      std::set<VolumeNum>::iterator byV;
   };

   std::vector<Iter> m_boxes;
   std::set<WightNum> m_wights;
   std::set<VolumeNum> m_volumes;

public:
   void Add(int w, int v)
   {
      size_t id = m_boxes.size();
      m_boxes.push_back({m_wights.insert({w, id}).first,
                              m_volumes.insert({v, id}).first});
   }

   int GetByW(int min_w)
   {
      const auto it = m_wights.lower_bound({min_w, m_boxes.size()});
      if (it == m_wights.end())
         return -1;

      size_t id = it->m_id;
      m_wights.erase(it);
      m_volumes.erase(m_boxes[id].byV);
      return id;
   }

   int GetByV(int min_v)
   {
      const auto it = m_volumes.lower_bound({min_v, m_boxes.size()});
      if (it == m_volumes.end())
         return -1;

      size_t id = it->m_id;
      m_volumes.erase(it);
      m_wights.erase(m_boxes[id].byW);
      return id;
   }
};

int main()
{
   Stock stock;

   // Добавляем коробки
   stock.Add(10, 100); // серийный номер 0
   stock.Add(20, 200); // серийный номер 1
   stock.Add(15, 150); // серийный номер 2
   stock.Add(10, 100); // серийный номер 3
   stock.Add(5, 50); // серийный номер 4

   // Получаем коробку по грузоподъемности
   std::cout << stock.GetByW(10) << std::endl; // ожидаем 0
   std::cout << stock.GetByW(15) << std::endl; // ожидаем 2
   std::cout << stock.GetByW(25) << std::endl; // ожидаем -1

   // Получаем коробку по объему
   std::cout << stock.GetByV(50) << std::endl; // ожидаем 3
   std::cout << stock.GetByV(200) << std::endl; // ожидаем 1
   std::cout << stock.GetByV(300) << std::endl; // ожидаем -1

   return 0;
}
