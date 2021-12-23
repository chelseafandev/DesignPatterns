#include "player.h"
#include "states/state.h" // 상호 참조를 피하기위해서 .cpp에서 state.h를 선언하여 사용함

dps::player::player()
{
    // context의 상태를 변경하기 위해 상태 클래스들 중 하나의 인스턴스를 생성하여 context에게 전달하라.
    // 여러분은 이 작업을 context 내에서 직접하거나 다양한 상태 클래스 혹은 클라이언트 내에서 수행할 수 있습니다. 작업을 수행하는 곳이 어디든지간에 해당 클래스는 인스턴스화된 상태 객체에 의존적이게 됩니다.
    state_ = new dps::ready_state(this);

    is_play_ = true;
    current_track_ = 0;

    for (int i = 1; i <= 12; i++)
    {
        std::string track = "track ";
        track += std::to_string(i);
        playlist_.push_back(track);
    }
}

dps::player::~player()
{

}

void dps::player::lock()
{
    if(state_ == nullptr)
    {
        return;
    }

    state_->click_lock();
}

void dps::player::play()
{
    if(state_ == nullptr)
    {
        return;
    }

    state_->click_play();
}

void dps::player::next()
{
    if(state_ == nullptr)
    {
        return;
    }

    state_->click_next();
}

void dps::player::previous()
{
    if(state_ == nullptr)
    {
        return;
    }

    state_->click_previous();
}

void dps::player::change_state(dps::state *new_state)
{
    state_ = new_state;
}

void dps::player::set_playing(bool val)
{
    is_play_ = val;
}

bool dps::player::is_playing()
{
    return is_play_;
}

void dps::player::start_playback()
{
    std::cout << "playing " << playlist_.at(current_track_) << std::endl;
}

void dps::player::next_track()
{
    current_track_++;
    if (current_track_ > playlist_.size() - 1)
    {
        current_track_ = 0;
    }

    std::cout << "playing " + playlist_.at(current_track_) << std::endl;
}

void dps::player::previous_track()
{
    current_track_--;
    if (current_track_ < 0)
    {
        current_track_ = playlist_.size() - 1;
    }

    std::cout << "playing " + playlist_.at(current_track_) << std::endl;
}

void dps::player::set_current_track_after_stop()
{
    current_track_ = 0;
}