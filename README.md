# Hidden Numerical Errors in Derivative Calculations

💻 **Project Overview**

Even machines can produce errors — and most of the time we don’t notice.  
This project explores **hidden numerical errors** in C++ when computing derivatives using the **finite difference method**, highlighting how **float (single precision) and double (double precision)** behave differently and where rounding errors start affecting results.

---

## 📌 Concept

The **numerical derivative** of a function \(f(x)\) is approximated using:

\[
f'(x) \approx \frac{f(x+h) - f(x)}{h}
\]

Where:
- `x` is the point of evaluation
- `h` is a small step size
- Floating-point arithmetic can produce **noticeable errors**, especially for very small or very large `h`.

---

## ⚙️ Features

- Computes **numerical derivative** for both float and double precision  
- Calculates **absolute error** compared to the true derivative (`cos(x)`)  
- Automatically highlights **where float precision starts producing noticeable errors**  
- Outputs **data for plotting error vs step size (h)**  

---

## 📝 Example Output

| Step size h | Error (float) | Error (double) |
|-------------|---------------|----------------|
| 1e-1        | 0.043         | 0.0429         |
| 1e-2        | 0.0009        | 0.0009         |
| 1e-8        | 0.00001       | 0.000000001    |
| 1e-10       | 0.01          | 0.00000000001  |
| 1e-12       | 0.5           | 0.0000000000001|

> **Observation:** Float loses precision much earlier than double. Double remains accurate for smaller `h`, but rounding errors eventually dominate.

---

## 💻 Code Structure

- `main.cpp` – Main program computing derivatives, errors, and highlighting noticeable float errors  
- Functions:
  - `double f(double x)` – Returns `sin(x)` for double precision  
  - `float f_float(float x)` – Returns `sin(x)` for float precision  
- Loop iterates over **decreasing `h` values** and prints:
  - `h` step size  
  - Numerical derivative (float & double)  
  - Absolute error (float & double)

---

## 🔬 Observations

- Float loses precision quickly; error >0.01 appears around `h ≈ 1e-10`  
- Double maintains accuracy for much smaller `h`  
- Demonstrates **catastrophic cancellation and rounding error** in numerical methods  
- Highlights **how small machine errors can grow silently** in computations

---

## 🎯 Real-World Relevance

Hidden numerical errors are critical in:  

- **Machine Learning** – gradient accumulation  
- **Physics Simulations** – forces, integrators  
- **Scientific Computing** – long-term simulations, finite differences  
- **Finance & Engineering** – risk modeling, numerical analysis  

Even tiny floating-point errors can have **serious real-world consequences**.

---

## 🛠️ How to Run

1. Clone the repository:

```bash
git clone https://github.com/hasnat-code/Numeric-Computing-Issue.git

#CPlusPlus #FloatingPointErrors #NumericalAnalysis #PortfolioProject #MachineLearning #Programming #Developer
