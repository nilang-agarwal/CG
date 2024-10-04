import tkinter as tk
from tkinter import ttk, messagebox
import paho.mqtt.client as mqtt
import json

# Global variables
existing_mac_addresses = {}
device_data = {}

# MQTT Configuration
broker_address = "broker.emqx.io"
port = 1883
topic = "India/Bihar/Patna"

# MQTT Client
client = mqtt.Client()

# Callback Functions
def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    client.subscribe(topic)

def on_message(client, userdata, msg):
    global device_data
    try:
        device_data = json.loads(msg.payload.decode())
        update_tabs()  # Update tabs on receiving a new message
    except Exception as e:
        print("Error processing message:", str(e))

client.on_connect = on_connect
client.on_message = on_message

def update_tabs():
    mac_address = device_data.get("MAC")
    if not mac_address:
        return  # No MAC address in the message

    # Create a new tab only if the MAC address is not already present
    if mac_address not in existing_mac_addresses:
        tab = ttk.Frame(notebook)
        notebook.add(tab, text=mac_address)  # Use MAC address as tab name
        existing_mac_addresses[mac_address] = tab  # Store the tab for this MAC address

    # Get the corresponding tab for this MAC address
    tab = existing_mac_addresses[mac_address]

    # Clear existing content
    for widget in tab.winfo_children():
        widget.destroy()

    # Create a frame for displaying values
    detail_frame = tk.Frame(tab)
    detail_frame.pack(padx=10, pady=10)

    # Create a grid layout for displaying values
    row = 0

    for thing in device_data["Details"].get("Things", []):
        # Create a label for the Thing name
        name_label = tk.Label(detail_frame, text=thing['Name'], font=("Helvetica", 12))
        name_label.grid(row=row, column=0, columnspan=4, padx=5, pady=5, sticky='nsew')
        row += 1

        # Check for Values and create a grid for them
        if "Values" in thing and isinstance(thing["Values"], list):
            for index, value in enumerate(thing["Values"]):
                col = index % 4  # Determine column
                value_row = row + (index // 4)  # Determine row based on index

                # Create a frame for each value with a black border
                value_frame = tk.Frame(detail_frame, bd=1, relief="solid")
                value_frame.grid(row=value_row, column=col, padx=5, pady=5)

                # Create labels for Value name and value
                value_label = tk.Label(value_frame, text=f"Value-{index + 1}", font=("Helvetica", 10))
                value_label.pack(side='top', padx=5, pady=2)

                value_value = tk.Label(value_frame, text=value, font=("Helvetica", 10))
                value_value.pack(side='bottom', padx=5, pady=2)

            # Adjust the row for the next thing based on the number of values
            row += (len(thing["Values"]) // 4) + (1 if len(thing["Values"]) % 4 else 0)

        else:
            # Display single value if no Values key exists
            value_to_display = thing.get("Value", "N/A")  # Get the single value or default to "N/A"
            value_frame = tk.Frame(detail_frame, bd=1, relief="solid")
            value_frame.grid(row=row, column=0, padx=5, pady=5)

            value_label = tk.Label(value_frame, text="Value", font=("Helvetica", 10))
            value_label.pack(side='top', padx=5, pady=2)

            value_value = tk.Label(value_frame, text=value_to_display, font=("Helvetica", 10))
            value_value.pack(side='bottom', padx=5, pady=2)

            # Increment the row for the next Thing
            row += 1

        # Add a separator line after each thing
        separator = tk.Frame(detail_frame, height=2, bg="#000000")
        separator.grid(row=row, columnspan=6, sticky='ew', padx=0, pady=10)
        row += 1  # Move to the next row after the separator

def connect_to_broker():
    try:
        client.connect(broker_address, port)
        client.loop_start()  # Start the MQTT loop
    except Exception as e:
        messagebox.showerror("Connection Error", str(e))

# Setup GUI
app = tk.Tk()
app.title("MQTT Home Screen")
app.geometry("600x400")
app.configure(bg="#f0f0f0")

notebook = ttk.Notebook(app)
notebook.pack(padx=10, pady=10, fill='both', expand=True)

# Connect to the MQTT broker after the GUI setup
app.after(100, connect_to_broker)

app.mainloop()

