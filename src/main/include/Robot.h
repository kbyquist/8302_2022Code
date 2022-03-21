// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>
#include "drive.h"
#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include "Controller.h"
#include "pneumatics.h"
#include <frc/Timer.h>
#include <units/time.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:

  Drive drivebase{};
  Pneumatics pneumatics{};
  
  frc::Timer autoTimer;

  frc::Joystick driver_joy{0};
  frc::Joystick operator_joy{1};
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Do Not Move";
  const std::string kAutoNameCustom = "Go Forward";
  const std::string kAutoNameCustom2 = "Release 1 Cargo, then move";
  std::string m_autoSelected;
};
