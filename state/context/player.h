#pragma once

#include <iostream>
#include <vector>

namespace dps
{
    // state 클래스를 전방선언하여 player와 state 클래스간의 상호 참조를 피함
    class state;
    
    // 1. context 역할을 수행할 클래스를 결정하자. context 클래스는 상태 의존적인 코드를 포함하고 있는 이미 존재하는 클래스일 수도 있고, 만약 상태에 관련된 코드가 여러 클래스에 걸쳐 작성되어 있다면 아예 새로운 클래스를 context용으로 만들 수도 있습니다.
    class player
    {
    public:
        player();
        ~player();

        // 5. context 클래스의 메소드들을 다시 조사하여 빈 상태 조건들과 해당 조건들에 상응하는 상태 객체의 호출을 서로 치환하라.
        void lock();
        void play();
        void next();
        void previous();
        /////////////////////////////////
        
        void change_state(state *new_state); // 4. context 클래스 내에 상태 인터페이스 타입의 참조 변수를 추가하고 해당 변수를 변경할 수 있는 public setter 메소드를 추가하라.
        void set_playing(bool val);
        bool is_playing();
        void start_playback();
        void next_track();
        void previous_track();
        void set_current_track_after_stop();

    private:
        state* state_; // 4. context 클래스 내에 상태 인터페이스 타입의 참조 변수를 추가하고 해당 변수를 변경할 수 있는 public setter 메소드를 추가하라.
        bool is_play_;
        int current_track_;

        std::vector<std::string> playlist_;
    };
}