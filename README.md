# cpypy

> A toy project to integrate C++ code into Python using `pybind11`, `setuptools`, and `uv`.

This project demonstrates how to wrap high-performance C++ code as a native Python extension using `pybind11`, while preserving Pythonic usability and integrating with NumPy.

---

## 📦 Project Structure

```
cpypy/
├── pyproject.toml         # Build config using setuptools and pybind11
├── main.py                # Sample usage script
├── src/
│   └── cpp_lib/
│       ├── __init__.py            # Exposes the compiled extension
│       ├── cpp_lib.cpython-*.so   # Compiled native module (auto-generated)
│       ├── cpp_lib.pyi            # Type stubs for IntelliSense
│       ├── lib.cpp                # pybind11 module entry point
│       └── lib_src/
│           ├── two.cpp            # Extra C++ source
│           └── three.cpp
├── typings/
│   └── cpp_lib/
│       ├── cpp_lib.pyi
│       └── __init__.pyi
└── .vscode/
    └── settings.json       # VS Code config for proper import resolution
```

---

## 🚀 Getting Started

### 1. Install dependencies

This project uses [uv](https://github.com/astral-sh/uv) for fast Python builds and dependency resolution.

```bash
uv venv
source .venv/bin/activate
uv pip install -e .
```

---

### 2. Run the demo

```bash
python main.py
```

Expected output:

```
[2. 4. 6.]
```

---

## 🧪 Using the Native Extension

The C++ extension is defined via `pybind11` and exposes the following Python API:

```python
from cpp_lib import scale_by_two

scale_by_two([1.0, 2.0, 3.0])
# → array([2.0, 4.0, 6.0])
```

Under the hood, this calls high-performance C++ code via NumPy buffers.

---

## 🛠 C++ Build Details

The extension is defined in `pyproject.toml`:

```toml
[[tool.setuptools.ext-modules]]
name = "cpp_lib.cpp_lib"
sources = [
    "src/cpp_lib/lib.cpp",
    "src/cpp_lib/lib_src/two.cpp",
    "src/cpp_lib/lib_src/three.cpp"
]
extra-compile-args = ["-std=c++17"]
```

Make sure your environment includes headers for:
- `Python.h` (provided via `pyenv`)
- `pybind11` (installed with `pip`)

