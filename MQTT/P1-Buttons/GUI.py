import tkinter as tk
from tkinter import messagebox, Toplevel
import paho.mqtt.client as mqtt
import json

broker_address = "broker.emqx.io"
port = 1883
topic = "India/Bihar/Patna"

client = mqtt.Client()

device_data = {}

def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    client.subscribe(topic)

def on_message(client, userdata, msg):
    global device_data
    try:
        device_data = json.loads(msg.payload.decode())
        update_things_list()
    except Exception as e:
        print("Error processing message:", str(e))

client.on_connect = on_connect
client.on_message = on_message

def update_things_list():


    for widget in things_frame.winfo_children():
        widget.destroy()  
    
    if "Details" in device_data and "Things" in device_data["Details"] and device_data["Details"]["Things"]:
        for thing in device_data["Details"]["Things"]:
            button = tk.Button(things_frame, text=thing["Name"], 
                               command=lambda t=thing: open_view_window(t),
                               bg="#008000", fg="#FFFFFF", font=("Helvetica", 14), 
                               relief="raised", padx=10, pady=5)
            button.pack(fill='both', padx=5, pady=5)

    else:
        print("Waiting for updates")


def open_view_window(thing):
    view_window = Toplevel(app)
    view_window.title(thing["Name"])
    
    detail_frame = tk.Frame(view_window)
    detail_frame.pack(padx=10, pady=10)

    labels = []
    
    row, col = 0, 0   
    for key, value in thing.items():
        if isinstance(value, list):
            value = ', '.join(map(str, value))   
        label_text = f"{key}\n{value}"   
        label = tk.Label(detail_frame, text=label_text, 
                         font=("Helvetica", 12), padx=10, pady=10,
                         borderwidth=2, relief="solid", width=15, height=3)
        labels.append((key, label))  
        label.grid(column=col, row=row, padx=5, pady=5)  
        col += 1
        if col > 3:   
            col = 0
            row += 1

   
    def update_labels(updated_thing):
        for key, label in labels:
            if key in updated_thing:  
                if isinstance(updated_thing[key], list):
                    value = ', '.join(map(str, updated_thing[key]))
                else:
                    value = updated_thing[key]
                 
                label['text'] = f"{key}\n{value}"

   
    def check_for_updates():
        updated_thing = next((t for t in device_data["Details"]["Things"] if t["Name"] == thing["Name"]), None)
        if updated_thing:
            update_labels(updated_thing)
        view_window.after(1000, check_for_updates)  

    check_for_updates()  


def connect_to_broker():
    try:
        client.connect(broker_address, port)
        client.loop_start()
    except Exception as e:
        messagebox.showerror("Connection Error", str(e))

app = tk.Tk()
app.title("MQTT Home Screen")
app.geometry("400x400")
app.configure(bg="#f0f0f0")

things_frame = tk.Frame(app, bg="#f0f0f0")
things_frame.pack(padx=10, pady=10, fill='both', expand=True)

connect_to_broker()

app.mainloop()
