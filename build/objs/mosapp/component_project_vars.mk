# Automatically generated build file. Do not edit.
COMPONENT_INCLUDES += $(PROJECT_PATH)/mosapp/include
COMPONENT_LDFLAGS += -L$(BUILD_DIR_BASE)/mosapp $(BUILD_DIR_BASE)/libmbedtls-esp32-latest.a $(BUILD_DIR_BASE)/libmongoose-esp32-latest.a $(BUILD_DIR_BASE)/libota-common-esp32-latest.a $(BUILD_DIR_BASE)/libota-http-client-esp32-latest.a $(BUILD_DIR_BASE)/libota-shadow-esp32-latest.a $(BUILD_DIR_BASE)/libdash-esp32-latest.a $(BUILD_DIR_BASE)/libota-http-server-esp32-latest.a $(BUILD_DIR_BASE)/librpc-service-ota-esp32-latest.a -Wl,--whole-archive -lmosapp -Wl,--no-whole-archive
COMPONENT_LINKER_DEPS += 
COMPONENT_SUBMODULES += 
COMPONENT_LIBRARIES += mosapp
COMPONENT_LDFRAGMENTS += 
component-mosapp-build: 
