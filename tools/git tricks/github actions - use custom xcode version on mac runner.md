---
tags:
  - tool
  - git
  - github
  - github-actions
---
# Github Actions Use Custom Xcode Version on Mac

Available versions can be checked on [this website](https://github.com/actions/runner-images/blob/main/images/macos/macos-14-Readme.md#xcode) (change url if you use a different macos version).

```yml
Mac:  
  runs-on: macos-latest  
  steps:  
    # Select fixed xcode version  
    - name: Select Xcode 15.4  
      run: sudo xcode-select -s /Applications/Xcode_15.4.app/Contents/Developer
      
    - name: Set up cmake  
      uses: jwlawson/actions-setup-cmake@v2.0  
      with:  
        cmake-version: '3.26.x'  
```
