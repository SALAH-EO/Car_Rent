# 🚗 Car Rent — Car Rental Management System

> **A console-based car rental management system written in C for managing vehicles, clients, and rental contracts.**

**Car_Rent** is a C application designed to help a car rental agency manage its day-to-day operations from a centralized console interface.

The application provides three main areas:

* 🚘 **Car Management**
* 👤 **Client Management**
* 📄 **Rental & Contract Management**

The system uses C structures and file handling to store and manipulate information locally. Instead of relying on an external database, the application persists its data through files such as `Voitures.txt`, `Clients.txt`, and `ContratsLocations.txt`.

The project demonstrates how a traditional business-management application can be implemented in **C using structures, modular functions, file I/O, menus, and CRUD-style operations**.

---

# 🎯 Project Overview

The goal of this project is to provide a simple management tool for a car rental agency.

A rental agency needs to keep track of:

```text
                    CAR RENTAL SYSTEM
                           │
             ┌─────────────┼─────────────┐
             │             │             │
             ▼             ▼             ▼
          🚘 Cars       👤 Clients     📄 Rentals
             │             │             │
             │             │             │
        Inventory       Customer      Contracts
        Management      Management    Management
```

The application brings these activities together into a single interactive console program.

From the main menu, the user can access:

1. **Location** — manage rental operations and contracts
2. **Gestion voitures** — manage the vehicle inventory
3. **Gestion clients** — manage customers
4. **Quitter** — exit the application

This structure is implemented directly in the main application flow.

---

# 🚘 Car Management

The vehicle management section allows the rental agency to maintain its fleet.

The application supports:

* Listing vehicles
* Adding vehicles
* Modifying vehicles
* Removing vehicles

Each vehicle contains information such as:

* Vehicle ID
* Brand
* Model/name
* Color
* Number of seats
* Daily rental price
* Rental availability/status

These properties are represented using a dedicated `voiture` structure in C.

A typical vehicle record can therefore be thought of as:

```text
Vehicle
├── ID
├── Brand
├── Model
├── Color
├── Number of seats
├── Price per day
└── Rental status
```

The system can list the vehicles currently registered in the agency and display their rental information, including whether they are currently available for rental.

---

# 👤 Client Management

The application also maintains a customer database.

The client management section provides:

* List clients
* Add a client
* Modify client information
* Delete a client

Each customer has a unique identifier and information such as:

* Client ID
* First name
* Last name
* CIN
* Address
* Telephone number

These fields are represented by the `client` structure.

The application generates an identifier when creating a new client and stores the resulting record in the client data file.

---

# 📄 Rental & Contract Management

The core business functionality of the application is rental management.

The rental section provides several operations:

```text
Rental Management
│
├── View rental contract
├── Rent a vehicle
├── Return a vehicle
├── Modify a contract
└── Delete a contract
```

These options are exposed through the rental submenu.

A rental contract contains information linking a client to a vehicle.

The contract structure includes:

* Contract number
* Vehicle ID
* Client ID
* Start date
* End date
* Rental cost

This creates a basic relationship between the agency's customers, vehicles, and rental transactions.

Conceptually:

```text
             ┌──────────────┐
             │    CLIENT    │
             │              │
             │  Client ID   │
             └──────┬───────┘
                    │
                    │
                    ▼
             ┌──────────────┐
             │   CONTRACT   │
             │              │
             │ Contract ID  │
             │ Start Date   │
             │ End Date     │
             │ Cost         │
             └──────┬───────┘
                    │
                    │
                    ▼
             ┌──────────────┐
             │    VEHICLE   │
             │              │
             │ Vehicle ID   │
             │ Model        │
             │ Price/Day    │
             └──────────────┘
```

This allows the application to represent the fundamental relationship required by a rental agency: **which customer rented which vehicle, for what period, and at what cost**.

---

# 🔄 Rental Workflow

A typical rental operation follows this general process:

```text
1. Identify the client
          │
          ▼
2. Specify the desired vehicle
          │
          ▼
3. Check vehicle information
          │
          ▼
4. Create the rental contract
          │
          ▼
5. Associate client + vehicle
          │
          ▼
6. Record rental dates and cost
          │
          ▼
7. Vehicle becomes part of an active rental
```

The rental function asks for the customer's identifier and then requests vehicle characteristics such as:

* Brand
* Vehicle name/model
* Color
* Number of seats

It then searches the vehicle records for a matching vehicle before creating the rental contract.

---

# 🔁 Returning a Vehicle

The application also provides a return operation.

The user can select the rental/contract associated with the vehicle being returned. The system then works with the contract and vehicle records to process the return operation.

This gives the application a basic rental lifecycle:

```text
AVAILABLE
    │
    │ Rent
    ▼
RENTED
    │
    │ Return
    ▼
AVAILABLE
```

---

# ✏️ Updating Records

The system allows existing information to be modified rather than requiring records to be recreated.

For example, vehicle information can be updated using its identifier, after which the application displays the existing information and allows selected fields to be changed.

The same concept is applied to customer records, where a customer can be located using their ID and their information can subsequently be modified.

This provides the application with the basic **CRUD** operations required by a management system:

| Operation | Cars | Clients | Contracts |
| --------- | :--: | :-----: | :-------: |
| Create    |   ✅  |    ✅    |     ✅     |
| Read      |   ✅  |    ✅    |     ✅     |
| Update    |   ✅  |    ✅    |     ✅     |
| Delete    |   ✅  |    ✅    |     ✅     |

---

# 💾 Data Persistence

One of the important characteristics of this project is that it does **not require a relational database**.

Instead, the application uses local files to persist information:

```text
Voitures.txt
Clients.txt
ContratsLocations.txt
```

