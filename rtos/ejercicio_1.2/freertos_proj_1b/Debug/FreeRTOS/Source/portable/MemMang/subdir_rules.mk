################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/MemMang/heap_2.obj: /home/asus/workspace_linux/FreeRTOS/Source/portable/MemMang/heap_2.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/opt/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="/home/asus/workspace_linux" --include_path="/home/asus/workspace_linux/driverlib" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/home/asus/workspace_linux/FreeRTOS/Source/include" --include_path="/home/asus/workspace_linux/freertos_proj_1b/" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="FreeRTOS/Source/portable/MemMang/heap_2.pp" --obj_directory="FreeRTOS/Source/portable/MemMang" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


