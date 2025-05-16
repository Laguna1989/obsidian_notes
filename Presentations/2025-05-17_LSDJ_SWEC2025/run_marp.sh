#!/bin/bash

# Build the presentation PDF
npx @marp-team/marp-cli@latest lsdj_presentation.md --pdf --allow-local-files
