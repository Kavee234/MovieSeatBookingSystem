# 🎬 Movie Ticket Booking System

## 📌 Project Overview
This is a **command-line C program** for managing movie ticket bookings.  
It allows theaters to set up movies and showtimes, manage seat maps, apply discounts, cancel bookings, search for customers, and generate revenue reports.

---

## ⚙️ Features
- **View Showtimes**: Lists all movies and their showtimes.
- **View Seat Map**: Displays a grid of seats (free `.` vs booked `X`).
- **Book a Seat**:
  - Validates seat availability.
  - Applies pricing tiers:
    - Regular (Rows A–B): Rs. 500  
    - Premium (Rows C–D): Rs. 750  
    - VIP (Row E): Rs. 1000  
  - Discounts:
    - Student: 10% off  
    - Senior Citizen: 20% off  
    - Group (≥4 seats): 10% off (can combine with Student/Senior).
- **Cancel a Booking**: Frees up a seat and updates revenue.
- **Search Booking**: Finds a booking by customer name.
- **Revenue Report**: Shows total tickets sold and revenue.
- **Validations**:
  - Prevents double booking.
  - Prevents invalid seat numbers.
  - Handles invalid input gracefully.

---

## 🖥️ How to Compile & Run
1. Clone the repository:
   ```bash
   git clone https://github.com/Kavee234/MovieSeatBookingSystem.git
   cd MovieSeatBookingSystem
2. gcc main.c -o bookingSystem
3. ./bookingSystem

