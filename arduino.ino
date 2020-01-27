
#include <Dynamixel2Arduino.h>

/*
    From the name specified in the Control Table of each model
    the alphabet is replaced with capital letters
    and the space(" ") is replaced with an underscore(_).
    
  MODEL_NUMBER,
  MODEL_INFORMATION,
  FIRMWARE_VERSION,
  PROTOCOL_VERSION,
  ID,
  SECONDARY_ID,
  BAUD_RATE,
  DRIVE_MODE,
  CONTROL_MODE,
  OPERATING_MODE,
  CW_ANGLE_LIMIT,
  CCW_ANGLE_LIMIT,
  TEMPERATURE_LIMIT,
  MIN_VOLTAGE_LIMIT,
  MAX_VOLTAGE_LIMIT,
  PWM_LIMIT,
  CURRENT_LIMIT,
  VELOCITY_LIMIT,
  MAX_POSITION_LIMIT,
  MIN_POSITION_LIMIT,
  ACCELERATION_LIMIT,
  MAX_TORQUE,
  HOMING_OFFSET,
  MOVING_THRESHOLD,
  MULTI_TURN_OFFSET,
  RESOLUTION_DIVIDER,
  EXTERNAL_PORT_MODE_1,
  EXTERNAL_PORT_MODE_2,
  EXTERNAL_PORT_MODE_3,
  EXTERNAL_PORT_MODE_4,
  STATUS_RETURN_LEVEL,
  RETURN_DELAY_TIME,
  ALARM_LED,
  SHUTDOWN,

  TORQUE_ENABLE,
  LED,
  LED_RED,
  LED_GREEN,
  LED_BLUE,
  REGISTERED_INSTRUCTION,
  HARDWARE_ERROR_STATUS,
  VELOCITY_P_GAIN,
  VELOCITY_I_GAIN,
  POSITION_P_GAIN,
  POSITION_I_GAIN,
  POSITION_D_GAIN,
  FEEDFORWARD_1ST_GAIN,
  FEEDFORWARD_2ND_GAIN,
  P_GAIN,
  I_GAIN,
  D_GAIN,
  CW_COMPLIANCE_MARGIN,
  CCW_COMPLIANCE_MARGIN,
  CW_COMPLIANCE_SLOPE,
  CCW_COMPLIANCE_SLOPE,
  GOAL_PWM,
  GOAL_TORQUE,
  GOAL_CURRENT,
  GOAL_POSITION,
  GOAL_VELOCITY,
  GOAL_ACCELERATION,
  MOVING_SPEED,
  PRESENT_PWM,
  PRESENT_LOAD,
  PRESENT_SPEED,
  PRESENT_CURRENT,
  PRESENT_POSITION,
  PRESENT_VELOCITY,
  PRESENT_VOLTAGE,
  PRESENT_TEMPERATURE,
  TORQUE_LIMIT,
  REGISTERED,
  MOVING,
  LOCK,
  PUNCH,
  CURRENT,
  SENSED_CURRENT,
  REALTIME_TICK,
  TORQUE_CTRL_MODE_ENABLE,
  BUS_WATCHDOG,
  PROFILE_ACCELERATION,
  PROFILE_VELOCITY,
  MOVING_STATUS,
  VELOCITY_TRAJECTORY,
  POSITION_TRAJECTORY,
  PRESENT_INPUT_VOLTAGE,
  EXTERNAL_PORT_DATA_1,
  EXTERNAL_PORT_DATA_2,
  EXTERNAL_PORT_DATA_3,
  EXTERNAL_PORT_DATA_4,
*/

  #define DXL_SERIAL   Serial1
  #define DEBUG_SERIAL Serial
  const uint8_t DXL_DIR_PIN = 2; //Direction pin

const uint8_t DXL_ID = 1;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

void setup() {
  // put your setup code here, to run once:
  DEBUG_SERIAL.begin(9600);
  dxl.setPortProtocolVersion(2.0);
  dxl.begin(9600);
  dxl.scan();
// set to joint mode
  dxl.writeControlTableItem(CONTROL_MODE, DXL_ID, 2);
  
  // Turn on torque
  dxl.writeControlTableItem(TORQUE_ENABLE, DXL_ID, 1);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(dxl.writeControlTableItem(GOAL_POSITION, DXL_ID, 200)){
    delay(100);
    DEBUG_SERIAL.println("p ");
    DEBUG_SERIAL.println(dxl.readControlTableItem(PRESENT_POSITION, DXL_ID));
    delay(100);
    DEBUG_SERIAL.println("v ");
    DEBUG_SERIAL.println(dxl.readControlTableItem(PRESENT_VOLTAGE, DXL_ID));
    delay(100);
    DEBUG_SERIAL.println("t ");
    DEBUG_SERIAL.println(dxl.readControlTableItem(PRESENT_TEMPERATURE, DXL_ID));
    delay(100);
  }
 
  if(dxl.writeControlTableItem(GOAL_POSITION, DXL_ID, 700)){
    delay(1000);
    DEBUG_SERIAL.println(dxl.readControlTableItem(PRESENT_POSITION, DXL_ID));
  }

  delay(2000);  
}