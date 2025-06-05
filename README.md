# Message Queue Implementation using System V IPC

This project demonstrates inter-process communication (IPC) using System V message queues on a university networked environment connected via `putty` to an `r800` server. To ensure accurate and isolated communication between processes, the implementation uses a dedicated `/tmp` directory and a unique key for each message queue.

## 🛠️ Technologies Used

- **C Programming**
- **System V Message Queues**
- **Linux (r800 Server)**
- **Putty Terminal**

## 📁 Project Structure

```bash
.
├── sender.c      # Code to send messages to the queue
├── receiver.c    # Code to receive messages from the queue
├── Makefile      # For compiling sender and receiver
└── /tmp/ipcdir/  # Temporary directory used for generating unique key
```

## 🧪 Why /tmp/ipcdir?
<p>Since the university lab environment is a shared networked system, messages sent via message queues may interfere with others using the same default key. To avoid this:

A unique directory (/tmp/ipcdir) is created.

A file inside this directory is used to generate a unique key using ftok().

This ensures that only your sender and receiver processes communicate with each other securely.</p>



![2 ](https://github.com/user-attachments/assets/6cf3e0f0-f80c-4ee6-a720-0e6e60efd589)

![exercise](https://github.com/user-attachments/assets/7662ceed-e28f-4e06-a75b-931336fcd9d8)
