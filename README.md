# 🔌 BadUSB Payloads

> A collection of BadUSB payloads for educational and security research purposes.

This repository contains various BadUSB (USB Rubber Ducky / HID attack) payload scripts written in both **DuckyScript** and **Arduino (Keyboard.h)** formats. These payloads are intended to help security researchers and students understand HID-based attack vectors and develop countermeasures.

---

## ⚠️ CRITICAL DISCLAIMER

**This repository contains BadUSB payload scripts capable of executing automated keystroke injection attacks on target machines.** These scripts are provided for **cybersecurity education, penetration testing research, and security awareness training purposes.**

> [!CAUTION]
> **By using any code in this repository, you acknowledge and agree that:**
> - Only use these payloads on systems you own or have explicit authorization to test.
> - **You are solely responsible** for your actions and any consequences resulting from the use of these payloads.
> - The author(s) of this repository accept **no responsibility or liability** whatsoever for any damage, loss, or legal consequences arising from the use or misuse of this code.
> - It is **your responsibility** to ensure that your use complies with all applicable local, state, national, and international laws.
>
> **USE ENTIRELY AT YOUR OWN RISK.**

---

## 📂 Payload Index

| Directory | Description |
|-----------|-------------|
| [`helloworld/`](./helloworld/) | Opens Notepad and types "Hello World!" — a basic proof-of-concept payload. |

---

## 🛠️ Supported Devices

Payloads in this repository are designed for or tested with:

- **USB Rubber Ducky** (Hak5) — `.txt` DuckyScript format
- **Arduino-based HID boards**  — `.ino` format
- **Flipper Zero BadUSB** — DuckyScript-compatible `.txt` format

---

## 📜 License

This project is licensed under the [MIT License](./LICENSE).
