# Unreal Engine Skill for Claude Code

A comprehensive Claude Code skill for Unreal Engine development with deep project structure understanding and best practices.

## Features

- **Zero Assumptions Philosophy**: Always discovers your project structure before suggesting code
- **Enhanced Input System**: Complete support for UE5's Enhanced Input with automatic asset discovery
- **Gameplay Ability System (GAS)**: Full GAS integration with setup guidance and common patterns
- **Plugin Support**: Handles experimental and beta plugins with intelligent documentation lookup
- **Version-Aware**: Automatically detects engine version and provides appropriate code
- **Project-Specific**: Discovers your naming conventions and existing patterns

## Installation

### For Claude Code

1. Copy this skill to your Claude Code skills directory:

```bash
# Personal skills (available in all projects)
cp -r unreal-engine ~/.claude/skills/

# OR Project skills (team-shared via git)
cp -r unreal-engine .claude/skills/
```

2. The skill will automatically activate when working on Unreal Engine projects

### For Claude.ai

1. Zip the skill directory
2. Upload to Claude.ai via the Skills interface
3. Enable the skill when working on Unreal Engine projects

## What This Skill Does

The skill automatically activates when you ask Unreal Engine development questions and:

1. **Discovers your project structure**:
   - Locates and reads `.uproject` file
   - Maps `Source/` and `Content/` directories
   - Identifies enabled plugins and engine version

2. **Finds existing assets**:
   - Input Actions and Mapping Contexts
   - Blueprint classes
   - C++ classes and naming conventions

3. **Provides context-aware suggestions**:
   - Uses your actual asset names (not generic placeholders)
   - Follows your project's patterns
   - Version-appropriate API usage

4. **Handles specialized systems**:
   - Enhanced Input binding
   - GAS setup and usage
   - Plugin integration
   - Blueprint-C++ interaction

## Topics Covered

- C++ gameplay programming
- Blueprint development
- Enhanced Input System configuration
- Gameplay Ability System (GAS)
- Project structure navigation
- Asset discovery and referencing
- Plugin integration (experimental/beta)
- API lookups for underdocumented features
- Debugging and troubleshooting

## Included References

The skill includes detailed reference documentation for:

- **Enhanced Input System** (`references/enhanced_input.md`): Complete API reference, binding patterns, and migration guides
- **Gameplay Ability System** (`references/gameplay_ability_system.md`): Setup, replication, abilities, attributes, and best practices
- **Common Pitfalls** (`references/common_pitfalls.md`): Troubleshooting for input, GAS, builds, and performance issues

## Usage Examples

Simply ask Claude about your Unreal Engine development tasks:

- "Add jump functionality to my character"
- "Set up Enhanced Input for movement"
- "Create a dash ability using GAS"
- "How do I bind input actions in C++?"
- "Help me debug this compilation error"

The skill will automatically discover your project structure and provide tailored solutions.

## Contributing

Contributions are welcome! If you have improvements or find issues:

1. Fork this repository
2. Make your changes
3. Submit a pull request

## License

This skill is provided as-is for use with Claude Code and Claude.ai.

## Author

Created for the Unreal Engine development community using Claude Code.
