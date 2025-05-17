# Hook Library

A lightweight hooking library for intercepting native functions and adding custom logic.

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Contributing](#contributing)
- [License](#license)

## 🔍 Overview

Hook Library is designed to intercept native functions like memcpy, allowing you to:
- Add custom validation and logic to function calls
- Debug and modify library behavior without source code changes
- Monitor and control native function execution

## ⭐ Features

### Core Components
```c
// Essential Data Types
typedef signed char        __int8;
typedef signed short      __int16;
typedef signed int        __int32;
typedef signed long long  __int64;

// Global Variables
uintptr_t Mylib;
DWORD libMylibBase = 0;
DWORD libMylibAlloc = 0;
unsigned int libMylibSize = 0x48B49;
```

### Key Features
- Native function interception
- Buffer validation
- Pointer safety checks
- Logging capabilities
- Cross-architecture compatibility

## 📥 Installation

### Prerequisites
- Android Studio or Aide
- NDK support
- Gradle build 


### Basic Implementation
```c
// Initialize hook system
init_hook();

// Register your hooks
register_hook("memcpy", hook_memcpy);

// Enable hooking
enable_hooks();
```

### Example Hook
```c
void* hook_memcpy(void* dest, const void* src, size_t count) {
    // Validation logic
    if (!dest || !src) {
        return NULL;
    }
    
    // Original function call
    return orig_memcpy(dest, src, count);
}
```


## 🤝 Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/Qwanwin/Hook-library/blob/main/LICENSE) file for details.

---
Made with  by [Qwanwin](https://github.com/Qwanwin)

## 🔗 Links
- [Repository](https://github.com/Qwanwin/Hook-library)
- [Issues](https://github.com/Qwanwin/Hook-library/issues)
