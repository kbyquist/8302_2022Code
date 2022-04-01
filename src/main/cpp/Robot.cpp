// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>

using namespace frc;

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAuto1, kAuto1);
  m_chooser.AddOption(kAuto2, kAuto2);
  m_chooser.AddOption(kAuto3, kAuto3);
  Shuffleboard::GetTab("Auto Selections")
    .Add("Auto Mode", m_chooser)
    .WithSize(2,1)
    .WithPosition(0,0)
    .WithWidget(BuiltInWidgets::kComboBoxChooser);

  drivebase.RobotInit();
  pneumatics.RobotInit();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  //fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAuto2) {
    autoTimer.Reset();
    autoTimer.Start();
  } else if (m_autoSelected == kAuto3) {
    autoTimer.Reset();
    autoTimer.Start();
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAuto2) {
    if (autoTimer.Get() < 3_s) {
      drivebase.arrowDriveAccel(-.75,0,1);
    } else {
      drivebase.arrowDriveAccel(0,0,1);
    }
  } else if (m_autoSelected == kAuto3) {
    if (autoTimer.Get() <= 3_s) {
      drivebase.arrowDriveAccel(0,0,1);
      pneumatics.CargoDoorDown();
    } else if (autoTimer.Get() > 3_s && autoTimer.Get() < 8_s) {
      drivebase.arrowDriveAccel(-.75,0,1);
    } else {
      drivebase.arrowDriveAccel(0,0,1);
    }
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  drivebase.arrowDriveAccel(driver_joy.GetRawAxis(controller::kLStickY), driver_joy.GetRawAxis(controller::kRStickX), 1);

  if(driver_joy.GetRawButton(controller::kAButton)){
    pneumatics.CargoDoorDown();
  } else {
    pneumatics.CargoDoorUp();
  }

  if(driver_joy.GetRawButton(controller::kYButton)) {
    pneumatics.StabilizerDeploy();
  } else {
    pneumatics.StabilizerRetract();
  }
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
