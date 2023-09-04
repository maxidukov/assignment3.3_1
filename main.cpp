#include <iostream>

class Calculator{
   double num1;
   double num2;
   double add(){
     return num1+num2;
   }
   //public:
   double multiply(){
     return num1*num2;
   }
   double subtract_1_2(){
     return num1-num2;
   }
   double subtract_2_1(){
     return num2-num1;
   }
   double divide_1_2(){
     return num1/num2;
   }
   double divide_2_1(){
     return num2/num1;
   }
   double (Calculator::*ffs[6])() = { //C-STYLE ARRAY OF POINTERS TO METHOD
     &Calculator::add,
     &Calculator::subtract_1_2, &Calculator::subtract_2_1,
     &Calculator::multiply,
     &Calculator::divide_1_2, &Calculator::divide_2_1,
   };
   char signs[7] = "+--*//";
   bool set_num1(double num1){
     if(num1){
        this->num1 = num1;
        return true;
     }else{
       return false;
     }
   }
   bool set_num2(double num2){
     if(num2){
        this->num2 = num2;
        return true;
     }else{
       return false;
     }
   }
   public:
   void turn_on(){
     while(1){
       double n1, n2;
       while(1){
         std::cout<<"Введите num1: ";
         std::cin>>n1;
         if(set_num1(n1)){
            break;
         }
         std::cout<<"Неверный ввод!\n";
       }
       while(1){
         std::cout<<"Введите num2: ";
         std::cin>>n2;
         if(set_num2(n2)){
            break;
         }
         std::cout<<"Неверный ввод!\n";
       }
       for(int i{};i<6;i++){
         char str[] = "num1   num2 = ";
         if(i==2||i==5){
           str[3] = '2';
           str[10] = '1';
         }
         str[5] = signs[i];
         std::cout<<str<<(this->*ffs[i])()<<"\n";
       }
     }
   }
};

int main() {
  Calculator my_calculator;
  my_calculator.turn_on();
}
