#include <iostream>

#include "state.h"

dps::lock_state::lock_state(dps::player *p) : dps::state(p)
{
    player_->set_playing(false);
}

dps::lock_state::~lock_state()
{

}

void dps::lock_state::click_lock()
{
    if (player_->is_playing())
    {
        player_->change_state(new dps::ready_state(player_));
        std::cout << "stop playing" << std::endl;
    }
    else
    {
        std::cout << "locked..." << std::endl;
    }
}

void dps::lock_state::click_play()
{
    player_->change_state(new dps::ready_state(player_));
    std::cout << "ready" << std::endl;
}

void dps::lock_state::click_next()
{
    std::cout << "locked..." << std::endl;
}

void dps::lock_state::click_previous()
{
    std::cout << "locked..." << std::endl;
}

dps::ready_state::ready_state(dps::player *p) : dps::state(p)
{

}

dps::ready_state::~ready_state()
{

}

void dps::ready_state::click_lock()
{
    player_->change_state(new dps::lock_state(player_));
    std::cout << "locked..." << std::endl;
}

void dps::ready_state::click_play()
{
    player_->start_playback();
    player_->change_state(new dps::play_state(player_));
}

void dps::ready_state::click_next()
{
    std::cout << "locked..." << std::endl;
}

void dps::ready_state::click_previous()
{
    std::cout << "locked..." << std::endl;
}

dps::play_state::play_state(dps::player *p) : dps::state(p)
{

}

dps::play_state::~play_state()
{

}

void dps::play_state::click_lock()
{
    player_->change_state(new dps::lock_state(player_));
    player_->set_current_track_after_stop();
    std::cout << "stop playing" << std::endl;
}

void dps::play_state::click_play()
{
    player_->change_state(new ready_state(player_));
    std::cout << "paused..." << std::endl;
}

void dps::play_state::click_next()
{
    player_->next_track();
}

void dps::play_state::click_previous()
{
    player_->previous_track();
}