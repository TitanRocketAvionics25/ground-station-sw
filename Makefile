sources = src/drivers/sx127x

hw_sources = src/ src/startup src/sysclk src/spiconf

WFLAGS = -Wall

build = build

CLISTM_SRC_DIRS = $(sources) $(hw_sources)
CLISTM_BUILD_DIR = $(build)
CLISTM_MODEL_NUM = STM32F411xE
CLISTM_HAL_MODULES = gpio dma spi
CLISTM_STARTUP_FILE = src/startup/startup.c
CLISTM_WFLAGS = $(WFLAGS)


.PHONY: clean
clean:
	rm -r build


include tools/command-line-stm32f4/command_line_stm32f4.mk
