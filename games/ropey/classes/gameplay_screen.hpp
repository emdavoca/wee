#pragma once

#include <Box2D/Box2D.h>
#include <SDL.h>
#include <core/vec2.hpp>
#include <engine/ecs.hpp>
#include <engine/b2DebugDrawImpl.hpp>
#include <engine/b2ContactListenerImpl.hpp>
#include <engine/camera.hpp>
#include <engine/gui/gamescreen.hpp>
#include <classes/common.hpp>

namespace wee {
    struct application;
}

class gameplay_screen : public wee::gamescreen {
    b2World* _world;
    bool _mousedown = false;
    int _time_down = 0;
    SDL_Rect _camera;
    entity_type b0, p, b1;
    size_t _current_beat_idx;
    entity_type _lastBeatTouched;
    kult::type _rope;
    wee::b2DebugDrawImpl _debugdraw;
    wee::camera _cam;
    wee::b2ContactListenerImpl _contacts;
    bool _spawnedNextBeat = false;
    std::vector<entity_type> _beats;
protected:
    void _restart();

public:
    gameplay_screen();
    virtual ~gameplay_screen();
    virtual void load_content();
    virtual void handle_input();
    virtual void update(int, bool, bool);
    virtual void draw(SDL_Renderer*);
public:
    int on_click() ;
};
