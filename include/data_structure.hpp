#pragma once

// Заголовочный файл с объявлением структуры данных

namespace itis {

  struct node {
    explicit node(int key);

    node* parent{};
    node* child{};
    node* left{};
    node* right{};
    int degree{};
    bool mark{}; //have this deleted child
    int key;
  };


  struct fib_heap {
    node* min;        // узел с минимальным корнем
    int roots_amount; // количество узлов
    bool isLess(node* first, node* second);      // указатель на функцию-компаратор

   public:
    node* add(int key);
    void union_fib_heap(fib_heap &fb);
   private:
    void add(node* newNode, node** sibl, node* par = NULL);
    bool union_root(node* newNode, int nodes_amount);


  };





  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
  inline constexpr auto kStringConstant = "Hello, stranger!";

  // Пример: объявление структуры с полями и методами
  struct MyStructure {
   public:
    int size_{0};
    int capacity_{0};
    int* data_{nullptr};

    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    int size() const {
      return size_;
    }
  };

}  // namespace itis