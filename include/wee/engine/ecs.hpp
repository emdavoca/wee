#pragma once

#include <kult/kult.hpp>
#include <Box2D/Box2D.h>
#include <engine/easing.hpp>
#include <core/vec2.hpp>
#include <SDL.h>
#include <iostream>

namespace wee {


    typedef kult::type entity_t;
    struct collision {
        entity_t self;
        entity_t other;
        vec2f point;
        vec2f n;
    };
    typedef std::function<void(const collision&)> collision_callback;

    typedef struct {
        b2Body* body    = nullptr;
        bool do_cleanup = false;

        collision_callback on_collision_enter = nullptr;
        collision_callback on_collision_leave = nullptr;
        collision_callback on_trigger_enter = nullptr;
        collision_callback on_trigger_leave = nullptr;
    } physics_t;

    typedef  struct {
        vec2f position;
        float rotation;
    } transform_t;

    typedef struct {
        SDL_Texture*        texture;
        SDL_Rect            src;
        SDL_Color           color;
        SDL_RendererFlip    flip = SDL_FLIP_NONE;
    } visual_t;

    typedef struct {
        vec2f    offset;
        float    rotation;
        entity_t parent;
    } nested_t;

    
    typedef struct {
        float* dst;
        std::function<float(float)> easing_fn;
    } tween_t;

    typedef struct {
        int time;
        int timeout;
        std::function<void(const entity_t&)> on_timeout = nullptr;
    } timeout_t;

    typedef struct {
        bool  hit;
        vec2f point;
        vec2f n; // normal
        float d; // length of fraction
    } raycast_t;


    typedef struct {
        b2Joint* joint;
        //bool do_cleanup;
    } joint_t;
    
    std::ostream& operator << (std::ostream&, const physics_t&);
    std::ostream& operator << (std::ostream&, const transform_t&);
    std::ostream& operator << (std::ostream&, const visual_t&);
    std::ostream& operator << (std::ostream&, const nested_t&);
    std::ostream& operator << (std::ostream&, const tween_t&);
    std::ostream& operator << (std::ostream&, const timeout_t&);
    std::ostream& operator << (std::ostream&, const raycast_t&);
    std::ostream& operator << (std::ostream&, const joint_t&);
    

    using physics   = kult::component<1,  physics_t>;
    using transform = kult::component<2,transform_t>;
    using visual    = kult::component<3,   visual_t>;
    using nested    = kult::component<4,   nested_t>;
    using tween     = kult::component<5,    tween_t>;
    using timeout   = kult::component<6,  timeout_t>;
    using raycast   = kult::component<7,  raycast_t>;
    using joint     = kult::component<8,   joint_t>;



}
