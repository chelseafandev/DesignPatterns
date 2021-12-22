# DesignPatterns

## Creational Patterns
### Singleton

[소스 코드로 이동](https://github.com/chelseafandev/DesignPatterns/blob/main/singleton.cpp)

싱글톤 패턴은 당신에게 이 클래스는 오직 한개의 인스턴스만을 가지며, 이 인스턴스에대한 전역적인 접근 방식을 제공한다는 사실을 보장해주는 생성과 관련된 디자인 패턴입니다.
> **Singleton** is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access point to this instance.

> The Singleton pattern solves two problems at the same time, violating the Single Responsibility Principle:
> 1. Ensure that a class has just a single instance.
> 2. Provide a global access point to that instance.

싱글톤 패턴을 구현하는 모든 방식에서 아래 2가지 과정은 공통적으로 포함됩니다.
> All implementations of the Singleton have these two steps in common:

* 싱글톤 클래스를 new 연산자를 사용하여 객체화하는 것을 막기 위해 **디폴트 생성자를 private으로 만들자**
* 생성자 역할을 하는 static 메소드를 만들자. 이 static 메소드 내부에서는 싱글톤 클래스의 객체를 생성하기 위한 private 생성자를 호출하고 이것을 static 필드에 저장합니다. 추가적으로 호출되는 해당 메소드는 이미 저장된(cached) 객체를 반환하게 됩니다.
> * Make the default constructor private, to prevent other objects from using the new operator with the Singleton class.
> * Create a static creation method that acts as a constructor. Under the hood, this method calls the private constructor to create an object and saves it in a static field. All following calls to this method return the cached object.

**reference**
- https://refactoring.guru/design-patterns/singleton
- https://refactoring.guru/design-patterns/singleton/cpp/example#example-1

<br>