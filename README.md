# Message Queue IPC using Parent-Child Processes (System V)

This project implements inter-process communication (IPC) using System V message queues, where a **child process sends** a message and the **parent process receives** it. Although a unique key and a temporary directory are used, interference can still occur due to the shared nature of the lab server.

## ⚙️ Environment

- **Linux** (`r800` University Server)
- **Putty Terminal Access**
- **System V Message Queues**
- **C Language**

## 🧠 Core Concept

- This program uses `fork()` to create a child process.
- The child sends a message using `msgsnd()`.
- The parent receives it using `msgrcv()`.

### 🔐 Isolation Attempt

- A temporary directory (`/tmp/ipcdir`) and a file (`keyfile`) are used to generate a **unique key** using `ftok()`.
- However, **due to a shared kernel message queue system** on the server, messages from other students/processes may still interfere — even if the key is unique — if the queue already exists with the same ID.

## 📁 Files

```bash
.
├── parent_child_ipc.c  # Single file with both sender (child) and receiver (parent)
└── /tmp/ipcdir/keyfile # Used for key generation
```

![2](https://github.com/user-attachments/assets/92d436e5-7594-40ce-adf1-22201fb47c90)


![3](https://github.com/user-attachments/assets/da57d03e-dd78-4c75-b907-86492b66151d)


![4](https://github.com/user-attachments/assets/38b78af0-1ffc-4841-adb0-7eced5d29d89)


![5ac](https://github.com/user-attachments/assets/26391979-881e-41bd-989e-c0a4f9c21b75)
