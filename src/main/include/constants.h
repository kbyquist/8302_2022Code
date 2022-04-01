#pragma once
#include <frc/DoubleSolenoid.h>

namespace motors{
    constexpr int kRightLeadDriveMotorID = 1;
    constexpr int kRightFollowDriveMotorID = 2;
    constexpr int kLeftLeadDriveMotorID = 3;
    constexpr int kLeftFollowDriveMotorID = 4;
}

namespace drive{
    constexpr bool kLeftInverted = false;
    constexpr bool kRightInverted = true;
    constexpr int kCurrentLimit = 125;
}

namespace pneumatics{
    constexpr int kPCMID = 10;
    constexpr int kStabilizerInID = 0;
    constexpr int kStabilizerOutID = 1;
    constexpr int kDoorInID = 2;
    constexpr int kDoorOutID = 3;

    constexpr frc::DoubleSolenoid::Value kStabilize = frc::DoubleSolenoid::kForward;
    constexpr frc::DoubleSolenoid::Value kRetractStabilize = frc::DoubleSolenoid::kReverse;

    constexpr frc::DoubleSolenoid::Value kDoorDown = frc::DoubleSolenoid::kForward;
    constexpr frc::DoubleSolenoid::Value kDoorUp = frc::DoubleSolenoid::kReverse;
}