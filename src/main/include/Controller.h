#pragma once

//map of buttons for joystick
namespace controller {
    constexpr int kLStickX = 0;
    constexpr int kLStickY = 1;

    constexpr int kRStickX = 4;
    constexpr int kRStickY = 5;

    constexpr int kLTrigger = 2;
    constexpr int kRTrigger = 3;

    constexpr int kAButton = 1;
    constexpr int kBButton = 2;
    constexpr int kXButton = 3;
    constexpr int kYButton = 4;

    //buttons marked LB and RB on top of controller
    constexpr int kL1Button = 5;
    constexpr int kR1Button = 6;

    constexpr int kBackButton = 7;
    constexpr int kStartButton = 8;

    //Pressing the joysticks; AKA L3 and R3
    constexpr int kPressLJoystick = 9;
    constexpr int kPressRJoystick = 10;
}