cmake_minimum_required(VERSION 3.13)

#set(PICO_DEOPTIMIZED_DEBUG on)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#set(PICO_SDK_PATH "~/pico/pico-sdk")

include(pico_sdk_import.cmake)

project(picones C CXX ASM)
pico_sdk_init()

get_filename_component(PICO_FOLDER ${CMAKE_CURRENT_LIST_DIR}/.. ABSOLUTE)

add_executable(picones
    main.cpp
    hid_app.cpp
    gamepad.cpp
    tar.cpp
)

pico_set_program_name(picones "picones")
pico_set_program_version(picones "0.1")

pico_enable_stdio_uart(picones 1)
pico_enable_stdio_usb(picones 0)

# tinyusb
set(FAMILY rp2040)
set(BOARD pico_sdk)
set(TINYUSB_DEBUG_LEVE 0)
include(${PICO_TINYUSB_PATH}/hw/bsp/${FAMILY}/family.cmake)
family_configure_target(picones)
# add_compile_definitions(CFG_TUSB_DEBUG=0)

target_link_libraries(picones
PRIVATE
    pico_stdlib
    pico_multicore
    hardware_dma
    hardware_pio
    hardware_i2c
    hardware_interp
    hardware_timer
    hardware_clocks
    hardware_pwm
    hardware_flash
    dvi
    util
    infones
    tinyusb_host
    pico_emu_utils
)

target_include_directories(picones
PRIVATE
    ${PICO_FOLDER}/pico_lib/
    ${PICO_FOLDER}/pico-emu-utils/
    ${PICO_FOLDER}/pimoroni-pico/drivers/fatfs
    ${PICO_FOLDER}/pimoroni-pico/drivers/sdcard
    infones
    .
)

add_subdirectory(${PICO_FOLDER}/pico-emu-utils "${CMAKE_CURRENT_BINARY_DIR}/pico-emu-utils")
add_subdirectory(${PICO_FOLDER}/pico_lib/util "${CMAKE_CURRENT_BINARY_DIR}/pico_lib/util")
add_subdirectory(${PICO_FOLDER}/pico_lib/dvi "${CMAKE_CURRENT_BINARY_DIR}/pico_lib/dvi")
add_subdirectory(${PICO_FOLDER}/pimoroni-pico/drivers/fatfs "${CMAKE_CURRENT_BINARY_DIR}/pimoroni-pico/drivers/fatfs")
add_subdirectory(${PICO_FOLDER}/pimoroni-pico/drivers/sdcard "${CMAKE_CURRENT_BINARY_DIR}/pimoroni-pico/drivers/sdcard")

add_subdirectory(infones)

pico_add_extra_outputs(picones)




