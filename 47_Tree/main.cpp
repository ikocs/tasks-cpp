/// Ваша задача — написать реализации функций Has, Insert и Delete для этого класса.
/// В примере с папками в файловой системе функция Has должна проверить, существует ли такая папка,
/// функция Insert должна создать папку (возможно, с промежуточными родительскими папками),
/// а Delete — удалить папку со всеми вложенными подпапками, если такая папка существует.

/// Можно считать, что вектор, передаваемый на вход этих функций, всегда непустой.

#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Node {
   std::map<std::string, Node> children;
};

class Tree {

private:
   Node root;

public:
   bool Has(const std::vector<std::string>& node) const;
   void Insert(const std::vector<std::string>& node);
   void Delete(const std::vector<std::string>& node);
};

bool Tree::Has(const std::vector<std::string>& node) const
{
   const Node* obj = &root;
   for (const auto& name : node)
   {
      if (!obj->children.contains(name))
         return false;

      obj = &obj->children.at(name);
   }

   return true;
}
void Tree::Insert(const std::vector<std::string>& node)
{
   Node* obj = &root;
   for (const auto& name : node)
   {
      if (obj->children.contains(name))
      {
         obj = &obj->children.at(name);
         continue;
      }

      obj->children[name] = Node();
      obj = &obj->children.at(name);
   }
}

void Tree::Delete(const std::vector<std::string>& node)
{
   Node* obj = &root;
   std::map<std::string, Node>* obj_map = nullptr;
   for (const auto& name : node)
   {
      if (!obj->children.contains(name))
         return;

      obj_map = &obj->children;
      obj = &obj->children.at(name);
   }

   if (obj_map != nullptr)
      obj_map->erase(node.back());
}

int main()
{
   Tree tree;

   const std::vector<std::string> str{"home", "user", "bin"};
   const std::vector<std::string> path1{"home", "user", "download"};
   tree.Insert(str);
   tree.Insert(path1);

   std::cout << tree.Has(str) << std::endl;

   tree.Delete(path1);

   std::cout << tree.Has(str) << std::endl;

   return 0;
}
