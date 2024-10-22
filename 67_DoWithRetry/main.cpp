/// Функция принимает на вход другую функцию без аргументов, возвращающую значение типа Result,
/// количество повторов, таймаут между повторами и флажок throwLast.
///
/// Одним из шаблонных параметров функции является тип исключения, на которое функция реагирует. 
/// Функция должна вызвать func, и если произошло исключение указанного типа, то вызвать нашу функцию Sleep 
/// с параметром sleepTime, а затем повторить попытку (если попытки еще остались). Максимальное количество вызовов func,
/// которое может получиться, равно retryCount + 1. Если на последней попытке происходит исключение указанного типа,
/// и throwLast истинно, этот же объект исключения должен проброситься дальше из функции. Если же throwLast ложно,
/// то надо просто вернуть пустой объект std::optional. Если же вызов func закончился успешно,
/// то надо просто вернуть результат func.

#include <exception>
#include <functional>
#include <optional>

void func() {}

void Sleep(int time)
{
}

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime, bool throwLast) {
   for (int i = 0; i < retryCount + 1; ++i) {
      try {
         return func();
      } catch (const Exception&) {
         if (i == retryCount) {
            if (throwLast) {
               throw;
            }
         } else {
            Sleep(sleepTime);
         }
      }
   }
   return {};
}

#include <iostream>

int main()
{
   int sleep_ms = 5;
   std::function<int()> func = std::bind(func);
   auto result = DoWithRetry<int>(func, 3, 0, true);
   return 0;
}
