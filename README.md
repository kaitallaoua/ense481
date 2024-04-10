# ense481 - STM32F10[1,2,3] Low Power Analysis

The structure is as follows:
- project: All relevant project files
  - code: the STM32CubeIde enviroment
  - docs: documentation on my project
  - freertos-tickless: my inital attempt on getting freertos-tickless working. Its a WIP
  - schematic: KiCad sch and pdf of project
- labs
  - 1: timing lab
  - 2: trig lab

## Project Setup
Get it [here](https://www.st.com/en/development-tools/stm32cubeide.html#get-software).

This project uses STM32CubeIde `Version: 1.13.1` and its code generator STM32CubeMX `Version: 6.9.1-RC1 Build: 20230719-1849 (UTC)`

Im not certain how to add an existing project into the ide, but following [this guide seems like a good one](https://community.st.com/t5/stm32cubemx-mcus/how-to-import-a-project-into-stmcubeide-which-is-generated-by/td-p/311448)

## Workflow

I was the only software person for this project, so I didnt bother with PR's and other typical and proper version control methods.

I highly recommend new contributers to review how the cube ide works and how to work with (not against) the code generator. Since the code generator will overwrite your changes if they are not in the proper place, it can be frustrating untill you are familiar with it. 

## Equipment

- A nucleo-F103RB
- Jumper wires
- Breadboard
- One 1 ohm resistor

## Setup

I snapped the ST-LINK off my nucleo to better measure the power of only the mcu components on their own. Use two pliers to make the snap clean or parts can fall off from the flexing.