# 🚀 C++ Template Project for JUCE-based audio applications (and plugins).

## Requirements

- Cmake
- Ninja
- LLDB

This template loosely assumes you are using VSCode, but you can set up your own debugging if preferred.

## Set-up

Clone the project using:

```sh
git clone --recurse-submodules <repo link>
```

This -should- immediately set-up the submodules as well.

Next you need to build the AudioPluginHost, which is located in:

```sh
cwd/lib/JUCE/extras/AudioPluginHost/Builds
```

There you can pick the platform you are building for, and build the _debug_ version of the host.

I recommend doing this only once, and then installing the debug version of AudioPluginHost to a default location on your system.
For MacOS this would be the appliations folder.

Next we need to set up some names and paths.
The first is in the .vscode folder in settings.json, here you need to set both the project name and the (absolute) path to AudioPluginHost.

The second is in the CMakeLists.txt file where you need to set the project name to match the name you just used in settings.json.
Here you can also configure other settings, take a look at "juce_add_plugin" for the options.

## Usage

This project uses **CMake** for building.
In the root of the project run the following commands in a terminal window.

### Configure (Set Up the Build)

```sh
cmake --preset <configure preset name>
```

The available configure presets are:

- debug
- Release

### Build (Compile the Project)

After configuring, build using the corresponding preset:

```sh
cmake --build --preset <build preset name>
```

The available build presets corresponding to your configure preset are:

- build-debug (if you used the debug preset)
- build-release (if you used the release preset)

The finalfiles will be in:

```
cwd/build/build_preset/artefacts/build_preset
```

There you will find the AU, Standalone and VST3 builds.
