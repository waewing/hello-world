#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

namespace ds{

template <class T>
class Integer
{
  private:
  
  int value;
  
  public:
  
    Integer() : value=0 {}
  
    Integer(int amount)
      {
        static_cast<Integer>(amount);
      }
  
    Integer(string amount2)
      {
        int tmp = stoi(amount2)
        if(tmp%1 = 0)
        {
         static_cast<Integer>(amount2); 
        }
        else
        {
         static_cast<Integer>(amount2) = 0; 
        }
      }

    Integer(const Integer<T>& obj)
      {
        value = obj.value;
      }

    Integer& operator=(const Integer<T>& rhs)
      {
        if(this != &rhs)
          {
            value = rhs.value;
          }
        return *this;
      }

    ~Integer()
      {
        delete[] value;
      }
  
     string ToString() const
      {
        std::stringstream out;
        out << value;
        return out.str(); 
      }
  
    friend ostream& operator<<(ostream& out,const Integer<T>& obj)
      {
        out << obj.ToString();
        return out;
      }
      
    friend Integer& operator>(const Integer<T>& rhs)
      {
        if(this != &rhs)
          {
            value = rhs.value;
          }
        return *this;
      }
      
    friend Integer& operator<(const Integer<T>& rhs)
      {
        if(this != &rhs)
          {
            value = rhs.value;
          }
        return *this;
      }
      
      friend Integer& operator>=(const Integer<T>& rhs)
      {
        if(this != &rhs)
          {
            value = rhs.value;
          }
        return *this;
      }
      
    friend Integer& operator<=(const Integer<T>& rhs)
      {
        if(this != &rhs)
          {
            value = rhs.value;
          }
        return *this;
      }
      
    friend Integer& operator==(const Integer<T>& rhs)
      {
        if(this != &rhs)
          {
            value = rhs.value;
          }
        return *this;
      }
       
       friend Integer& operator+(const Integer<T>& rhs)
      {
        if(this != &rhs)
          {
            value = rhs.value;
          }
        return *this;
      }
      
    friend Integer& operator-(const Integer<T>& rhs)
      {
        if(this != &rhs)
          {
            value = rhs.value;
          }
        return *this;
      }
  
  
};

}

