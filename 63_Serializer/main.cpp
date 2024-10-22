#include <iostream>
#include <string>

class Serializer
{
public:
   virtual ~Serializer() = default;

   virtual void BeginArray() = 0;
   virtual void AddArrayItem(const std::string&) = 0;
   virtual void EndArray() = 0;
};

class JsonSerializer final : public Serializer
{
public:
   JsonSerializer() = default;
   ~JsonSerializer() override = default;

   void BeginArray() override
   {
      if (!need_sep)
         std::cout << ",";
      std::cout << "[";
      need_sep = true;
   }

   void AddArrayItem(const std::string& param) override
   {
      if (!need_sep)
         std::cout << ",";
      std::cout << "\"" << param << "\"";
      need_sep = false;
   }

   void EndArray() override
   {
      std::cout << "]";
      need_sep = false;
   }

private:
   bool need_sep{true};
};

int main()
{
   JsonSerializer serializer;

   serializer.BeginArray();
   serializer.BeginArray();
   serializer.AddArrayItem("string");
   serializer.AddArrayItem("string");
   serializer.AddArrayItem("string");
   serializer.EndArray();
   serializer.BeginArray();
   serializer.AddArrayItem("int");
   serializer.AddArrayItem("string");
   serializer.EndArray();
   serializer.BeginArray();
   serializer.EndArray();
   serializer.EndArray();

   return 0;
}
