################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2

ORDERED_OBJS += \
"./pulsador_antirebote.obj" \
"./startup_ccs.obj" \
"./utils/cmdline.obj" \
"./utils/cpu_usage.obj" \
"./utils/eeprom_pb.obj" \
"./utils/flash_pb.obj" \
"./utils/isqrt.obj" \
"./utils/random.obj" \
"./utils/ringbuf.obj" \
"./utils/scheduler.obj" \
"./utils/sine.obj" \
"./utils/smbus.obj" \
"./utils/softi2c.obj" \
"./utils/softssi.obj" \
"./utils/softuart.obj" \
"./utils/spi_flash.obj" \
"./utils/uartstdio.obj" \
"./utils/ustdlib.obj" \
"./drivers/buttons.obj" \
"./drivers/rgb.obj" \
"./FreeRTOS/Source/croutine.obj" \
"./FreeRTOS/Source/list.obj" \
"./FreeRTOS/Source/queue.obj" \
"./FreeRTOS/Source/tasks.obj" \
"./FreeRTOS/Source/timers.obj" \
"./FreeRTOS/Source/portable/MemMang/heap_2.obj" \
"./FreeRTOS/Source/portable/CCS/ARM_CM4F/port.obj" \
"./FreeRTOS/Source/portable/CCS/ARM_CM4F/portasm.obj" \
"../freertos_project.cmd" \
$(GEN_CMDS__FLAG) \
-l"libc.a" \
-l"C:\Users\Adrian\workspace_windows\driverlib\Debug\driverlib.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include utils/subdir_vars.mk
-include drivers/subdir_vars.mk
-include FreeRTOS/Source/subdir_vars.mk
-include FreeRTOS/Source/portable/MemMang/subdir_vars.mk
-include FreeRTOS/Source/portable/CCS/ARM_CM4F/subdir_vars.mk
-include subdir_rules.mk
-include utils/subdir_rules.mk
-include drivers/subdir_rules.mk
-include FreeRTOS/Source/subdir_rules.mk
-include FreeRTOS/Source/portable/MemMang/subdir_rules.mk
-include FreeRTOS/Source/portable/CCS/ARM_CM4F/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
TP2-ej1-4.out \

EXE_OUTPUTS__QUOTED += \
"TP2-ej1-4.out" \

BIN_OUTPUTS += \
TP2-ej1-4.hex \

BIN_OUTPUTS__QUOTED += \
"TP2-ej1-4.hex" \


# All Target
all: TP2-ej1-4.out

# Tool invocations
TP2-ej1-4.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off -z -m"TP2-ej1-4.map" --heap_size=0 --stack_size=512 -i"C:/Users/Adrian/workspace_windows/driverlib" -i"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/lib" -i"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" --reread_libs --warn_sections --display_error_number --diag_wrap=off --xml_link_info="TP2-ej1-4_linkInfo.xml" --rom_model -o "TP2-ej1-4.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

TP2-ej1-4.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armhex"  -o "TP2-ej1-4.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "pulsador_antirebote.pp" "startup_ccs.pp" "utils\cmdline.pp" "utils\cpu_usage.pp" "utils\eeprom_pb.pp" "utils\flash_pb.pp" "utils\isqrt.pp" "utils\random.pp" "utils\ringbuf.pp" "utils\scheduler.pp" "utils\sine.pp" "utils\smbus.pp" "utils\softi2c.pp" "utils\softssi.pp" "utils\softuart.pp" "utils\spi_flash.pp" "utils\uartstdio.pp" "utils\ustdlib.pp" "drivers\buttons.pp" "drivers\rgb.pp" "FreeRTOS\Source\croutine.pp" "FreeRTOS\Source\list.pp" "FreeRTOS\Source\queue.pp" "FreeRTOS\Source\tasks.pp" "FreeRTOS\Source\timers.pp" "FreeRTOS\Source\portable\MemMang\heap_2.pp" "FreeRTOS\Source\portable\CCS\ARM_CM4F\port.pp" 
	-$(RM) "pulsador_antirebote.obj" "startup_ccs.obj" "utils\cmdline.obj" "utils\cpu_usage.obj" "utils\eeprom_pb.obj" "utils\flash_pb.obj" "utils\isqrt.obj" "utils\random.obj" "utils\ringbuf.obj" "utils\scheduler.obj" "utils\sine.obj" "utils\smbus.obj" "utils\softi2c.obj" "utils\softssi.obj" "utils\softuart.obj" "utils\spi_flash.obj" "utils\uartstdio.obj" "utils\ustdlib.obj" "drivers\buttons.obj" "drivers\rgb.obj" "FreeRTOS\Source\croutine.obj" "FreeRTOS\Source\list.obj" "FreeRTOS\Source\queue.obj" "FreeRTOS\Source\tasks.obj" "FreeRTOS\Source\timers.obj" "FreeRTOS\Source\portable\MemMang\heap_2.obj" "FreeRTOS\Source\portable\CCS\ARM_CM4F\port.obj" "FreeRTOS\Source\portable\CCS\ARM_CM4F\portasm.obj" 
	-$(RM) "FreeRTOS\Source\portable\CCS\ARM_CM4F\portasm.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

