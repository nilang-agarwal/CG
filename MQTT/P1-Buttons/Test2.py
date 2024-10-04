import tkinter as tk
from tkinter import messagebox
import paho.mqtt.client as mqtt
import json

broker_address = "broker.emqx.io"
port = 1883
topic = "India/Bihar/Patna"

client = mqtt.Client()
received_data = None  # To store the last received message

def on_message(client, userdata, msg):
    global received_data
    received_data = msg.payload.decode()  # Store the received message
    create_buttons(received_data)

client.on_message = on_message

def create_buttons(message):
    try:
        data = json.loads(message)  # Parse the JSON message
        things = data['Details']['Things']
        
        # Clear existing buttons
        for widget in button_frame.winfo_children():
            widget.destroy()
        
        # Create new buttons for each "Thing"
        for thing in things:
            btn = tk.Button(button_frame, text=thing['Name'], command=lambda name=thing['Name']: on_button_click(name, thing))
            btn.pack(pady=5, padx=10, fill=tk.X)

    except Exception as e:
        messagebox.showerror("Error", f"Error processing message: {str(e)}")

def on_button_click(name, thing_data):
    # Display the JSON data in a message box
    json_data = json.dumps(thing_data, indent=4)
    messagebox.showinfo(f"Data for {name}", json_data)

def connect_to_broker():
    try:
        client.connect(broker_address, port)
        client.subscribe(topic)
        client.loop_start()
    except Exception as e:
        messagebox.showerror("Connection Error", f"Connection error: {str(e)}")

app = tk.Tk()
app.title("MQTT Button Display")
app.geometry("600x400")

# Frame for buttons
button_frame = tk.Frame(app)
button_frame.pack(pady=10, fill=tk.BOTH, expand=True)

connect_to_broker()

app.mainloop()
