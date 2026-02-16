import serial
import time

sender = None
receiver = None


# ---------------------------
# Open Ports
# ---------------------------
def open_ports():
    global sender, receiver

    print("\nOpening COM6 (Sender) and COM7 (Receiver)...\n")

    sender = serial.Serial("COM6", 115200, timeout=1)
    receiver = serial.Serial("COM7", 115200, timeout=1)

    time.sleep(3)

    sender.reset_input_buffer()
    receiver.reset_input_buffer()


# ---------------------------
# Close Ports
# ---------------------------
def close_ports():
    global sender, receiver

    print("\nClosing Ports...\n")

    if sender and sender.is_open:
        sender.close()

    if receiver and receiver.is_open:
        receiver.close()


# ---------------------------
# Wait for Sender Message
# ---------------------------
def wait_for_sender(expected, timeout=10):
    global sender
    start = time.time()

    while time.time() - start < timeout:
        line = sender.readline().decode(errors="ignore").strip()

        if line:
            print("Sender ->", line)

            if expected in line:
                print("✔ Sender Matched:", expected)
                return

    raise AssertionError(f"{expected} NOT found from Sender")


# ---------------------------
# Wait for Receiver Message
# ---------------------------
def wait_for_receiver(expected, timeout=10):
    global receiver
    start = time.time()

    while time.time() - start < timeout:
        line = receiver.readline().decode(errors="ignore").strip()

        if line:
            print("Receiver ->", line)

            if expected in line:
                print("✔ Receiver Matched:", expected)
                return

    raise AssertionError(f"{expected} NOT found from Receiver")