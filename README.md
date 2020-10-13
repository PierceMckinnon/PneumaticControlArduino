# PneumaticControlArduino

This Arduino code is for an Arduino Nano which controlled 4 relays by receiving the control signals over UART from an STM32 board. 
It then sends data about the pneumatic system such as "pressure", back to the STM32 with appropriate headers so that the STM32 can adjust controls for the system.
