# COMPUTER REMOTE CONTROL VIA EMAIL - HCMUS
## Overview
- This project is contributed by **23122009 Bang My Linh** and **23122040 Nguyen Thi My Kim**
- Go to [YOUTUBE DEMO PC REMOTE CONTROLLER](https://www.youtube.com/watch?v=_-SRAjogUFU) for details
### Client side
- Client uses Qt as  a framework for creating Graphical User Interfaces (GUI) and includes modules for handling graphical tasks. 
- Client also uses the EASendMail and EAGetMail libraries to handle email-related tasks on the Client side:
   - **EASendMail** supports sending emails via SMTP servers.
   - **EAGetMail** supports receiving and managing emails via POP3, IMAP, or EWS (Exchange Web Services).
### Server side
- Service side uses FFmpeg as an open-source library used for processing video, audio, and related multimedia tasks.

## INSTALLATION
### Install our project
```
git clone https://github.com/gracebml/hcmus_socket
```
### Install EASendMail and EAGetMail for Client Side
1. Download the installer:
   - Go to [EASendMail and EAGetMail Installer](https://www.emailarchitect.net).
   - Download **EASendMail SMTP Component** and **EAGetMail POP3/IMAP4 Component**.

2. Post-installation setup:
   - Navigate to the directory: `/EASendMail/Include/tlh`.
   - Copy the files `easendmailobj.tlh` and `easendmailobj.tli` to your project folder for client.
   - Navigate to the directory: `/EAGetMail/Include/tlh`.
   - Copy the files `EAGetMailobj.tlh` and `EAGetMailobj.tli` to your project folder for client.

---

### Install Qt for Client Side
#### Install Qt Source Code
1. Create a folder named `Qt` on your C drive:
   - Path: `C:\Qt`

2. Download the Qt source code:
   - Use this [link](https://drive.google.com/drive/folders/1CN83O5P_SY23CsLIbV87PYppQtj7Iu5h?usp=sharing) to download `6.8.1.zip`.
   - Place `6.8.1.zip` in `C:\Qt` and extract it there.

3. Verify the path:
   - Ensure the final path is `C:\Qt\6.8.1\msvc2022_64`, and this directory contains the Qt source files.

#### Install Qt Extensions for Visual Studio
1. Open the solution file `clientapp.sln` in Visual Studio.
2. Install extensions:
   - Go to `Extension` > `Manage Extensions`.
   - Search for "Qt" and install the following:
     - **Qt Vs CMake Tools**
     - **LEGACY Qt Visual Studio Tools**

3. Complete installation:
   - Close Visual Studio after installing the extensions.
   - Follow the prompts in the `VSIX Installer` to modify and complete the installation.
   - Restart your computer.

#### Add Qt Versions to Qt Extension
1. Open the solution file `clientapp.sln` in Visual Studio.
2. Configure Qt Versions:
   - Go to `Extension` > `Qt VS Tools` > `Qt Versions`.
   - In the `Options` window, click the "+" icon, then the folder icon to select a path.
   - Navigate to `C:\Qt\6.8.1\msvc2022_64\bin\qmake.exe` and click `Open`.
   - Click `OK` to finalize the configuration.

---

### Install FFmpeg for Server Side
1. Create a folder named `ffmpeg` on your C drive:
   - Path: `C:\ffmpeg`

2. Download FFmpeg:
   - Download the ZIP file from [FFmpeg Latest Builds](https://github.com/BtbN/FFmpeg-Builds/releases/download/latest/ffmpeg-master-latest-win64-gpl.zip).

3. Extract the files:
   - Place the `ffmpeg-master-latest-win64-gpl.zip` file in `C:\ffmpeg` and extract it.

4. Move executable files:
   - Navigate to `C:\ffmpeg\ffmpeg-master-latest-win64-gpl\bin`.
   - Copy the following files to `C:\ffmpeg`:
     - `ffmpeg.exe`
     - `ffplay.exe`
     - `ffprobe.exe`

5. Add FFmpeg to Environment Variables:
   - Search for "Edit environment variables for your account" in the Windows search bar.
   - In the `Environment Variables` window, under `User variables for Administrator_Name`, select `Path` and click `Edit`.
   - In the `Edit Environment Variable` window, click `New` and add `C:\ffmpeg`.
   - Click `OK` to save and close all dialogs.

---

By following these steps, the required libraries and tools will be installed and configured for the project. Ensure that all paths and environment variables are set correctly before running the application.