The main program opens these files when the application starts and passes the corresponding file handles to the management functions.

The application uses C's file-management functions such as:

```c
fopen()
fread()
fwrite()
fseek()
fclose()
```

This allows structured C records to be written to and read from local files.

The project therefore demonstrates an important C programming concept:

> **Using binary file I/O as a lightweight persistence layer for a business application.**

---

# 🧱 Data Model

The application's main business entities are represented using C structures.

### Vehicle

```text
voiture
├── idVoiture
├── marque
├── nomVoiture
├── couleur
├── nbplaces
├── prixJour
└── EnLocation
```

### Client

```text
client
├── idClient
├── nom
├── prenom
├── Cin
├── adresse
└── telephone
```

### Rental Contract

```text
contrat
├── numContrat
├── idVoiture
├── idClient
├── debut
├── fin
└── Cout
```

### Date

```text
date
├── dd
├── mm
└── yy
```

These structures form the data model of the application.

---

# 🖥️ Console Dashboard

The application is designed around a menu-driven console interface.

The main dashboard is:

```text
========================================

             MENU PRINCIPAL

 Location..............................1
 Gestion voitures......................2
 Gestion clients.......................3
 Quitter...............................4

 Votre choix :
```

The user selects an operation by entering its corresponding number.

The application then routes the request to the appropriate management section.

This approach makes the application straightforward to operate while demonstrating how hierarchical menus can be implemented in C.

---

# ⚙️ Technical Architecture

The application follows a simple modular architecture:

```text
                       ┌──────────────────┐
                       │     main.c       │
                       │ Application Flow │
                       └────────┬─────────┘
                                │
              ┌─────────────────┼─────────────────┐
              │                 │                 │
              ▼                 ▼                 ▼
       Rental Management   Vehicle Management  Client Management
              │                 │                 │
              └─────────────────┼─────────────────┘
                                │
                                ▼
                         File Persistence
                                │
              ┌─────────────────┼─────────────────┐
              ▼                 ▼                 ▼
        Voitures.txt      Clients.txt     ContratsLocations.txt
```

The application separates:

* Data structures
* Menu logic
* Business operations
* Persistent storage

The main program coordinates the different management modules through function pointers and menu selections.

---

# 🛠️ Technologies

### Programming Language

**C**

### Standard Libraries

The project uses standard C libraries including:

* `stdio.h`
* `stdlib.h`
* `string.h`
* `time.h`

These provide functionality for:

* Input/output
* File management
* Dynamic/general-purpose utilities
* String manipulation
* Random ID generation and time-related operations

The project imports these libraries directly in `main.c`.

### Data Storage

**Local binary files**

* `Voitures.txt`
* `Clients.txt`
* `ContratsLocations.txt`

### Development Environment

The repository contains a Code::Blocks project configuration (`Car_Rent.cbp`) together with the C source and header files.

---

# 🚀 Getting Started

## Prerequisites

To run the project, you need a C compiler.

You can use any environment supporting standard C development, such as:

* GCC
* MinGW
* Code::Blocks
* Visual Studio Code with a C compiler
* Linux/macOS terminal with GCC or Clang

---

## 1. Clone the Repository

```bash
git clone https://github.com/SALAH-EO/Car_Rent.git
cd Car_Rent
```

---

## 2. Compile With GCC

If GCC is installed:

```bash
gcc main.c -o car_rent
```

Then run:

### Linux / macOS

```bash
./car_rent
```

### Windows

```bash
car_rent.exe
```

The repository also includes a Code::Blocks project file, so the project can be opened directly in Code::Blocks.

---

# ▶️ Running the Application

After launching the program, the main menu will appear.

Choose:

```text
1 → Rental Management
2 → Vehicle Management
3 → Client Management
4 → Exit
```

### Example: Managing Vehicles

Choose:

```text
2
```

You will then have access to:

```text
1 → List vehicles
2 → Add vehicle
3 → Modify vehicle
4 → Delete vehicle
5 → Return
```

These operations correspond directly to the vehicle-management menu implemented in the application.

### Example: Managing Clients

Choose:

```text
3
```

The available operations are:

```text
1 → List clients
2 → Add client
3 → Modify client
4 → Delete client
5 → Return
```

### Example: Managing Rentals

Choose:

```text
1
```

The rental section provides:

```text
1 → View contract
2 → Rent a vehicle
3 → Return vehicle
4 → Modify contract
5 → Delete contract
6 → Return
```

---

# 📋 Example Usage Scenario

Imagine a rental agency receives a new customer.

### Step 1 — Register the customer

The administrator opens:

```text
Gestion clients → Ajouter client
```

The system collects the customer's information and generates an ID.

### Step 2 — Add a vehicle

The administrator opens:

```text
Gestion voitures → Ajouter voiture
```

The system records:

* Brand
* Model
* Color
* Number of seats
* Daily price
* Rental status

### Step 3 — Rent the vehicle

The administrator opens:

```text
Location → Louer voiture
```

The customer ID and desired vehicle characteristics are entered.

### Step 4 — Contract

The application creates a rental contract connecting:

```text
Customer
   +
Vehicle
   +
Rental Dates
   +
Cost
```

### Step 5 — Return

When the customer returns the vehicle, the administrator uses:

```text
Location → Retourner voiture
```

This represents the complete basic rental lifecycle.

---

# 👨‍💻 Author

**Salah Eddine Ouirra**

Data Science & Big Data | Software Engineering | AI Engineering

---

# ⭐ Repository

[View the project on GitHub](https://github.com/SALAH-EO/Car_Rent)

If you find the project useful or interesting, feel free to ⭐ star the repository.
