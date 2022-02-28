from pynput import keyboard
import serial
ser= serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=1)


def on_press(key):
    if key == keyboard.Key.esc:
        ser.close()
        return False  # stop listener
    try:
        k = key.char  # single-char keys
    except:
        k = key.name  # other keys
    if k in ['w', 'up']:  # keys of interest
        ser.write(b'w')
        print('Key pressed: ' + k)
        line =  ser.readline()
        string = line.decode()
        str = string.rstrip()
        print(str)
    if k in ['s', 'down']:  # keys of interest
        ser.write(b's')
        print('Key pressed: ' + k)
        line =  ser.readline()
        string = line.decode()
        str = string.rstrip()
        print(str)
    if k in ['+', 'q']:  # keys of interest
        ser.write(b'+')
        print('Key pressed: ' + k)
        line =  ser.readline()
        string = line.decode()
        str = string.rstrip()
        print(str)
    if k in ['-', 'e']:  # keys of interest
        ser.write(b'-')
        print('Key pressed: ' + k)
        line =  ser.readline()
        string = line.decode()
        str = string.rstrip()
        print(str)

listener = keyboard.Listener(on_press=on_press)
listener.start()  # start to listen on a separate thread
listener.join()  # remove if main thread is polling self.keysS
