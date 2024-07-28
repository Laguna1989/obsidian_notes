---
tags:
  - tool
  - debugging
  - audio
---
# Setup

- Plugin (clap/vst3) needs to be build in debug mode
- In reaper `settings` -> `Plugins` -> `VST` or `CLAP` add debug folder from plugin build folder which contains the clap/vst file
- In IDE select the vst/clap target
	- set executable to reaper

# Debugging

- Once the plugin is loaded into the project, breakpoints will become active
- Debugging works as with a normal executable

# Tips

- Reaper loads plugins from folders in the order the folders are listed.
	- Early folders are checked first
	- This can be used to "override" the normal plugin with the debug version
- Storing a reaper project for easy setup saves time
- Automation lanes can be used to automatically (and consistently) toggle parameter changes
