import serial
import time
import pyautogui

# Change the COM port to match the one your Arduino is connected to
ser = serial.Serial('COM3', 9600, timeout=1)

# The distance at which a hand gesture is detected
gesture_distance = 10

while True:
    # Read the distance measured by the ultrasonic sensor
    ser.write(b'r')
    distance = ser.readline().decode().rstrip()

    try:
        # Convert the distance to an integer
        distance = int(distance)

        # If the hand is close enough, change the slide
        if distance < gesture_distance:
            pyautogui.press('right')
            
        # If the hand is close enough, change the slide backward
        if distance > gesture_distance:
            pyautogui.press('left')

        # Wait for a short period of time before checking again
        time.sleep(0.1)
    except ValueError:
        # If the distance couldn't be converted to an integer, ignore it
        pass
