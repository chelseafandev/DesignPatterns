# DesignPatterns

- [DesignPatterns](#designpatterns)
  - [Creational Patterns](#creational-patterns)
    - [Singleton](#singleton)
    - [Abstract Factory](#abstract-factory)

<br>

## Creational Patterns
생성 패턴은 다양한 객체 생성 메커니즘을 제공하며 이를 통해 코드에 유연성을 더하고 기존 코드를 재사용하게 해줍니다.
> Creational patterns provide various object creation mechanisms, which increase flexibility and reuse of existing code.

### Singleton

[소스 코드로 이동](https://github.com/chelseafandev/DesignPatterns/blob/main/singleton.cpp)

싱글톤 패턴은 당신에게 이 클래스는 오직 한개의 인스턴스만을 가지며, 이 인스턴스에대한 전역적인 접근 방식을 제공한다는 사실을 보장해주는 생성과 관련된 디자인 패턴입니다.
> **Singleton** is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access point to this instance.

> The Singleton pattern solves two problems at the same time, violating the Single Responsibility Principle:
> 1. Ensure that a class has just a single instance.
> 2. Provide a global access point to that instance.

<br>

싱글톤 패턴을 구현하는 모든 방식에서 아래 2가지 과정은 공통적으로 포함됩니다.
> All implementations of the Singleton have these two steps in common:

* 싱글톤 클래스를 new 연산자를 사용하여 객체화하는 것을 막기 위해 **디폴트 생성자를 private으로 만들자**
* 생성자 역할을 하는 static 메소드를 만들자. 이 static 메소드 내부에서는 싱글톤 클래스의 객체를 생성하기 위한 private 생성자를 호출하고 이것을 static 필드에 저장합니다. 추가적으로 호출되는 해당 메소드는 이미 저장된(cached) 객체를 반환하게 됩니다.
> * Make the default constructor private, to prevent other objects from using the new operator with the Singleton class.
> * Create a static creation method that acts as a constructor. Under the hood, this method calls the private constructor to create an object and saves it in a static field. All following calls to this method return the cached object.

<br>

**reference**
- https://refactoring.guru/design-patterns/singleton
- https://refactoring.guru/design-patterns/singleton/cpp/example#example-1

<br>

### Abstract Factory

[소스 코드로 이동](https://github.com/chelseafandev/DesignPatterns/blob/main/abstractfactory.cpp)

추상 팩토리 패턴은 당신에게 객체들의 구현 클래스들을 구체적으로 명시하지 않으면서도 연관된 객체들의 집합을 제공하는 생성과 관련된 디자인 패턴입니다.
> **Abstract Factory** is a creational design pattern that lets you produce families of related objects without specifying their concrete classes.

<br>

추상 팩토리 패턴에서는 아래 4가지 정도를 제안하고 있습니다.

1. 제품 집합에 속한 각각의 제품에 대한 인터페이스를 선언하자. 그러면 당신은 이 인터페이스를 규칙을 따르는 제품의 모든 변형들을 만들어낼 수 있습니다.
2. 추상 팩토리 인터페이스를 선언하자. 여기서 추상 팩토리란 제품 집합에 속한 모든 제품에 대한 생성 메소드의 목록을 가진 인터페이스 입니다. 생성 메소드들은 반드시 1번에서 언급했던 추상 제품 타입(이 인터페이스를 바탕으로 구현된 구체적인 제품 타입이 아닌)을 반환해야합니다.
3. 이번엔 단일 제품이 아닌 제품 집합의 각각의 변형에 대해 2번에서 언급한 추상 팩토리 인터페이스를 기반으로한 팩토리 클래스를 생성합니다. 이 팩토리 클래스는 해당 제품 집합에 속한 특정 타입의 제품을 반환하게됩니다.
4. 어플리케이션(3번의 팩토리 클래스를 사용하는 주체)에서는 반드시 팩토리 타입을 선택해야합니다.
> 1. Declare **interfaces for each distinct product** of the product family explicitly. Then you can make all variants of products follow those interfaces.
> 2. Declare the Abstract Factory — an **interface with a list of creation methods for all products** that are part of the product family. These methods must return **abstract product** types represented by the interfaces we extracted previously.
> 3. For each variant of a product family, we create a **separate factory class** based on the AbstractFactory interface. A factory is a class that returns products of a **particular kind**.
> 4. The application must select the factory type.

<br>

**reference**
- https://refactoring.guru/design-patterns/abstract-factory