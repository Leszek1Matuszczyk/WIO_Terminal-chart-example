# WIO_Terminal-chart-example


### Overview

This Arduino project utilizes the WIO Terminal's built-in LCD screen and light sensor to create real-time bar charts displaying light sensor readings. The project features two charts, each representing different aspects of the light sensor data. The code leverages the TFT_eSPI library for LCD control and includes functions for drawing dynamic bar charts with customizable styles.

### Hardware Used

- **WIO Terminal**
  - Built-in LCD Screen
  - Built-in Light Sensor

### Libraries

Copy the following files to the your project directory:

1. [TFT_eSPI Library](https://github.com/Bodmer/TFT_eSPI)
2. [Free_Fonts Library](https://github.com/Bodmer/Free_Fonts)

### Code Description

The Arduino code includes the following key components:

1. **Chart Drawing Functions:**
   - `chart1`: Draws a bar chart with a black background and a white line for a given sensor value.
   - `chart2`: Draws a bar chart with a blue lower part, white upper part, and a black line for a given sensor value.

2. **Setup Function:**
   - Initializes timing variables, the LCD display, and sets up the initial display on the WIO Terminal screen.

3. **Loop Function:**
   - Reads the light sensor value.
   - Updates the first and second charts every 30 milliseconds with dynamic data (in this example, presenting the same data).
   - Updates the LCD display with real-time light sensor values.

### Usage

1. Copy the required libraries into the "libraries" folder of the project.
2. Upload the code to the WIO Terminal using the Arduino IDE.
3. Ensure that the WIO Terminal is connected and powered.
4. Observe real-time bar charts on the WIO Terminal's LCD screen, representing light sensor readings with different chart styles.

### Notes

- Adjust chart parameters (size, colors, etc.) by modifying the function arguments in the `chart1` and `chart2` calls within the loop.

### Acknowledgments

This project is based on the TFT_eSPI and Free_Fonts libraries. Credits go to the library's developers for providing powerful tools for interfacing with TFT displays on Arduino platforms.
