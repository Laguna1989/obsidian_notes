---
tags:
  - tool
  - debugging
  - opengl
---

Generally hard to do

# Glsl-debugger

Does not work `debugee killed`

# Apitrace

- apitrace is a #tool for #opengl debugging
- Seems to work reasonably well
- <https://github.com/apitrace/apitrace>
- Build via
	- ```git clone --recurse-submodules  https://github.com/apitrace/apitrace.git```
	- ```cmake -S. -Bbuild -DCMAKE_BUILD_TYPE=RelWithDebInfo```
	- ```make -C build```
- Create Trace
	- ```cd build```
	- ```./apitrace trace /home/laguna/projects/slew_rate_limiter/cmake-build-debug/impl/slew_rate_limiter_plugin/sloth_artefacts/Debug/Standalone/sloth  --output sloth.trace```
- Tracefile is... complicated. Get a tracedump:
	- convert to readable version
		- ```./apitrace dump sloth.trace > sloth.trace.log```
		- created log file can be inspected with vim
	- investigate with `./qapitrace` -> file -> open `[path to trace file]`
		- gives list of frames with list of instructions
		- right click on any instruction -> lookup state

# Renderdoc
