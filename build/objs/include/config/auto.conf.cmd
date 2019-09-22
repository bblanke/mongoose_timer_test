deps_config := \
	/opt/Espressif/esp-idf/components/app_trace/Kconfig \
	/opt/Espressif/esp-idf/components/driver/Kconfig \
	/opt/Espressif/esp-idf/components/efuse/Kconfig \
	/opt/Espressif/esp-idf/components/espcoredump/Kconfig \
	/opt/Espressif/esp-idf/components/esp_adc_cal/Kconfig \
	/opt/Espressif/esp-idf/components/esp_event/Kconfig \
	/opt/Espressif/esp-idf/components/esp32/Kconfig \
	/opt/Espressif/esp-idf/components/ethernet/Kconfig \
	/opt/Espressif/esp-idf/components/freertos/Kconfig \
	/opt/Espressif/esp-idf/components/heap/Kconfig \
	/opt/Espressif/esp-idf/components/log/Kconfig \
	/opt/Espressif/esp-idf/components/lwip/Kconfig \
	/opt/Espressif/esp-idf/components/nvs_flash/Kconfig \
	/opt/Espressif/esp-idf/components/pthread/Kconfig \
	/opt/Espressif/esp-idf/components/spi_flash/Kconfig \
	/opt/Espressif/esp-idf/components/tcpip_adapter/Kconfig \
	/opt/Espressif/esp-idf/components/vfs/Kconfig \
	/opt/Espressif/esp-idf/components/spiffs/Kconfig \
	/opt/Espressif/esp-idf/components/bt/Kconfig \
	/opt/Espressif/esp-idf/components/app_update/Kconfig.projbuild \
	/opt/Espressif/esp-idf/components/bootloader/Kconfig.projbuild \
	/opt/Espressif/esp-idf/components/esptool_py/Kconfig.projbuild \
	/opt/Espressif/esp-idf/components/partition_table/Kconfig.projbuild \
	/opt/Espressif/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)

ifneq "$(IDF_TARGET)" "esp32"
include/config/auto.conf: FORCE
endif
ifneq "$(IDF_CMAKE)" "n"
include/config/auto.conf: FORCE
endif

$(deps_config): ;
