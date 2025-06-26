# Data Structures Final Project – Debt Tracking System

This repository contains the full C++ solution to the final project of the Data Structures Course.

## 🚩 Problem Overview

The project simulates a system where multiple people lend and borrow money to/from each other over time, keeping a detailed record of all debts and credits. The challenge is to process up to 150,000 commands, efficiently responding to various financial queries about the network.

### Supported Operations

1. **Recording a Transaction:**  
   Person X lends a positive amount to person Y.
2. **Querying Richest Net Balance:**  
   Who currently has the highest (positive) net profit?
3. **Querying Poorest Net Balance:**  
   Who currently has the lowest (negative) net profit?
4. **Count Owed People:**  
   How many people does person S owe?
5. **Count Owing People:**  
   How many people owe money to person S?
6. **Settle Up:**  
   How much must person S1 pay S2 (with 2 decimals) to settle up their mutual debts?

See the project.pdf for sample I/O and full statement.

### Constraints

- Up to 150,000 commands (efficient data structures required)
- All names are lowercase, up to 8 alphabetic characters
- Monetary values are always positive, 2 decimal digits

---

## 💻 Usage

### 1. Build

Make sure you have `g++` (or another C++17+ compiler):

```bash
g++ -o project project.cpp
```

### 2. Run
```bash
./project
```
like this screenshot for input1:
![Screenshot from 2025-06-26 10-48-13](https://github.com/user-attachments/assets/d669217f-4778-42da-9012-a2fbfa1ebeb1)
![Screenshot from 2025-06-26 10-48-25](https://github.com/user-attachments/assets/4f75bd0d-52c7-4b7d-8c42-4dc2be520044)
![Screenshot from 2025-06-26 10-48-25](https://github.com/user-attachments/assets/4f75bd0d-52c7-4b7d-8c42-4dc2be520044)

![Screenshot from 2025-06-26 10-48-13](https://github.com/user-attachments/assets/d669217f-4778-42da-9012-a2fbfa1ebeb1)

