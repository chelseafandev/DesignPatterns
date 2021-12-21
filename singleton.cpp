/*
singleton 패턴 구성 방법
  1. 디폴트 생성자를 private로 선언하여 클래스 외부에서는 생성자가 호출되지않도록 막는다.
  2. 복사 생성자를 삭제(delete) 해준다.
  3. 대입 연산자를 삭제(delete) 해준다.
  4. 생성자 역할을 해줄 static 함수(상세구현은 소스 코드를 통해 확인)를 public으로 선언한다. 구현은 class 외부에서 해야한다.
*/

#include <iostream>
#include <mutex>

class my_singleton
{
public:
    // 생성자 역할을 해줄 static 함수를 생성한다.
    static my_singleton* get_instance();

    // 복사생성자를 delete 해준다.
    my_singleton(my_singleton& other) = delete;

    // 대입연산자를 delete 해준다.
    void operator=(const my_singleton& other) = delete;

private:
    // 디폴트 생성자를 private로 선언한다.
    my_singleton()
    {
        
    }

    ~my_singleton()
    {

    }

    static my_singleton* instance_ptr_;
    static std::mutex mutex_; // get_instance() 함수를 thread-safe하게 만들기위해 mutex를 사용함
};

my_singleton* my_singleton::instance_ptr_ = nullptr;
std::mutex my_singleton::mutex_;

my_singleton* my_singleton::get_instance()
{
    // The class lock_guard is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex for the duration of a scoped block.
    std::lock_guard<std::mutex> lock(mutex_);
    if(my_singleton::instance_ptr_ == nullptr)
    {
        // my_singleton 클래스의 static 멤버 함수인 get_instance 함수 안에서는 my_singleton 생성자 호출이 가능함
        my_singleton::instance_ptr_ = new my_singleton();
    }

    return my_singleton::instance_ptr_;
}

class non_singleton
{
public:
    non_singleton()
    {

    }

    ~non_singleton()
    {

    }

private:

};

int main()
{ 
    // my_singleton* mys = new my_singleton(); // error! my_singleton 클래스의 생성자가 private으로 정의되어있기 때문에

    my_singleton* mys1 = my_singleton::get_instance();
    my_singleton* mys2 = my_singleton::get_instance();
    std::cout << "1st singleton object address: " << mys1 << std::endl;
    std::cout << "2nd singleton object address: " << mys2 << std::endl;

    non_singleton* nos1 = new non_singleton();
    non_singleton* nos2 = new non_singleton();
    std::cout << "1st non-singleton object address: " << nos1 << std::endl;
    std::cout << "2nd non-singleton object address: " << nos2 << std::endl;

    return 0;
}
