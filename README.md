# DesignPatterns

- [DesignPatterns](#designpatterns)
  - [Creational Patterns](#creational-patterns)
    - [Singleton](#singleton)
    - [Abstract Factory](#abstract-factory)
  - [Behavioral Patterns](#behavioral-patterns)
    - [State](#state)

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

<br>
<br>

## Behavioral Patterns
행위 디자인 패턴은 객체 간의 책임 할당과 알고리즘에 관련된 패턴입니다.
> Behavioral design patterns are concerned with algorithms and the assignment of responsibilities between objects.

### State

[소스 코드로 이동]()

상태 패턴은 객체의 내부 상태가 변경될 때 그것(object)이 행위를 변경하도록 하는 행위 디자인 패턴입니다. 이것은 마치 객체가 클래스를 변경한 것처럼 보입니다.
> State is a behavioral design pattern that lets an object alter its behavior when its internal state changes. It appears as if the object changed its class.

<br>

상태 패턴은 [유한 상태 기계(Finite-State Machine)]()의 개념과 밀접하게 연관되어있습니다.
> The State pattern is closely related to the concept of a Finite-State Machine.

어떠한 순간이든 프로그램이 위치할 수 있는 유한한 개수의 상태가 존재한다라는 것이 유한 상태 기계의 주요한 아이디어입니다. 고유 상태에 따라 프로그램은 각기 다르게 동작하며, 하나의 상태에서 또 다른 상태로 즉시 이동될 수 있습니디. 하지만 현재 어떠한 상태에 있는지에 따라 특정 상태로의 전이가 불가할 수 도 있습니다. 이러한 상태 간의 전이 규칙(transition)들 또한 유한하며 미리 결정되어집니다.
> The main idea is that, at any given moment, there’s a finite number of states which a program can be in. Within any unique state, the program behaves differently, and the program can be switched from one state to another instantaneously. However, depending on a current state, the program may or may not switch to certain other states. These switching rules, called transitions, are also finite and predetermined.

<br>

상태 패턴은 존재할 수 있는 모든 객체의 상태들을 새로운 클래스들로 생성하고, 각각의 상태에 따른 행위들을 이 클래스들로부터 추출하도록 제안하고 있습니다.
> The State pattern suggests that you create new classes for all possible states of an object and extract all state-specific behaviors into these classes.

<br>

모든 행위들을 각자가 구현하는 대신에 context라고 불리는 원본 객체가 그것의 현재 상태를 나타내는 상태 객체의 레퍼런스(reference) 값을 저장하도록 하며, 상태와 관련된 모든 작업들을 해당 객체에게 위임합니다.
> Instead of implementing all behaviors on its own, the original object, called context, stores a reference to one of the state objects that represents its current state, and delegates all the state-related work to that object.

<br>

context를 또 다른 상태로 전이하기 위해서는 활성화된 상태 객체를 새로운 상태를 나타내는 또 다른 객체로 바꿔주어야합니다. 이것은 모든 상태 클래스들이 동일한 인터페이스를 구현하고, context 자체가 이러한 객체들과 함께 작동하는 경우에만 가능합니다.
> To transition the context into another state, replace the active state object with another object that represents that new state. This is possible only if all state classes follow the same interface and the context itself works with these objects through that interface.

<br>

아래 제시한 6가지 과정을 소스 코드 상에 주석으로 표시해 두었으니 참고하시기 바랍니다.

1. context 역할을 수행할 클래스를 결정하자. context 클래스는 상태 의존적인 코드를 포함하고 있는 이미 존재하는 클래스일 수도 있고, 만약 상태에 관련된 코드가 여러 클래스에 걸쳐 작성되어 있다면 아예 새로운 클래스를 context용으로 만들 수도 있습니다.
2. 상태 인터페이스를 선언하자. 비록 이 인터페이스는 context에 선언된 모든 메소드들을 반영할 수 있지만, 오직 상태에 관련된 행위를 포함하고있는 메소드들을 반영하는 것에 목표를 둡니다.
3. 실제 구현될 모든 상태에 대해서 상태 인터페이스를 상속받는 클래스를 생성하자. 그리고나서 context의 메소들을 조사하여 상태와 관련된 모든 코드를 상태 인터페이스를 상속받는 새로운 클래스에 포팅합니다.<br>
   상태 관련 코드를 상태 클래스로 옮기는 동안, 여러분은 그것들이 context의 private 멤버에 의존적이라는 사실을 발견할 수도 있습니다. 여기 몇가지 해결책이 있습니다.
    - 해당 필드와 메소드를 public으로 만들어라.
    - 여러분이 추출한 행위를 context의 public 메소드로 변경하고 해당 메소드를 상태 클래스에서 호출하도록 해라. 이 방법은 비록 깔끔하진않지만 빠르며, 추후 언제든지 이것을 수정할 수 있씁니다.
4. context 클래스 내에 상태 인터페이스 타입의 참조 변수를 추가하고 해당 변수를 변경할 수 있는 public setter 메소드를 추가하라.
5. context 클래스의 메소드들을 다시 조사하여 빈 상태 조건들과 해당 조건들에 상응하는 상태 객체의 호출을 서로 치환하라.
6. context의 상태를 변경하기 위해 상태 클래스들 중 하나의 인스턴스를 생성하여 context에게 전달하라. 여러분은 이 작업을 context 내에서 직접하거나 다양한 상태 클래스 혹은 클라이언트 내에서 수행할 수 있습니다. 작업을 수행하는 곳이 어디든지간에 해당 클래스는 인스턴스화된 상태 객체에 의존적이게 됩니다.
> 1. Decide what class will act as the context. It could be an existing class which already has the state-dependent code; or a new class, if the state-specific code is distributed across multiple classes.
> 2. Declare the state interface. Although it may mirror all the methods declared in the context, aim only for those that may contain state-specific behavior.
> 3. For every actual state, create a class that derives from the state interface. Then go over the methods of the context and extract all code related to that state into your newly created class.
>    While moving the code to the state class, you might discover that it depends on private members of the context. There are several workarounds:
>    - Make these fields or methods public.
>    - Turn the behavior you’re extracting into a public method in the context and call it from the state class. This way is ugly but quick, and you can always fix it later.
> 4. In the context class, add a reference field of the state interface type and a public setter that allows overriding the value of that field.
> 5. Go over the method of the context again and replace empty state conditionals with calls to corresponding methods of the state object.
> 6. To switch the state of the context, create an instance of one of the state classes and pass it to the context. You can do this within the context itself, or in various states, or in the client. Wherever this is done, the class becomes dependent on the concrete state class that it instantiates.

<br>

**reference**
- https://refactoring.guru/design-patterns/state
- https://refactoring.guru/design-patterns/state/java/example
- https://en.wikipedia.org/wiki/Finite-state_machine
- https://daru-daru.tistory.com/70