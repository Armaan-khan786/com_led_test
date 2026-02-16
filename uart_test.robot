*** Settings ***
Library           uart_lib.py
Suite Setup       Open Ports
Suite Teardown    Close Ports

*** Test Cases ***

LED1 Test
    Wait For Receiver    READY
    Wait For Sender      Sending Pin: 18
    Wait For Receiver    Received Pin: 18


LED2 Test
    Wait For Receiver    READY
    Wait For Sender      Sending Pin: 19
    Wait For Receiver    Received Pin: 19


LED3 Test
    Wait For Receiver    READY
    Wait For Sender      Sending Pin: 21
    Wait For Receiver    Received Pin: 21


LED4 Test
    Wait For Receiver    READY
    Wait For Sender      Sending Pin: 22
    Wait For Receiver    Received Pin: 22