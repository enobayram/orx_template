#traverse all the directory and subdirectory
define walk
  $(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call walk, $(e)))
endef

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := orx_template

LOCAL_CFLAGS += -std=c++11 -fexceptions -frtti
LOCAL_C_INCLUDES := $(LOCAL_PATH)/src $(ORX_DIR)/scroll/include/Scroll

ALL_SOURCES := $(call walk, $(LOCAL_PATH)/src)

FILE_LIST := $(filter %.cpp, $(ALL_SOURCES))
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_STATIC_LIBRARIES := orx

LOCAL_ARM_MODE := arm

include $(BUILD_SHARED_LIBRARY)

$(call import-module,lib/static/android)

