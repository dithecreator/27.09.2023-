#include <iostream>
using namespace std;


struct Element
{
  // Данные
  char data;
  // Адрес следующего элемента списка
  Element* Next;
};

// Односвязный список
class List
{
  // Адрес головного элемента списка
  Element* Head;
  // Адрес головного элемента списка
  Element* Tail;
  // Количество элементов списка
  int Count;

public:
  // Конструктор
  List();
  // Деструктор
  ~List();

  // Добавление элемента в список
  // (Новый элемент становится последним)
  void Add(char data);

  // Удаление элемента списка
  // (Удаляется головной элемент)
  void Del();
  // Удаление всего списка
  void DelAll();

  // Распечатка содержимого списка
  // (Распечатка начинается с головного элемента)
  void Print();

  // Получение количества элементов, находящихся в списке
  int GetCount();
  void InsertElement(char data, int p);
  void DelByPosition(int p);
  int FinfEl();
    void insert(char data, int pos);
    void deleteElement(int pos);
    char findbypos(int pos);
};

List::List()
{
  // Изначально список пуст
  Head = Tail = NULL;
  Count = 0;
}

List::~List()
{
  // Вызов функции удаления
  DelAll();
}

int List::GetCount()
{
  // Возвращаем количество элементов
  return Count;
}


void List::insert(char data, int pos) {
    Element* newElement = new Element;
    newElement->data = data;

    if (pos == 0) {
        newElement->Next = Head;
        Head = newElement;
    }
    
    else{
        Element* current = Head;
        int currentPosition = 0;

        while (current != NULL && currentPosition < pos - 1){
            current = current->Next;
            currentPosition++;
        }

        if (current == NULL) {
  
            current->Next = newElement;
            
        }
        else {
            newElement->Next = current->Next;
            current->Next = newElement;
        }
    }
}

void List:: deleteElement(int pos){
    
}

void List::DelByPosition(int p)
{

    Element* temp = Head;
    while (p >= 0) {
      temp = temp->Next;
      p--;
    }
    Element* del = temp -> Next;
    temp -> Next = del ->  Next;
    delete del;
    cout << "Temp->Data: " << temp->data << endl;
}
char List:: findbypos(int pos){
    
    Element* temp = Head;
    char result;
    for(int i = 0; temp != NULL; i++){
        if(i == pos){
            result = temp -> data;
            break;
        }
        temp = temp -> Next;
    }
    return result;
    
    
    
}



void List::Add(char data)
{
  // создание нового элемента
  Element* temp = new Element;

  // заполнение данными
  temp->data = data;
  // следующий элемент отсутствует
  temp->Next = NULL;
  // новый элемент становится последним элементом списка
  // если он не первый добавленный
  if (Head != NULL) {
    Tail->Next = temp;
    Tail = temp;
  }
  // новый элемент становится единственным
  // если он первый добавленный
  else {
    Head = Tail = temp;
  }
}

void List::Del()
{
  // запоминаем адрес головного элемента
  Element* temp = Head;
  // перебрасываем голову на следующий элемент
  Head = Head->Next;
  // удаляем бывший головной элемент
  delete temp;
}

void List::DelAll()
{
  // Пока еще есть элементы
  while (Head != 0)
    // Удаляем элементы по одному
    Del();
}

void List::Print()
{
  // запоминаем адрес головного элемента
  Element* temp = Head;
  // Пока еще есть элементы
  while (temp != 0)
  {
    // Выводим данные
    cout << temp->data << " ";
    // Переходим на следующий элемент
    temp = temp->Next;
  }

  cout << "\n\n";
}

// Тестовый пример
int main()
{
  // Создаем объект класса List
  List lst;

  // Тестовая строка
  char s[] = "Hello, World !!!\n";
  // Выводим строку
  cout << s << "\n\n";
  // Определяем длину строки
  int len = strlen(s);
  // Загоняем строку в список
  for (int i = 0; i < len; i++)
    lst.Add(s[i]);
  // Распечатываем содержимое списка
  lst.Print();
  // Удаляем три элемента списка
  
  //Распечатываем содержимое списка
  lst.Print();
    char dat = 'c';
    int pos = 5;
    lst.insert(dat, pos);
    lst.Print();
  lst.DelByPosition(2);
    lst.Print();
    char a = lst.findbypos(5);
    cout << "A: " << a << endl;
}
