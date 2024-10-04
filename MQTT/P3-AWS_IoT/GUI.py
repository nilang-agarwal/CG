import tkinter as tk
from tkinter import ttk, messagebox
import paho.mqtt.client as mqtt
import json
import ssl

existing_mac_addresses = {}
device_data = {}
broker_address = "a3c7k5ajyxpwnh-ats.iot.ap-northeast-1.amazonaws.com"
port = 8883
topic = "India/Bihar/Patna"

client = mqtt.Client()
client.tls_set(
    r"C:\Certs\AmazonRootCA1.pem",
    certfile=r"C:\Certs\45ba4dc21f729655ce049e81d17f6946e3d58e6144629998669527c3f4d818c1-certificate.pem.crt",
    keyfile=r"C:\Certs\45ba4dc21f729655ce049e81d17f6946e3d58e6144629998669527c3f4d818c1-private.pem.key",
    tls_version=ssl.PROTOCOL_TLSv1_2
)

def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    client.subscribe(topic)

def on_message(client, userdata, msg):
    global device_data
    try:
        device_data = json.loads(msg.payload.decode())
        update_tabs() 
    except Exception as e:
        print("Error processing message:", str(e))

client.on_connect = on_connect
client.on_message = on_message

def update_tabs():
    mac_address = device_data.get("MAC")
    if not mac_address:
        return

    if mac_address not in existing_mac_addresses:
        tab = ttk.Frame(notebook, padding=(10, 10))
        notebook.add(tab, text=mac_address)
        existing_mac_addresses[mac_address] = tab

    tab = existing_mac_addresses[mac_address]
    for widget in tab.winfo_children():
        widget.destroy()

    detail_frame = tk.Frame(tab, bg="#ffffff")
    detail_frame.pack(padx=10, pady=10)

    row = 0
    for thing in device_data["Details"].get("Things", []):
        name_label = tk.Label(detail_frame, text=thing['Name'], font=("Helvetica", 12, 'bold'), bg="#ffffff")
        name_label.grid(row=row, column=0, columnspan=4, padx=5, pady=5)
        row += 1

        if "Values" in thing and isinstance(thing["Values"], list):
            for index, value in enumerate(thing["Values"]):
                col = index % 4
                value_row = row + (index // 4)

                value_frame = tk.Frame(detail_frame, bd=1, relief="raised", bg="#e6f7ff")
                value_frame.grid(row=value_row, column=col, padx=5, pady=5)

                value_print = tk.Label(value_frame, text=f"Value-{index + 1}\n{value}", font=("Helvetica", 10), bg="#e6f7ff")
                value_print.pack(side='top', padx=5, pady=2)

            row += (len(thing["Values"]) // 4) + (1 if len(thing["Values"]) % 4 else 0)

        else:
            value = thing.get("Value", "N/A")
            value_frame = tk.Frame(detail_frame, bd=1, relief="raised", bg="#e6f7ff")
            value_frame.grid(row=row, column=0, padx=5, pady=5)

            value_print = tk.Label(value_frame, text=f"Value\n{value}", font=("Helvetica", 10), bg="#e6f7ff")
            value_print.pack(side='top', padx=5, pady=2)

            row += 1

        separator = tk.Frame(detail_frame, height=2, bg="#cccccc")
        separator.grid(row=row, columnspan=6, sticky='ew', padx=0, pady=10)
        row += 1

def connect_to_broker():
    try:
        client.connect(broker_address, port)
        client.loop_start()
    except Exception as e:
        messagebox.showerror("Connection Error", str(e))

app = tk.Tk()
app.title("Devices Data")
app.geometry("600x400")
app.configure(bg="#ffffff")

style = ttk.Style()
style.configure("TNotebook", background="#f0f0f0")
style.configure("TNotebook.Tab", background="#cceeff", padding=(10, 5))
style.map("TNotebook.Tab", background=[("active", "#99ccff")])

notebook = ttk.Notebook(app)
notebook.pack(padx=10, pady=10, fill='both', expand=True)

app.after(100, connect_to_broker)
app.mainloop()
