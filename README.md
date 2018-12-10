# ultrasonic_keyboard
A project based on arduino with ultrasonic sensors
The main feature of this interface is controlling PC actions with hand gestures.
For detecting hand gestures, I used two ultrasonic sensors equipped with arduino.
In the arduino code, I have written a function to calculate distance of an obstacle.
In the forever while loop, using the above function and checked for the range continuously 
to generate serial data based on gestures, different serial data for different gestures.
From this serail data, with the help of python library, pyautogui, I mapped the keyboard functionality
to the serial data(gesture based).
First I need to dump the code to arduino Uno and ran the python script in the background.
