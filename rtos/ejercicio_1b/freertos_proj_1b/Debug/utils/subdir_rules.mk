################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
utils/cmdline.obj: /home/asus/workspace_linux/utils/cmdline.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/cmdline.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/cpu_usage.obj: /home/asus/workspace_linux/utils/cpu_usage.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/cpu_usage.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/eeprom_pb.obj: /home/asus/workspace_linux/utils/eeprom_pb.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/eeprom_pb.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/flash_pb.obj: /home/asus/workspace_linux/utils/flash_pb.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/flash_pb.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/isqrt.obj: /home/asus/workspace_linux/utils/isqrt.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/isqrt.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/random.obj: /home/asus/workspace_linux/utils/random.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/random.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/ringbuf.obj: /home/asus/workspace_linux/utils/ringbuf.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/ringbuf.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/scheduler.obj: /home/asus/workspace_linux/utils/scheduler.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/scheduler.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/sine.obj: /home/asus/workspace_linux/utils/sine.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/sine.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/smbus.obj: /home/asus/workspace_linux/utils/smbus.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/smbus.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/softi2c.obj: /home/asus/workspace_linux/utils/softi2c.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/softi2c.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/softssi.obj: /home/asus/workspace_linux/utils/softssi.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/softssi.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/softuart.obj: /home/asus/workspace_linux/utils/softuart.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/softuart.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/spi_flash.obj: /home/asus/workspace_linux/utils/spi_flash.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/spi_flash.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/uartstdio.obj: /home/asus/workspace_linux/utils/uartstdio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/uartstdio.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utils/ustdlib.obj: /home/asus/workspace_linux/utils/ustdlib.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utils/ustdlib.pp" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


