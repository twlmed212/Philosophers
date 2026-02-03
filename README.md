# Philosophers

## Description

The **Philosophers** project is a classic concurrency problem from the 42 school curriculum that simulates the famous **Dining Philosophers Problem** introduced by Edsger Dijkstra. This project teaches fundamental concepts of concurrent programming, including thread management, mutexes, and synchronization.

## The Problem

Several philosophers sit at a round table with a large bowl of spaghetti in the center. Each philosopher alternates between three states: **eating**, **thinking**, and **sleeping**. To eat, a philosopher needs two forks (one on their left and one on their right). The challenge is to design a solution that prevents deadlock and ensures all philosophers can eat without starving.

## Objectives

- Understand and implement multi-threading and process synchronization
- Learn to use mutexes to protect shared resources
- Avoid common concurrency issues: deadlock, race conditions, and starvation
- Manage time-based simulations with precise timing control

## Key Concepts

- **Threads/Processes**: Each philosopher runs as a separate thread or process
- **Mutexes**: Used to protect access to shared resources (forks)
- **Synchronization**: Coordinating philosophers to prevent conflicts
- **Resource Management**: Efficiently managing limited resources (forks)
- **Timing**: Precise time tracking for eating, sleeping, and thinking durations