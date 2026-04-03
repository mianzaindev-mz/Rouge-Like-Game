# RogueEngine

A fully featured roguelike game and engine built in C++ from scratch. This project demonstrates professional C++ development practices across all phases of software engineering, from low-level memory management to high-level architecture design.
a
## Features

### Core Engine
- **Entity-Component Architecture**: Modular design allowing flexible entity composition
- **Custom Rendering Layer**: Efficient rendering system optimized for terminal-based games
- **Real-time Combat System**: Turn-based or real-time combat mechanics
- **Procedural Dungeon Generation**: Algorithmically generated levels with rooms, corridors, and secrets
- **Inventory System**: Comprehensive item management with equipment, consumables, and crafting
- **Save/Load Persistence**: Robust serialization system for game state preservation

### Game Features
- Character progression and stats
- Multiple enemy types with AI
- Interactive world with traps, treasures, and NPCs
- Multiple dungeon levels with increasing difficulty
- Achievement system
- High score tracking

## Architecture

The engine is built with modern C++ practices:
- RAII for resource management
- Smart pointers for memory safety
- Template metaprogramming for type safety
- Exception-safe code
- Multi-threaded where appropriate
- Cross-platform compatibility

## Building

### Prerequisites
- CMake 3.16 or higher
- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- (Optional) SDL2 for enhanced rendering

### Build Instructions
```bash
mkdir build
cd build
cmake ..
make
```

### Running
```bash
./RogueEngine
```

## Current Status

**Version 0.2**

- [x] Basic project structure
- [x] CMake build system
- [x] Player entity with basic stats
- [ ] Entity-component system
- [ ] Rendering layer
- [ ] Dungeon generation
- [ ] Combat system
- [ ] Inventory system
- [ ] Persistence
- [ ] Game loop and input handling

## Contributing

This project follows professional development standards:
- Code reviews required
- Unit tests for all features
- Documentation for all public APIs
- Clean, readable code with consistent style

### Development Setup
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests
5. Submit a pull request

## License

This project is proprietary and licensed for educational and non-commercial use only. All rights reserved.

**Permitted:** Educational learning, academic research, personal hobby projects  
**Prohibited:** Commercial use, redistribution, derivative works for profit

See the LICENSE file for full details. For commercial licensing, contact the copyright holder.

## Roadmap

- **v0.3**: Basic rendering and input
- **v0.5**: Entity system and dungeon generation
- **v1.0**: Complete game with all core features
- **v1.5**: Multiplayer support
- **v2.0**: Advanced features and modding support
- **vx.x**: More Features and Updates coming soon



