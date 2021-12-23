#pragma once

#include "context/player.h"

namespace dps
{
    // 2. 상태 인터페이스를 선언하자. 비록 이 인터페이스는 context에 선언된 모든 메소드들을 반영할 수 있지만, 오직 상태에 관련된 행위를 포함하고있는 메소드들을 반영하는 것에 목표를 둡니다.
    class state
    {
    public:
        state(player *p) : player_(p) {} // 생성자에 context 정보를 넘겨줌으로써 필요 시에 상태 객체가 context의 유용한 데이터를 가지고 올 수 있도록함
        virtual ~state() {}

        virtual void click_lock() = 0;
        virtual void click_play() = 0;
        virtual void click_next() = 0;
        virtual void click_previous() = 0;

    protected:
        player *player_; // 여러분이 추출한 행위를 context의 public 메소드로 변경하고 해당 메소드를 상태 클래스에서 호출하도록 해라. 이 방법은 비록 깔끔하진않지만 빠르며, 추후 언제든지 이것을 수정할 수 있씁니다.
    };
    ///////////////////////////////////////////////////////////////////////////////////

    // 3. 실제 구현될 모든 상태에 대해서 상태 인터페이스를 상속받는 클래스를 생성하자. 그리고나서 context의 메소들을 조사하여 상태와 관련된 모든 코드를 상태 인터페이스를 상속받는 새로운 클래스에 포팅합니다.
    class lock_state
        : public state
    {
    public:
        lock_state(player *p);
        ~lock_state();

        void click_lock() override;
        void click_play() override;
        void click_next() override;
        void click_previous() override;
    };

    class ready_state
        : public state
    {
    public:
        ready_state(player *p);
        ~ready_state();

        void click_lock() override;
        void click_play() override;
        void click_next() override;
        void click_previous() override;
    };

    class play_state
        : public state
    {
    public:
        play_state(player *p);
        ~play_state();

        void click_lock() override;
        void click_play() override;
        void click_next() override;
        void click_previous() override;
    };
    ///////////////////////////////////////////////////////////////////////////////////
}