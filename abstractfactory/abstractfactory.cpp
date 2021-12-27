#include <iostream>


// 1. 제품 집합에 속한 각각의 제품에 대한 인터페이스를 선언하자. 그러면 당신은 이 인터페이스를 규칙을 따르는 제품의 모든 변형들을 만들어낼 수 있습니다.
class button
{
public:
    virtual ~button() {} // 부모클래스의 소멸자는 항상 virtual로 선언하는 습관을 들이자

    virtual void paint() = 0; // 순수 가상 함수를 포함하는 클래스는 추상 클래스(인터페이스)
};

class window_button 
    : public button
{
public:
    void paint() override
    {
        std::cout << "paint window button" << std::endl;
    }
};

class mac_button
    : public button
{
public:
    void paint() override
    {
        std::cout << "paint mac button" << std::endl;
    }
};
///////////////////////////////////////////////////////////////////////////////////

// 1. 제품 집합에 속한 각각의 제품에 대한 인터페이스를 선언하자. 그러면 당신은 이 인터페이스를 규칙을 따르는 제품의 모든 변형들을 만들어낼 수 있습니다.
class checkbox
{
public:
    virtual ~checkbox() {}
    virtual void paint() = 0;
};

class window_checkbox
    : public checkbox
{
public:
    void paint() override
    {
        std::cout << "paint window checkbox" << std::endl;
    }
};

class mac_checkbox
    : public checkbox
{
public:
    void paint() override
    {
        std::cout << "paint mac checkbox" << std::endl;
    }
};
///////////////////////////////////////////////////////////////////////////////////

// 2. 추상 팩토리 인터페이스를 선언하자. 여기서 추상 팩토리란 제품 집합에 속한 모든 제품에 대한 생성 메소드의 목록을 가진 인터페이스 입니다. 생성 메소드들은 반드시 1번에서 언급했던 추상 제품 타입(이 인터페이스를 바탕으로 구현된 구체적인 제품 타입이 아닌)을 반환해야합니다.
class guid_factory
{
public:
    virtual ~guid_factory() {}

    virtual button* create_button() = 0;
    virtual checkbox* create_checkbox() = 0;
};
///////////////////////////////////////////////////////////////////////////////////

// 3. 이번엔 단일 제품이 아닌 제품 집합의 각각의 변형에 대해 2번에서 언급한 추상 팩토리 인터페이스를 기반으로한 팩토리 클래스를 생성합니다. 이 팩토리 클래스는 해당 제품 집합에 속한 특정 타입의 제품을 반환하게됩니다.
class window_guid_factory
    : public guid_factory
{
public:
    // 추상 클래스의 포인터 형식으로의 반환은 가능함
    button* create_button() override
    {
        // 반환 타입은 인터페이스이고 실제 생성하는 객체는 인터페이스를 기반으로 한 구현 클래스
        return new window_button();
    }

    checkbox* create_checkbox() override
    {
        return new window_checkbox();
    }
};

class mac_guid_factory
    : public guid_factory
{
public:
    button* create_button() override
    {
        return new mac_button();
    }

    checkbox* create_checkbox() override
    {
        return new mac_checkbox();
    }
};
///////////////////////////////////////////////////////////////////////////////////

// 4. 어플리케이션(3번의 팩토리 클래스를 사용하는 주체)에서는 반드시 팩토리 타입을 선택해야합니다.
class application
{
public:
    // 생성자의 인자(type)를 통해 생성할 팩토리 타입을 전달받는다
    application(std::string type)
    {
        if(type.compare("window") == 0)
        {
            factory_ = new window_guid_factory();
        }
        else if(type.compare("mac") == 0)
        {
            factory_ = new mac_guid_factory();
        }
        else
        {
            factory_ = nullptr;
        }
    }

    ~application()
    {
        if(factory_ != nullptr)
        {
            delete factory_;
            factory_ = nullptr;
        }

        if(button_ != nullptr)
        {
            delete button_;
            button_ = nullptr;
        }

        if(checkbox_ != nullptr)
        {
            delete checkbox_;
            checkbox_ = nullptr;
        }
    }

    void create_ui()
    {
        if(factory_ == nullptr)
        {
            return;
        }

        button_ = factory_->create_button();
        checkbox_ = factory_->create_checkbox();
    }

    void paint_button()
    {
        if(checkbox_ == nullptr)
        {
            return;
        }

        button_->paint();
    }

    void paint_checkout()
    {
        if(checkbox_ == nullptr)
        {
            return;
        }

        checkbox_->paint();
    }

private:
    guid_factory* factory_;
    button* button_;
    checkbox* checkbox_;
};
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    application ap_mac("mac");
    ap_mac.create_ui();
    ap_mac.paint_button();
    ap_mac.paint_checkout();
    
    application ap_window("window");
    ap_window.create_ui();
    ap_window.paint_button();
    ap_window.paint_checkout();

    return 0;
}