---
tags:
  - tool
  - ai
links: "[[Tools MOC]]"
---
[Reference](https://www.reddit.com/r/StableDiffusion/comments/xkjjf9/upscale_to_huge_sizes_and_add_detail_with_sd/)

- Open the automatic1111 webui.
- Go to "img2img" tab at the top.
- Put something like "highly detailed" in the prompt box.1
- Select the "SD upscale" button at the top.
  - UPDATE: In the most recent version (9/22), this button is gone. Instead, you need to go down to "Scripts" at the bottom and select the "SD Upscale" script. Otherwise the process is the same.
- Load an initial image into the box (e.g. 512x512).
- Choose an upscaler. I recommend downloading additional models.2
- Choose the settings for SD upscaling:
  - A high number of iterations (150+).3
  - A high CFG scale (8-15) for adding detail.
  - A low denoising strength (0.1 to 0.2 or so) to keep most of the source image intact.
