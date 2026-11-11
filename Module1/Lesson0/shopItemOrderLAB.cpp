#include <iostream>
#include <string>

using namespace std;

class ShopItemOrder

{
public:
  ShopItemOrder();

  void set_name(string name);
  void set_price(double price);
  void set_numberOrdered(int numberOrdered);

  string get_name() {return name;}
  double get_price() {return price;}
  int get_numberOrdered() {return numberOrdered;}
  double get_total_price();
  
  private:
  string name;
  int price;
  int numberOrdered;
};

void ShopItemOrder::set_name(string name){
  this->name = name;
}

void ShopItemOrder::set_price(double price){
  this->price = price;
}

void ShopItemOrder::set_numberOrdered(int numberOrdered){
  this->numberOrdered = numberOrdered;
}

double ShopItemOrder::get_total_price(){
  return price * numberOrdered;
}

ShopItemOrder::ShopItemOrder(){}

// code from answer to test
int main()
{
  ShopItemOrder orderTShirts;
  ShopItemOrder orderJeans;

  orderTShirts.set_name("T-shirt mens black size M");
  orderTShirts.set_price(23.4);
  orderTShirts.set_numberOrdered(3);

  orderJeans.set_name("Jeans mens blue size M");
  orderJeans.set_price(42.2);
  orderJeans.set_numberOrdered(2);

  std::cout << orderTShirts.get_numberOrdered() << " x \""
            << orderTShirts.get_name() << "\" = "
            << orderTShirts.get_total_price() << std::endl;

  std::cout << orderJeans.get_numberOrdered() << " x \""
            << orderJeans.get_name() << "\" = "
            << orderJeans.get_total_price() << std::endl;
  return 0;
}